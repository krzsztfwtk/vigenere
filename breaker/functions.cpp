//FUNCTIONS DECLARATIONS

#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <fstream>
#include <math.h>

#include "functions.h"
#include "config.h"


bool paramsEntry(std::string& input_filename, std::string& source_filename,
	std::string& key_filename, std::string& output_filename, const int n, char* argv[])
{
	std::string arg;

	for (int i = 1; i < n - 1; i++)
	{
		arg = argv[i];

		if (arg == "-i")
		{
			input_filename = argv[i + 1];
		}

		else if (arg == "-w")
		{
			source_filename = argv[i + 1];
		}

		else if (arg == "-k")
		{
			key_filename = argv[i + 1];
		}

		else if (arg == "-o")
		{
			output_filename = argv[i + 1];
		}
	}

	if (
		input_filename == "" ||
		source_filename == "" ||
		key_filename == "" ||
		output_filename == ""
		)
	{
		return false;
	}

	return true;
}

std::deque<int> initiateEmptyHistogram()
{
	std::deque<int> empty_histogram;

	for (int i = 0; i < configuration::alphabet_length; i++)
	{
		empty_histogram.push_back(0);
	}

	return empty_histogram;
}

int maxValueInHistogram(const std::deque<int>& h)
{
	int max = 0;

	for (int i : h)
	{
		if (i > max)
		{
			max = i;
		}
	}

	return max;
}

std::deque<int> histogramFromFile(std::ifstream& file, const int gap, const int starting_index)
{
	std::deque<int> histogram = initiateEmptyHistogram();
	std::stringstream file_content;
	std::string line;

	file.clear();
	file.seekg(starting_index);

	long int index = 0;

	while (std::getline(file, line))
	{
		for (char c : line)
		{
			if (c < 0) //sometimes there are such chars: (int)c < 0, then isaplha crashes
			{
				continue;
			}

			if (isalpha(c))
			{
				c = tolower(c);

				if (index % gap == 0)
				{
					histogram[(int)c - (int)'a']++;
				}

				index++;
			}
		}
	}
	return histogram;
}

/*
void printHistogram (const std::deque<int> &  h, const int size)
{
	int max = maxValueInHistogram(h);
	int count = 0;

	for (const int i : h)
	{
		std::cout << alphabet_lowercase[count];

		for (int j = 0; j < ((i * size) / max); j++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;

		count++;
	}
}
*/

/*
struct histogram
{
	std::deque<int> znaki;
	int przesuniecie;
	static const int max_value_in_rescaled_histogram = 20000;
};
*/

void shiftHistogram(std::deque<int>& h)
{
	h.push_back(h.front());
	h.pop_front();
}

void rescaleHistogram(std::deque<int>& h)
{
	int max = maxValueInHistogram(h);

	for (int& i : h)
	{
		size_t t = (size_t)i;
		t *= configuration::max_value_in_rescaled_histogram;
		t /= max;

		i = (int)t;
	}
}

bool areHistogramsTheSameLanguage(const std::deque<int>& h1, const std::deque<int>& h2)
//histograms MUST be rescaled before
{
	double sum_of_squares = 0;

	for (int i = 0; i < configuration::alphabet_length; i++)
	{
		double x = (h1[i] - h2[i]);
		sum_of_squares += x * x;
	}

	double deviation = sqrt(sum_of_squares / configuration::alphabet_length);
	//std::cout << deviation << std::endl;
	//std::cout << (deviation < configuration::max_deviation_for_the_same_language) << std::endl;
	if (deviation < configuration::max_deviation_for_the_same_language)
	{
		return true;
	}

	return false;
}

char findLetterInKey(std::ifstream& encrypted_file, const std::deque<int>& language_histogram,
	const int key_length, const int letter_index)
{
	std::deque<int> everyNthLetterHistogram =
		histogramFromFile(encrypted_file, key_length, letter_index);

	rescaleHistogram(everyNthLetterHistogram);

	if (areHistogramsTheSameLanguage(everyNthLetterHistogram, language_histogram))
	{
		std::cout << 'a';
		return 'a';
	}

	for (int i = 1; i < configuration::alphabet_length; i++)
	{
		shiftHistogram(everyNthLetterHistogram);

		if (areHistogramsTheSameLanguage(everyNthLetterHistogram, language_histogram))
		{
			std::cout << configuration::alphabet_lowercase[i];
			return configuration::alphabet_lowercase[i];
		}
	}

	return '\0'; //cannot find accurate letter  
}

std::string findKey(std::ifstream& encrypted_file,
	const std::deque<int>& language_histogram, const int key_length)
{
	std::string key = "";

	for (int i = 0; i < key_length; i++)
	{
		char letter = findLetterInKey(encrypted_file, language_histogram, key_length, i);

		if (letter == '\0')
		{
			return ""; //cannot find key
		}


		key += letter;
	}



	return key;
}


void decryptFile(std::ifstream& encrypted_file,
	std::ofstream& output_file, const std::string& key)
{
	encrypted_file.clear();
	encrypted_file.seekg(0);

	std::string line;
	int count = 0;
	int key_length = key.length();

	while (std::getline(encrypted_file, line))
	{
		for (char& c : line)
		{
			if ((int)c < 0)
			{
				continue;
			}

			if (isalpha(c)) //checks if char is in alphabet (no need to decrypt non-alpha chars)
			{
				c = tolower(c);
				unsigned int shift = (int)tolower(key[count % key_length]) - int('a'); // magic numbers :-)

				c -= shift;

				if ((int)c < (int)'a')
				{
					c += configuration::alphabet_length;  // magic numbers :-)
				}

				count++;
			}
		}

		output_file << line;
	}
}