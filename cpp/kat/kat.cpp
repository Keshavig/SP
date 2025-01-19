#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <fstream>

#define ERRCODE -1

bool checkValidFile(const char* str)
{
   const std::string filepath = std::string(str);
   std::string Actualfilepath;

   size_t pos = filepath.find("~");

   if (pos == std::string::npos)
      Actualfilepath = filepath;
   else { std::string username = getenv("USER"); std::string halfFilePath = filepath.substr(pos+1);

      std::string Actualfilepath = "/home/" +  username + halfFilePath;
   }


   bool exist = std::filesystem::exists(Actualfilepath);
   return exist;
}

size_t checkArgument(size_t argc, char* argv[])
{
   for (size_t i = 1; i < argc; i++)
   {
      /*TODO store all true files in a vector to print them all; for in case user does something like cat file1.txt file2.txt etc */
      if (checkValidFile(argv[i])) {
         return i;
      }
   }

   return ERRCODE;
}

void printfile(const std::string& file) {
   std::ifstream File(file);

   if (File.is_open())
      std::cout << File.rdbuf();
   else 
      std::cerr << "Failed to open file" << std::endl;

   File.close();
}

int main(int argc, char* argv[])
{
   if (argc < 2) {
      std::cerr << "File name not provided" << std::endl;
      return ERRCODE;
   }

   size_t out = checkArgument(argc, argv);

   if (out != ERRCODE) 
      printfile(argv[out]);

   return 0;
}
