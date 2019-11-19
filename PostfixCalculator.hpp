/*Qiao Gan Chen
november 19
Project 7
*/


#pragma once
#include <iostream>
#include <stack>
#include <string>

class PostfixCalculator{
public:
  //construstor
  PostfixCalculator();

  //helper function
  int precedence(char c);
  bool isOperator(char c);
  bool balanced(std::string s);

  //member function
  std::string convertToPostfix(std::string infix_expression);
  double calculatePostfix(std::string postfix_expression);
  void testCalculator(std::string input_file_name);
private:
  std::stack<char> OperatorStack;
  
};
