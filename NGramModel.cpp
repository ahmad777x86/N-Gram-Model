#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "NGramModel.h"
#include "Tokenizer.h"

using namespace std;

NGram::NGram(int gram)
{
    this->context_size = gram;
}

void NGram::calculateOccurences(vector<string> corpus, map<string, int> lookup_table)
{
    int i = 0;
    int j = 1;
    vector<int> context_window;

    while (j < corpus.size() - 1)
    {
        context_window.push_back(lookup_table[corpus[i++]]);
        context_window.push_back(lookup_table[corpus[j++]]);

        if (this->occurences.find(context_window) == occurences.end())
        {
            occurences[context_window] = 1;
        }
        else
        {
            occurences[context_window]++;
        }
        context_window.clear();
    }
    cout << "Calculated occurences!" << endl;
}

void NGram::display_occurences()
{
    for (auto i : occurences)
    {
        cout << i.first[0] << " " << i.first[1] << ": " << i.second << endl;
    }
}