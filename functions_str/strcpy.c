/* ��ǥ : strcpy�� strcmp �Լ� ����� */
/* Date : 2021.01.18 (Mon)*/

#include <stdio.h>
#include <stdlib.h>

void strcpy(char* dst, char* src);

int main(void)
{
	char buf[100];
	char* src = "test string";
	strcpy(buf, src);
	printf("%s\n", buf);

	return 0;
}

void strcpy(char* dst, char* src)
{
	int strlen = 0;

	for (int i = 0; src[i] != 0; i++)
	{
		strlen += 1;
	}

	*dst = (char *) malloc(sizeof(strlen + 1));
	if (dst == NULL)
	{
		return 1;
	}

	for (int i = 0, n = strlen; i < n+1; i++)
	{
		dst[i] = src[i];
	}
} 