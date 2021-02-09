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
    double x;
    double y;
} Length;

Length getRectLength(int rows, int cols, double radian);
Coords moveToCenter(Coords input, int rows, int cols, Length rect);
Coords rotationMatrix(Coords input, double radian, Coords base);

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
    Coords inputXY, base, resXY;

    Mat img = imread(imgName, IMREAD_GRAYSCALE);
    int rows = img.rows - 1;
    int cols = img.cols - 1;

    rotLength = getRectLength(rows, cols, radian);
    Mat rotImg = Mat::zeros(rotLength.x + 1, rotLength.y + 1, img.type());

    base.x = rotLength.x / 2;
    base.y = rotLength.y / 2;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            inputXY.x = j;
            inputXY.y = i;

            resXY = moveToCenter(inputXY, rows, cols, rotLength);
            resXY = rotationMatrix(resXY, radian, base);

            rotImg.at<uchar>((int)resXY.y, (int)resXY.x) = img.at<uchar>(i, j);
        }
    }

    imshow("original", img);
    imshow("result", rotImg);
    waitKey(0);

    return 0;
}


Length getRectLength(int rows, int cols, double radian)
{
    Coords a, b, c, d, base = { 0 };
    Coords max, min;
    Length rotLength;

    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = rows;
    c.x = cols;
    c.y = 0;
    d.x = cols;
    d.y = rows;

    a = rotationMatrix(a, radian, base);
    b = rotationMatrix(b, radian, base);
    c = rotationMatrix(c, radian, base);
    d = rotationMatrix(d, radian, base);

    max.x = std::max({ a.x, b.x, c.x, d.x });
    min.x = std::min({ a.x, b.x, c.x, d.x });

    max.y = std::max({ a.y, b.y, c.y, d.y });
    min.y = std::min({ a.y, b.y, c.y, d.y });

    rotLength.x = max.x - min.x;
    rotLength.y = max.y - min.y;

    return rotLength;
}

Coords moveToCenter(Coords input, int rows, int cols, Length rect)
{
    Coords res = { 0 };
    Coords movePoint = { 0 };

    movePoint.x = (rect.x - cols) / 2;
    movePoint.y = (rect.y - rows) / 2;

    res.x = input.x + movePoint.x;
    res.y = input.y + movePoint.y;

    return res;
}

Coords rotationMatrix(Coords input, double radian, Coords base)
{
    Coords res;
    res.x = 0;
    res.y = 0;

    res.x = cos(radian) * (input.x - base.x) - sin(radian) * (input.y - base.y) + base.x;
    res.y = sin(radian) * (input.x - base.x) + cos(radian) * (input.y - base.y) + base.y;

    return res;
}