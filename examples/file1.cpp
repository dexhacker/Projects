#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_anagrams(string s1, string s2) {
    vector<int> a(26);

    for (char c : s1) {
        a[c-'a']++;
    }

    for (char c : s2) {
        a[c-'a']--;
    }


    for (int i = 0; i < 26; i++) {
        if (a[i] != 0) return false;
    }
    return true;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << is_anagrams(s1, s2);
}
