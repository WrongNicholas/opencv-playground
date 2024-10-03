#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << "[camera device ID]" << std::endl;
    return -1;
  }

  CascadeClassifier cascade;
  if (!cascade.load("/opt/homebrew/Cellar/opencv/4.10.0_9/share/opencv4/haarcascades/haarcascade_frontalface_default.xml")) {
    std::cerr << "ERROR: COULD NOT LOAD HAARCASCADE" << std::endl;
  }

  VideoCapture video(stoi(argv[1]));
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

    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);

    vector<Rect> faces;
    cascade.detectMultiScale(gray, faces, 1.2, 4, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

    for (size_t i = 0; i < faces.size(); i++)
      rectangle(frame, faces[i], Scalar(255, 0, 0), 2);

    imshow("Face Detection", frame);

    if (waitKey(30) == 'q') break;
  }

  video.release();
  destroyAllWindows();
  return 0;
}
