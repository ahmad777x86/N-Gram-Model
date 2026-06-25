#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

class NGram
{
private:
    int context_size;
    map<vector<int>, int> occurences;
    int output_token;

public:
    NGram(int);
    int getGramSize();
    void calculateOccurences(const vector<string> &, const map<string, int> &);
    double predictNextToken(const vector<string> &, const map<string, int> &, int verbose);
    void display_occurences_head(map<string, int>);
    string displayToken(map<string, int>);
};