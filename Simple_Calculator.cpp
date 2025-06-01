//Write a program that takes two numbers and an operator as input (+,-,*,/,%) and performs the corresponding arithmetic operation.
//Display the result on the console.

#include<iostream>
using namespace std;

int main() {

    int a, b;
    cout<<"Enter the First Number"<<endl;
    cin>>a;

    cout<<"Enter the Second Number"<<endl;
    cin>>b;

    char op;
    cout<<"Enter the operator"<<endl;
    cin>>op;

    switch(op) {
        case '+': cout<<"The Addition of Two Numbers is "<<a+b<<endl;        //switch case to handle multiple cases.
            break;
        case '-': cout<<"The Subtraction of Two Numbers is "<<a-b<<endl;
            break;
        case '*': cout<<"The Multiplication of Two Numbers is "<<a*b<<endl;
            break;
        case '/': if(b !=0 ) {cout<<"The Division of Two Numbers is "<<a/b<<endl;}else {cout<<"UNDEFINED"<<endl;}   //'0' in denominator give infinity.
            break;
        case '%': cout<<"Reminder when a divide by b is "<<a%b<<endl;          //Reminder after division.
            break;
        default: cout<<"Please Enter a valid operator from (+,-,*,/,%)";
    }

    return 0;
}