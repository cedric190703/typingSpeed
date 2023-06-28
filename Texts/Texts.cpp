#include "Texts.h"

// Bank of all texts
const char* texts[] = {
    "Computer programming is the process of performing particular computations (or more generally, "
    "accomplishing specific computing results), usually by designing and building executable computer programs.",
    "Programming involves tasks such as analysis, generating algorithms, profiling algorithms' accuracy "
    "and resource consumption, and the implementation of algorithms (usually in a particular programming language). "
    "Relatedly, software engineering combines engineering techniques and principles with software development. "
    "Also, those involved with software development may at times engage in reverse engineering, "
    "which is the practice of seeking to understand an existing program so as to re-implement its function in some way."
};

int numTexts = sizeof(texts) / sizeof(texts[0]);

string getText() {
    int idx = rand() % 3;
    return texts[idx];
}