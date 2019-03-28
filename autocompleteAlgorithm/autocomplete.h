#ifndef _autoComplete
#define _autoComplete

#include "../utilities/header.h"

/*
 *
 */
class SuffixTrieNodeAutocomplete {
   private:
    char letter;
    map<lli, SuffixTrieNodeAutocomplete*> children;
   public:
    /*
     *
     */
    void insertSuffix(string suffix, lli i);

    /*
     *
     */
    void print(string str, vs &output);

    /*
     *
     */
    void autocomplete(string str, vs &output);
};

/*
 *
 */
class SuffixTrieAutocomplete {
   private:
    SuffixTrieNodeAutocomplete root;

   public:
    /*
     *
     */
    void read_text();
};

/*
 *
 */
void vector_to_text(vs output, string word, ofstream &f_out);

/*
 *
 */
void print_to_text(vs output, string word, ofstream &f_out);

/*
 *
 */
void autocomplete();

#endif