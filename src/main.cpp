#include<bits/stdc++.h>
#include "Detector.hpp"

using namespace std;
using namespace cv;

int main()
{
    Detector mDetector;
    Mat img,imga;


    //apri
    /*VideoCapture cap_cam(0);
    while(true)
    {
    cap_cam.read(imga);
    mDetector.detect(imga);
    waitKey(1);
    }*/

    //cube
        string path ="../res/cb.mp4";
    
       VideoCapture cap(path);
    while(true)
    {
        cap.read(img); 
        mDetector.detect(img,5);
        waitKey(10);
     
    }

    return 0;
}