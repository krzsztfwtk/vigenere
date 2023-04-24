# Vigenère Cipher Breaker

This program breaks the Vigenère cipher. It determines the key used to encrypt the text and decrypts it. The program is run from the command line using the following params (the order of params is arbitrary):

- `-i` input file with encrypted text
- `-w` input file with text in the language in which the encrypted text is written
- `-k` output file with the found key
- `-o` output file with decrypted text

Running the program without parameters will display a short information on how to use it.  

Vigenère Cipher Breaker is in the `decryption/` directory. There is also a program to encrypt with Vigenère Cipher in the `encryption/` directory.

## File Structure

```bash
vigenere/
│
├── decryption/
│   ├── config.h
│   ├── Doxyfile
│   ├── functions.cpp
│   ├── functions.h
│   ├── makefile
│   └── vigenere.cpp
│
├── encryption/
│   ├── encryption.cpp
│   └── makefile
│
├── resources/
│   ├── frankenstein.txt
│   └── hamlet.txt
│
└── test.sh
```

## Documentation

The program is documented using Doxygen. To generate the documentation, run the following command in the `decryption/` directory:

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

The program can be compiled with `g++` using the `make` system. To compile the program, execute the following commands in the `encryption/` or `decryption/` directory:

```bash
make
make clean
```

This will compile the program and create an executable file. The program can be run using the command-line params described above.
