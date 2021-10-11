//Name: postFix.cpp
//Purpose: to read postfix algebraic expressions, evalute, and output
//Author: Mackenzie Zappe
//Date: 9/7/2020

#include <iostream>
#include "StackLinked.cpp"
#include <ctype.h>
#include <fstream>

int strlen(const std::string word){
    int counter =0;
    int i = 0;
    while(word[i] != '\0'){
        counter++;
        i++;
    }
return counter;
}
float powerOperation(float operand1, float operand2){
         float total = 1;
                for(int i = 0; i < operand1; i++){
                    
                    total *= operand2;
        
                }
                
                return total;
}
float applyOperator(char operation, float operand1, float operand2){
    float total =23;
    switch(operation){
    case '+': total = operand1 + operand2;break;
    case '-': total = operand2 - operand1;break;
    case '*': total = operand1 * operand2;break;
    case '/': total = operand1 / operand2;break;
    case '^': total = powerOperation(operand1, operand2);
                break;

    }

    return total;
}

float calculatingPostfix(std::string postfix, StackLinked<float>stack){
    stack.clear();
    float result = 0.0;
    float operand1= 0.0;
    float operand2= 0.0;
    for(int i=0; i < strlen(postfix); i++){
        if(isdigit(postfix[i])){
            stack.push(postfix[i]-'0');

        }else{
            operand1 = stack.pop();
            operand2  = stack.pop();
            result = applyOperator(postfix[i], operand1, operand2);
            stack.push(result);
        }

        
    }
    return result;
}
int main(){

    StackLinked<float> stack;
    std::ofstream outputFile;
    
    outputFile.open("PostfixOutputFile.txt");


    std::string input1, input2, input3, input4, input5;

    std::cout << "Enter 1st postfix expression" << std::endl;
    std::cin >> input1;

    std::cout << "Enter 2nd postfix expression" << std::endl;
    std::cin >> input2;

    std::cout << "Enter 3rd postfix expression" << std::endl;
    std::cin >> input3;

    std::cout << "Enter 4th postfix expression" << std::endl;
    std::cin >> input4;

    std::cout << "Enter 5th postfix expression" << std::endl;
    std::cin >> input5;

    float output1 = calculatingPostfix(input1,stack);
    float output2 = calculatingPostfix(input2,stack);
    float output3 = calculatingPostfix(input3,stack);
    float output4 = calculatingPostfix(input4,stack);
    float output5 = calculatingPostfix(input5,stack);

    outputFile<<  input1 << " = " << output1 << std::endl;
    outputFile<<  input2 << " = " << output2 << std::endl;
    outputFile<<  input3 << " = " << output3 << std::endl;
    outputFile<<  input4 << " = " << output4 << std::endl;
    outputFile<<  input5 << " = " << output5 << std::endl;

    std::cout<<  input1 << " = " << output1 << std::endl;
    std::cout<<  input2 << " = " << output2 << std::endl;
    std::cout<<  input3 << " = " << output3 << std::endl;
    std::cout<<  input4 << " = " << output4 << std::endl;
    std::cout<<  input5 << " = " << output5 << std::endl;

    outputFile.close();
return 0;
}