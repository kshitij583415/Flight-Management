#include <iostream>
#include <fstream>
#include <string>

void printBoxFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int maxLength = 0;

    // Find the maximum line length
    while (std::getline(file, line)) {
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }
    file.clear();
    file.seekg(0);

    // Print the top border
    std::cout << "+" << std::string(maxLength + 2, '-') << "+" << std::endl;

    // Print the content inside the box
    while (std::getline(file, line)) {
        std::cout << "| " << line;
        std::cout << std::string(maxLength - line.length(), ' ') << " |" << std::endl;
    }

    // Print the bottom border
    std::cout << "+" << std::string(maxLength + 2, '-') << "+" << std::endl;

    file.close();
}


