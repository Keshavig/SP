#pragma once

#include <iostream>
#include <string>

class Colorful {
private:
   inline bool M_checkColorCodeValidation(const std::string &hexColorCode);
   inline size_t M_hex2deci(const std::string &hexColorCode); 
   inline void M_resetTermColor(void);

   void M_setTermColor(const std::string &hexColorCode);

public:
   void M_printSpaces(size_t spaces);
   void M_print(const std::string &message, const std::string &hexColor); 
};

// c:w
// #include "colors.tpp"
