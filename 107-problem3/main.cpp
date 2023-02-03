#include <stdio.h>
#define SIZE 20
typedef enum {False = 0, True = 1} Bool;
bool isEmpty(char stack[], int top){
    if(top <= -1) return true;
    else return false;
}
bool push(char stack[], int *topp, char element){
    stack[++(*topp)] = element;
    return true;
}
bool pop(char stack[], int *topp, char *element){
    if(isEmpty(stack,(*topp))) return false;
    (*element) = stack[(*topp)--];
    return true;
}
void popAll(char stack[], int *topp, char postfix[], int *indexp){
    while(!isEmpty(stack,(*topp))){
        postfix[(*indexp)++] = stack[(*topp)--];
        printf("%c",postfix[(*indexp)-1]);
    }
}
bool isOperand(char c){
    if((c>='a') && (c<='z')) return true;
    else return false;
}
int opPriority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return 0;
}
bool shouldPopOp(char x, char y){
    if(opPriority(x) > opPriority(y)) return true;
    else return false;
}
void operatorProcess(char stack[], int *topp, char postfix[], int *index, char c){
    char elem;
    bool nonEmpty;
    nonEmpty = pop(stack, topp, &elem);
    while (nonEmpty&&shouldPopOp(elem, c)){
        postfix[(*index)++] = elem;
        printf("%c", elem);
        nonEmpty = pop(stack, topp, &elem);
    }
    if(!shouldPopOp(elem, c)) push(stack, topp, elem);
    push(stack, topp, c);
}
void operandProcess(char postfix[], int *indexp, char c){
    postfix[(*indexp)++] = c;
    printf("%c",c);
}
void infixToPostfix(char infix[], char postfix[], int size){
    int i=0, index = 0, top = -1;
    char stack[SIZE];
    for(i=0; i<size; i++){
        if(isOperand(infix[i])){
            operandProcess(postfix, &index, infix[i]);
        }
        else{
            operatorProcess(stack, &top, postfix, &index, infix[i]);
        }
    }
    popAll(stack,&top,postfix,&index);
}
void test01(){
    char infix1[] = "a+b*c-d/e^f";
    char infix2[] = "a*b-c/d^e*f+g*h";
    char postfix[30];
    int size = 15;
    infixToPostfix(infix1, postfix, size);
    infixToPostfix(infix2, postfix, size);
}
int main(){
    test01();
    return 0;
}