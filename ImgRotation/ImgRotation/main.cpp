#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <algorithm>
#include <cmath>

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
Coords backwardRotationMatrix(Coords input, double radian, Coords Center, Coords rotCenter);
Mat backwardMapping(Mat img, double radian);
uchar bilinearInterpolation(Mat img, Coords input);

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
    double radian = (CV_PI / 180.0) * val;

    Mat img = imread(imgName, IMREAD_GRAYSCALE);
    Mat res;    

    imshow("original", img);
    res = forwardMapping(img, radian);
    imshow("forward", res);
    res = backwardMapping(img, radian);
    imshow("backward", res);
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
    b.y = img.rows - 1;
    c.x = img.cols - 1;
    c.y = 0;
    d.x = img.cols - 1;
    d.y = img.rows - 1;

    a = rotationMatrix(a, radian, zero, zero);
    b = rotationMatrix(b, radian, zero, zero);
    c = rotationMatrix(c, radian, zero, zero);
    d = rotationMatrix(d, radian, zero, zero);

    max.x = std::max({ a.x, b.x, c.x, d.x });
    min.x = std::min({ a.x, b.x, c.x, d.x });

    max.y = std::max({ a.y, b.y, c.y, d.y });
    min.y = std::min({ a.y, b.y, c.y, d.y });

    rotLength.width = (max.x - min.x) + 1;
    rotLength.height = (max.y - min.y) + 1;

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
            else
            {
                cout << "x : " << res.x << endl;
                cout << "y : " << res.y << endl << endl;
            }
        }
    }
    return rotImg;
}

Coords backwardRotationMatrix(Coords input, double radian, Coords Center, Coords rotCenter)
{
    Coords res = { 0 };

    res.x = cos(radian) * (input.x - rotCenter.x) - sin(radian) * (input.y - rotCenter.y) + Center.x;
    res.y = sin(radian) * (input.x - rotCenter.x) + cos(radian) * (input.y - rotCenter.y) + Center.y;

    return res;
}

Mat backwardMapping(Mat img, double radian)
{
    Coords input, res, center, rotCenter;
    Length rotLength;

    rotLength = getRectLength(img, radian);
    Mat rotImg = Mat::zeros(rotLength.height, rotLength.width, img.type());

    center.x = img.cols / 2;
    center.y = img.rows / 2;

    rotCenter.x = rotLength.width / 2;
    rotCenter.y = rotLength.height / 2;

    for (int i = 0; i < rotImg.rows; i++)
    {
        for (int j = 0; j < rotImg.cols; j++)
        {
            input.x = j;
            input.y = i;

            res = backwardRotationMatrix(input, radian, center, rotCenter);

            if (!(res.x < 0 || res.y < 0 || res.x >= img.cols || res.y >= img.rows))
            {
                rotImg.at<uchar>(i, j) = bilinearInterpolation(img, res);
            }
        }
    }
    return rotImg;
}

uchar bilinearInterpolation(Mat img, Coords input)
{
    double x1, x2, y1, y2, w1, h1;
    double p1Pixel, p2Pixel, p3Pixel, p4Pixel;
    double firstPixel, secondPixel, resPixel;

    x1 = floor(input.x);
    y1 = floor(input.y);

    if (x1 != img.cols - 1)
        x2 = x1 + 1;
    else
        x2 = img.cols - 1;
    
    if (y1 != img.rows - 1)
        y2 = y1 + 1;
    else
        y2 = img.rows - 1;

    p1Pixel = img.at<uchar>(y1, x1);
    p2Pixel = img.at<uchar>(y1, x2);
    p3Pixel = img.at<uchar>(y2, x1);
    p4Pixel = img.at<uchar>(y2, x2);

    w1 = input.x - x1;
    h1 = input.y - y1;

    firstPixel = p1Pixel * (1 - w1) + p2Pixel * w1;
    secondPixel = p3Pixel * (1 - w1) + p4Pixel * w1;

    resPixel = firstPixel * (1 - h1) + secondPixel * h1;
    
    resPixel = round(resPixel);
    if (resPixel > 255)
        resPixel = 255;

    return (uchar)resPixel;
}