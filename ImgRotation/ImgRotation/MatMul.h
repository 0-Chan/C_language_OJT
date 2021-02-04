#ifndef _MAT_MUL_H
#define _MAT_MUL_H

typedef struct
{
    int row;
    int col;
    int* elements;
} Matrix, * pMatrix;

int getMat(int inputCnt, char* txtFiles[], Matrix* inMat);
int mulMat(Matrix mat1, Matrix mat2, Matrix* resMat);
void printMat(Matrix mat);
void checkError(int errorCode);


#endif