#include <filesystem>
#include <fstream>
#include <iostream>

#include "kat.hpp"

bool isValidFile(const char *str) {
  const std::string filepath = std::string(str);
  std::string Actualfilepath;

  size_t pos = filepath.find("~");

  if (pos == std::string::npos)
    Actualfilepath = filepath;
  else {
    std::string username = getenv("USER");
    std::string halfFilePath = filepath.substr(pos + 1);

    Actualfilepath = "/home/" + username + halfFilePath;
  }

  bool exist = std::filesystem::exists(Actualfilepath);
  return exist;
}

void printHeaderDecorator(const std::string &str) {
  std::cout << "====================" << str << "====================" << std::endl;
}

void printfile(const std::string &file) {
  std::ifstream File(file);

  if (File.is_open()) {
#if SIMPLE_MULTI_FILE_DECORATION
    printHeaderDecorator(file);
#endif

    std::cout << File.rdbuf();
    File.close();

#if SIMPLE_MULTI_FILE_DECORATION
    printHeaderDecorator(file);
#endif

    return;
  }

  std::cout << "File opening failed: " << file << std::endl;
}

void checkArgument(size_t argc, char *argv[]) {
  for (size_t i = 1; i < argc; i++) {
    if (isValidFile(argv[i]))
      printfile(argv[i]);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "File name not provided" << std::endl;
    return 1;
  }

  checkArgument(argc, argv);
  return 0;
}
