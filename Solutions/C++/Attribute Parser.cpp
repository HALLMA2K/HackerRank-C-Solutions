#include <bits/stdc++.h>

using namespace std;

int main() {
    int numLines, numQueries, i;
    cin >> numLines >> numQueries;

    string temp;
    // vector to store the lines of HTML code
    vector<string> htmlLines;
    // vector to store the queries
    vector<string> queries;

    cin.ignore();

    for (i = 0; i < numLines; i++) {
        getline(cin, temp);
        htmlLines.push_back(temp);
    }

    for (i = 0; i < numQueries; i++) {
        getline(cin, temp);
        queries.push_back(temp);
    }

    // map to store the parsed HTML tags and their attributes
    map<string, string> attributeMap;
    // vector to store the tag names
    vector<string> tagNames;

    for (i = 0; i < numLines; i++) {
        temp = htmlLines[i];
        // remove double quotes from the line
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        // remove angle brackets from the line
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

        if (temp.substr(0, 2) == "</") {
            // closing tag, remove the last tag from the vector
            tagNames.pop_back();
        }
        else {
            stringstream ss;
            ss.str("");
            ss << temp;

            string tag, prop, val;
            char ch;
            // parse the line and extract the tag name, property name and property value
            ss >> ch >> tag >> prop >> ch >> val;

            string tagWithParent = "";
            if (tagNames.size() > 0) {
                // this is not the root tag, prepend the parent tag's name
                tagWithParent = *tagNames.rbegin();
                tagWithParent = tagWithParent + "." + tag;
            }
            else {
                tagWithParent = tag;
            }

            tagNames.push_back(tagWithParent);
            // store the attribute in the map
            attributeMap[tagWithParent + "~" + prop] = val;

            while (ss) {
                // extract additional properties from the line
                ss >> prop >> ch >> val;
                attributeMap[tagWithParent + "~" + prop] = val;
            }
        }
    }

    for (i = 0; i < numQueries; i++) {
        // find the attribute with the name specified in the query
        if (attributeMap.find(queries[i]) == attributeMap.end()) {
            cout << "Not Found!\n";
        }
        else {
            // print the value of the attribute
            cout << attributeMap[queries[i]] << endl;
        }
    }

    return 0;
}
