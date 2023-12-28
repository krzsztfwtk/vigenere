#!/bin/bash

# Build encryption module
make -C encryption/

# Encrypt the input file
./encryption/encryption -i resources/frankenstein.txt -o resources/frankenstein.enc -k resources/example.key

# Clean up the encryption module
make -C encryption/ clean

# Build breaker module
make -C breaker/

# Breake cipher and decrypt the encrypted file
./breaker/breaker -i resources/frankenstein.enc -w resources/hamlet.txt -k resources/frankenstein.key -o resources/frankenstein.dec

# Clean up the breaker module
make -C breaker/ clean

# Display the result
echo "If everything works correctly there should have been created files /resources/frankenstein.enc frankenstein.key (here should be \"mysecret\") frankenstein.dec (here should be text exactly the same like in frankenstein.txt but without non-alpha chars)"

