/* Goal : Bubble sort, selection sort, merge sort function coding. */
/* Date : 2021.01.19 */

#include <stdio.h>

#define ARR_LENGTH 8

int* bubbleSort(int *arr);
int* selectionSort(int *arr);

int* mergeSort(int* arr);
void split(int* arr, int start, int end);
void merge(int* arr, int start, int mid, int end);

void printArray(int* arr, int n);


int main(void)
{
	int arr0[] = { 4, 6, 2, 1, 3, 8, 5, 7 };
	int arr1[] = { 6, 7, 5, 8, 1, 2, 3, 4 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr3[] = { 8, 7, 6, 5, 4, 3, 2, 1 };

	int* buf;
	
	printf("Before : ");
	printArray(arr3, ARR_LENGTH);
	buf = mergeSort(arr3);

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
			if(omega == ARR_LENGTH)
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
			if(minVal > arr[j+1])
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
	split(arr, 0, ARR_LENGTH - 1);

	return arr;
}

void split(int* arr, int start, int end)
{
	int mid = (start + end) / 2;

	if(mid != start || mid != end)
	{
		split(arr, start, mid);
		split(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void merge(int* arr, int start, int mid, int end)
{
	int sort[ARR_LENGTH] = {0};

//	int iterate = (mid - start) + 2;    // 도는 횟수 x, 횟수를 체크

	int right = mid + 1;

	int a = 0, b = 0;

 	for(int i = 0; (start + a <= mid) && (right + b <= end); i++)
	{
		if(arr[start + a] < arr[right + b])
		{
			sort[start + a + b] = arr[start + a];
			a++;
		}
		else
		{
			sort[start + a + b] = arr[right + b];
			b++;
		}
	}

	int before = start + a + b;

	if(start + a > mid) // index로 비교
	{
		for(int i = before; i <= end; i++)
		{
			sort[i] = arr[right + b];	// 왼쪽 오른쪽 다른 것
			b++;
		}
	}
	else
	{
		for (int i = before; i <= end; i++)
		{
			sort[i] = arr[start + a];
			a++;
		}
	}

	for(int j = start; j < end + 1; j++)
	{
		arr[j] = sort[j];	
	}
}

void printArray(int* arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%i, ", arr[i]);
	}
}