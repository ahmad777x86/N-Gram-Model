#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Tokenizer.h"
#include "Utility.h"

using namespace std;

int main()
{
    string corpus = Utility::readCorpus("decision_trees_corpus.txt");

    vector<string> table = Tokenizer::tokenize(corpus);

    cout << "Corpus size: " << table.size() << endl;

    map<string, int> u_table = Tokenizer::uniqueTokenMapping(table);
    cout << "Unique table size: " << u_table.size() << endl;
    return 0;
}