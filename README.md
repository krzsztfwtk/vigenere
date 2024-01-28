# Vigenère

This repository is dedicated to encrypting/decrypting Vigenère Cipher and breaking it with frequency analysis.

## Project Structure

The Vigenère Cipher Breaker program is located in the `breaker/` directory. Additionally, there are programs available for encrypting files with the Vigenère Cipher in the `encryption/` directory, and for decrypting files encrypted with the Vigenère Cipher when the key is already known in the `decryption/` directory.

If you prefer a more comprehensive solution, there is an All-In-One program located in the `/all_in_one` directory. I recommend using this program as it combines the functionality of the breaker, encryption, and decryption programs.

For detailed instructions on how to use the breaker program or the All-In-One program, please refer to the respective README.md files in the `breaker/` and `/all_in_one` directories.

Running each of the programs without parameters will also display a short information with example on how to use it.

```bash
├── all_in_one
│   ├── config.h
│   ├── functions.cpp
│   ├── functions.h
│   ├── main.cpp
│   ├── Makefile
│   ├── README.md
├── breaker
│   ├── breaker.cpp
│   ├── config.h
│   ├── Doxyfile
│   ├── functions.cpp
│   ├── functions.h
│   ├── Makefile
│   └── README.md
├── decryption
│   ├── decryption.cpp
│   └── Makefile
├── encryption
│   ├── encryption.cpp
│   └── Makefile
├── README.md
├── resources
│   ├── example.key
│   ├── frankenstein.txt
│   ├── hamlet.txt
└── test.sh
```

## Documentation

The program is documented using Doxygen. To generate the documentation, run the following command in the `breaker/` or `/all_in_one` directory:

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

The program can be compiled with `g++` using the `make` system. To compile the program, execute the following commands in the `encryption/` or `decryption/` or `breaker/` directory:

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
