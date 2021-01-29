/* Goal : Matrix multiplication program in C
 * date : 2021. 01 . 29
 * author : Young Chan Kim (CogaPlex)
 */

#define MAX_MATRICES 10
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int elements[100];
} Matrix;

int getMat(int argc, char* argv[], Matrix* inMat);
int mulMat(Matrix* mat, Matrix* resMat, int matNum[]);
void printMat(Matrix* mat, int index);
void checkError(int errorCode);


int main(int argc, char* argv[])
{
    if (argc == 1 || argc > MAX_MATRICES)
    {
        return 1;
    }
    
    int errorCode = 0;
    int index = 0;
    int indexes[3] = {0, 0, 0};
    Matrix inMat[MAX_MATRICES];
    Matrix resMat[MAX_MATRICES-1] = {0};

    errorCode = getMat(argc, argv, inMat);
    checkError(errorCode);
    
    printMat(inMat, 0);
    printMat(inMat, 1);

    indexes[0] = 0;
    indexes[1] = 1;
    indexes[2] = 0;

    errorCode = mulMat(inMat, resMat, &indexes);
    checkError(errorCode);

    printMat(resMat, 0);
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

int mulMat(Matrix* mat, Matrix* resMat, int indexes[])
{
    int A = indexes[0];
    int B = indexes[1];
    int AB = indexes[2];

    if ((mat + A)->col != (mat + B)->row)
    {
        return 3;
    }

    (resMat + AB)->row = (mat + A)->row;
    (resMat + AB)->col = (mat + B)->col;

    int n = (resMat + AB)->row * (resMat + AB)->col;
    int i = 0, m = 0;

    while (i < n)
    {
        for (int j = 0; j < (resMat + AB)->col; i++, j++)
        {
            for (int k = 0; k < (mat + A)->col; k++)
            {
                (resMat + AB)->elements[i] += (mat + A)->elements[k + ((mat + A)->col * m)] * (mat + B)->elements[(k * (mat + B)->col) + j];
            }
        }
        m++;
    }

    return 0;
}

void printMat(Matrix* mat, int index)
{
    int row = (mat + index)->row;
    int col = (mat + index)->col;

    printf("#row %d   #col %d\n", row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", (mat + index)->elements[(col * i) + j]);
        }    
        printf("\n");
    }
    printf("\n");
}

void checkError(int errorCode)
{
    switch (errorCode)
    {
    case 0:
        break;
    case 1:
        printf("MatMul.exe 에러 : 입력된 값이 없거나, 너무 많습니다.");
        exit(1);
    case 2:
        printf("getMat 에러 : File open에 실패했습니다.");
        exit(1);
    case 3:
        printf("mulMat 에러 : 입력된 행렬끼리 곱셈 연산이 불가능합니다.");
        exit(1);
    default:
        printf("Undefined error code. Please check again.");
        break;
    }
}