#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <Windows.h>
#include <sys/timeb.h>
#include <chrono>
using namespace cv;
using namespace std;
Mat inputimage;
Mat grayimg;
Mat binaryimg, dilateimg, erodeimg;
string imageWindow = "VideoCapture";

int main()
{
    clock_t start ,end;
    inputimage = imread("C:\\Users\\AOI\\source\\repos\\opencv_windows_test\\x64\\Debug\\home.jpg");
    namedWindow(imageWindow);
    while (true)
    {
        /*gettimeofday(&start, NULL);*/
        start = clock();
        for (int i = 0; i < 10000; i++)
        {
            /*capture.read(cameraFeed);*/
            cvtColor(inputimage, grayimg, COLOR_RGB2GRAY);
            threshold(grayimg, binaryimg, 125, 255, 0);
            dilate(binaryimg, dilateimg, 10, Point(-1, -1), 10);
            erode(dilateimg, erodeimg, 10, Point(-1, -1), 10);
            printf("%d\n", i);
        }
        /*gettimeofday(&end, NULL);*/
        end = clock();
        auto time = end - start;
        /*putText(erodeimg ,to_string(cost),Point(10,30),FONT_HERSHEY_COMPLEX,0.8,Scalar(255,255,255));*/
        imshow(imageWindow, erodeimg);
        /*float diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;*/
        printf("Lasting Time: %d millisecond.\n", (time));
        waitKey(0);
    }
}
