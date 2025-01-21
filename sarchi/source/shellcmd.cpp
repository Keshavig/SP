#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string> 

#include "shellcmd.hpp"

const std::string shellcmd(const std::string &cmd)
{
   std::string output;
   output.reserve(OUTPUT_SIZE);

   std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
   if (!pipe)
      throw std::runtime_error("popen() failed");

   for (char c; (c = fgetc(pipe.get())) != EOF;) {
      output += c;
   }

   return output;
}
