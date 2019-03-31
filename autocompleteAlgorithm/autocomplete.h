#ifndef _autoComplete
#define _autoComplete

#include "../utilities/header.h"

/*
 * SuffixTrieNodeAutocomplete is the tree knots class,
 * each node has a letter of the word to be inserted and a map
 * that by its property we can insert and search directly for the
 * indices without needing to allocate memory for all the characters
 */
class SuffixTrieNodeAutocomplete {
   private:
    char letter;
    map<lli, SuffixTrieNodeAutocomplete*> children;
   public:
    /* 
     * Receive a word, and create a node for each character
     * of this word if it does not already exist
     */
    void insertSuffix(string suffix, lli i);

    /* 
     * With the possibilities to self-complete, we save in a vector
     * concatenating the suffix to complete with the possibilities
     */
    void insertInVector(string str, vs &output);

    /* 
     * We get the prefix we want to auto-complete, we first check
     * if there is a prefix, if it exists, we use an auxiliary to
     * tree. First we check if what we are going to self-complete is only one
     * character, if it is, we can complete with all the suffixes we have so far
     * of that character. Otherwise, we traverse the tree to the end of the current suffix
     * and we check the tree if it has children, if it has, it means that we can
     * auto-complete by calling the function to put the options in the file.
     */
    void autocomplete(string str, vs &output);
};

/*
 * SuffixTrieAutocomplete creates the root for the tree
 * that we will use to autocomplete the words
 */
class SuffixTrieAutocomplete {
   private:
    SuffixTrieNodeAutocomplete root;

   public:
    /* 
     * Function where we receive the text from the file, we define for
     * when you want to autocomplete a word add "* \". While
     * is not read "* \" we insert in the tree the word
     */
    void read_text();
};

/*
 * With the vector with saved possibilities, we check if we save
 * some word, if not, it means that we have no option to
 * complete, if yes we put in the file the possibilities.
 */
void print_to_text(vs output, string word, ofstream &f_out);

/* 
 * Function that creates the root of the tree and passes
 * the text that will be inserted in the suffix tree
 */
void autocomplete();

#endif