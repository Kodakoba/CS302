//DRIVER - By Lloyd Cargo
//HW3 - Staks
//infix -> postfix, includes "ui" code and arithmetic.
#include "linkedStack.h"
#include <iostream>
#include <string>

int orderFunc(char);
//there was a UI function but it's 2 lines
double calcFourth(const std::string&); //reference to what this project secretly is >:)


//baby program :)
int main(){
    std::string inFixExpr = "";
    std::string postFixExpr = "";
    double calculatedResult = 0.0;
    LinkedStack<char> stack;

    std::cout << "Input an infix expression:" << std::endl;
    std::getline(std::cin, inFixExpr);

    int interator = inFixExpr.length();

    for(int i = 0; i < interator; i++){ //you couldn't make an expression that long if you tried
        if(inFixExpr[i] == ' ') continue; //skip, SOF says this is how
        
        if(inFixExpr[i] == '('){
            stack.push(inFixExpr[i]);
        }
        else if(inFixExpr[i] == ')'){
            while(!stack.isEmpty() && stack.peek() != '('){
                postFixExpr += stack.peek();
                stack.pop();
            }
            stack.pop();
        }
        else if(orderFunc(inFixExpr[i]) > 0){
            while(!stack.isEmpty() && orderFunc(inFixExpr[i]) <=  orderFunc(stack.peek()) && stack.peek() != '('){
                postFixExpr += stack.peek();
                stack.pop();
            }
            stack.push(inFixExpr[i]);
        }
        else if(orderFunc(inFixExpr[i]) == -1){
            postFixExpr += inFixExpr[i];
        }
        else{
            std::cout << "something in inFixExpr[i] was not handled" << std::endl;
        }
    }
    while(!stack.isEmpty()){
        postFixExpr += stack.peek();
        stack.pop();
    }
    calculatedResult = calcFourth(postFixExpr);
    std::cout << postFixExpr << std::endl;
    std::cout << calculatedResult << std::endl;
    return 0;
}

int orderFunc(char inOperand){
    //this is a bad way to do this, do as a I say not as I do.
    if(inOperand == '*' || inOperand == '/'){
        return 2;
    }
    else if(inOperand == '+' || inOperand == '-'){
        return 1;
    }
    else{
        return -1;
    }
}


double calcFourth(const std::string& posFix){
    LinkedStack<double> stack2; //don't know if you can have the same name-different types and im not trying to find out.
    int interator = posFix.length();
    for(int i = 0; i < interator; i++){
        char read = posFix[i]; //cause technically a string is an array
        char read2[2] = {read, '\0'};
        double value = atof(read2);
        //this took too long to fix (i cri)
        if(read >= '0' && read <= '9'){ 
            stack2.push(value);
        } 
        else{
            double op2 = stack2.peek();
            stack2.pop();
            double op1 = stack2.peek();
            stack2.pop();
            if(read == '*'){
                stack2.push(op1 * op2);
            }
            else if(read == '/'){
                stack2.push(op1 / op2);
            }
            else if(read == '+'){
                stack2.push(op1 + op2);
            }
            else if(read == '-'){
                stack2.push(op1 - op2);
            }
            else{
                std::cout << "operator wasn't understood by calculator" << std::endl;
            }
        }
    }
    return stack2.peek();
}