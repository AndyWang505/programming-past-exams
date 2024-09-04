/*
*
* NTUT 112 Problem 2
*
*/

#include <stdio.h>
#include <stdlib.h>
typedef enum {black_ops, top_secret, secret, non_secret} securitylevels;
void f1(char *s1, char *s2){
    for (; *s1!='\0'; s1++);
    for (; *s2!='\0'; *s1 = *s2, s1++, s2++);
    *s1 = '\0';
}

securitylevels f2(){
    return (non_secret - black_ops)/3<secret ? black_ops : non_secret;
}

int getValue(int A[][2], int B[][2], int n, int row, int column){
    int value = 0;
    for (int k=0; k<n; k++){
        value = value + A[row][k] * B[k][column];
    }
    return value;
}

void f3(int A[2][2], int B[2][2], int C[2][2], int n){
    for (int row=0; row<n; row++){
        for (int column=0; column<n; column++){
            C[row][column] = getValue(A, B, n, row, column);
        }
    }
}

int f4(int i){
    int *p = &i, *q = p;
    return ++(*q);
}

double f5(int a, int b){
    double t = ((a--)/3+b%4);
    return t;
}

void f6(int D[], int n){
    int i=0, m=0;
    m = n>>4;
    m = m<<4;
    for (int i=7; i>=4; i--){
        D[i] = (m&(1<<i)) ? 1 : 0;
    }
}

int main(void){
    char s1[100] = "NTUT", s2[100] = "Good";
    int A[2][2] = {{1,2}, {2,1}}, B[2][2] = {{1,2}, {2,3}}, C[2][2], D[10];
    f1(s1, s2);
    printf("%s\n", s1);
    printf("%d\n", f2());
    f3(A, B, C, 2);
    printf("%d %d\n", C[0][0], C[1][1]);
    printf("%d\n", f4(20));
    printf("%3.2f\n", f5(6, 6));
    f6(D, 123);
    printf("%d%d%d\n", D[1], D[3], D[5]);
    return 0;
}