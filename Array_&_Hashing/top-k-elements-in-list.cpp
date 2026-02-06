//link: https://neetcode.io/problems/top-k-elements-in-list/question?list=neetcode150

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> arra;
        int n = nums.size();
        vector <vector<int>> bucket(n+1);
        vector <int> result;

        for (int num: nums){
            arra[num]++;
        }

        for (auto& it: arra){
            bucket[it.second].push_back(it.first);

        }

        for (int i = n; i>=1 && result.size()<k; i--){
            for(int numb : bucket[i]){
                result.push_back(numb);
                if(result.size() == k) return result;
            }
        }

        return result;
    }
};
