#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[]) {
  
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " [camera device ID]" << std::endl;
    return -1;
  }

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
