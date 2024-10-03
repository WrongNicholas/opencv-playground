// THIS PROJECT BARELY WORKS!
// IT WILL PROBABLY LOOK TERRIBLE!

#include <opencv2/opencv.hpp>
#include <thread>
#include <chrono>

using namespace cv;

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " [path/to/video]" << std::endl;
    return -1;
  }

  VideoCapture video(argv[1]);
  if (!video.isOpened()) {
    std::cerr << "ERROR: COULD NOT OPEN VIDEO" << std::endl;
    return -1;
  }

  int video_width = static_cast<int>(video.get(CAP_PROP_FRAME_WIDTH));
  int video_height = static_cast<int>(video.get(CAP_PROP_FRAME_HEIGHT));
  int frame_count = static_cast<int>(video.get(CAP_PROP_FRAME_COUNT));

  for (int i = 0; i < frame_count; ++i) {

    Mat frame;
    bool success = video.read(frame);
    if (!success) {
      std::cerr << "ERROR: COULD NOT READ FRAME" << std::endl;
      return -1;
    }
    

    int pixel_skip = 20;
    for (int y = 0; y < video_height; y+=30) {
      for (int x = 0; x < video_width; x+=10) {

        Vec3b color = frame.at<Vec3b>(y, x);

        int r = color[2];
        int g = color[1];
        int b = color[0];

        //r*=3;
        //g/=2;
        //b*=2;

        std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << "█" << "\033[0m";
      }

      std::cout << std::endl;
    }

    
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
    std::cout << "\033[2J\033[H"; 
    //system("clear");

    //std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
 
  video.release();

  return 0;
}
