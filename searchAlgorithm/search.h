#ifndef _search
#define _search

#include "../utilities/header.h"

/*
 *
 */
class SuffixTrieNodeSearch {
   private:
    map<lli, SuffixTrieNodeSearch*> children;
    vector<ii> *indexes;

   public:
    /*
     *
     */
    SuffixTrieNodeSearch() { indexes = new vector<ii>; }

    /*
     *
     */
    void insertSuffix(string suffix, lli index, lli start);

    /*
     *
     */
    vector<ii> *search(string pattern);
};

/*
 *
 */
class SuffixTrieSearch {
   private:
    SuffixTrieNodeSearch root;

   public:
    /*
     *
     */
    SuffixTrieSearch(string txt) {
        for (lli i = 0; i < txt.length(); i++) {
            root.insertSuffix(txt.substr(i), i, i);
        }
    }

    /*
     *
     */
    void search(string pat);
};

/*
 *
 */
void print_to_text(string pattern, vector<ii> *result);

/*
 *
 */
void search_in_text();

#endif