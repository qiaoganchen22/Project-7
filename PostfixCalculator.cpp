/*Qiao Gan Chen
november 19
Project 7
*/

#include "PostfixCalculator.hpp"
#include <fstream>

PostfixCalculator::PostfixCalculator(){
  //constructor 
}

bool PostfixCalculator::isOperator(char c){
  if( c == '*' || c == '-' || c == '+' || c == '/'){
    return true;
  }
  return false;
}

int PostfixCalculator::precedence(char c){
  if(c == '*' || c == '/'){
    return 5;
  }
  else if(c == '+' || c == '-'){
    return 6;
  }
  return 0;
}

bool PostfixCalculator::balanced(std::string s){
  int parenthesis=0;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '('){
      parenthesis += 1;
    }
    if(s[i] == ')'){
      parenthesis -= 1;
    }
  }
  if(parenthesis == 0){
    return true;
  }
  return false;
}


std::string PostfixCalculator::convertToPostfix(std::string infix_expression){
  if(!balanced(infix_expression)){
    return "Precondition Violated Exception: Unbalanced parenthesis";
  }
  std::string postfix="";
  for(int i = 0; i < infix_expression.length(); i++){
    char c = infix_expression[i];
    //operand
    if(isdigit(c)){
      if(!(i != 0 && isdigit(infix_expression[i-1]))){
	postfix += " ";
      }
      postfix += c;
    }
    if(c == '('){
      OperatorStack.push(c);
    }
    //operators
    if(isOperator(c)){
      while(!OperatorStack.empty() && OperatorStack.top() != '(' && precedence(c) <= precedence(OperatorStack.top())){
	postfix += " ";
	postfix += OperatorStack.top();
	OperatorStack.pop();
      }
      OperatorStack.push(c);
    }
    //clsoe parenthesis
    if(c == ')'){
      while(OperatorStack.top() != '('){
	postfix += " ";
	postfix += OperatorStack.top();
	OperatorStack.pop();
      }
      OperatorStack.pop();
    }
    if(!isOperator(c)){
      //precondition violated exception
      return "Precondition Violated Exception: Unknown operator";
    }
  }
  while(!OperatorStack.empty()){
    postfix += " ";
    postfix += OperatorStack.top();
    OperatorStack.pop();
  }
  if(isspace(postfix[0])){
    postfix = postfix.substr(1, postfix.length() - 1);
    postfix += " ";
  }
  return postfix;
}

double PostfixCalculator::calculatePostfix(std::string postfix_expression){
  return 0.0;

}

void PostfixCalculator::testCalculator(std::string input_file_name){
  std::cout << convertToPostfix("(2*3)+4");
  /*
  //writes into results text file
  out_file.open(input_file_name);
  ou_file << 0 << std::endl;
  out_file.close();*/
}
