#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <algorithm>
#include <cmath>

#define PI 3.14159265358

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
Mat forwardMapping(Mat img, double radian);
Coords backwardRotationMatrix(Coords input, double radian, Coords rotCenter);
Mat backwardMapping(Mat img, double radian);

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
    double radian = (PI / 180.0) * val;

    Mat img = imread(imgName, IMREAD_GRAYSCALE);
    Mat res;    

//  res = forwardMapping(img, radian);
    res = backwardMapping(img, radian);

    imshow("original", img);
    imshow("result", res);
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

Mat forwardMapping(Mat img, double radian)
{
    Coords input, res, center, rotCenter;
    Length rotLength;

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
            input.x = j;
            input.y = i;

            res = rotationMatrix(input, radian, center, rotCenter);

            if (!(res.x < 0 || res.y < 0 || res.x >= rotImg.cols || res.y >= rotImg.rows))
            {
                rotImg.at<uchar>((int)res.y, (int)res.x) = img.at<uchar>(i, j);
            }
        }
    }
    return rotImg;
}

Coords backwardRotationMatrix(Coords input, double radian, Coords rotCenter)
{
    Coords res = { 0 };

    res.x = cos(radian) * (input.x - rotCenter.x) - sin(radian) * (input.y - rotCenter.y) + rotCenter.x;
    res.y = sin(radian) * (input.x - rotCenter.x) + cos(radian) * (input.y - rotCenter.y) + rotCenter.y;

    return res;
}

Mat backwardMapping(Mat img, double radian)
{
    Coords input, res, center, rotCenter;
    Length rotLength;

    rotLength = getRectLength(img, radian);
    Mat rotImg = Mat::zeros(rotLength.height, rotLength.width, img.type());
    Mat tmp = Mat::zeros(rotLength.height, rotLength.width, img.type());

    center.x = img.cols / 2;
    center.y = img.rows / 2;

    rotCenter.x = rotLength.width / 2;
    rotCenter.y = rotLength.height / 2;

    for (int y = 0; y < img.rows; y++)
    {
        for (int x = 0; x < img.cols; x++)
        {
            tmp.at<uchar>(y + rotCenter.y - center.y, x + rotCenter.x - center.x) = img.at<uchar>(y, x);
        }
    }

    for (int i = 0; i < rotImg.rows; i++)
    {
        for (int j = 0; j < rotImg.cols; j++)
        {
            input.x = j;
            input.y = i;

            res = backwardRotationMatrix(input, radian, rotCenter);

            if (!(res.x < 0 || res.y < 0 || res.x >= rotImg.cols || res.y >= rotImg.rows))
            {
                rotImg.at<uchar>(i, j) = tmp.at<uchar>((int)res.y, (int)res.x);
            }
        }
    }
    return rotImg;
}