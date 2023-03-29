#include <stdio.h>
#include <string.h>

float test01(void){
  int a = 5, b = 2;
  return a/b;
}

int test04(void){
  struct {char str1[10], str2[10];} s;
  strcpy(s.str1, "yahoo");
  strcpy(s.str2, "google");
  strcat(s.str1, strcat(s.str2, "adobe"));
  return strcmp(s.str1, s.str2);
}

int main(void) {
  // printf("%3.1f\n",test01());
  printf("%d\n",test04());
  return 0;
}