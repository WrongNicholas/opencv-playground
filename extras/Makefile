CXX = g++

CXXFLAGS = -std=c++11 -I/opt/homebrew/Cellar/opencv/4.11.0_1/include/opencv4

LDFLAGS = -L/opt/homebrew/Cellar/opencv/4.11.0_1/lib -lopencv_core -lopencv_videoio -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui

SRC = main.cpp

TARGET = main

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
