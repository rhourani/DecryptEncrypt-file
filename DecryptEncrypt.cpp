#include <iostream>
#include <fstream>

void xor_cypher(const std::string& input_file, const std::string& output_file, char key) {
    std::ifstream input(input_file, std::ios::binary);
    std::ofstream output(output_file, std::ios::binary);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    char buffer;
    while (input.get(buffer)) {
        char encrypted_char = buffer ^ key;
        output.put(encrypted_char);
    }

    input.close();
    output.close();
}

int main() {
    std::string input_file = "C:\\Users\\Admin\\source\\repos\\Exercise3\\passwords.txt";
    std::string encrypted_file = "C:\\Users\\Admin\\source\\repos\\Exercise3\\encrypted.txt";
    std::string decrypted_file = "C:\\Users\\Admin\\source\\repos\\Exercise3\\decrypted.txt";
    char key = 'x';  // Choose any char as a key

    // Encrypt the file
    xor_cypher(input_file, encrypted_file, key);

    // Decrypt the file
    xor_cypher(encrypted_file, decrypted_file, key);

    return 0;
}
