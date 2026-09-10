#include <iostream>
#include "jumper.hpp"

int main() {
    
    ruezo::FrameHandler fh(10 , 10);
    std::this_thread::sleep_for(std::chrono::microseconds(1));
    std::cout << fh.getDeltaTime() << std::endl;

    return 0;
}