#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    std::vector<std::string> words = {"People", "continue", "to", "inquire", "the", "reason",
                                      "for", "the", "race", "for", "outer", "space"};
    std::vector<std::string> tags = {"NNS", "VBP", "TO", "VB", "DT", "NN", "IN", "DT", "NN",
                                     "IN", "JJ", "?"};

    for (int i = 0; i < words.size(); i++) {
        if (tags[i] == "?") {
            if (words[i] == "outer") {
                tags[i] = "JJ";
            } else if (words[i] == "space") {
                tags[i] = "NN";
            } else {
                tags[i] = "NN";
            }
        }
        std::cout << words[i] << "/" << tags[i] << " ";
    }
    
    std::cout << std::endl;

    return 0;
}
