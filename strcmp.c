/* 목표 : strcpy와 strcmp 함수 만들기 */
/* Date : 2021.01.18 (Mon)*/

#include <stdio.h>
#include <stdlib.h>

int strcmp(char* a, char* b);

int main(void)
{
	char* a = "ascii";
	char* b = "baseball";

	int ret = strcmp(a, b);
	
	if (ret < 0)
	{
		printf("%s 는 %s 보다 작습니다.\n",a, b);
	}
	else if (ret > 0)
	{
		printf("%s 는 %s 보다 큽니다.\n", a ,b);
	}
	else
	{
		printf("%s 와 %s 는 같은 문자열입니다.\n",a ,b);
	}
}

int strcmp(char* a, char* b) 
{
	int ret = 0;
	int num = 0;

	for (int i = 0; (a[i] != 0) || (b[i] != 0); i++)
	{
		if (a[i] == b[i])
		{
			ret = 0;
		}
		num = i;
	}

	if ((a[num] == 0) && (b[num] == 0))
	{
		ret = 0;
	}
	else if (a[num] == 0)
	{
		ret = -1;
	}
	else if (b[num] == 0)
	{
		ret = 1;
	}

	return ret;
} 