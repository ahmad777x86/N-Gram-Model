#include <iostream>
#include <fstream>
#include <vector>
#include "Tokenizer.h"

using namespace std;

int main()
{
    fstream corpus_file("decision_trees_corpus.txt");
    string corpus;
    if (corpus_file.is_open())
    {
        corpus_file >> corpus;
        cout << corpus << endl;
        corpus_file.close();
        cout << "Retreived successfully" << endl;
    }
    else
    {
        cout << "Failed to retreive text" << endl;
    }
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