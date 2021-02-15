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
Coords rotationMatrix(Coords input, double radian, Coords center);

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

    cout << "rad :" << radian << endl;

    Length rotLength;
    Coords inputXY, center, rotCenter, resXY;

    Mat img = imread(imgName, IMREAD_GRAYSCALE);

    rotLength = getRectLength(img, radian);
    Mat rotImg = Mat::zeros(rotLength.width, rotLength.height, img.type());

    center.x = (img.rows - 1) / 2;
    center.y = (img.cols - 1) / 2;

    rotCenter.x = (rotLength.width - 1) / 2;
    rotCenter.y = (rotLength.height - 1) / 2;

    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            inputXY.x = j;
            inputXY.y = i;

            resXY = rotationMatrix(inputXY, radian, rotCenter);

            if (!(resXY.x < 0 || resXY.y < 0 || resXY.x > rotLength.width - 1 || resXY.y > rotLength.height - 1))
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
    Coords a, b, c, d, center = { 0 };
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

    a = rotationMatrix(a, radian, center);
    b = rotationMatrix(b, radian, center);
    c = rotationMatrix(c, radian, center);
    d = rotationMatrix(d, radian, center);

    max.x = std::max({ a.x, b.x, c.x, d.x });
    min.x = std::min({ a.x, b.x, c.x, d.x });

    max.y = std::max({ a.y, b.y, c.y, d.y });
    min.y = std::min({ a.y, b.y, c.y, d.y });

    rotLength.width = (max.x - min.x) + 1;
    rotLength.height = (max.y - min.y) + 1;

    return rotLength;
}

Coords rotationMatrix(Coords input, double radian, Coords center)
{
    Coords res = {0};

    res.x = cos(radian) * (input.x - center.x) + sin(radian) * (input.y - center.y) + center.x;
    res.y = -sin(radian) * (input.x - center.x) + cos(radian) * (input.y - center.y) + center.y;

    return res;
}