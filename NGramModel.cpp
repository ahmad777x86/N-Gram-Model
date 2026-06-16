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
    vector<int> context_window;
    int k = 0;
    while (k + context_size < corpus.size())
    {
        for (int i = 0; i < this->context_size; i++)
        {
            context_window.push_back(lookup_table[corpus[k + i]]);
            k++;
        }

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

void NGram::display_occurences(map<string, int> str_to_ids)
{
    vector<string> ids_to_str = Tokenizer::idsToStrings(str_to_ids);
    for (auto i : occurences)
    {
        cout << ids_to_str[i.first[0]] << " " << ids_to_str[i.first[1]] << ": " << i.second << endl;
    }
}