#include <cstdlib>
#include <iostream>
#include <string>

#include "sarchi.hpp"
#include "colors.hpp"

void sarchiPrint(const std::string &hexColor, Colorful& colorful)
{
   size_t logoSize = DISTRO_LOGO.size();
   size_t compoSize = ComponentSet.size();

   size_t loopRunner = logoSize > compoSize ? logoSize : compoSize;

   // We will loop for the longest thing, what is longer? the length of distro logo or the no of components 
   for (size_t i = 0; i < loopRunner; ++i) {
      if (i < logoSize) {
         colorful.M_print(DISTRO_LOGO[i], hexColor);
      }

      // What to do if we have more components than the no of strings in
      // DISTRO_LOGO vector
      if (i < compoSize) {

         i >= logoSize ? colorful.M_printSpaces(DISTRO_LOGO[0].size() + NUM_SPACES) : colorful.M_printSpaces(NUM_SPACES);

         colorful.M_print(ComponentSet[i].componentName, ComponentSet[i].componentColor);
         colorful.M_print(ComponentSet[i].componentValue,ComponentSet[i].componentColor);
      }
      std::cout << '\n';
   }
}

int main(void) {
   Colorful colorful;
   std::cout << '\n';

   sarchiPrint(LOGOCOLOR, colorful);
   std::cout << std::endl;

   return 0;
}
