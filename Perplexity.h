#include <iostream>

using namespace std;

class Perplexity
{
private:
    int seq_length;
    double log_probabilities_sum;
    double perplexity;

public:
    Perplexity();
    void setSeqLength(int);
    void incrementSeqLength(int);
    void setProbabilities(double);
    void incrementProbabilities(double);
    double calculatePerplexity();
    void displayPerplexity();
};
