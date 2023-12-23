/** @file*/


#ifndef CONFIG_H
#define CONFIG_H

#include <string>

namespace configuration
{
	const std::string alphabet_lowercase = "abcdefghijklmnopqrstuvwxyz";
	const int alphabet_length = 'z' - 'a' + 1;

	const int max_value_in_rescaled_histogram = 10000;
	const double max_deviation_for_the_same_language = 1500;

	const int max_key_length = 5000;
	const std::string manual = 
		"\nUsage of the program:\n\n"
		"To encrypt a text file using the Vigenère cipher:\n"
		"--en -i <input file> -k <key file> -o <output file>\n"
		"  --en: flag for encryption mode\n"
		"  -i: input file with plain text\n"
		"  -k: input file with the key\n"
		"  -o: output file for the encrypted text\n"
		"  Example: ./program --en -i plain.txt -k key.txt -o encrypted.txt\n\n"
		"To decrypt a text file encrypted with the Vigenère cipher:\n"
		"--de -i <input file> -k <key file> -o <output file>\n"
		"  --de: flag for decryption mode\n"
		"  -i: input file with encrypted text\n"
		"  -k: input file with the key\n"
		"  -o: output file for the decrypted text\n"
		"  Example: ./program --de -i encrypted.txt -k key.txt -o decrypted.txt\n\n"
		"To break the Vigenère cipher:\n"
		"--br -i <input file> -w <source file> -k <output key file> -o <output file>\n"
		"  --br: flag for breaking the cipher\n"
		"  -i: input file with encrypted text\n"
		"  -w: input file with text in the language of the encrypted text\n"
		"  -k: output file for the found key\n"
		"  -o: output file for the decrypted text\n"
		"  Example: ./program --br -i encrypted.txt -w book.txt -k key.txt -o decrypted.txt\n\n";

}

enum class Mode {
    ENCRYPT,
    DECRYPT,
    BREAK,
    UNDEFINED
};

#endif
