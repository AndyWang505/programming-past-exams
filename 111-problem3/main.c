/*
*
* NTUT 111 Problem 3
*
*/

#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_QUIZ 3
// 巨集/宏 定義前置處理器以3取代所有NUM_OF_QUIZ符號

typedef struct student{
	char id[10];
	char name[30];
	float grade;
	int quizs[NUM_OF_QUIZ];
}STUDENT;

float calculate_grade_as_quiz_average(STUDENT student){
	int sum = 0;
	for(int i=0;i < NUM_OF_QUIZ;i++){
		sum = sum + student.quizs[i];
	}
	return (float)sum/NUM_OF_QUIZ;
}

void descending_sort_by_grade(STUDENT *students, int numOfStudents){
	STUDENT tempStudent;
	// STUDENT型別變數tempStudent
	int i,j;
	for(int i=0;i < numOfStudents;i++){
		for(int j=0;j < numOfStudents-1;j++){
			if(students[j].grade < students[j+1].grade){
				tempStudent = students[j+1];
				students[j+1] = students[j];
				students[j] = tempStudent;
			}
		}
	}
}

int main(void){
	int numOfStudents;
	STUDENT students[] = {{"t011","John",0.0,{80,85,70}},
					 	  {"t020","Eric",0.0,{90,95,80}},
						  {"t022","Mary",0.0,{90,95,90}},
						  {"t003","Apple",0.0,{90,85,80}} };
	numOfStudents = sizeof(students)/sizeof(students[0]);
//	printf("%d",numOfStudents);
	for(int i=0;i < numOfStudents;i++){
		students[i].grade = calculate_grade_as_quiz_average(students[i]);
	}

	descending_sort_by_grade(students, numOfStudents);

	for(int i = 0;i < numOfStudents;i++){
		printf("%s\t%s\t%.2f",students[i].id, students[i].name, students[i].grade);
		for(int j=0;j < NUM_OF_QUIZ;j++){
			printf("\t%d",students[i].quizs[j]);
		}
		printf("\n");
	}
	return 0;
}
