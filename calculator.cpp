#include "calculator.hpp"
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>


bool isValidDouble(const std::string &s) {
    int i = 0; // index for parsing
    int tot_length = s.size();

    if (tot_length == 0) return false; // if the string is empty

    if (s[i] == '+' || s[i] == '-') i++; // skips the signs so it follows format

    bool hasDigits = false; // variable to track if int digit exist
    while (i<tot_length && isdigit(s[i])) {
        hasDigits = true; // at least one digit is formed
        i++;
    }

    if (i == tot_length) return hasDigits; // if there are no digits after the decimal but its an int

    if(s[i] != '.') return false; // returns false if there is no decimal point
    i++; // skips the .

    if (i == tot_length) return false; // if there are no digits after the decimal

    bool hasFracDigits = false; // variable to track fractional digits
    while (i < tot_length && isdigit(s[i])) {
        hasFracDigits = true; // if there is at least one fractional digit
        i++;
    }

    return hasDigits && hasFracDigits && i == tot_length;

}

// splits doubles
void splitDouble(const std::string &s, char &sign, std::string &intPart, std::string &fracPart) {
    int i = 0; // variable 
    sign = '+'; // the default sign
    if (s[i] == '+' || s[i] == '-') sign = s[i++]; // stores what the actual sign is

    while (i < s.size() && s[i] !='.') intPart += s[i++]; // retreives int part
    i++; // skips decimal point
    while (i < s.size()) fracPart += s[i++]; // retrieves fractional part
}

// makes it so the 2 parts are of equal length
void padParts(std::string &a, std::string &b, bool leftPad) {
    int len = std::max(a.length(), b.length()); // max length of two
    if (leftPad) {
        a = std::string(len - a.length(), '0') + a; // pad front
        b = std::string(len - b.length(), '0') + b;
    } else {
        a += std::string(len - a.length(), '0'); // pad end
        b += std::string(len - b.length(), '0');
    }
}

// adds the string-formatted doubles
std::string addDoubles(const std::string &s1, const std::string &s2) {
    char sign1, sign2; // stores the signs of each number
    std::string int1, frac1, int2, frac2; // parts of both numbers

    splitDouble(s1, sign1, int1, frac1); // decompose s1
    splitDouble(s2, sign2, int2, frac2); // decompose s2

    padParts(frac1, frac2, false); // equalize frac part
    padParts(int1, int2, true); // equalize int part

    std::string fracResult = ""; // result of frac
    std::string intResult = ""; // result of int

    int carry = 0; // carry for the sum

    // actia; addition
    for (int i = frac1.size() - 1; i >= 0; --i) {
        int sum = (frac1[i] - '0') + (frac2[i] - '0') + carry; // digit sum
        carry = sum / 10; // updates carry
        fracResult += (sum % 10) + '0'; // stores result digit
    }
    std::reverse(fracResult.begin(), fracResult.end()); // correct order

    for (int i = int1.size() - 1; i >= 0; --i) {
        int sum = (int1[i] - '0') + (int2[i] - '0') + carry; // digit sum
        carry = sum / 10; // updates carry
        intResult += (sum % 10) + '0'; // store result digit
    }
    if (carry) intResult += '1'; // final carry
    std::reverse(intResult.begin(), intResult.end()); // correct order

    return intResult + "." + fracResult; // return full result

}

// reads lines from a file
std::vector<std::string> readLinesFromFile(const std::string &filename) {
    std::ifstream file(filename); // open file
    std::string line; // line buffer
    std::vector<std::string> lines; // store valid lines
    while (getline(file, line)) { // read line by line
        if (!line.empty()) lines.push_back(line); // store non-empty
    }
    return lines; // return all lines
}

double parse_number(const std::string &expression) {
    return std::stod(expression); // safely parse
}


