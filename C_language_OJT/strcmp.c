/* 목표 : strcpy와 strcmp 함수 만들기 */
/* Date : 2021.01.18 (Mon)*/

#include <stdio.h>
#include <ctype.h>

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
	int i = 0;
	int a_tmp = 0;
	int b_tmp = 0;

	for (i = 0; (a[i] != '\0') || (b[i] != '\0'); i++)
	{
		a_tmp = toupper(a[i]);
		b_tmp = toupper(b[i]);

		if (a_tmp != b_tmp)
		{
			if (a_tmp < b_tmp)
			{
				ret = -1;
				return ret;
			}
			else if (a_tmp > b_tmp)
			{
				ret = 1;
				return ret;
			}
		}
	}

	if (a[i] == '\0' && b[i] == '\0')
	{
		ret = 0;
	}
	else if (a[i] == '\0')
	{
		ret = -1;
	}
	else
	{
		ret = 1;
	}

	return ret;
} 