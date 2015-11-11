/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int first=0, last=len-1,flag1=0,flag2=0;
	if ((Arr != NULL)&&(len>0)){
		while (first < last){
			if (Arr[first] < Arr[first + 1]){
				first++;
			}
			else if (flag2 == 1){
				flag1 = 1;
				break;
			}
			else{
				flag1 = 1;
			}
			if (Arr[last] > Arr[last - 1]){
				last--;
			}
			else if (flag1 == 1){
				flag2 = 1;
				break;
			}
			else{
				flag2 = 1;
			}
		}
		if ((flag1 == 1) && (flag2 == 1)){
			Arr[first] = Arr[first] + Arr[last];
			Arr[last] = Arr[first] - Arr[last];
			Arr[first] = Arr[first] - Arr[last];
		}
		return Arr;
	}
	else{
		return NULL;
	}
		
}