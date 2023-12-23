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

            std::ifstream key_file(key_filename);

            if (!key_file)
            {
                std::cout << "ERROR: There is no file: " << key_filename << std::endl;
                successful = false;
            }

            break;

        case Mode::DECRYPT:
            std::cout << "Decryption mode selected." << std::endl;
            break;
            
        case Mode::BREAK: {
            std::cout << "Break encryption mode selected." << std::endl;

            std::ifstream source_file(source_filename);
            if (!source_file) {
                std::cout << "ERROR: Unable to open source file: " << source_filename << std::endl;
                return 0;
            }

            std::ofstream key_file(key_filename);
            if (!key_file)
            {
                std::cout << "ERROR: There is no file: " << key_filename << std::endl;
                successful = false;
            }

            std::deque<int> language_histogram = histogramFromFile(source_file, 1, 0);
            source_file.close();
            rescaleHistogram(language_histogram);

            std::string key;
            std::ifstream input_file(input_filename);
            if (!input_file) {
                std::cout << "ERROR: Unable to open input file: " << input_filename << std::endl;
                return 0;
            }

            std::cout << "Key length tested: ";
            for (int key_length = 1; key_length <= configuration::max_key_length; ++key_length) {
                std::cout << key_length << ' ';
                key = findKey(input_file, language_histogram, key_length);
                if (!key.empty()) {
                    break;
                }
            }
            std::cout << std::endl;

            if (key.empty()) {
                std::cout << "Key recovery failed" << std::endl;
                return 0;
            } else {
                std::cout << "Key recovery successful\n" << std::endl;
                std::ofstream key_file(key_filename);
                if (!key_file) {
                    std::cout << "ERROR: Unable to open key file: " << key_filename << std::endl;
                    return 0;
                }
                key_file << key;
                key_file.close();

                std::ofstream output_file(output_filename);
                if (!output_file) {
                    std::cout << "ERROR: Unable to open output file: " << output_filename << std::endl;
                    return 0;
                }

                decryptFile(input_file, output_file, key);
                input_file.close();
                output_file.close();
            }

            break;
        }

        default:
            std::cout << "No valid mode selected. Please use --en, --de, or --br." << std::endl;
            std::cout << configuration::manual;
            break;
    }

    return 0;
}
