#include <Logger.h>

#include <iostream>

void log(const std::string& log_str) {
  std::cout << log_str << std::endl;
}

std::string double_string(const std::string& input_str) {
  return input_str + input_str;
}