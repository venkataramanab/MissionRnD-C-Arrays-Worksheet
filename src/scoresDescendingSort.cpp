/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
struct student {
	char name[10];
	int score;
};
struct student* quickSort(struct student *arr, int l, int h);
void swap(int* p1, int* p2);
int partition(struct student *Arr, int left, int right);
void * scoresDescendingSort(struct student *students, int len) {
	if ((students)&&(len>0)){
		if (len == 1){
			return students;
		}
		else{//quick sort
			return quickSort(students, 0, len - 1);
		}
	}
	else{
		return NULL;
	}
}
struct student* quickSort(struct student *Arr, int left, int right)
{
	if (left < right)
	{
		int p = partition(Arr, left, right);
		quickSort(Arr, left, p - 1);
		quickSort(Arr, p + 1, right);
	}
	return Arr;
}
int partition(struct student *Arr, int left, int right)
{
	int temp = Arr[right].score;
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++)
	{
		if (Arr[j].score >= temp)
		{
			i++;
			swap(&Arr[i].score, &Arr[j].score);
		}
	}
	swap(&Arr[i + 1].score, &Arr[right].score);
	return (i + 1);
}
void swap(int* p1, int* p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}

