#include <iostream>
#include <vector>
#include "Tokenizer.h"

using namespace std;

int main()
{
    string corpus = "Hello, This is a corpus ";
    vector<string> table = Tokenizer::tokenize(corpus);
    Tokenizer::display_table(table);
    return 0;
}