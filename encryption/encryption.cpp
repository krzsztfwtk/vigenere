#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void encrypt_file(std::ifstream& input_file, std::ofstream& output_file, std::ifstream& key_file)
{
    std::string key;
    key = key_file.get(); 
    const unsigned int key_length = key.length();
    std::string cipher_text = "";
    unsigned int c = 0;
    std::string line = "";
    std::stringstream ss;
    std::stringstream result;


    while (std::getline(input_file, line))
    {
        ss << line;
    }

    char z;

    while(ss >> z)
    {
        if ((int)z < 0)
        {
            continue;
        }

        if (isalpha(z)) //checks if char is in alphabet (no need to encrypt non-alpha chars)
        {
            z = tolower(z);
            unsigned int shift = (int)tolower(key[c % key_length]) - 97;

            for (int j = 0; j < shift; j++)
            {
                if (z == 'z')
                {
                    z -= 25;
                }

                else
                {
                    z++;
                }
            }

            result << z;
            c++;
        }
    }

    while (result >> line)
    {
        output_file << line;
    }
}


int main(int n, char* argv[])
{
    const std::string manual =
        "Incorrect use of the program.\n\n"
        "Encrypts with the Vigenere cipher\n\n"
        "-i input file with text\n"
        "-o output file with encrypted text\n"
        "-k input string with key\n\n"
        "example: encryption -i text.txt -o encrypted_text.txt -k secretkey\n";

    std::string key = "";

    std::string input_filename = "";
    std::string key_filename = "";
    std::string output_filename = "";

    //params entry begins
    {
        std::string arg = "";

        for (int i = 1; i < n; i++)
        {
            arg = argv[i];

            if (arg == "-i")
            {
                input_filename = argv[i + 1];
            }

            else if (arg == "-o")
            {
                output_filename = argv[i + 1];
            }

            else if (arg == "-k")
            {
                key_filename = argv[i + 1];
            }
        }

        if (
            input_filename == "" ||
            output_filename == ""
            )
        {
            std::cout << std::endl << manual << std::endl;
            return 0;
        }
    }
    //params entry ends

    std::ifstream input_file(input_filename);
    std::ofstream output_file(output_filename);
    std::ifstream key_file(key_filename);

    encrypt_file(input_file, output_file, key_file);

    input_file.close();
    output_file.close();
}
