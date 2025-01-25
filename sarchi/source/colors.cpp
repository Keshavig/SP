#include "colors.hpp"

inline bool Colorful::M_checkColorCodeValidation(const std::string &hexColorCode) {
   if (hexColorCode.size() != 7 || hexColorCode[0] != '#') {
      return false;
   }

   return true;
}

inline size_t Colorful::M_hex2deci(const std::string& hexColorCode) {
   size_t decValue = std::stoi(hexColorCode, nullptr, 16);
   return decValue;
}


void Colorful::M_printSpaces(size_t spaces) {
   for (size_t i = 1; i <= spaces; i++)
      std::cout << ' ';
}

void Colorful::M_setTermColor(const std::string& hexColorCode) {
   if (hexColorCode == "NONE" || hexColorCode == "NULL" || hexColorCode == "" || hexColorCode == "NORMAL" || hexColorCode == "DEFAULT") {
      return;
   }

   if (!M_checkColorCodeValidation(hexColorCode)) {
      std::cout << "error: invalid hex color code (should be 7 characters long; in the form of #rrggbb): " << hexColorCode << std::endl;
      exit(1);
   }

   std::string _termColor1 = "\033[38;2;";

   std::string _R = std::string(1, hexColorCode[1]) + std::string(1, hexColorCode[2]);
   std::string _G = std::string(1, hexColorCode[3]) + std::string(1, hexColorCode[4]);
   std::string _B = std::string(1, hexColorCode[5]) + std::string(1, hexColorCode[6]);

   size_t Rdeci = M_hex2deci(_R);
   size_t Gdeci = M_hex2deci(_G);
   size_t Bdeci = M_hex2deci(_B);

   std::string R = std::to_string(Rdeci);
   std::string G = std::to_string(Gdeci);
   std::string B = std::to_string(Bdeci);

   std::string color = _termColor1 + R + ";" + G + ";" + B + "m";
   std::cout << color;
}

inline void Colorful::M_resetTermColor(void) { 
   std::cout << "\033[o"; 
}


void Colorful::M_print(const std::string& message, const std::string& hexColor) {
   M_setTermColor(hexColor);
   std::cout << message;
   M_resetTermColor();
}

