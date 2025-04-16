#include <iostream> // for i/o

#include "calculator.hpp"

int main(int argc, char *argv[]) {
    // checks if a filename was passed as a command-line argument
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1; // Exit with error code
    }

    std::string filename = argv[1]; // gets filename from command line

    auto lines = readLinesFromFile(filename); // read lines

    for (const auto &line : lines) { // for each line
        std::cout << "Processing: " << line << "\n"; // show input

        if (!isValidDouble(line)) { // check validity
            std::cout << "Invalid double format. Skipping.\n"; // error
            continue; // skip line
        }

        std::string result = addDoubles(line, "-123.456"); // add to constant
        std::cout << "Result: " << result << "\n"; // show result
    }
    return 0; // end program
}
