# Vigenère Cipher Decryption-Encryption-Breaker

This program encrypts, decrypts and breaks the Vigenère cipher. It determines the key used to encrypt the text and decrypts it. The program is run from the command line using the following params (the order of params is arbitrary):


- git s encrypts text files using the Vigenère method:
The program is executed from the command line using the following switches (the order of switches is arbitrary):
- `--en` encryption flag
- `-i` input plaintext file
- `-o` output encrypted text file
- `-k` key file
**for example:** ./main --en -i plaintext -k key -o encrypted

- decrypts text files encrypted with the Vigenère method:
- `--de` decryption flag
- `-i` input encrypted text file
- `-o` output plaintext file
- `-k` key file
**for example:** ./main --de -k key -o decrypted -i ciphertext

-  breaks text files encrypted with the Vigenère method:
- `--br` cipher breaking flag
- `-w` input file Ensure that the (book.txt) is written in the same language as the original text that was encrypted. It is important that the book is representative of its language, preferably related to a similar field as the encrypted text, and sufficiently large to accurately represent the language.
- `-i` input encrypted text file
- `-o` output plaintext file
**for example:** ./main --br -i ciphertext -w book.txt -k key.txt -o decrypted


Running the program without parameters will display a short information on how to use it.  

**Example:**

To find the key for (`encrypted.txt`), save the key in (`key.txt`), decrypt encrypted text and save the decrypted text to a file (`decrypted.txt`), follow these steps:

1. Ensure that the (`book.txt`) is written in the same language as the original text that was encrypted. It is important that the book is representative of its language, preferably related to a similar field as the encrypted text, and sufficiently large to accurately represent the language.

2. Run the following command in the command line to decrypt the text:

```bash
breaker -i encrypted.txt -w book.txt -k key.txt -o decrypted.txt
```

## File Structure

The Vigenère Cipher Breaker program is located in the `breaker/` directory. Additionally, there are programs available for encrypting files with the Vigenère Cipher in the `encryption/` directory, and for decrypting files encrypted with the Vigenère Cipher when the key is already known in the `decryption/` directory.

Running the encryption or decryption program without parameters will also display a short information with example on how to use it.

```bash
├── breaker
│   ├── breaker.cpp
│   ├── config.h
│   ├── Doxyfile
│   ├── functions.cpp
│   ├── functions.h
│   └── makefile
├── decryption
│   ├── decryption.cpp
│   └── makefile
├── encryption
│   ├── encryption.cpp
│   └── makefile
├── README.md
├── resources
│   ├── frankenstein.txt
│   └── hamlet.txt
└── test.sh
```

## Documentation

The program is documented using Doxygen. To generate the documentation, run the following command in the `all_in_one/` directory:

```bash
doxygen Doxyfile
```

This will create an HTML documentation in the `/html` and LaTeX code in the `/latex` directory. In order to generate PDF documentation go to `/latex` and execute:

```bash
make
```

## Testing

A test script (`test.sh`) is provided to test the program with the included sample files (`frankenstein.txt` and `hamlet.txt`). The script runs the program with relevant options. To run the test script, execute the following command:

```bash
chmod +x test.sh 
./test.sh
```

The script will print an appropriate message.

## Compiling

The program can be compiled with `g++` using the `make` system. To compile the program, execute the following commands in the `all_in_one` directory:

```bash
make
```

This will compile the program and create an executable file. The program can be run using the command-line params described above.

To delete executable file you can run:

```bash
make clean
```

## Issues

If something is not clear or you have any issues with the program, please feel free to open an issue on GitHub. I appreciate your feedback and will do my best to resolve any issues as quickly as possible.
