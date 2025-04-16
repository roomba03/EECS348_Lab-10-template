#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>
#include <vector>

// this function should expect that `expression` has already been
// validated and thus throw no exceptions
double parse_number(const std::string &expression);

// checks if a string represents a valid double
bool isValidDouble(const std::string &s);

// adds 2 valid double-format strings and returns the result as a string
std::string addDoubles(const std::string &s1, const std::string &s2);

// reads file 
std::vector<std::string> readLinesFromFile(const std::string &filename);


#endif // __CALCULATOR_HPP
