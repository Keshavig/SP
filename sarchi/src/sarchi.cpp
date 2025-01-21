#include <cstdlib>
#include <iostream>
#include <string>

#include "sarchi.hpp"
#define LOG(X) std::cout << X << std::endl

class Colorful {
private:
   inline bool M_checkColorCodeValidation(const std::string &hexColorCode) {
      if (hexColorCode.size() != 7 || hexColorCode[0] != '#') {
         return false;
      }

      return true;
   }

   inline size_t M_hdec(const std::string &hexColorCode) {
      size_t decValue = std::stoi(hexColorCode, nullptr, 16);
      return decValue;
   }

   void M_setTermColor(const std::string &hexColorCode) {
      if (hexColorCode == "NONE" || hexColorCode == "NULL" || hexColorCode == "" || hexColorCode == "NORMAL")
         return;

      if (!M_checkColorCodeValidation(hexColorCode)) {
         std::cout << "error: invalid hex color code (should be 7 characters long; in the form of #rrggbb): " << hexColorCode << std::endl;
         exit(1);
      }

      std::string _termColor1 = "\033[38;2;";

      std::string _R =
         std::string(1, hexColorCode[1]) + std::string(1, hexColorCode[2]);
      std::string _G =
         std::string(1, hexColorCode[3]) + std::string(1, hexColorCode[4]);
      std::string _B =
         std::string(1, hexColorCode[5]) + std::string(1, hexColorCode[6]);

      size_t Rdeci = M_hdec(_R);
      size_t Gdeci = M_hdec(_G);
      size_t Bdeci = M_hdec(_B);

      std::string R = std::to_string(Rdeci);
      std::string G = std::to_string(Gdeci);
      std::string B = std::to_string(Bdeci);

      std::string color = _termColor1 + R + ";" + G + ";" + B + "m";
      std::cout << color;
   }

   inline void M_resetTermColor(void) { std::cout << "\033[o"; }

private:
   template <typename T>
   void print(const T &message, const std::string &hexColor) {
      M_setTermColor(hexColor);
      std::cout << message;
      M_resetTermColor();
   }

   void printSpaces(size_t spaces) {
      for (size_t i = 1; i <= spaces; i++)
         std::cout << ' ';
   }

public:
   void printInfo(const std::string &hexColor)
   {
      size_t logoSize = DISTRO_LOGO.size();
      size_t compoSize = ComponentSet.size();

      size_t loopRunner = logoSize > compoSize ? logoSize : compoSize;

      for (size_t i = 0; i < loopRunner; ++i) {
         // Print util in the range
         if (i < logoSize) {
            print<std::string>(DISTRO_LOGO[i], hexColor);
         }

         // What to do if we have more components than the no of strings in
         // DISTRO_LOGO vector
         if (i < compoSize) {

            i >= logoSize ? printSpaces(DISTRO_LOGO[0].size() + NUM_SPACES) : printSpaces(NUM_SPACES);

            print<std::string>(ComponentSet[i].componentName, ComponentSet[i].componentColor);
            print<std::string>(ComponentSet[i].componentValue,ComponentSet[i].componentColor);
         }
         std::cout << '\n';
      }
   }
};

int main(void) {
   Colorful colorful;
   std::cout << '\n';

   colorful.printInfo(LOGOCOLOR);
   std::cout << std::endl;

   return 0;
}
