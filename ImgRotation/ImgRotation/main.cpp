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

Coords rotationMatrix(int degree, Coords input);

int main(int argc, char* argv[])
 {
    if (argc != 3)
    {
        cout<<"Argument ���� �������� �ʽ��ϴ�."<<endl;
        return 1;
    }

    string imgName = argv[1];
    auto degree = argv[2];
    double val = atof(degree);
    double radian = (PI / 180) * val;


    Coords inputXY, resXY;
    uchar inPixel = 0;
    uchar resPixel = 0;
	Mat img = imread(imgName, IMREAD_GRAYSCALE);
//    Mat rotImg = imread(imgName, IMREAD_GRAYSCALE);

    Mat rotImg = Mat::zeros(500, 500, img.type());

    int rows = img.rows;
    int cols = img.cols;   

    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            inputXY.x = j;
            inputXY.y = i;
            inPixel = img.at<uchar>(i, j);

            resXY = rotationMatrix(radian, inputXY);
            cout << " res : " << resPixel << "in : " << inPixel << endl;
            resPixel = rotImg.at<uchar>(resXY.y, resXY.x);

            resPixel = inPixel;
            
            cout << " res : " << resPixel << "in : " << inPixel << endl;
        }
    }

    img.at<uchar>();

    cout << "Rows : " << rows << endl;
    cout << "Cols : " << cols << endl;

    imshow("original", img);
//    cout << img << endl;

    img.at<uchar>(100, 100);


	imshow("result", rotImg);
	waitKey(0);

	return 0;
}


Coords rotationMatrix(int radian, Coords input)
{
    Coords res;

    res.x = cos(radian) * input.x + (sin(radian) * -1) * input.y;
    res.y = sin(radian) * input.x + cos(radian) * input.y;

    if (res.x < 1 || res.y < 1)
    {
        res.x = 0;
        res.y = 0;
    }
    
    return res;
}

/* ���� �ڵ�
1) img.at<uchar>(i, j);

2) �ݺ��� i �� ��row��
3) �ݺ��� j �� ��col�� �޴´�.

��� ���� �ް�

4) ����� Ư�� degree ��ŭ ������.

5) ���? ȸ����ȯ����� �̿��ؼ�.
cos ��Ÿ  -sin ��Ÿ
sin ��Ÿ   cos ��Ÿ

6) ��� ���� �̸� ��ȯ�ص� frame ���� ���� �ִ´�.

7) ����Ѵ�.

Rows : 121
Cols : 288
*/