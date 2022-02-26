#include "mainwindow.h"
#include <QApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>
#include <math.h>
#include <chrono>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <omp.h>

#define DEBUG_MODE 1
using namespace std;
using namespace cv;

void read_directory(string &name, vector<string> &v)
{
    DIR *dirp = opendir(name.c_str());
    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL)
    {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}

int main_1()
{
    vector<string> v;
    string read_dir = "C:\Users\HP\OneDrive\Desktop\T2\T2-IMAGES";  \\add your own read and write direction according to your system
    string write_dir = "C:\Users\HP\OneDrive\Desktop\T2\result.txt";
    read_directory(read_dir, v);

    for (string s : v)
    {
        string filename = read_dir + "/" + s;
        Mat img = imread(filename, 0);
        cout << filename << endl;
        if (img.empty())
        {
            continue;
        }

        Mat Img_orig = img.clone();

        if (Img_orig.channels() == 3)
        {
            cvtColor(Img_orig, Img_orig, CV_BGR2GRAY);
        }
        else
        {
            Img_orig.copyTo(Img_orig);
        }
        // Rect rt = Rect(0,0,Img_orig.cols/2, Img_orig.rows);
        // Mat cropped_image = Img_orig(rt).clone();

        // ADD YOUR CODE HERE
        Mat img1 = imread("C:\Users\HP\OneDrive\Desktop\T2\T2-IMAGES\NG\25-07-2020_10_56_48img_1810.jpg");
        Mat img2 = imread("C:\Users\HP\OneDrive\Desktop\T2\T2-IMAGES\OK\25-07-2020_11_02_41img_1835.jpg");

        // calc the difference
        Mat diff;
        absdiff(img1, img2, diff);

        // Get the mask if difference greater than th
        int th = 10; // 0
        Mat mask(img1.size(), CV_8UC1);
        for (int j = 0; j < diff.rows; ++j)
        {
            for (int i = 0; i < diff.cols; ++i)
            {
                cv::Vec3b pix = diff.at<cv::Vec3b>(j, i);
                int val = (pix[0] + pix[1] + pix[2]);
                if (val > th)
                {
                    mask.at<unsigned char>(j, i) = 255;
                }
            }
        }

        // get the foreground
        Mat res;
        bitwise_and(img2, img2, res, mask);

        // display
        imshow("res", res);
        waitKey();
    }
}

int main()
{
    main_1();
}
