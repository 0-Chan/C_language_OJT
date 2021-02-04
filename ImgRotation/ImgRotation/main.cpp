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
        cout<<"Argument 수가 적절하지 않습니다."<<endl;
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

/* 수도 코드
1) img.at<uchar>(i, j);

2) 반복문 i 는 행row를
3) 반복문 j 는 열col을 받는다.

행렬 값을 받고

4) 행렬을 특정 degree 만큼 돌린다.

5) 어떻게? 회전변환행렬을 이용해서.
cos 세타  -sin 세타
sin 세타   cos 세타

6) 결과 값을 미리 변환해둔 frame 에다 갖다 넣는다.

7) 출력한다.

Rows : 121
Cols : 288
*/