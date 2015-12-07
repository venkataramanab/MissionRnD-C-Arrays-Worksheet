/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	struct student temp,**res,*temp1;
	int test = 0;
	if ((K==0)||(K<0)||(K>len)){
		return NULL;
	}
	else if (K == 1){
		for (int i = 0; i < len; i++){
			if (test<students[i].score){
				test = i;
			}
		}
		temp1 = &students[test];
		res = &temp1;
		return res;
	}
	else{//selection sort
		for (int i = 0; i < len; i++){
			for (int j = i; j < len; j++){
				if (students[i].score < students[j].score){
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
		for (int i = 0; i < K;i++){
			res[i] = &students[i];
		}
		return res;
	}
}