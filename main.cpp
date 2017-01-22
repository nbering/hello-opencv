#include "opencv2/highgui/highgui.hpp"
#include "opencv2/aruco.hpp"

#include <iostream>

using namespace cv;
using namespace cv::aruco;
using namespace std;

int main()
{
    Mat markerImage;
    Ptr<Dictionary> dictionary = getPredefinedDictionary(DICT_6X6_250);

    drawMarker(dictionary, 25, 200, markerImage, 1);


    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);

    imshow("MyWindow", markerImage);

    waitKey(0);

    destroyWindow("MyWindow");

    return 0;
}