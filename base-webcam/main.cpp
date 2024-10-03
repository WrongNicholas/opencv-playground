#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  
  VideoCapture video(0);
  if (!video.isOpened()) {
    std::cerr << "ERROR COULD NOT OPEN VIDEO" << std::endl;
    return -1;
  } 
  
  while (true) {
    Mat frame;
    video >> frame;

    if (frame.empty()) {
      std::cerr << "ERROR: BLANK FRAME GRABBED" << std::endl;
      break;
    }

    imshow("Face Detection", frame);

    if (waitKey(30) == 'q') break;
  }

  video.release();
  destroyAllWindows();

  return 0;
}
