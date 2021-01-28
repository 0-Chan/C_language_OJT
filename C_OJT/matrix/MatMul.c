/* Goal : Matrix multiplication program in C
 * date : 2021. 01 . 28
 * author : Young Chan Kim (CogaPlex)
 */

//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct Matrix
{
    int row;
    int col;
    int elements[100];
};

int main(int argc, char* argv[])
{
    if (argc == 1 || argc > 10)
    {
        return 1;
    }
    
    struct Matrix m[10];

    int res;

    for (int i = 1; i < argc; i++)
    {
        FILE* file = fopen(argv[i], "r");
        if (file == NULL)
        {
            return 1;
        }
        
        // m[] 주소값 전달?
        fscanf(file, "%c %c", m[i]->row, m[i]->col);

        while (1)
        {
            res = fscanf(file, "%c", m->elements);
        }
    }

    unsigned char col[30];
    fread(&col, sizeof(char), 30, file);

    for (int i = 0; i < 3; i++)
    {
        printf("%c\n", col[i]);
    }
    for (int i = 3; i < 30; i++)
    {
        printf("%c\n", col[i]);
    }
}