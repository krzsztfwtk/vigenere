// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <string>

#include "functions.h"
#include "config.h"


int main(int argc, char* argv[]) {
    std::string input_filename{ "" };
    std::string source_filename{ "" };
    std::string key_filename{ "" };
    std::string output_filename{ "" };
    Mode mode = Mode::UNDEFINED;

    //params entry begins

    bool successful = paramsEntry(input_filename, source_filename, 
        key_filename, output_filename, mode, argc, argv);

    std::cout <<
		"\ninput_filename:" << input_filename <<
		"\nsource_filename:" << source_filename <<
		"\nkey_filename:" << key_filename <<
		"\noutput_filename:" << output_filename << "\n\n";

    if (!successful) {
        std::cout << "\nERROR: Params entry failed\n";
        std::cout << configuration::manual;
        return 0;
    }

    std::ifstream input_file(input_filename);

    if (!input_file)
	{
		std::cout << "ERROR: There is no file: " << input_filename << std::endl;
		successful = false;
	}

    if (mode == Mode::BREAK) {
        std::ifstream source_file(source_filename);

        if (!source_file)
        {
            std::cout << "ERROR: There is no file: " << source_filename << std::endl;
            successful = false;
        }
    }

	std::ofstream key_file(key_filename);

	if (!key_file)
	{
		std::cout << "ERROR: There is no file: " << key_filename << std::endl;
		successful = false;
	}

	std::ofstream output_file(output_filename);

	if (!output_file)
	{
		std::cout << "ERROR: There is no file: " << output_filename << std::endl;
		successful = false;
	}

    if (!successful) {
        return 0;
    }

    //params entry ends

    switch (mode) {
        case Mode::ENCRYPT:
            std::cout << "Encryption mode selected." << std::endl;
            break;
        case Mode::DECRYPT:
            std::cout << "Decryption mode selected." << std::endl;
            break;
        case Mode::BREAK:
            std::cout << "Break encryption mode selected." << std::endl;
            break;
        default:
            std::cout << "No valid mode selected. Please use --en, --de, or --br." << std::endl;
            std::cout << configuration::manual;
            break;
    }

    return 0;
}
