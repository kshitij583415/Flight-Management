#include <iostream>
#include <string>

void printBoxWithLabel(const std::string &label)
{
    int labelLength = label.length();
    int boxWidth = labelLength + 4; // Account for padding and borders

    // Print top border
    std::cout << std::string(boxWidth, '-') << std::endl;

    // Print label with padding and borders
    std::cout << "| " << label << " |" << std::endl;

    // Print bottom border
    std::cout << std::string(boxWidth, '-') << std::endl;
}

int main()
{
    std::string label = "Hello, World!";
    printBoxWithLabel(label);

    return 0;
}
