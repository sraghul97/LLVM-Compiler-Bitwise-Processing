%{
#include <cstdio>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <unordered_map>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "llvm/Bitcode/BitcodeReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/SystemUtils.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/FileSystem.h"

using namespace llvm;
using namespace std;


// Need for parser and scanner
extern FILE *yyin;
int yylex();
void yyerror(const char*);
int yyparse();
 
// Needed for LLVM
string funName;
Module *M;
LLVMContext TheContext;
IRBuilder<> Builder(TheContext);

unordered_map<string, Value *> id_mapping_table;
%}

%verbose                              
%define parse.trace                     

%union {
  vector<string> *params_list;
  Value *union_value;
  char *union_id;
  int union_number;
}

/*%define parse.trace*/

%type <params_list> params_list
%type <union_value> expr
%type <union_value> ensemble
%type <union_value> statement
%type <union_value> statements

%token IN FINAL
%token ERROR
%token <union_number> NUMBER
%token <union_id> ID 
%token BINV INV PLUS MINUS XOR AND OR MUL DIV MOD
%token COMMA ENDLINE ASSIGN LBRACKET RBRACKET LPAREN RPAREN NONE COLON
%token REDUCE EXPAND

%precedence BINV
%precedence INV
%left PLUS MINUS OR
%left MUL DIV AND XOR MOD

%start program

%%

program: inputs statements_opt final
{
  YYACCEPT;
}
;

inputs:   IN params_list ENDLINE
{  
  std::vector<Type*> param_types;
  for(auto s: *$2)
    {
      param_types.push_back(Builder.getInt32Ty());
    }
  ArrayRef<Type*> Params (param_types);
  
  // Create int function type with no arguments
  FunctionType *FunType = 
    FunctionType::get(Builder.getInt32Ty(),Params,false);

  // Create a main function
  Function *Function = Function::Create(FunType,GlobalValue::ExternalLinkage,funName,M);

  int arg_no=0;
  for(auto &a: Function->args()) {
    // iterate over arguments of function
    // match name to position
    Value *arg_ptr = &a;   // as it loops, refers first to a, then b, then c and so on
    id_mapping_table[$2->at(arg_no)] = arg_ptr;   // Store the argument pointer in the map
    arg_no++;       // Move to the next argument position
  }
  
  //Add a basic block to main to hold instructions, and set Builder
  //to insert there
  Builder.SetInsertPoint(BasicBlock::Create(TheContext, "entry", Function));

}
| IN NONE ENDLINE
{ 
  // Create int function type with no arguments
  FunctionType *FunType = 
    FunctionType::get(Builder.getInt32Ty(),false);

  // Create a main function
  Function *Function = Function::Create(FunType,  
         GlobalValue::ExternalLinkage,funName,M);

  //Add a basic block to main to hold instructions, and set Builder
  //to insert there
  Builder.SetInsertPoint(BasicBlock::Create(TheContext, "entry", Function));
}
;

params_list: ID
{
  $$ = new vector<string>;
  // add the ID to vector
  $$->push_back($1);
}
| params_list COMMA ID
{
  // add the ID to $1
  $$->push_back($3);
}
;

final: FINAL ensemble endline_opt
{
  
  Builder.CreateRet($2);
  return 0; /* program is done */
}
;

endline_opt: %empty 
| ENDLINE
;

statements_opt: %empty 
| statements
;

statements:   statement 
| statements statement
;

statement: ID ASSIGN ensemble ENDLINE
{
  id_mapping_table[$1] = $3;
} 
| ID NUMBER ASSIGN ensemble ENDLINE            
{
  if (id_mapping_table.find($1) == id_mapping_table.end())
  {
    // Check if key $1 is not found in id_mapping_table
    printf("ERROR! It’s illegal to set a bit of '%s' before defining '%s'\n",string($1).c_str(), string($1).c_str());
    YYABORT; // Abort parsing if key $1 is not found
  }
  Value *id_value = id_mapping_table[$1]; // Get the value corresponding to key $1
  Value *ensemble_value_1 = Builder.CreateSRem(Builder.getInt32($2), Builder.getInt32(32));
  Value *ensemble_value_2 = Builder.CreateAnd($4, Builder.getInt32(1));
  ensemble_value_2 = Builder.CreateShl(ensemble_value_2, ensemble_value_1); // Shift ensemble_value_2 left by ensemble_value_1
  
  Value *bit_mask = Builder.CreateNot(Builder.CreateShl(Builder.getInt32(1), ensemble_value_1));  // Create a bitmask by shifting 1 left by ensemble_value_1 and then negating it
  id_value = Builder.CreateAnd(id_value, bit_mask); // Clear the bit in id_value at ensemble_value_1 position
  id_value = Builder.CreateOr(id_value, ensemble_value_2); // Set the bit in id_value at ensemble_value_1 position
  id_mapping_table[$1] = id_value; // Update the value in id_mapping_table for key $1
  $$ = id_mapping_table[$1]; // Set the return value to the updated value for key $1
}
| ID LBRACKET ensemble RBRACKET ASSIGN ensemble ENDLINE                 
{
  if (id_mapping_table.find($1) == id_mapping_table.end())
  {
    // Check if key $1 is not found in id_mapping_table
    printf("ERROR! It’s illegal to set a bit of '%s' before defining '%s'\n",string($1).c_str(), string($1).c_str());
    YYABORT; // Abort parsing if key $1 is not found
  }
  Value *id_value = id_mapping_table[$1]; // Get the value corresponding to key $1
  Value *ensemble_value_1 = Builder.CreateSRem($3, Builder.getInt32(32)); // Calculate the remainder of $3 divided by 32
  Value *ensemble_value_2 = Builder.CreateAnd($6, Builder.getInt32(1)); // Extract the least significant bit of $6
  ensemble_value_2 = Builder.CreateShl(ensemble_value_2, ensemble_value_1); // Shift ensemble_value_2 left by ensemble_value_1

  Value *bit_mask = Builder.CreateNot(Builder.CreateShl(Builder.getInt32(1), ensemble_value_1)); // Create a bitmask for clearing the bit at ensemble_value_1
  id_value = Builder.CreateAnd(id_value, bit_mask); // Clear the bit in id_value at ensemble_value_1 position
  id_value = Builder.CreateOr(id_value, ensemble_value_2); // Set the bit in id_value at ensemble_value_1 position
  id_mapping_table[$1] = id_value; // Update the value in id_mapping_table for key $1
  $$ = id_mapping_table[$1]; // Set the return value to the updated value for key $1
}
;

ensemble:  expr 
{
  $$ = $1;
}
| expr COLON NUMBER                  // 566 only   
{
  Value *value_expr = Builder.CreateShl($1, Builder.getInt32($3)); // Shift the value of $1 left by $3 bits

  $$ = value_expr; // Set the return value to the shifted value
}
| ensemble COMMA expr
{
  Value *value_expr = $3; // Store $3 in value_expr
  Value *ensemble_value = $1; // Store $1 in ensemble_value
  Value *final_value; // Declare final_value

  value_expr = Builder.CreateShl(value_expr, Builder.getInt32(0)); // Shift value_expr left by 0 bits (no effect)
  ensemble_value = Builder.CreateShl(ensemble_value, Builder.getInt32(1)); // Shift ensemble_value left by 1 bit
  final_value = Builder.CreateOr(ensemble_value, value_expr); // OR ensemble_value with value_expr

  $$ = final_value; // Set the return value to final_value
}
| ensemble COMMA expr COLON NUMBER   // 566 only   
{
  Value *value_expr = $3; // Store $3 in value_expr
  Value *ensemble_value = $1; // Store $1 in ensemble_value
  Value *final_value; // Declare final_value

  value_expr = Builder.CreateShl(value_expr, $5); // Shift value_expr left by $5 bits (NUMBER)
  ensemble_value = Builder.CreateShl(ensemble_value, $5); // Shift ensemble_value left by $5 bits  (NUMBER)
  ensemble_value = Builder.CreateShl(ensemble_value, Builder.getInt32(1)); // Shift ensemble_value left by 1 bit (COMMA)
  final_value = Builder.CreateOr(ensemble_value, value_expr); // OR ensemble_value with value_expr

  $$ = final_value; // Set the return value to final_value
}
;

expr:   ID   
{
  if (id_mapping_table.find($1) == id_mapping_table.end())
  {
    printf("ERROR! It’s illegal to get/read '%s' before defining '%s'\n",string($1).c_str(), string($1).c_str());
    $$ = Builder.getInt32(0); 
    //return 0; 
    //YYABORT;
  }
  else
  {
    $$ = id_mapping_table[$1]; 
  }
}
| ID NUMBER     
{
  if (id_mapping_table.find($1) == id_mapping_table.end())
  {
    printf("ERROR! It’s illegal to get/read a bit of '%s' before defining '%s'\n",string($1).c_str(), string($1).c_str());
    $$ = Builder.getInt32(0); 
    //return 0; 
    //YYABORT; 
  }
  else
  {
    Value *id_value = id_mapping_table[$1]; // Get value from id_mapping_table for key $1
    Value *number_value = Builder.CreateSRem(Builder.getInt32($2), Builder.getInt32(32)); // Get remainder of $2 divided by 32
    Value *Final_Value = Builder.CreateLShr(id_value, number_value); // Logical shift right id_value by number_value bits
    Final_Value = Builder.CreateAnd(Final_Value, Builder.getInt32(1)); // Perform bitwise AND with 1
    $$ = Final_Value; // Set the return value to Final_Value
  }
}
| NUMBER
{
  $$ = Builder.getInt32($1);  
}
| expr PLUS expr
{
  $$ = Builder.CreateAdd($1,$3);
}
| expr MINUS expr
{
  $$ = Builder.CreateSub($1,$3);
}
| expr XOR expr
{
  $$ = Builder.CreateXor($1,$3); 
}
| expr AND expr
{
  $$ = Builder.CreateAnd($1,$3);
}
| expr OR expr
{
  $$ = Builder.CreateOr($1,$3);
}
| INV expr
{
  $$ = Builder.CreateNot($2);
}
| BINV expr
{
  $$ = Builder.CreateXor(Builder.getInt32(1), $2);
}
| expr MUL expr
{
  $$ = Builder.CreateMul($1,$3);
}
| expr DIV expr
{
  $$ = Builder.CreateUDiv($1,$3);
}
| expr MOD expr
{
  $$ = Builder.CreateSRem($1,$3); //Getting reminder $1 % $3
}
| ID LBRACKET ensemble RBRACKET   
{
  if (id_mapping_table.find($1) == id_mapping_table.end())
  {
    printf("ERROR! It’s illegal to get/read a bit of '%s' before defining '%s'\n",string($1).c_str(), string($1).c_str());
    $$ = Builder.getInt32(0);
    //return 0; 
    //YYABORT;  
  }
  else
  {
    Value *id_value = id_mapping_table[$1]; // Get value from id_mapping_table for key $1
    Value *number_value = Builder.CreateSRem($3, Builder.getInt32(32)); // Get remainder of $3 divided by 32
    Value *Final_Value = Builder.CreateLShr(id_value, number_value); // Logical shift right id_value by number_value bits
    Final_Value = Builder.CreateAnd(Final_Value, Builder.getInt32(1)); // Perform bitwise AND with 1
    $$ = Final_Value; // Set the return value to Final_Value
  }
}
| LPAREN ensemble RPAREN       
{
  $$ = $2;
}
/* 566 only */
| LPAREN ensemble RPAREN LBRACKET ensemble RBRACKET        
{ 
  Value *Final_Value = Builder.CreateLShr($2, $5); // Logical shift right $2 by $5 bits
  Final_Value = Builder.CreateAnd(Final_Value, Builder.getInt32(1)); // Perform bitwise AND with 1
  $$ = Final_Value; // Set the return value to Final_Value
}
| REDUCE AND LPAREN ensemble RPAREN       
{
  Value *temp_value; // Declare temporary value
  Value *final_value = Builder.getInt32(1); // Initialize final_value to 1
  for (int LoopCounter = 0; LoopCounter < 32; LoopCounter++) // Loop from 0 to 31
  {
    temp_value =  Builder.CreateLShr($4, Builder.getInt32(LoopCounter)); // Shift $4 right by LoopCounter bits
    temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1
    final_value = Builder.CreateAnd(final_value, temp_value); // Perform bitwise AND with temp_value
  } 
  $$ = final_value; // Set the return value to final_value
}
| REDUCE OR LPAREN ensemble RPAREN       
{
  Value *temp_value; // Declare temporary value
  Value *final_value = Builder.getInt32(0); // Initialize final_value to 0
  for (int LoopCounter = 0; LoopCounter < 32; LoopCounter++) // Loop from 0 to 31
  {
    temp_value =  Builder.CreateLShr($4, Builder.getInt32(LoopCounter)); // Shift $4 right by LoopCounter bits
    temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1
    final_value = Builder.CreateOr(final_value, temp_value); // Perform bitwise OR with temp_value
  } 
  $$ = final_value; // Set the return value to final_value
}
| REDUCE XOR LPAREN ensemble RPAREN       
{
  Value *temp_value = Builder.CreateLShr($4, Builder.getInt32(0)); // Shift $4 right by 0 bits
  temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1
  Value *final_value = temp_value; // Initialize final_value with temp_value

  for (int LoopCounter = 1; LoopCounter < 32; LoopCounter++) // Loop from 1 to 31
  {
    temp_value =  Builder.CreateLShr($4, Builder.getInt32(LoopCounter)); // Shift $4 right by LoopCounter bits
    temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1
    final_value = Builder.CreateXor(final_value, temp_value); // Perform bitwise XOR with temp_value
  } 
  $$ = final_value; // Set the return value to final_value
}
| REDUCE PLUS LPAREN ensemble RPAREN       
{
  Value *temp_value; // Declare a temporary Value pointer
  Value *final_value; // Declare the final Value pointer
  for (int LoopCounter = 0; LoopCounter < 32; LoopCounter++) // Loop through each bit position
  {
    temp_value =  Builder.CreateLShr($4, Builder.getInt32(LoopCounter)); // Shift $4 right by LoopCounter bits
    temp_value =  Builder.CreateAnd(temp_value, Builder.getInt32(1)); // Perform bitwise AND with 1   
    if (LoopCounter == 0) // If it's the first iteration
    {
      final_value = temp_value; // Assign temp_value to final_value
    }
    else // For subsequent iterations
    {
      final_value = Builder.CreateAdd(final_value, temp_value); // Add temp_value to final_value
    }
  } 
  $$ = final_value; // Set the return value to final_value
}
| EXPAND  LPAREN ensemble RPAREN        
{
  Value *ensemble_value = Builder.CreateAnd($3, Builder.getInt32(1)); // Get the LSB of $3
  Value *condition = Builder.CreateICmpEQ(ensemble_value, Builder.getInt32(0)); // Check if LSB is 0
  $$ = Builder.CreateSelect(condition, Builder.getInt32(0), Builder.getInt32(0xFFFFFFFF)); // If LSB is 0, return 0; otherwise, return 0xFFFFFFFF
}
;

%%

unique_ptr<Module> parseP1File(const string &InputFilename)
{
  funName = InputFilename;
  if (funName.find_last_of('/') != string::npos)
    funName = funName.substr(funName.find_last_of('/')+1);
  if (funName.find_last_of('.') != string::npos)
    funName.resize(funName.find_last_of('.'));
    
  //errs() << "Function will be called " << funName << ".\n";
  
  // unique_ptr will clean up after us, call destructor, etc.
  unique_ptr<Module> Mptr(new Module(funName.c_str(), TheContext));

  // set global module
  M = Mptr.get();
  
  /* this is the name of the file to generate, you can also use
     this string to figure out the name of the generated function */
  yyin = fopen(InputFilename.c_str(),"r");

  //yydebug = 1;
  if (yyparse() != 0)
    // errors, so discard module
    Mptr.reset();
  else
    // Dump LLVM IR to the screen for debugging
    M->print(errs(),nullptr,false,true);
  
  return Mptr;
}

void yyerror(const char* msg)
{
  printf("%s\n",msg);
}
