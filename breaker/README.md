# Vigenère Cipher Breaker

This program breaks the Vigenère cipher. It determines the key used to encrypt the text and decrypts it. The program is run from the command line using the following params (the order of params is arbitrary):

- `-i` input file with encrypted text
- `-w` input file with text in the language in which the encrypted text is written
- `-k` output file with the found key
- `-o` output file with decrypted text

Running the program without parameters will display a short information on how to use it.  

**Example:**

To find the key for (`encrypted.txt`), save the key in (`key.txt`), decrypt encrypted text and save the decrypted text to a file (`decrypted.txt`), follow these steps:

1. Ensure that the (`book.txt`) is written in the same language as the original text that was encrypted. It is important that the book is representative of its language, preferably related to a similar field as the encrypted text, and sufficiently large to accurately represent the language.

2. Run the following command in the command line to decrypt the text:

```bash
breaker -i encrypted.txt -w book.txt -k key.txt -o decrypted.txt
```
