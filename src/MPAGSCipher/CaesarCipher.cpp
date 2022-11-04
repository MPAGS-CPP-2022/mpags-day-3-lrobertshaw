#include "CaesarCipher.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "CipherMode.hpp"

Cipher::Cipher(std::size_t key) : key_{key}
{
    //
}

Cipher::Cipher(std::string key) : key_{std::stoul(key)}
{
    //
}

std::string Cipher::applyCipher(const std::string& inputText, const CipherMode mode)
{    

    // Create the output string
    std::string outputText;

    // Create the alphabet container
    const std::vector<char> alphabet = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const std::size_t alphabetSize{alphabet.size()};

    // Make sure that the key is in the range 0 - 25
    const std::size_t truncatedKey{key_ % alphabetSize};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for (size_t i{0}; i < alphabetSize; ++i) {
            if (origChar == alphabet[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                switch(mode){
                    case CipherMode::Encrypt:
                        processedChar = alphabet[(i + truncatedKey) % alphabetSize];
                        break;
                    case CipherMode::Decrypt:
                        processedChar = alphabet[(i + alphabetSize - truncatedKey) % alphabetSize];
                        break;
                }
                
                // if (encrypt) {
                //     processedChar = alphabet[(i + truncatedKey) % alphabetSize];
                // } else {
                //     processedChar = alphabet[(i + alphabetSize - truncatedKey) %
                //                              alphabetSize];
                // }
                break;
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }

    return outputText;
}