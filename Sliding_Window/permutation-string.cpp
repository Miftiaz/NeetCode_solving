//link: https://neetcode.io/problems/permutation-string/question

/*
Solution 1: (But GPT Says it's risky for interview)

1. Make a hash "freq" to keep the frequencies of the characters in s1.
2. iterate r;
3. make a copy of if. use it until a character appears which is not in the s1.
4. If s2[r] exists in the copy_freq, decrement the frequence by 1 as we have seen it. and increment the flag, to determine how long we've found.
5. If flag == length of s1, return true.
6. if s2[r] exists but we have already seen it as we needed, freq = 0,
    we'll iterate to the index of s2[r] where we saw it for the first time in the current window, so we are shrinking the left window.
    while doing so, increment the s2[l] frequency as it's not in the current window now. decrement the flag.
    after reaching the index, do the same.
7. Then go as usual. as we've deleted a s2[r], so decrement it's frequency as if we found it new.
8. End.
*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char, int> freq;

        for (int i: s1){
            freq[i]++;
        }

        int flag = 0, length = s1.size(), l=0;
        unordered_map <char, int> freq_copy(freq);

        for(int r = 0; r<s2.size(); r++){
            flag = 0;
            while(freq_copy.find(s2[r]) != freq_copy.end()){
                if(freq_copy[s2[r]] == 0) {
                    while(s2[l]!=s2[r]){
                        freq_copy[s2[l]]++;
                        l++;
                        flag--;
                    }
                    freq_copy[s2[l]]++;
                    l++;
                    flag--;
                }
                freq_copy[s2[r]]--;
                flag++;
                if (flag == length) return true;
                r++;
            }
            if(flag>0) freq_copy = freq;
        }
        return false;
    }
};

/*

Solution 2:

1. If s1 is bigger than s2, of course result is false.
2. Define two vectors for storing the frequencies. (as we have only 26 characters, vector is more handy)
3. The window length is fixed and that is the size of the s1 string.
4. Every iteration, we just store the frequencies of the characters in our current window.
5. First, store the frequency of the first window in the s2_count, and frequency of the characters of s1 in s1_count. 
   Use character - 'a' to get 0 - 26 to all the characters from 0-index.
6. Iterate 26 times and determine the matches.Most of the character count will be zero.
7. Iterate s2 starting with r = s1.size() as it's the next value for window to be inserted. 
8. Check if current window has exact 26 matches or not. if it does return true.
9. increment the frequency of the s2[r] in the s2_count as it now is in the window.
10. check if frquency of s2[r] in the s1_count and s2_count matches or not.
    If matches, matches++;
    Otherwise (to be exact, as we inserted it extra in the window), matches-- (as previously it matched)

11. Decrement the frequency of the s2[l] in the s2_count as it now is not in the window.
12. check if frquency of s2[l] in the s1_count and s2_count matches or not.
    If matches (The character has exact frquency in the window as it should have), matches++;
    Otherwise (to be exact, as we deleted it but it belonged to the window), matches-- (as previously it matched)
13. l--;
14. Repeat 8 to 13 until r<s2.length()
15. Return matches == 26. 

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector <int> s1_count(26, 0);
        vector <int> s2_count(26, 0);

        for(int i=0; i<s1.length(); i++){
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }

        int matches = 0; 

        for(int i=0; i<26; i++){
            if (s1_count[i] == s2_count[i]) {
                matches++;
            }
        }

        int l = 0;
        for(int r=s1.size(); r<s2.size(); r++){
            if (matches == 26) return true;

            int r_index = s2[r] - 'a';
            s2_count[r_index]++;
            if (s1_count[r_index] == s2_count[r_index]){
                matches++;
            }
            else if(s1_count[r_index]+1 == s2_count[r_index]){
                matches--;
            }

            int l_index = s2[l] - 'a';
            s2_count[l_index]--;
            if(s1_count[l_index] == s2_count[l_index]){
                matches++;
            }
            else if(s1_count[l_index]-1 == s2_count[l_index]){
                matches--;
            }
            l++;
        }

        return matches == 26;
    }
};
