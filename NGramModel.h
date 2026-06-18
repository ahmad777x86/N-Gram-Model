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
    void calculateOccurences(vector<string>, map<string, int>);
    void estimateProbabilites(vector<string>, map<string, int>);
    void display_occurences_head(map<string, int>);
    string displayToken(map<string, int>);
};