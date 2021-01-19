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
			// ����
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
	// ���� ��Ʈ
	// 1. ��� ���Ҹ� �����Ѵ�. (���� �� ���� �� ����!)
	// 2. ������ �� ���Ҹ� ���� ��ģ��.
	// 3. 2�� 2���� ���Ͽ� ��ģ��.
	// 4. 4�� 4���� ���Ͽ� ��ģ��.

	//--------------------------------------------------
	
	// check if arrLength is > 1
	//{
	// mid�� �����Ͽ� �迭�� �Ҵ� ����
	// ��ͷ� ����
	//}

	// ������ �迭 0 �� 1�� ���Ѵ�
	// ���� ������ ��ġ

	// 2�� 3��... 4�� 5��... 6�� 7��...

	// 01�� 23��....  45�� 67��...

	// 0123�� 4567��..

	// sort �Ϸ� arr ��ȯ
	
	return arr;
}

void printArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%i, ", arr[i]);
	}
}