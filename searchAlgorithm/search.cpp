#include "search.h"

void SuffixTrieNodeSearch::insertSuffix(string str, lli start, lli index) {
    indexes->push_back(make_pair(start, index));

    if (str.length() > 0) {
        char charIndex = str.at(0);

        if (children[charIndex] == NULL) {
            children[charIndex] = new SuffixTrieNodeSearch();
        }

        children[charIndex]->insertSuffix(str.substr(1), start, index + 1);
    }
}

vector<ii>* SuffixTrieNodeSearch::search(string str) {
    if (str.length() == 0) {
        return indexes;
    }

    if (children[str.at(0)] != NULL) {
        return (children[str.at(0)])->search(str.substr(1));
    } else {
        return NULL;
    }
}

void print_to_text(string pattern, vector<ii>* result) {
    ofstream f_out;
    f_out.open("output/search.txt");
    if (result == NULL) {
        f_out << "Search for " << pattern << ":" << endl;
        f_out << "Pattern not found" << endl;
    } else {
        auto i = result->begin();
        lli patLen = pattern.length();
        f_out << "Search for " << pattern << ":" << endl;
        for (i; i != result->end(); ++i) {
            f_out << "Indexes: [" << i->first << ", " << i->second - 1 << "]" << endl;
        }
    }
    f_out.close();
}

void SuffixTrieSearch::search(string pattern) {
    vector<ii>* result = root.search(pattern);
    print_to_text(pattern, result);
}

void search_in_text() {
    string word, txt, pattern;
    fstream f_in;

    f_in.open("input/input.txt");
    while (true) {
        if (f_in.eof()) {
            break;
        } else {
            f_in >> word;
            if (txt.size() != 0)
                txt += " ";
            txt += word;
        }
    }
    f_in.close();
    SuffixTrieSearch STrie(txt);

    cout << "Enter the word to search: ";
    cin >> pattern;
    cout << endl;
    
    STrie.search(pattern);
    cout << "Output printed in the output file search.txt in the output folder\n" << endl;
}