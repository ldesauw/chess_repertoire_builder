#include "string_utils.h"
#include <string>
#include <vector>

/**
 * Split a string using the delimiter c
 *
 * @param s The string to split
 * @param c The delimiter to split on
 * @return A vector of string obtained from spliting s on the delimiter c
 */
std::vector<std::string> split(const std::string &s, char c) {
  std::vector<std::string> result;
  size_t begin = 0;
  while (true) {
    size_t end = s.find_first_of(c, begin);
    result.push_back(s.substr(begin, end - begin));

    if (end == std::string::npos) {
      break;
    }

    begin = end + 1;
  }
  return result;
}
