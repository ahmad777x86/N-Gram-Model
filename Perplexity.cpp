#include <iostream>
#include <math.h>
#include "Perplexity.h"

using namespace std;

Perplexity::Perplexity()
{
    this->log_probabilities_sum = 0;
    this->perplexity = -1;
    this->seq_length = 0;
}

void Perplexity::setSeqLength(int seqlength)
{
    this->seq_length = seqlength;
}

void Perplexity::incrementSeqLength(int l)
{
    this->seq_length += l;
}

void Perplexity::setProbabilities(double logprobabilitysum)
{
    this->log_probabilities_sum = logprobabilitysum;
}

void Perplexity::incrementProbabilities(double probability)
{
    this->log_probabilities_sum += log2(probability);
}

double Perplexity::calculatePerplexity()
{
    perplexity = log_probabilities_sum / seq_length;
    perplexity = pow(2, -perplexity);
    return perplexity;
}

void Perplexity::displayPerplexity()
{
    if (perplexity != -1)
    {
        cout << "\nPerplexity: " << perplexity << endl;
    }
    else
    {
        cout << "Calculate Perplexity first!" << endl;
    }
}