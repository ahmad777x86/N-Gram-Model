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

const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";

int main()
{
    srand(time(0));
    short n = -1;
    short flag = 1;

    string corpus = Utility::readCorpus("corpus.txt");

    vector<string> table = Tokenizer::tokenize(corpus);

    cout << CYAN << BOLD << string(50, '=') << RESET << endl;
    cout << MAGENTA << BOLD << "\t\t--- N-GRAM MODEL ---" << RESET << endl;
    cout << CYAN << BOLD << string(50, '=') << RESET << "\n"
         << endl;

    cout << GREEN << "[-] " << "Loading corpus..." << RESET << endl;
    cout << GREEN << BOLD << "Corpus size: " << table.size() << RESET << endl;

    map<string, int> u_table = Tokenizer::stringToIds(table);
    cout << GREEN << "[-] " << "Tokenizing raw text splits..." << RESET << endl;
    cout << GREEN << BOLD << "Unique table size: " << u_table.size() << "\n"
         << endl;

    do
    {
        cout << CYAN << BOLD << "Enter Gram Size (greater than 1 ideally): " << RESET;
        flush(cout);
        cin >> n;
    } while (n < 1);
    cout << GREEN << "[-] " << "Estimating counts..." << RESET << endl;

    // model
    NGram model(n);
    model.calculateOccurences(table, u_table);
    // model.display_occurences_head(u_table);

    // Metric
    Perplexity perplexity;
    perplexity.setSeqLength(model.getGramSize() - 1);

// I/O
io:
    string input_str;

    cout << CYAN << BOLD << "\nInput text sequence: " << RESET;
    flush(cout);
    if (flag == 1)
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
            cout << RED << BOLD << "Please input gram_size-1 words atleast" << RESET << endl;
            input.clear();
            flag = 0;
            goto io;
        }
    }

    cout << YELLOW << BOLD << "Output: " << RESET;
    for (auto i : input)
    {
        cout << YELLOW << i << " ";
    }
    Utility::inference(model, perplexity, u_table, input, 20, 0);
    cout << "\n"
         << endl;
    cout << CYAN << BOLD << string(50, '=') << RESET << endl;
    cout << MAGENTA << BOLD << "\t\t--- Model Evaluation ---" << RESET << endl;
    cout << CYAN << BOLD << string(50, '=') << RESET << endl;

    cout << GREEN << BOLD << "\nPerplexity: " << perplexity.calculatePerplexity() << RESET << endl;
    return 0;
}