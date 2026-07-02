#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <limits>
#include <algorithm>
#include "Tokenizer.h"
#include "Utility.h"
#include "NGramModel.h"
#include "Perplexity.h"

using namespace std;

int main()
{
    srand(time(0));
    short n = -1;
    string input_str;

    string corpus = Utility::readCorpus("corpus.txt");

    vector<string> table = Tokenizer::tokenize(corpus);

    cout << "Corpus size: " << table.size() << endl;

    map<string, int> u_table = Tokenizer::stringToIds(table);
    cout << "Unique table size: " << u_table.size() << endl;

    do
    {
        cout << "Enter Gram Size (greater than 1 ideally): ";
        flush(cout);
        cin >> n;
    } while (n < 1);

    // model
    NGram model(n);
    model.calculateOccurences(table, u_table);
    // model.display_occurences_head(u_table);

    // Metric
    Perplexity perplexity;
    perplexity.setSeqLength(model.getGramSize() - 1);

// I/O
io:
    cout << "\nInput text sequence: ";
    flush(cout);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, input_str);

    vector<string> input_seq = Tokenizer::tokenize(input_str);
    vector<string> input;
    for (int i = model.getGramSize() - 2; i >= 0; i--)
    {
        try
        {
            input.push_back(input_seq.at(input_seq.size() - 1 - i));
        }
        catch (const std::exception &e)
        {
            cout << "Please input gram_size-1 words atleast" << endl;
            goto io;
        }
    }

    cout << "Output: ";
    for (auto i : input)
    {
        cout << i << " ";
    }
    Utility::inference(model, perplexity, u_table, input, 20, 0);
    cout << "\n"
         << endl;
    cout << "\nPerplexity: " << perplexity.calculatePerplexity() << endl;
    return 0;
}