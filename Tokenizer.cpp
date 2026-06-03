#include <iostream>
#include <vector>
#include "Tokenizer.h"

using namespace std;

vector<string> Tokenizer::tokenize(string corpus)
{
    vector<string> lookup_table;
    char *word = new char[40];
    int cw = 0;

    for (int i = 0; corpus[i] != '\0'; i++)
    {
        if (corpus[i] != ' ' && corpus[i] != ',' && corpus[i] != '-')
        {
            word[cw] = corpus[i];
            cw++;
        }
        else if (cw >= 1)
        {
            word[cw] = '\0';
            cw = 0;
            lookup_table.push_back(word);
        }
    }
    return lookup_table;
}

void Tokenizer::display_table(vector<string> table)
{
    for (auto i : table)
    {
        cout << i << endl;
    }
}