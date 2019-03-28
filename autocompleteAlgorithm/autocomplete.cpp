#include "autocomplete.h"

void SuffixTrieNodeAutocomplete::print(string str, vs &output) {
    auto it = children.begin();
    for (it; it != children.end(); ++it) {
        children[it->first]->print(str + (char)it->first, output);
    }
    if (children.size() == 0) {
        output.push_back(str);
    }
}

void SuffixTrieNodeAutocomplete::autocomplete(string str, vs &output) {
    SuffixTrieNodeAutocomplete *aux;
    if (children[str[0]] != NULL) {
        aux = children[str[0]];

        if (str.size() == 1) {
            aux->print(str, output);
        } else {
            lli i;
            for (i = 1; i < str.size(); i++) {
                if (aux->children[str[i]] == NULL) {
                    break;
                }
                if (i != str.size() - 1) {
                    aux->children = aux->children[str[i]]->children;
                }
            }
            if (i == str.size()) {
                aux->children[str[i - 1]]->print(str, output);
            }
        }
    }
}

void SuffixTrieNodeAutocomplete::insertSuffix(string suffix, lli i) {
    if (i == suffix.size()) {
        return;
    }
    if (children[suffix[i]] == NULL) {
        children[suffix[i]] = new SuffixTrieNodeAutocomplete();
        letter = suffix[i];
    }
    children[suffix[i]]->insertSuffix(suffix, i + 1);
}

void SuffixTrieAutocomplete::read_text() {
    string word;
    fstream f_in;
    ofstream f_out;
    f_in.open("input/input.txt");
    f_out.open("output/autocomplete.txt");
    while (f_in >> word) {
        if (word[word.size() - 1] == '*' and word[word.size() - 2] == '\\') {
            vs output;
            root.autocomplete(word.substr(0, word.size() - 2), output);
            print_to_text(output, word, f_out);
            output.clear();
            root.insertSuffix(word.substr(0, word.size() - 2), 0);
        } else {
            root.insertSuffix(word, 0);
        }
    }
    f_out.close();
    f_in.close();
}

void print_to_text(vs output, string word, ofstream &f_out) {
    lli size_of_output = output.size();
    if (size_of_output == 0) {
        f_out << "No options for: " << word.substr(0, word.size() - 2) << endl;
    } else {
        f_out << "Options for: " << word.substr(0, word.size() - 2) << endl;
        for (lli i = 0; i < min(lli(5), size_of_output); i++) {
            f_out << "Option [" << i + 1 << "]: " << output[i] << endl;
        }
    }
    f_out << endl;
}

void autocomplete() {
    SuffixTrieAutocomplete Strie;
    Strie.read_text();
    cout << "Output printed in the output file autocomplete.txt in the output folder\n" << endl;
}