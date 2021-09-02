// Stack 자료구조를 이용한 괄호 문제

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isValid(char *s) {
    
    int len = strlen(s);
    char Stack[len];
    int top=-1;
    
    for(int i=0;i<len;i++) {

        if(s[i]=='('||s[i]=='{'||s[i]=='[') {
            Stack[++top]=s[i];
        } //push
        else if(s[i]==')') {
            if(Stack[top]=='(') {
                top--;
            }
            else return false;
        }//앞단계 확인하고 (면 pop, 아니면 return false
        else if(s[i]=='}') {
            if(Stack[top]=='{') {
                top--;
            }
            else return false;
        }
        else if(s[i]==']') {
            if(Stack[top]=='[') {
                top--;
            }
            else return false;
        }

        if(i==len-1) {
            if(top==-1) return true;
            else return false;
        }
    }
    
    
    return false;
}

void main() {

    char *s = (char *)malloc(sizeof(char) * 10000);
    scanf("%s", s);

    if (isValid(s)==true) {
        printf("true\n");
        free(s);
        return ;
    }
    else {
        printf("false\n");
        free(s);
        return ;
    }

    free(s);
    return;
}