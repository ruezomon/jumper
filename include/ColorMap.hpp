#include <map>
#include <string>

#include "RGB.hpp"

namespace ruezo {
   std::map<std::string, RGB> cmap = {
      {"red", ruezo::RGB(255, 0, 0)},
      {"green", ruezo::RGB(0, 255, 40)},
      {"blue", ruezo::RGB(0, 0, 255)},
      {"yellow", ruezo::RGB(255, 255, 0)},
      {"cyan", ruezo::RGB(0, 255, 255)},
      {"magenta", ruezo::RGB(255, 0, 255)},
      {"orange", ruezo::RGB(255, 165, 0)},
      {"violet", ruezo::RGB(0x79, 0x21, 0xb1)},
      {"white", ruezo::RGB(238, 238, 238)},
      {"grey", ruezo::RGB(169, 169, 169)},
      {"dgrey", ruezo::RGB(36, 36, 36)},
      {"black", ruezo::RGB(1, 2, 3)}
   };
}
