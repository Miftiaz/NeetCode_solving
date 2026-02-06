//link: https://neetcode.io/problems/string-encode-and-decode/question?list=neetcode150

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string, x;
        for (string s : strs){
            x = to_string(s.size()) + "#" + s;
            encoded_string += x;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {

        vector<string> strs;
        int i = 0;
        while(i<s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int size_string = stoi(s.substr(i, j-i));

            string str = s.substr(j+1, size_string);

            strs.push_back(str);

            i = j + size_string + 1;
        }
        
        return strs;
    }
};
