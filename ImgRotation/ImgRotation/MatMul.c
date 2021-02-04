/* Goal : Matrix multiplication program in C
 * date : 2021. 02 . 01
 * author : Young Chan Kim (CogaPlex)
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "MatMul.h"


//int main(int argc, char* argv[])
//{
//    if (argc == 1)
//    {
//        return 1;
//    }
//    
//    int inputCnt = argc - 1;
//    char** txtFiles = argv + 1;
//    int errorCode = 0;
//
//    pMatrix inMat = (pMatrix)malloc(sizeof(Matrix) * inputCnt);
//    if (inMat == NULL)
//    {
//        return 1;
//    }
//    Matrix resMat = {0};
//    
//    errorCode = getMat(inputCnt, txtFiles, inMat);
//    checkError(errorCode);
//
//    resMat = inMat[0];
//
//    for (int i = 1; i < inputCnt; i++)
//    {
//        printf("-----%d 번째 연산.-----\n", i);
//        Matrix a = resMat;
//        Matrix b = inMat[i];
//
//        Matrix* ab = &resMat;
//
//        printMat(a);
//        printMat(b);
//
//        errorCode = mulMat(a, b, ab);
//        checkError(errorCode);
//
//        printMat(resMat);
//
//        printf("----------------------\n");
//    }
//
//    for (int i = 0; i < inputCnt; i++)
//    {
//        free(inMat[i].elements);
//        inMat[i].elements = NULL;
//    }
//    free(resMat.elements);
//    free(inMat);
//    return 0;
//}


int getMat(int inputCnt, char* txtFiles[], Matrix* inMat)
{
    int res = 0;

    for (int i = 0; i < inputCnt; i++)
    {
        FILE* file = fopen(txtFiles[i], "r");
        if (file == NULL)
        {
            return 2;
        }

        res = fscanf(file, "%d", &inMat[i].row);
        res = fscanf(file, "%d", &inMat[i].col);

        int eleSize = inMat[i].row * inMat[i].col;
        int j = 0;
        
        inMat[i].elements = (int*)malloc(eleSize * sizeof(int));
        if (inMat[i].elements == NULL)
        {
            return 3;
        }

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

int mulMat(Matrix mat1, Matrix mat2, Matrix* resMat)
{
    if (mat1.col != mat2.row)
    {
        return 4;
    }

    int aRow = mat1.row;
    int aCol = mat1.col;
    int bRow = mat2.row;
    int bCol = mat2.col;

    int abRow = aRow;
    int abCol = bCol;

    resMat->row = abRow;
    resMat->col = abCol;

    resMat->elements = (int*)malloc((abRow * abCol) * sizeof(int));
    if (resMat->elements == NULL)
    {
        return 3;
    }

    int haha = sizeof(resMat->elements);

    for (int i = 0; i < abRow; i++)
    {
        for (int j = 0; j < abCol; j++)
        {
            *(resMat->elements + j + (i * abCol)) = 0;

            for (int k = 0; k < aCol; k++)
            {
                *(resMat->elements + j + (i * abCol)) += mat1.elements[k + (aCol * i)] 
                                                    * mat2.elements[(k * bCol) + j];
            }
        }
    }

    return 0;
}

void printMat(Matrix mat)
{
    int row = mat.row;
    int col = mat.col;

    printf("#row %d  #col %d\n", row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", mat.elements[(col * i) + j]);
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
        printf("동적할당 에러 : Malloc에 실패했습니다.");
        exit(1);
    case 4:
        printf("mulMat 에러 : 입력된 행렬끼리 곱셈 연산이 불가능합니다.");
        exit(1);
    default:
        printf("Undefined error code. Please check again.");
        break;
    }
}