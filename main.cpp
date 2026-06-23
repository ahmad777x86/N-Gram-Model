#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "Tokenizer.h"
#include "Utility.h"
#include "NGramModel.h"

using namespace std;

int main()
{
    srand(time(0));

    string corpus = Utility::readCorpus("corpus.txt");

    vector<string> table = Tokenizer::tokenize(corpus);

    cout << "Corpus size: " << table.size() << endl;

    map<string, int> u_table = Tokenizer::stringToIds(table);
    cout << "Unique table size: " << u_table.size() << endl;

    NGram model(2);
    model.calculateOccurences(table, u_table);
    model.display_occurences_head(u_table);

    vector<string> input = {"diabolical"};
    cout << "Output: ";
    for (auto i : input)
    {
        cout << i << " ";
    }
    for (int i = 0; i < 10; i++)
    {
        model.estimateProbabilites(input, u_table);
        cout << " ";
        rotate(input.begin(), input.begin() + 1, input.end());
        input.pop_back();
        input.push_back(model.displayToken(u_table));
    }
    return 0;
}