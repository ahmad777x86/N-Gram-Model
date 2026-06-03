#pragma once
#include <string>
#include <vector>

using namespace std;

class Tokenizer
{
public:
    static vector<string> tokenize(string);
    static void display_table(vector<string>);
};