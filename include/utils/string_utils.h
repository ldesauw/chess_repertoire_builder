#ifndef STRING_UTILS_H_
#define STRING_UTILS_H_

#include <string>
#include <vector>

/**
 * Split a string using the delimiter c
 *
 * @param s The string to split
 * @param c The delimiter to split on
 * @return A vector of string obtained from spliting s on the delimiter c
 */
std::vector<std::string> split(const std::string &s, char c);
#endif // STRING_UTILS_H_
