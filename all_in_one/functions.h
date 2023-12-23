/** @file */

//FUNCTIONS HEADERS

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <deque>
#include <fstream>
#include <string>

#include "config.h"


Mode determineMode(const std::string& flag);

/// @brief Parses command line arguments to determine the operation mode and assigns parameters 
///        to appropriate variables. Also validates the presence of required arguments based on the selected mode.
/// @param[out] input_filename Name of the input file; for encrypted text in ENCRYPT/DECRYPT modes, 
///                            and for text in the language of the encrypted text in BREAK mode.
/// @param[out] source_filename Name of the input file with text in the language of the encrypted text, 
///                             used only in BREAK mode.
/// @param[out] key_filename Name of the file where the key is stored; used for storing the found key in BREAK mode, 
///                          and for reading the key in ENCRYPT/DECRYPT modes.
/// @param[out] output_filename Name of the output file; for decrypted text in DECRYPT/BREAK modes, 
///                             and for encrypted text in ENCRYPT mode.
/// @param[out] mode The operation mode of the program determined from the command line arguments (ENCRYPT, DECRYPT, BREAK).
/// @param[in] n Number of command line arguments passed to the main function.
/// @param[in] argv Pointer to an array of command line arguments.
/// @return True if the necessary parameters are provided and valid for the selected mode, otherwise false.
bool paramsEntry(
	std::string& input_filename,
	std::string& source_filename,
	std::string& key_filename,
	std::string& output_filename,
	Mode& mode,
	int argc, char* argv[]	
);




/// @brief Initiates empty histogram
/// @return Deque full of zeros with alphabet length size
std::deque<int> initiateEmptyHistogram();


/// @brief Finds max value in the deque
/// @param h The deque to search
/// @return Max value in the deque
int maxValueInHistogram(const std::deque<int>& h);



/// @brief Creates a histogram of the frequency of letters in a text file
/// @param file Input file stream of text file
/// @param gap A gap between the letters that are counted
/// @param starting_index Index of the letter in file from which it starts counting
/// @return A deque being histogram of the frequency of letters
std::deque<int> histogramFromFile(std::ifstream& file,
	const int gap, const int starting_index);


/// @brief Shifts deque one index to the right, last element becomes first element
/// @param h A deque to be shifted
void shiftHistogram(std::deque<int>& h);

/// @brief Rescales values in deque, max in rescaled deque value is set to configuration::max_value_in_rescaled_histogram
/// @param h Deque to be rescaled
void rescaleHistogram(std::deque<int>& h);

/// @brief Checks if the histograms are close enough to each other to be considered as histograms of letter frequencies in texts of the same language
/// @param h1 First histogram - must be rescaled before
/// @param h2 Second histogram - must be rescaled before
/// @return false if histograms are not the same language, true if they are
bool areHistogramsTheSameLanguage(const std::deque<int>& h1, const std::deque<int>& h2);

/// @brief Finds a letter in the key of the given index
/// @param encrypted_file File with encrypted text
/// @param language_histogram Rescaled histogram of letter frequencies in language of encrypted text
/// @param key_length Length of key
/// @param letter_index Index of letter in key which is being attempted to recover
/// @return Letter in the key of the given index if letter recovery successful, '\0' if letter recover failed
char findLetterInKey(std::ifstream& encrypted_file, const std::deque<int>& language_histogram,
	const int key_length, const int letter_index);

/// @brief Finds a key used to encrypt encrypted text
/// @param encrypted_file File with encrypted text
/// @param language_histogram Rescaled histogram of letter frequencies in language of encrypted text - it MUST be rescaled before
/// @param key_length Length of key
/// @return Key if key recovery successful, "" if key recovery failed
std::string findKey(std::ifstream& encrypted_file,
	const std::deque<int>& language_histogram, const int key_length);

/// @brief Decrypts file encrypted with Vigenere cipher using given key
/// @param[in] encrypted_file 
/// @param[out] output_file 
/// @param[in] key 
void decryptFile(std::ifstream& encrypted_file,
	std::ofstream& output_file, const std::string& key);

#endif