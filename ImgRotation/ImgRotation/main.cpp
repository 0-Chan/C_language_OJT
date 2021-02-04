#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <stdio.h>
#include "MatMul.h"

using namespace cv;
using namespace std;


int main(int argc, char** argv) {

	Mat img = imread("max.jpg", IMREAD_GRAYSCALE);

	imshow("original", img);

    int inputCnt = 1;

    pMatrix inMat = (pMatrix)malloc(sizeof(Matrix) * inputCnt);
    if (inMat == NULL)
    {
        return 1;
    }
    Matrix resMat = { 1 };

//    printf("%d\n", inMat->elements[0]);
    printf("12\n");


	imshow("result", img);
	waitKey(0);

	return 0;
}