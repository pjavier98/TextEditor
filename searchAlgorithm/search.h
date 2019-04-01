#ifndef _search
#define _search

#include "../utilities/header.h"

/* 
 * SuffixTrieNodeSearch is the tree node class,
 * Each node has a vector to save the
 * occurrences of each suffix. And each node has a map pointing
 * to another map with the references to the characters
 * of the string. By the property of the map we can insert
 * and search directly for indexes without having to allocate memory
 * for all characters.
 */
class SuffixTrieNodeSearch {
   private:
    map<lli, SuffixTrieNodeSearch*> children;
    vector<ii> *indexes;

   public:
    /* 
     * Creates each node, each node having a vector
     * to save the indices where each occurrence
     * suffix appears.
     */
    SuffixTrieNodeSearch() { indexes = new vector<ii>; }

    /* 
     * Recursive function to insert text suffixes
     * saving in a vector the indices in which it appears, and
     * if there is no node for the current character, we create and
     * add in the tree to the end of the word.
     */
    void insertSuffix(string suffix, lli index, lli start);

    /* 
     * Recursive function to search for a pattern, where it exists
     * return to a vector all indices where this pattern
     * pops up.
    */
    vector<ii> *search(string pattern);
};

/*  
 * SuffixTrieAutocomplete creates the root for the tree
 * we will use to search for the words in the text
 */
class SuffixTrieSearch {
   private:
    SuffixTrieNodeSearch root;

   public:
    /*
     * We create the tree with all possible suffixes
     * that exists in the text, and saved in a vector
     * the initial and final positions of this suffix.
     */
    SuffixTrieSearch(string txt) {
        for (lli i = 0; i < txt.length(); i++) {
            root.insertSuffix(txt.substr(i), i, i);
        }
    }

    /* 
     * Call the recursive function to return the indices
     * where the pattern appears.
     */
    void search(string pat);
};

/* 
 * Function where it receives a vector with the results
 * of the intervals of the indices, if it is empty, no
 * there is what you want to fetch, otherwise we put
 * in the file the ranges.
 */
void print_to_text(string pattern, vector<ii> *result);

/* 
 * Function where we read all the text of the file and put in
 * a string variable to create the tree. We received which
 * word you want to search, and we perform the search.
 */
void search_in_text();

#endif
