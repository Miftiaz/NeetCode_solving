//link: https://neetcode.io/problems/daily-temperatures/question

/*

Just used a stack to store the index of temperatures which still hasn't seen any warmer temp.
Initialize Res with 0.

1. Iterate the array
2. Compare the current temp[i] with the top of the stack.
   Keep removing the top of the stack if it's less than the current temp[i]
   and update the res[topofstack]
3. push the index i in the stack;

Example:

    [30, 38, 30, 36, 35, 40, 28]

    Stack: [0]

    i=1;
    Stack.top = 0; temp[0] < temp[i];
    So, pop 0, Stack = []
    Push 1, Stack = [1]

    i=2;
    Stack.top = 1; temp[1] > temp[i];
    Push 2, Stack = [1, 2]

    i=3;
    Stack.top = 2; temp[2] < temp[i];
    So, pop 2, Stack = [1]
    Stack.top = 1; temp[1] > temp[i];
    Push 3, Stack = [1,3]

    i=4;
    Stack.top = 3; temp[3] > temp[i];
    Push 4, Stack = [1, 3, 4]

    i=5;
    Stack.top = 4; temp[4] < temp[i];
    So, pop 4, Stack = [1, 3]
    Stack.top = 3; temp[3] < temp[i];
    So, pop 3, Stack = [1]
    Stack.top = 1; temp[1] < temp[i];
    So, pop 1, Stack = []

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> indx;
        int n = temperatures.size();
        vector <int> res(n, 0);
        indx.push(0);

        for(int i=1; i<n; i++){
            int l_indx = indx.top();
            while(!indx.empty() && temperatures[i] > temperatures[l_indx]){
                res[l_indx] = i - l_indx;
                indx.pop();
                if(!indx.empty()) l_indx = indx.top();
            }
            indx.push(i);
        }
        return res;
    }
};


/*
More efficient. Using DP

1. Iterate from right to left.
2. for every temp[i] check from j = i+1
3. if temp[j] < temp[i]
    If res[j] = 0, then break (as there's no warmer day ahead. we are checking right to left.)
    if res[j] > 0, jump to that value j = j+res[j];

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && temperatures[j] <= temperatures[i]) {
                if (res[j] == 0) {
                    j = n;
                    break;
                }
                j += res[j];
            }

            if (j < n) {
                res[i] = j - i;
            }
        }
        return res;
    }
};