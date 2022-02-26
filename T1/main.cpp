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
    string read_dir = "C:\Users\HP\OneDrive\Desktop\FrameWork\T1";
    string write_dir = "C:\Users\HP\OneDrive\Desktop\FrameWork\output.txt";
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
        // Read Image
        Mat img = imread("C:\Users\HP\OneDrive\Desktop\FrameWork\T1\09-08-2021_11_07_29img_84.jpg");
        cout << "Width : " << img.size().width << endl;
        cout << "Height: " << img.size().height << endl;
        cout << "Channels: :" << img.channels() << endl;
        // Crop Image
        Mat cropped_image = img(Range(80, 280), Range(150, 330)); // Any random dimension

        // Display Image
        imshow(" Original Image", img);
        imshow("Cropped Image", cropped_image);

        // Save the cropped Image
        imwrite("Cropped Image.jpg", cropped_image);

        // 0 means loop infinitely
        waitKey(0);
        destroyAllWindows();
    }
}

int main()
{
    main_1();
}
