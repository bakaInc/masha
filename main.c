
#include "stm32f4xx.h"                  // Device header
#include "RTE_Components.h"             // Component selection

#include <stdlib.h>
#include "stdio.h"
#include "string.h"



#include "HeapSort.h"
#include "TimSort.h"
#include "QuickSort.h"


int quickFindNumberByIndex(int *numbers, int left, int right, int position)
{
  int pivot;

	int l_hold = left;
	int r_hold = right;
	pivot = numbers[(left + right) / 2];

	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}

		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;

	//printf ("Numbers\n");
	for (int i = 0; i < 24; i++) {
		//printf ("%d ", numbers[i]);
	}
	//printf ("\n");
	for (int i = left; i < pivot - 1; i++) {
		//printf ("%d ", numbers[i]);
	}
	//printf ("  |||| ");
	for (int i = pivot + 1; i < right; i++) {
		//printf ("%d ", numbers[i]);
	}
	
	

	if (pivot == position ) { 
		//printf ("  end"); printf (" ** pivot - %d   elemrazdel - %d, pos - %d", pivot, elemrazdel, position); printf ("\n");
		return numbers[pivot];
	}
	if (pivot > position) {
		//printf ("  left");  printf (" ** pivot - %d   elemrazdel - %d, pos - %d", pivot, elemrazdel, position); printf ("\n");
		return quickFindNumberByIndex (numbers, left, pivot-1, position);
	}
	else{
		//printf ("  right");  printf (" ** pivot - %d   elemrazdel - %d, pos - %d", pivot, elemrazdel,position); printf ("\n");
		return quickFindNumberByIndex (numbers, pivot+1, right, position);
	
	}

}


int main(void){
	
	int b[24] = { -19,121,58,-211,4,8585,-45,23,21,-2323,11,3,14,11,11,12,14,-67,-69,-36,66,27171,-31,58 };
	int BB[24] = { -19,121,58,-211,4,8585,-45,23,21,-2323,11,3,14,11,11,12,14,-67,-69,-36,66,27171,-31,58 };
	int len = sizeof (b) / 4;


	printf ("\nInitial array\n");
	for (int i = 0; i < len; i++) {
		printf ("%d ", BB[i]);
	}

	//quickSort (b, 0,len-1);  //OR
	integer_timsort(b,len);
	//heapSort(b,len);
	
	printf ("\nSort array\n");
	for (int i = 0; i < len; i++) {
		printf ("%d ", b[i]);
	}
	printf ("\n");


	int cc = 0;

	int CC[24] = { 0 };
	for (int i = 1; i <= len; i++) {
		for (int i = 0; i < len; i++) {
			CC[i] = BB[i];
		}
		cc = quickFindNumberByIndex (CC, 0, len-1, i-1);//NADO PEREDAT INDEX 0..len
		printf ("sravnenie: number %d   sort_array_index %d   otvet %d\n", i, b[i-1], cc);

	}
	

	
	
	while(1){
		//printf("efefefeff");
		
	}
	
}

