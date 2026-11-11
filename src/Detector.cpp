#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <bits/stdc++.h>
#include "Detector.hpp"

using namespace std;
using namespace cv;

Detector::Detector()
{

}

void Detector::detect(const Mat& imga) 
{
    Mat result = imga.clone();

    Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_APRILTAG_36h11);
    
    vector<int> ids;                 
    vector<vector<Point2f>> corners;  

    aruco::detectMarkers(imga, dictionary, corners, ids);
    if (ids.size() > 0) 
    {
        cv::aruco::drawDetectedMarkers(result, corners, ids);
    }


    imshow("Image_raw", imga);
    imshow("result", result);
}

void Detector::detect(const Mat&img,int a)
{
    Mat imgHSV,mask,imgDil,imgErode;
    //转HSV
    cvtColor(img,imgHSV,COLOR_BGR2HSV);
    //创建一个核用来膨胀
    Mat kernel=cv::getStructuringElement(MORPH_RECT,Size(10,10));

    vector<vector<Point>> contours;

//red
    //限定一个颜色区间
    inRange(imgHSV,Scalar(0,120,70),Scalar(10,255,255),mask);
    //膨胀
    dilate(mask,imgDil,kernel);
    

    if(countNonZero(imgDil)>2000 &&countNonZero(imgDil)<30000)//减小干扰
    //如果有红色，就显示并画框写文字 
    {
        ////找边界，为了避免把魔方的每个小方块都框一遍选择mask作为轮廓
        Rect test=boundingRect(imgDil);
        //画框写字
        rectangle(img,test,Scalar(15,255,255),2);
        putText(img,"red",Point(test.x,test.y),FONT_HERSHEY_DUPLEX,0.8,Scalar(15,255,255),2);

    }
    
    //orange
    inRange(imgHSV,Scalar(11,100,100),Scalar(22,255,255),mask);

    dilate(mask,imgDil,kernel);


    
    if(countNonZero(mask)>2000)
    {
   
        Rect test=boundingRect(mask);
        rectangle(img,test,Scalar(22,255,255),2);
        putText(img,"orange",Point(test.x,test.y),FONT_HERSHEY_DUPLEX,0.8,Scalar(22,255,255),2);

    }

    //yellow

        inRange(imgHSV,Scalar(23,100,100),Scalar(35,255,255),mask);

        dilate(mask,imgDil,kernel);
        
        
    if(countNonZero(mask)>2000)
    {

        Rect test=boundingRect(mask);
        rectangle(img,test,Scalar(35,255,255),2);
        putText(img,"yellow",Point(test.x,test.y),FONT_HERSHEY_DUPLEX,0.8,Scalar(35,255,255),2);

    }
    
    //white
    inRange(imgHSV,Scalar(0,0,220),Scalar(180,15,255),mask);
    
        dilate(mask,imgDil,kernel);
        
    
    if(countNonZero(mask)>2000 &&countNonZero(mask)>30000)
    {

        Rect test=boundingRect(mask);
        rectangle(img,test,Scalar(0,256,0),2);
        putText(img,"white",Point(test.x,test.y),FONT_HERSHEY_DUPLEX,0.8,Scalar(0,256,0),2);

    }

    
    
    //blue
    inRange(imgHSV,Scalar(100,80,50),Scalar(130,255,255),mask);

    dilate(mask,imgDil,kernel);
    

    
    if(countNonZero(mask)>2000)
    {
        
        Rect test=boundingRect(mask);
        rectangle(img,test,Scalar(130,255,255),2);
        putText(img,"blue",Point(test.x,test.y),FONT_HERSHEY_DUPLEX,0.8,Scalar(130,255,255),2);

    }

        int hmin = 0, smin = 0, vmin = 0;
    int hmax = 179, smax = 255, vmax = 255;

    



    imshow("Image_raw",img);
    imshow("Image_binary",mask);
    imshow("Image_HSV",imgHSV);
}