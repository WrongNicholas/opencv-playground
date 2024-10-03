#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  
  VideoCapture video(0);

  if (!video.isOpened()) {
    std::cerr << "ERROR COULD NOT OPEN VIDEO" << std::endl;
    return -1;
  }

  int video_width = static_cast<int>(video.get(CAP_PROP_FRAME_WIDTH));
  int video_height = static_cast<int>(video.get(CAP_PROP_FRAME_HEIGHT));

  Size video_size(video_width, video_height);
  VideoWriter writer("output.mp4", VideoWriter::fourcc('m', 'p', '4', 'v'), 15, video_size); 
  
  if (!writer.isOpened()) {
    std::cerr << "ERROR: COULD NOT OPEN WRITING FILE" << std::endl;
    return -1;
  }

  while (true) {
    Mat frame;
    video >> frame;

    if (frame.empty()) {
      std::cerr << "ERROR: BLANK FRAME GRABBED" << std::endl;
      break;
    }

    writer.write(frame);

    imshow("Webcam", frame);

    if (waitKey(30) == 'q') break;
  }

  video.release();
  writer.release();
  destroyAllWindows();

  return 0;
}
