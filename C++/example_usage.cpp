#include <iostream>
#include "HollosFileEncoder.hh"

int main() {
    // Example usage of encoding
    std::string originalData = "Hello, World!";
    std::string encodedData = encode(originalData);

    std::cout << "Original Data: " << originalData << std::endl;
    std::cout << "Encoded Data:  " << encodedData << std::endl;

    // Example usage of decoding
    std::string decodedData = decode(encodedData);

    std::cout << "Decoded Data:  " << decodedData << std::endl;

    return 0;
}