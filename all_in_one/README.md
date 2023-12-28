# Vigenère Cipher Toolkit

This program encrypts, decrypts and breaks the Vigenère cipher. It determines the key used to encrypt the text and decrypts it. The program is run from the command line using the following params (the order of params is arbitrary):

1. Encrypts text files with the Vigenère cipher:
    - `--en` encryption flag
    - `-i` input file with text
    - `-o` output file with encrypted text
    - `-k` input file with key
    
    ```bash
    # example:
    ./main --en -i text.txt -o encrypted_text.txt -k secret.key
    ```

2. Decrypts text files encrypted with the Vigenère cipher:
    - `--de` decryption flag
    - `-i` input file with encrypted text
    - `-o` output file with decrypted text
    - `-k` input file with key
    
    ```bash
    # example:
    ./main --de -i encrypted_text.txt -o text.txt -k secret.key
    ```

3. Breaks text files encrypted with the Vigenère cipher (determines the key used to encrypt the text and decrypts it):
    - `--br` cipher breaking flag
    - `-i` input file with encrypted text
    - `-w` input file with text in the language in which the encrypted text is written
    - `-k` output file with the found key
    - `-o` output file with decrypted text

    ```bash
    # example:
    ./main --br -i encrypted.txt -w book.txt -k key.txt -o decrypted.txt
    ```

Running the program without parameters will display a short information on how to use it.  
