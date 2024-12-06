CXX = g++

CXXFLAGS = -std=c++11 -I/opt/homebrew/Cellar/opencv/4.10.0_14/include/opencv4

LDFLAGS = -L/opt/homebrew/Cellar/opencv/4.10.0_14/lib -lopencv_core -lopencv_videoio -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui

SRC = main.cpp

TARGET = main

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
