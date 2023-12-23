// vigenere.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <string>

#include "functions.h"
#include "config.h"

int main(int n, char* argv[])
{
	std::string input_filename{ "" };
	std::string source_filename{ "" };
	std::string key_filename{ "" };
	std::string output_filename{ "" };


	//params entry begins

	bool successful = paramsEntry(input_filename, source_filename, key_filename, output_filename, n, argv);

	std::cout <<
		"\ninput_filename:" << input_filename <<
		"\nsource_filename:" << source_filename <<
		"\nkey_filename:" << key_filename <<
		"\noutput_filename:" << output_filename << "\n\n";

	if (successful == false)
	{
		std::cout << "\nERROR: Params entry failed\n";
		std::cout << configuration::manual;
		return 0;
	}

	std::ifstream input_file(input_filename);

	if (!input_file)
	{
		std::cout << "ERROR: There is no file: " << input_filename << std::endl;
		std::cout << configuration::manual;
		return 0;
	}

	std::ifstream source_file(source_filename);

	if (!source_file)
	{
		std::cout << "ERROR: There is no file: " << source_filename << std::endl;
		std::cout << configuration::manual;
		return 0;
	}

	std::ofstream key_file(key_filename);

	if (!source_file)
	{
		std::cout << "ERROR: There is no file: " << key_filename << std::endl;
		std::cout << configuration::manual;
		return 0;
	}

	std::ofstream output_file(output_filename);

	if (!output_file)
	{
		std::cout << "ERROR: There is no file: " << output_filename << std::endl;
		std::cout << configuration::manual;
		return 0;
	}

	//params entry ends

	std::deque<int> language_histogram = histogramFromFile(source_file, 1, 0);
	source_file.close();
	rescaleHistogram(language_histogram);

	std::string key = "";


	std::cout << "key lenght tested: ";

	for (int key_length = 1; key_length <= configuration::max_key_length; key_length++)
	{
	
		std::cout << key_length << ' ';
		
		key = findKey(input_file, language_histogram, key_length);

		if (not key.empty())
		{
			break;
		}
	}

	std::cout << std::endl;

	if (key.empty())
	{
		std::cout << "key recovery failed";
		return 0;
	}

	else
	{
		std::cout << "key recovery successful\n\n";
		key_file << key;
	}

	key_file.close();

	decryptFile(input_file, output_file, key);

	input_file.close();
	output_file.close();
}
