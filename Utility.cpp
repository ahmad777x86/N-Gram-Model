#include <iostream>
#include <fstream>
#include <filesystem>
#include "Utility.h"
#include "Perplexity.h"
#include "NGramModel.h"

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

void Utility::inference(NGram &model, Perplexity &perplexity, const map<string, int> &str_to_ints, vector<string> &input, const int iterations, const int verbose_mode)
{
    for (int i = 0; i < iterations; i++)
    {
        perplexity.incrementProbabilities(model.predictNextToken(input, str_to_ints, verbose_mode));
        cout << " ";
        if (input.size() > 0)
        {
            rotate(input.begin(), input.begin() + 1, input.end());
            if (input.size() > 0)
                input.pop_back();
            input.push_back(model.displayToken(str_to_ints));
        }
        else
        {
            model.displayToken(str_to_ints);
        }
        perplexity.incrementSeqLength(1);
    }
}
