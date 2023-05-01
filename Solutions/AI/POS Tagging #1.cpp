#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    std::vector<std::pair<std::string, std::string>> taggedSentence {
        {"The", "DT"},
        {"planet", "NN"},
        {"Jupiter", "NNP"},
        {"and", "CC"},
        {"its", "PPS"},
        {"moons", "NNS"},
        {"are", "VBP"},
        {"in", "IN"},
        {"effect", "NN"},
        {"a", "DT"},
        {"minisolar", "JJ"},
        {"system", "NN"},
        {",", ","},
        {"and", "CC"},
        {"Jupiter", "NNP"},
        {"itself", "PRP"},
        {"is", "VBZ"},
        {"often", "RB"},
        {"called", "VBN"},
        {"a", "DT"},
        {"star", "NN"},
        {"that", "IN"},
        {"never", "RB"},
        {"caught", "VBN"}, 
        {"fire", "NN"},
        {".", "."}
    };

    // Iterate through the sentence, filling in the missing tags
    for (int i = 0; i < taggedSentence.size(); i++) {
        if (taggedSentence[i].second == "??") {
            // Fill in 2-letter tag based on context
            if (taggedSentence[i-1].second == "JJ") {
                taggedSentence[i].second = "NN";
            } else if (taggedSentence[i-1].second == "DT") {
                taggedSentence[i].second = "JJ";
            } else if (taggedSentence[i-1].second == "CC") {
                taggedSentence[i].second = "JJ";
            }
        } else if (taggedSentence[i].second == "???") {
            // Fill in 3-letter tag based on context
            if (taggedSentence[i-1].second == "VBP" && taggedSentence[i+1].second == "NN") {
                taggedSentence[i].second = "NNP";
            } else if (taggedSentence[i-1].second == "IN" && taggedSentence[i+1].second == "NN") {
                taggedSentence[i].second = "NNP";
            } else if (taggedSentence[i-1].second == "IN" && taggedSentence[i+1].second == "VBN") {
                taggedSentence[i].second = "PPS";
            }
        }
    }

    // Print out the tagged sentence with filled-in missing tags
    for (int i = 0; i < taggedSentence.size(); i++) {
        std::cout << taggedSentence[i].first << "/" << taggedSentence[i].second << " ";
    }
    
    std::cout << std::endl;

    return 0;
}


