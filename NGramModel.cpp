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

int NGram::getGramSize()
{
    return this->context_size;
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
        k++;
    }
    cout << "Calculated occurences!" << endl;
}

void NGram::estimateProbabilites(vector<string> input_seq, map<string, int> str_to_ints)
{
    vector<int> context_window;
    int max_occ_token_count = 0;
    int total_count = 0;
    float highest_proabability = 0;

    for (int i = 0; i < context_size - 1; i++)
    {
        if (str_to_ints.find(input_seq[i]) != str_to_ints.end())
        {
            context_window.push_back(str_to_ints[input_seq[i]]);
        }
        else
        {
            context_window.push_back(-1);
            output_token = -1;
            return;
        }
    }

    for (auto i : str_to_ints)
    {
        context_window.push_back(i.second);
        if (occurences.find(context_window) != occurences.end())
        {
            total_count += occurences[context_window];
        }
        context_window.pop_back();
    }

    // cout << "Total count: " << total_count << endl;
    for (auto i : str_to_ints)
    {
        context_window.push_back(i.second);
        if (occurences.find(context_window) != occurences.end())
        {
            if (occurences[context_window] > max_occ_token_count)
            {
                output_token = i.second;
                if (total_count != 0)
                    highest_proabability = (float)occurences[context_window] / total_count;
                max_occ_token_count = occurences[context_window];
            }
        }
        context_window.pop_back();
    }
    cout << "\nOutput Token: " << output_token << " | Probability: " << highest_proabability << endl;
}

void NGram::display_occurences_head(map<string, int> str_to_ids)
{
    int c = 0;
    vector<string> ids_to_str = Tokenizer::idsToStrings(str_to_ids);
    for (auto i : occurences)
    {
        if (c == 5)
            break;
        for (int j = 0; j < context_size; j++)
        {
            cout << i.first[j] << " ";
        }
        cout << ": " << i.second << endl;
        c++;
    }
}

string NGram::displayToken(map<string, int> str_to_ids)
{
    vector<string> ids_to_str = Tokenizer::idsToStrings(str_to_ids);
    if (output_token != -1)
    {
        cout << ids_to_str[output_token] << " ";
        return ids_to_str[output_token];
    }
    else
    {
        cout << "<idk>" << " ";
        return "<idk>";
    }
}