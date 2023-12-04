#include <iostream>
#include <fstream>
#include <cctype>

class BinaryConverter {
public:
    BinaryConverter() : totalDecimal(0), badInput(false) {}

    void convertAndPrint(std::istream& input) {
        char ch;
        while (input.get(ch)) {
            if (std::isspace(ch)) {
                continue; // Skip whitespaces
            }
            else if (ch == '0' || ch == '1') {
                processBinaryDigit(ch);
            }
            else {
                std::cout << "Bad digit on input" << std::endl;
                badInput = true;
                // Consume the rest of the invalid input
                while (input.get(ch) && !std::isspace(ch)) {}
            }
        }

        if (!badInput) {
            printResult();
        }
    }

private:
    void processBinaryDigit(char digit) {
        totalDecimal = totalDecimal * 2 + (digit - '0');
        binaryNumber += digit;
    }

    void printResult() const {
        std::cout << "Binary Number\tDecimal Equivalent" << std::endl;
        std::cout << binaryNumber << "\t\t" << totalDecimal << std::endl;
    }

    int totalDecimal;
    std::string binaryNumber;
    bool badInput;
};

int main() {
    std::ifstream inputFile("BinaryIn.dat");
    if (!inputFile) {
        std::cerr << "Error opening BinaryIn.dat" << std::endl;
        return 1;
    }

    BinaryConverter converter;
    converter.convertAndPrint(inputFile);

    return 0;
}
