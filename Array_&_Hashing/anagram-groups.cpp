//link: https://neetcode.io/problems/anagram-groups/question?list=neetcode150

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string c : strs){
            string key = c;
            sort(key.begin(), key.end());
            map[key].push_back(c);
        }

        vector<vector<string>> result;
        for (auto& it: map){
            result.push_back(it.second);
        }

        return result;
    }
};
