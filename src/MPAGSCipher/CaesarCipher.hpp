#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <iostream>
#include "CipherMode.hpp"

class Cipher
{
    public:
        explicit Cipher(std::size_t key);
        explicit Cipher(std::string key);
        
        std::string applyCipher(const std::string& inputText, const CipherMode mode);

    private:
        std::size_t key_;


};

#endif