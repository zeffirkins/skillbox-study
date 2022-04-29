#include <iostream>

int alphabet = 26;

char shift(char sign, int key, char startSymbol){
    char endSymbol = startSymbol + alphabet;
    if (sign + key >= endSymbol)
        return (sign + key - endSymbol + startSymbol);
    else
    if (sign + key < startSymbol)
        return (sign + key + endSymbol - startSymbol);
    else
        return (sign + key);
}


std::string encrypt_caesar(std::string text, int key)
{
    for (int i = 0; i < text.length(); ++i)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = shift(text[i], key, 'A');
        else
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = shift(text[i], key, 'a');
    }
    return text;
}


std::string decrypt_caesar(std::string text, int key)
{
    encrypt_caesar(text, -key);
    return text;
}


int main() {
    std::cout << "Input text for encrypt:";
    std::string text;
    std::getline(std::cin, text);

    int key;
    do
    {
        std::cout << "Input key for shift (0 - 26):";
        std::cin >> key;
    } while (key < 0 || key > alphabet);

    std::cout << "Encrypted: " << encrypt_caesar(text, key) << "\n";
    std::cout << "Decrypted: " << decrypt_caesar(text, key) << "\n";

}