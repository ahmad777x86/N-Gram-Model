#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class Tokenizer
{
public:
    static vector<string> tokenize(string);
    static void display_table(vector<string>);
    static map<string, int> uniqueTokenMapping(vector<string>);
};