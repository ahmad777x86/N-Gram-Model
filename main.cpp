#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "Tokenizer.h"
#include "Utility.h"
#include "NGramModel.h"
#include "Perplexity.h"

using namespace std;

int main()
{
    srand(time(0));

    string corpus = Utility::readCorpus("corpus.txt");

    vector<string> table = Tokenizer::tokenize(corpus);

    cout << "Corpus size: " << table.size() << endl;

    map<string, int> u_table = Tokenizer::stringToIds(table);
    cout << "Unique table size: " << u_table.size() << endl;

    // model
    NGram model(3);
    model.calculateOccurences(table, u_table);
    model.display_occurences_head(u_table);

    // Metric
    Perplexity perplexity;
    perplexity.setSeqLength(model.getGramSize() - 1);

    // I/O
    vector<string> input = {"diabolical", "gpu"};
    cout << "Output: ";

    for (auto i : input)
    {
        cout << i << " ";
    }
    Utility::inference(model, perplexity, u_table, input, 10, 0);
    cout << "\nPerplexity: " << perplexity.calculatePerplexity() << endl;
    return 0;
}