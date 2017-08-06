#include "opencv2/aruco.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace cv::aruco;
using namespace std;

int main() {
  Mat markerImage;
  int keyCode;
  int markerId = 1;
  bool done = false;

  Ptr<Dictionary> dictionary = getPredefinedDictionary(DICT_5X5_1000);
  Ptr<DetectorParameters> detectorParams = DetectorParameters::create();

  VideoCapture inputVideo;
  inputVideo.open(0);

  namedWindow("Marker", CV_WINDOW_AUTOSIZE);
  namedWindow("Camera", CV_WINDOW_AUTOSIZE);

  while (!done && inputVideo.grab()) {
    Mat image, imageCopy;

    inputVideo.retrieve(image);

    vector<int> ids;
    vector<vector<Point2f> > corners, rejected;
    vector<Vec3d> rvecs, tvecs;

    detectMarkers(image, dictionary, corners, ids, detectorParams, rejected);

    image.copyTo(imageCopy);

    if (ids.size() > 0) {
      drawDetectedMarkers(imageCopy, corners, ids);
    }

    if (ids.size() == 2) {
      rectangle(imageCopy, corners[0][0], corners[1][0],
                    Scalar(100, 0, 255));
    }

    imshow("Camera", imageCopy);

    drawMarker(dictionary, markerId, 200, markerImage, 1);

    imshow("Marker", markerImage);

    keyCode = waitKey(1);

    switch (keyCode) {
      case 123:
        markerId = markerId > 0 ? markerId - 1 : 0;
        break;
      case 124:
        markerId = markerId < 999 ? markerId + 1 : 999;
        break;
      case 125:
        markerId = markerId > 0 ? markerId - 1 : 0;
        break;
      case 126:
        markerId = markerId < 999 ? markerId + 1 : 999;
        break;
      case 27:
        done = true;
        break;
    }
  }

  destroyWindow("Marker");
  destroyWindow("Camera");

  return 0;
}
