#pragma once
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include "NGramModel.h"
#include "Perplexity.h"

using namespace std;

class Utility
{
public:
    static string readCorpus(string);
    static void inference(NGram &model, Perplexity &perplexity, const map<string, int> &str_to_ints,
                          vector<string> &input, const int iterations, const int verbose_mode);
};