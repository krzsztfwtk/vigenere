# Vigenère Cipher Decryption-Encryption-Breaker

This program encrypts, decrypts and breaks the Vigenère cipher. It determines the key used to encrypt the text and decrypts it. The program is run from the command line using the following params (the order of params is arbitrary):

1. Encrypts text files using the Vigenère method:
- `--en` encryption flag
- `-i` input plaintext file
- `-o` output encrypted text file
- `-k` key file
**for example:** ./main --en -i plaintext -k key -o encrypted

2. Decrypts text files encrypted with the Vigenère method:
- `--de` decryption flag
- `-i` input encrypted text file
- `-o` output plaintext file
- `-k` key file
**for example:** ./main --de -k key -o decrypted -i ciphertext

3.  Breaks text files encrypted with the Vigenère method:
- `--br` cipher breaking flag
- `-w` input file Ensure that the (book.txt) is written in the same language as the original text that was encrypted. It is important that the book is representative of its language, preferably related to a similar field as the encrypted text, and sufficiently large to accurately represent the language.
- `-i` input encrypted text file
- `-o` output plaintext file
**for example:** ./main --br -i ciphertext -w book.txt -k key.txt -o decrypted


Running the program without parameters will display a short information on how to use it.  


## Issues

If something is not clear or you have any issues with the program, please feel free to open an issue on GitHub. I appreciate your feedback and will do my best to resolve any issues as quickly as possible.
