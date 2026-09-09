#include <iostream>
#include "jumper.hpp"

int main() {
    
    ruezo::GameHandler gh(10, 10);
    ruezo::GameHandler gh2(10, 10);
    ruezo::Player p(5, 5);
    p.linkGame(&gh);
    p.linkGame(&gh2);

    return 0;
}