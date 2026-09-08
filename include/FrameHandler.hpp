#include <Image.hpp>

class FrameHandler {
private:
    ruezo::Image img;
    int* pixelBuffer;

public:
    FrameHandler(int width, int height);
    ~FrameHandler();
    int* getPixelBuffer();
    ruezo::Image& getImage();
};