#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Tokenizer.h"
#include "Utility.h"
#include "NGramModel.h"

using namespace std;

int main()
{
    string corpus = Utility::readCorpus("corpus.txt");

    vector<string> table = Tokenizer::tokenize(corpus);

    cout << "Corpus size: " << table.size() << endl;

    map<string, int> u_table = Tokenizer::stringToIds(table);
    cout << "Unique table size: " << u_table.size() << endl;

    NGram model(2);
    model.calculateOccurences(table, u_table);
    model.display_occurences_head(u_table);

    string input = "black";
    cout << "Output: " << input;
    for (int i = 0; i < 5; i++)
    {
        model.estimateProbabilites(vector<string>{input}, u_table);
        cout << " ";
        input = model.displayToken(u_table);
    }
    return 0;
}