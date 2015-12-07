/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include <malloc.h>
void * removeArrayDuplicates(int *Arr, int len)
{
	int count = 0;
	if ((Arr) && (len > 0)){
		for (int i = 0; i < len; i++){
			for (int j = i + 1; j < len; j++){
				if (Arr[i] == Arr[j]){
					Arr[i] = '.';
				}
			}
		}
		for (int i = 0, k = 0; i < len; i++){
			if (Arr[i] == '.'){
				count++;
			}
			else{
				Arr[k++] = Arr[i];
			}
		}
		len = len - count;
		return Arr;
	}
	else{
		return NULL;
	}
}