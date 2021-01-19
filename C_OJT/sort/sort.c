/* Goal : Bubble sort, selection sort, merge sort function coding. */
/* Date : 2021.01.19 */

#include <stdio.h>
#include <stdlib.h>

static int ARR_LENGTH = 8;

int* bubbleSort(int *arr);
int* selectionSort(int *arr);
int* mergeSort(int* arr);

void printArray(int* arr, int n);


int main(void)
{
	int arr0[] = { 4, 6, 2, 1, 3, 8, 5, 7 };
	int arr1[] = { 6, 7, 5, 8, 1, 2, 3, 4 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr3[] = { 8, 7, 6, 5, 4, 3, 2, 1 };

	int* buf;
	
	printf("Before : ");
	printArray(arr1, ARR_LENGTH);
	buf = mergeSort(arr1);

	printf("\nAfter : ");
	printArray(buf, ARR_LENGTH);
}


int* bubbleSort(int* arr)
{
	int tmp = 0;
	int omega = 0;

	for(int i = 0; i < ARR_LENGTH - 1; i++)
	{
		for(int j = 0; j < ARR_LENGTH - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;

				omega = 0;
			}
			omega += 1;
			if (omega == ARR_LENGTH)
			{
				return arr;
			}
		}
	}
	return arr;
}

int* selectionSort(int* arr)
{
	int minVal = arr[0];
	int minIndex = 0;
	int tmp = 0;

	for(int i = 0; i < ARR_LENGTH - 1; i++)
	{
		for(int j = i; j < ARR_LENGTH - 1; j++)
		{
			if (minVal > arr[j+1])
			{
				minVal = arr[j+1];
				minIndex = j+1;
			}
		}
		if (minVal == arr[i])
		{
			// 유지
		}
		else
		{
			tmp = arr[i];
			arr[i] = minVal;
			arr[minIndex] = tmp;
		}
		minVal = arr[i+1];
	}
	return arr;
}

int* mergeSort(int* arr)
{
	// 머지 소트
	// 1. 모든 원소를 분할한다. (나눌 수 없을 때 까지!)
	// 2. 인접한 두 원소를 비교해 합친다.
	// 3. 2개 2개를 비교하여 합친다.
	// 4. 4개 4개를 비교하여 합친다.

	//--------------------------------------------------
	
	// check if arrLength is > 1
	//{
	// mid를 기점하여 배열을 할당 해줌
	// 재귀로 구현
	//}

	// 포인터 배열 0 과 1을 비교한다
	// 작은 순으로 배치

	// 2와 3을... 4와 5를... 6과 7을...

	// 01와 23을....  45와 67을...

	// 0123과 4567을..

	// sort 완료 arr 반환
	
	return arr;
}

void printArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%i, ", arr[i]);
	}
}