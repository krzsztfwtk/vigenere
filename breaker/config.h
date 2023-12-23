/** @file*/


#ifndef CONFIG_H
#define CONFIG_H

#include <string>

namespace configuration
{
	   const std::string alphabet_lowercase = "abcdefghijklmnopqrstuvwxyz";
	   const int alphabet_length = 'z' - 'a' + 1;

	   const int max_value_in_rescaled_histogram = 10000;
	   const double max_deviation_for_the_same_language = 2800;

	   const int max_key_length = 5000;
	   const std::string manual =
		   "\nIncorrect use of the program.\n\n"
		   "Breaks the Vigenere cipher\n\n"
		   "-i input file with encrypted text\n"
		   "-w input file with text in the language of the encrypted text\n"
		   "-k output file with the found key\n"
		   "-o output file with decrypted text\n\n"
		   "example: breaker -i encrypted.txt "
		   "-w book.txt -k key.txt -o decrypted.txt\n\n";
}

#endif
