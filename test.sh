#!/bin/bash

# Build encryption module
make -C encryption/

# Encrypt the input file
./encryption/encryption -i resources/frankenstein.txt -o resources/frankenstein.enc -k "supersecret"

# Clean up the encryption module
make -C encryption/ clean

# Build decryption module
make -C decryption/

# Decrypt the encrypted file
./decryption/vigenere -i resources/frankenstein.enc -w resources/hamlet.txt -k resources/frankenstein.key -o resources/frankenstein.dec

# Clean up the decryption module
make -C decryption/ clean

# Display the result
echo "If everything works correctly there should have been created files /resources/frankenstein.enc frankenstein.key (here should be \"supersecret\") frankenstein.dec (here should be text exactly the same like in frankenstein.txt but without non-alpha chars)"

