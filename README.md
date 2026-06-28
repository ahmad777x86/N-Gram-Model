# N-Gram-Model
N-Gram Model is an NLP model used to predict next token/word in a sequence based on the previous n-1 tokens in a sequence. This assumption of local context is borrowed from the markov chains where the next state of a system relies completely on the current state rather than previous states.

---

# Requirements

- C++ compiler (g++ ideally)

---

# How to run

1. Clone this repository.
2. In the root of this repository, run the following command:

```bash
g++ NGramModel.cpp Perplexity.cpp Tokenizer.cpp Utility.cpp main.cpp -o main.exe
```
3. Input gram size and text sequence and see the magic ✨✨.
4. If you want to change the corpus of the model, just paste your text corpus into the `corpus.txt` file and re-compile. (Optional)
5. You can also change no. of tokens generated from the `main.cpp` file, default is 10 tokens. (Optional)

---

# Code Structure

- `NGramModel.cpp` contains the NGram model class with probability estimation and inference modules.
- `Perplexity.cpp` contains the Perplexity class to evaluate model performance.
- `Tokenizer.cpp` contains the Tokenizer class to break up the corpus into tokens(single word/character).
- `Utility.cpp` contains the Utility class for some helpful modules.

---

# Suggestions

If you have any suggestions regarding code readability, practices, etc. please create an issue I'll be sure to check it out `:)`.