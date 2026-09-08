#include <map>
#include <string>

#include "RGB.hpp"

namespace ruezo {
   std::map<std::string, RGB> cmap = {
      {"red", RGB(255, 0, 0)},
      {"green", RGB(0, 255, 40)},
      {"blue", RGB(0, 0, 255)},
      {"yellow", RGB(255, 255, 0)},
      {"cyan", RGB(0, 255, 255)},
      {"magenta", RGB(255, 0, 255)},
      {"orange", RGB(255, 165, 0)},
      {"violet", RGB(0x79, 0x21, 0xb1)},
      {"white", RGB(238, 238, 238)},
      {"grey", RGB(169, 169, 169)},
      {"dgrey", RGB(36, 36, 36)},
      {"black", RGB(1, 2, 3)}
   };
}