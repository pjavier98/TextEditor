#include "autocompleteAlgorithm/autocomplete.h"
#include "badnessAlgorithm/badness.h"
#include "searchAlgorithm/search.h"
#include "utilities/header.h"

int main() {
    while (true) {
        cout << "********************************" << endl;
        cout << "*         Insert:              *" << endl;
        cout << "* [1] -> To search a word      *" << endl;
        cout << "* [2] -> To autocomplete words *" << endl;
        cout << "* [3] -> To justify a text     *" << endl;
        cout << "* [0] -> To get out            *" << endl;
        cout << "********************************" << endl;
        lli choose;
        cin >> choose;
        if (choose == 1) {
            search_in_text();
        } else if (choose == 2) {
            autocomplete();
        } else if (choose == 3) {
            badness();
        } else if (choose == 0) {
            break;
        }
    }
}