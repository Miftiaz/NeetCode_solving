//link: https://neetcode.io/problems/is-anagram/question?list=neetcode150

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> a, b;
        for (char c : s) {
            a[c]++;
        }
        for (char c : t) {
            b[c]++;
        }
        return a == b;
    }
};
