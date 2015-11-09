/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL){
		return NULL;
	}
	else if (len<0){
		return NULL;
	}
	else{
		Arr = (int*)realloc(Arr, sizeof(int)*(len + 1));
		if ((len == 0) || (num<Arr[0])){
			Arr[0] = num;
			return Arr;
		}
		else if (num>Arr[len - 1]){
			Arr[len] = num;
			return Arr;
		}
		else{
			int temp = len - 1;
			while ((Arr[temp] > num) && (temp >= 0)){
				Arr[temp + 1] = Arr[temp];
				temp--;
			}
			Arr[temp+1] = num;
			return Arr;
		}	
	}
}