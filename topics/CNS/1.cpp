#include <bits/stdc++.h>

using namespace std;

/**
 * PolyAlphabetic Cipher
 */


int char_to_num(char c)
{
    return c - 'a';
}
void tolower(string &s)
{
    for (auto &c : s)
    {
        c = tolower(c);
    }
}

string encrypt(string plaintext, string key)
{
    tolower(plaintext);
    tolower(key);

    string ciphertext;

    for (int i = 0; plaintext.size() != key.size(); i++)
        key.push_back(key[i]);

    for (int i = 0; i < plaintext.size(); i++)
    {
        if (plaintext[i] == ' ')
        {
            ciphertext.push_back(' ');
            continue;
        }
        int c = (char_to_num(plaintext[i]) + char_to_num(key[i])) % 26;
        ciphertext.push_back(c + 'a');
    }

    return ciphertext;
}

string decrypt(string ciphertext, string key)
{

    tolower(ciphertext);
    tolower(key);

    string plaintext;

    for (int i = 0; ciphertext.size() != key.size(); i++)
        key.push_back(key[i]);

    for (int i = 0; i < ciphertext.size(); i++)
    {
        if (ciphertext[i] == ' ')
        {
            plaintext.push_back(' ');
            continue;
        }
        int c = (char_to_num(ciphertext[i]) - char_to_num(key[i]) + 26) % 26;
        plaintext.push_back(c + 'a');
    }

    return plaintext;
}

int main()
{
    string plaintext = "attack on titaN";
    string key = "lemon";
    string encryptedText = encrypt(plaintext, key);
    string decryptedText = decrypt(encryptedText, key);

    cout << plaintext << endl
         << encryptedText << endl
         << decryptedText << endl;
    return 0;
}