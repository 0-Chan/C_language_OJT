#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>

#define PI 3.14159265

using namespace cv;
using namespace std;

typedef struct
{
    int x;
    int y;
} Coords;

Coords rotationMatrix(double degree, Coords input, Coords base);

int main(int argc, char* argv[])
 {
    if (argc != 3)
    {
        cout<<"Argument 수가 적절하지 않습니다."<<endl;
        return 1;
    }

    string imgName = argv[1];
    auto degree = argv[2];
    double val = atof(degree);
    double radian = (PI / 180) * val;

    Coords inputXY, resXY, base;
    resXY.x = 0;
    resXY.y = 0;

	Mat img = imread(imgName, IMREAD_GRAYSCALE);
    int rows = img.rows;
    int cols = img.cols;
    int gap = 2 * (cols - rows);
    Mat rotImg = Mat::zeros(cols, rows + gap, img.type());

    imshow("original", img);

    base.x = cols;
    base.y = rows;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            inputXY.x = j;
            inputXY.y = i;

            resXY = rotationMatrix(radian, inputXY, base);

            rotImg.at<uchar>((int)resXY.y, (int)resXY.x) = img.at<uchar>(i, j);
        }
    }

    cout << "Rows : " << rows << endl;
    cout << "Cols : " << cols << endl;

	imshow("result", rotImg);
	waitKey(0);

	return 0;
}


Coords rotationMatrix(double radian, Coords input, Coords base)
{
    Coords res;
    res.x = 0; 
    res.y = 0;

    res.x = (cos(radian) * (input.x - base.x)) - (sin(radian) * input.y) + base.x;
    res.y = (sin(radian) * (input.x - base.y)) + (cos(radian) * input.y) + base.y;

    if (res.x < 0 || res.y < 0 )
    {
        res.x = 0;
        res.y = 0;
    }
    return res;
}