#include <cstdlib>
#include <iostream>
#include <string>

#include "sarchi.hpp"

class Colorful {
private:
   inline bool M_checkColorCodeValidation(const std::string& hexColorCode) {
      if (hexColorCode.size() > 7 && hexColorCode[0] == '#')
         return false;

      return true;
   }

   inline size_t M_hdec(const std::string& hexColorCode) {
      size_t decValue = std::stoi(hexColorCode, nullptr, 16);
      return decValue;
   }


   void M_setTermColor(const std::string& hexColorCode) {
      if (!M_checkColorCodeValidation(hexColorCode)) {
         std::cout << "Invalid hex color code: " << hexColorCode << std::endl;
         exit(1);
      }


      std::string _termColor1 = "\033[38;2;";

      std::string _R = std::string(1, hexColorCode[1]) + std::string(1, hexColorCode[2]);
      std::string _G = std::string(1, hexColorCode[3]) + std::string(1, hexColorCode[4]);
      std::string _B = std::string(1, hexColorCode[5]) + std::string(1, hexColorCode[6]);

      size_t Rdeci = M_hdec(_R);
      size_t Gdeci = M_hdec(_G);
      size_t Bdeci = M_hdec(_B);

      std::string R = std::to_string(Rdeci);
      std::string G = std::to_string(Gdeci);
      std::string B = std::to_string(Bdeci);

      // std::cout << "\033[38;2;255;165;0m";
      std::string color = _termColor1 + R + ";" + G + ";" + B + "m";
      std::cout << color;
   }

   inline void M_resetTermColor(void) {
      std::cout << "\033[o";
   }

public:
   template<typename T> 
   void print(const T& message, const std::string& hexColor)
   {
      M_setTermColor(hexColor);
      // for (size_t i = 0; i < ARCHLINUX_LOGO.size(); ++i) {
      //    std::cout <<  ARCHLINUX_LOGO[i] << "   ";
      // }

      std::cout << message;
      M_resetTermColor();
   }

   void printSpaces(size_t spaces) {
      for (size_t i = 1; i <= spaces; i++)
         std::cout << ' ';
   }


   void printInfo(const std::string& hexColor)
   {
      size_t logoSize = ARCHLINUX_LOGO.size();
      size_t compoSize = ComponentSet.size();

      for (size_t i = 0; i < logoSize; ++i) {
         print<std::string>(ARCHLINUX_LOGO[i], hexColor);

         if (i < compoSize) {
            printSpaces(1);
            print<std::string>(ComponentSet[i].componentName, ComponentSet[i].componentColor);
            print<std::string>(ComponentSet[i].componentValue, ComponentSet[i].componentColor);
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
