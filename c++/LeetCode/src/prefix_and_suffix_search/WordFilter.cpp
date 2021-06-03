//
// Created by dexhacker on 6/2/21.
//

#include "WordFilter.h"
#include <cassert>

prefix_and_suffix_search::WordFilter::WordFilter(vector<string> &words) {
    for (int k = 0; k < words.size(); k++) {
        string s = words[k];
        string pref = "";
        for (int i = 0; i < min(10, (int)s.size()); i++) {
            pref += s[i];
            string suf = "";
            for (int j = s.size() - 1; j >= max(0, (int)s.size() - 10); j--) {
                suf = s[j] + suf;
                hash_map[pref][suf] = k;
            }
        }
    }
}

int prefix_and_suffix_search::WordFilter::f(string prefix, string suffix) {
    if (hash_map[prefix].count(suffix) > 0) return hash_map[prefix][suffix];

    return -1;
}

void prefix_and_suffix_search::WordFilter::test() {
    vector<string> words {"apple"};
    auto wf = new WordFilter(words);
    assert(wf->f("a", "e") == 0);

    cout << "WordFilter completed!" << endl;
}
