#include "Texts.h"

// Bank of all texts
const char* texts[] = {
    "Computer programming is the process of performing particular computations (or more generally.",
    "Programming involves tasks such as analysis, generating algorithms, profiling algorithms' accuracy.",
    "which is the practice of seeking to understand an existing program so as to re-implement its function in some way."
};

int numTexts = sizeof(texts) / sizeof(texts[0]);

string getText() {
    int idx = rand() % 3;
    return texts[idx];
}