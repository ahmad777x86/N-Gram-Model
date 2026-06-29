#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include "Tokenizer.h"

using namespace std;

vector<string> Tokenizer::tokenize(string corpus)
{
    vector<string> lookup_table;
    char *word = new char[40];
    int cw = 0;

    for (int i = 0; corpus[i] != '\0'; i++)
    {
        if (!isspace(corpus[i]))
        {
            if (!ispunct(corpus[i]))
            {
                word[cw] = corpus[i];
                cw++;
            }
            else if (cw >= 1)
            {
                word[cw] = '\0';
                cw = 0;
                lookup_table.push_back(word);
                word[cw] = corpus[i];
                word[++cw] = '\0';
                lookup_table.push_back(word);
                cw = 0;
            }
            else
            {
                word[cw] = corpus[i];
                word[++cw] = '\0';
                cw = 0;
                lookup_table.push_back(word);
            }
        }
        else if (cw >= 1)
        {
            word[cw] = '\0';
            cw = 0;
            lookup_table.push_back(word);
        }
    }
    if (cw >= 1)
    {
        word[cw] = '\0';
        cw = 0;
        lookup_table.push_back(word);
    }
    if (lookup_table.size() == 0)
    {
        word[cw] = '\0';
        cw = 0;
        lookup_table.push_back(word);
    }
    delete[] word;
    return lookup_table;
}

void Tokenizer::display_table(vector<string> table)
{
    cout << "Tokenized corpus: " << endl;
    for (auto i : table)
    {
        cout << i << endl;
    }
    cout << endl;
}

vector<string> Tokenizer::idsToStrings(map<string, int> string_to_ids)
{
    vector<string> ids_to_string;
    string *ids_to_string_arr = new string[string_to_ids.size()];
    for (auto i : string_to_ids)
    {
        ids_to_string_arr[i.second] = i.first;
    }
    for (int i = 0; i < string_to_ids.size(); i++)
    {
        ids_to_string.push_back(ids_to_string_arr[i]);
    }
    delete[] ids_to_string_arr;
    return ids_to_string;
}

map<string, int> Tokenizer::stringToIds(vector<string> corpus)
{
    map<string, int> unique_table;
    int c = 0;
    for (auto i : corpus)
    {
        if (unique_table.find(i) == unique_table.end())
        {
            unique_table[i] = c;
            c++;
        }
    }
    return unique_table;
}