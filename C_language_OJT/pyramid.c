/* ��ǥ : * �׸��� �Լ� �ۼ� */
/* Date : 2021.01.18 */

#include <stdio.h>

void star(int level);
void star2(int level);
void star3(int level);

int main(void)
{
	star(2);
}



void star(int level) // ���� �ױ�
{
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void star2(int level) // ������ �Ƕ�̵�
{
	for (int i = 0; i < level - 1; i++)
	{
		for (int j = 0; j < (i - 1) * 2; j++)
		{	
			printf(" ");
			for (int k = 0; k < level; k++)
			{
				printf("*");
			}
		}
	}
}

void star3(int level) // ���� �Ƕ�̵�
{

}