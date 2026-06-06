#include <iostream>
#include <fstream>
#include <vector>
#include "Tokenizer.h"
#include "Utility.h"

using namespace std;

int main()
{
    string corpus = Utility::readCorpus("decision_trees_corpus.txt");

    vector<string> table = Tokenizer::tokenize(corpus);
    Tokenizer::display_table(table);

    string input;
    getline(cin, input);

    vector<string> input_table = Tokenizer::tokenize(input);
    Tokenizer::display_table(input_table);

    string window = input_table.back();

    cout << input;
    for (int i = 0; i < 5; i++)
    {
        cout << table.at(rand() % table.size()) << " ";
    }
    return 0;
}