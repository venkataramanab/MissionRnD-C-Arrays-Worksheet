
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stdio.h>
int validation(int*, int);
void *count(int *moreCount, int *lessCount, int *Arr, int score, int len);
int boundaryCond(int *Arr, int score, int len, int **lessCount, int **moreCount);
void *studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	//as input is a sorted array we can use binary search
	//binary search results faster than accessing each element
	*lessCount = 0;
	*moreCount = 0;
	if (validation(Arr, len)){
		if (boundaryCond(Arr,score,len,&lessCount,&moreCount)){
			return count(moreCount, lessCount, Arr, score, len);
		}
	}
	else{
		return NULL;
	}
}
int validation(int *Arr, int len){
	if (Arr == NULL){
		return NULL;
	}
	else if (len <= 0){
		return NULL;
	}
	else{
		return 1;
	}
}
void *count( int *moreCount, int *lessCount, int *Arr, int score, int len){
	int mid;
	int high=len-1,low=0;
	while (high > low){
		mid = (high + low) / 2;
		if ((Arr[mid] < score) && (Arr[mid + 1]> score)){
			*lessCount = mid + 1;
			*moreCount = len - mid - 1;
			break;
		}
		else if (Arr[mid] == score){
			if (Arr[mid - 1] == Arr[mid]){
				high = mid - 1;
			}
			else{
				*lessCount = mid;
				*moreCount = len - mid - 1;
				break;
			}
		}
		else if (Arr[mid] < score){
			low = mid;
		}
		else if (Arr[mid]>score){
			high = mid;
		}
		else{
			return NULL;
		}
	}
}
int boundaryCond(int *Arr, int score,int len, int **lessCount, int **moreCount){
	if (score<Arr[0]){
		**moreCount = len;
		**lessCount = 0;
	}
	else if (score>Arr[len-1]){
		**lessCount = len;
		**moreCount = 0;
	}
	else {
		return 1;
	}
	return 0;
}