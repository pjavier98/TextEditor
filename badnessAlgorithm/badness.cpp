#include "badness.h"

void print_to_text(vlli print, vs text, lli size, ofstream& f_out) {
    if(print[size] != 1) {
        print_to_text(print, text, print[size] - 1, f_out);
    }
    for (lli i = print[size]; i <= size; i++) {
        f_out << text[i - 1] << " ";
    }
    f_out << endl;
}

vlli make_arrays(vvlli matrix, lli size) {
    vlli cost, print;
    cost.resize(size + 1);
    print.resize(size + 1);

    for (lli i = 1; i <= size; i++) {
        cost[i] = INT_MAX;
    }
    for (lli j = 1; j <= size; j++) {
        for (lli i = 1; i <= j; i++) {
            if (matrix[i][j] != INT_MAX && (matrix[i][j] + cost[i - 1]) < cost[j]) {
                cost[j] = matrix[i][j] + cost[i - 1];
                print[j] = i;
            }
        }
    }
    return print;
}

vvlli make_matrix(lli size, lli weight, vlli lengthWords) {
    vvlli matrix;
    matrix.resize(size + 1);

    for (lli i = 0; i <= size; i++) {
        matrix[i].resize(size + 1);
    }
    for (lli i = 1; i <= size; i++) {
        lli count = lengthWords[i];
        matrix[i][i] = (lli)pow(weight - count, 3);
        for (lli j = i + 1; j <= size; j++) {
            count += lengthWords[j] + 1;
            if (count <= weight) {
                matrix[i][j] = (lli)pow(weight - count, 3);
            } else {
                matrix[i][j] = INT_MAX;
            }
        }
    }
    matrix[size][size] = 0;
    return matrix;
}

void badness() {
    string word;
    lli weight;
    vs text;
    vlli lengthWords;
    lengthWords.push_back(0);
    fstream f_in;
    f_in.open("input/input.txt");
    while (true) {
        if (f_in.eof()) {
            break;
        } else {
            f_in >> word;
            text.push_back(word);
            lengthWords.push_back(word.size());
        }
    }

    cout << "Enter the width to justify: ";
    cin >> weight;
    cout << endl;

    lli size = text.size();
    vvlli matrix = make_matrix(size, weight, lengthWords);
    vlli print = make_arrays(matrix, size);


    ofstream f_out;
    f_out.open("output/badness.txt");
    print_to_text(print, text, size, f_out);
    cout << "Output printed in the output file badness.txt in the output folder\n" << endl;
    f_in.close();
    f_out.close();
}