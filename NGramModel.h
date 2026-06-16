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

public:
    NGram(int);
    void calculateOccurences(vector<string>, map<string, int>);
    void display_occurences(map<string, int>);
};