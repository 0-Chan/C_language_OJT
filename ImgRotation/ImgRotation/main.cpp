#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <algorithm>
#include <cmath>

#define PI 3.14159265

using namespace cv;
using namespace std;

typedef struct
{
    double x;
    double y;
} Coords;

typedef struct
{
    int width;
    int height;
} Length;

Length getRectLength(Mat img, double radian);
Coords rotationMatrix(Coords input, double radian, Coords center, Coords rotCenter);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Argument 수가 적절하지 않습니다." << endl;
        return 1;
    }

    char* imgName = argv[1];
    char* degree = argv[2];
    double val = atof(degree);
    double radian = (PI / 180) * val;

    Length rotLength;
    Coords inputXY, center, rotCenter, resXY;

    Mat img = imread(imgName, IMREAD_GRAYSCALE);

    rotLength = getRectLength(img, radian);
    Mat rotImg = Mat::zeros(rotLength.height, rotLength.width, img.type());

    center.x = img.cols / 2;
    center.y = img.rows / 2;

    rotCenter.x = rotLength.width / 2;
    rotCenter.y = rotLength.height / 2;

    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            inputXY.x = j;
            inputXY.y = i;

            resXY = rotationMatrix(inputXY, radian, center, rotCenter);

            if (!(resXY.x < 0 || resXY.y < 0 || resXY.x >= rotImg.cols || resXY.y >= rotImg.rows))
            {
                rotImg.at<uchar>((int)resXY.y, (int)resXY.x) = img.at<uchar>(i, j);
            }
        }
    }
    
    imshow("original", img);
    imshow("result", rotImg);
    waitKey(0);

    return 0;
}


Length getRectLength(Mat img, double radian)
{
    Coords a, b, c, d, zero = { 0 };
    Coords max, min;
    Length rotLength;

    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = img.rows;
    c.x = img.cols;
    c.y = 0;
    d.x = img.cols;
    d.y = img.rows;

    a = rotationMatrix(a, radian, zero, zero);
    b = rotationMatrix(b, radian, zero, zero);
    c = rotationMatrix(c, radian, zero, zero);
    d = rotationMatrix(d, radian, zero, zero);

    max.x = std::max({ a.x, b.x, c.x, d.x });
    min.x = std::min({ a.x, b.x, c.x, d.x });

    max.y = std::max({ a.y, b.y, c.y, d.y });
    min.y = std::min({ a.y, b.y, c.y, d.y });

    rotLength.width = max.x - min.x;
    rotLength.height = max.y - min.y;

    return rotLength;
}

Coords rotationMatrix(Coords input, double radian, Coords center, Coords rotCenter)
{
    Coords res = { 0 };

    res.x = cos(radian) * (input.x - center.x) + sin(radian) * (input.y - center.y) + rotCenter.x;
    res.y = -sin(radian) * (input.x - center.x) + cos(radian) * (input.y - center.y) + rotCenter.y;

    return res;
}