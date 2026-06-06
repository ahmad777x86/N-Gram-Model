#include <iostream>
#include <fstream>
#include <filesystem>
#include "Utility.h"

using namespace std;

string Utility::readCorpus(string filename)
{
    string corpus;
    char c;
    char *corpus_chars = nullptr;
    int i = 0;

    fstream file(filename);
    if (file.is_open())
    {
        int size = filesystem::file_size(filename);
        corpus_chars = new char[size / sizeof(char)];

        while (!file.eof())
        {
            file.get(c);
            corpus_chars[i] = c;
            i++;
        }

        corpus = corpus_chars;
        delete[] corpus_chars;

        file.close();
        return corpus;
    }
    else
    {
        cout << "File not found!" << endl;
        return string("Corpus placeholder");
    }
}