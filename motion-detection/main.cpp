#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  
  VideoCapture video(1);

  if (!video.isOpened()) {
    std::cerr << "ERROR COULD NOT OPEN VIDEO" << std::endl;
    return -1;
  }

  int video_width = static_cast<int>(video.get(CAP_PROP_FRAME_WIDTH));
  int video_height = static_cast<int>(video.get(CAP_PROP_FRAME_HEIGHT));

  Mat prev_frame, diff_frame;
  video >> prev_frame;
  cvtColor(prev_frame, prev_frame, COLOR_BGR2GRAY);

  GaussianBlur(prev_frame, prev_frame, Size(5, 5), 0);

  while (true) {
    Mat frame, gray_frame;
    video >> frame;

    cvtColor(frame, gray_frame, COLOR_BGR2GRAY);

    GaussianBlur(gray_frame, gray_frame, Size(5, 5), 0);

    absdiff(prev_frame, gray_frame, diff_frame);

    threshold(diff_frame, diff_frame, 25, 255, THRESH_BINARY);

    imshow("Motion Detection", diff_frame);

    if (waitKey(30) == 'q') break;

    gray_frame.copyTo(prev_frame);
  }

  video.release();
  destroyAllWindows();

  return 0;
}
