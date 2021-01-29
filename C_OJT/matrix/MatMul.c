/* Goal : Matrix multiplication program in C
 * date : 2021. 01 . 29
 * author : Young Chan Kim (CogaPlex)
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int elements[100];
} Matrix;

int getMat(int argc, char* argv[], Matrix* inMat);
int mulMat(Matrix* mat1, Matrix* mat2, Matrix* resMat);
void printMat(Matrix* resMat);
void checkError(int errorCode);


int main(int argc, char* argv[])
{
    if (argc == 1 || argc > 10)
    {
        return 1;
    }
    
    int errorCode = 0;
    Matrix inMat[10];
    Matrix resMat[9] = {0};

    //파일 입력
    errorCode = getMat(argc, argv, inMat);

    printf("row : %d // col : %d\n", inMat[0].row, inMat[0].col);
    printf("%d %d %d\n", inMat[0].elements[0], inMat[0].elements[1], inMat[0].elements[2]);
    printf("%d %d %d\n", inMat[0].elements[3], inMat[0].elements[4], inMat[0].elements[5]);
    printf("%d %d %d\n", inMat[0].elements[6], inMat[0].elements[7], inMat[0].elements[8]);

    printf("\n");

    printf("row : %d // col : %d\n", inMat[1].row, inMat[1].col);
    printf("%d %d %d\n", inMat[1].elements[0], inMat[1].elements[1], inMat[1].elements[2]);
    printf("%d %d %d\n", inMat[1].elements[3], inMat[1].elements[4], inMat[1].elements[5]);
    printf("%d %d %d\n", inMat[1].elements[6], inMat[1].elements[7], inMat[1].elements[8]);

    //행렬 연산
    if (inMat[0].col != inMat[1].row)
    {
        return 3;
    }

    resMat[0].row = inMat[0].row;
    resMat[0].col = inMat[1].col;

    int n = resMat[0].row * resMat[0].col;
    int i = 0, m = 0, l = 0;
    
    while (i < n)
    {
        for (int j = 0; j < resMat[0].col; j++)
        {
            for (int k = 0; k < inMat[0].col; k++)
            {
                resMat[0].elements[i] += inMat[0].elements[k + (inMat[0].col * m)] * inMat[1].elements[k * inMat[1].col + l];
            }
            i++;
            l++;
        }
        l = 0;
        m++;        
    }

    printf("\n");

    printf("row : %d // col : %d\n", resMat[0].row, resMat[0].col);
    printf("%d %d %d\n", resMat[0].elements[0], resMat[0].elements[1], resMat[0].elements[2]);
    printf("%d %d %d\n", resMat[0].elements[3], resMat[0].elements[4], resMat[0].elements[5]);
    printf("%d %d %d\n", resMat[0].elements[6], resMat[0].elements[7], resMat[0].elements[8]);
}


int getMat(int argc, char* argv[], Matrix* inMat)
{
    int res = 0;

    for (int i = 0; i < argc - 1; i++)
    {
        FILE* file = fopen(argv[i+1], "r");
        if (file == NULL)
        {
            return 2;
        }

        res = fscanf(file, "%d", &inMat[i].row);
        res = fscanf(file, "%d", &inMat[i].col);

        int j = 0;

        while (1)
        {
            res = fscanf(file, "%d", &inMat[i].elements[j]);
            if (res == EOF)
            {
                break;
            }
            j++;
        }
        fclose(file);
    }

    return 0;
}