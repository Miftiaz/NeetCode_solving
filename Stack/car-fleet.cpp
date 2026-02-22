//link:https://neetcode.io/problems/car-fleet/question

/*

if a leading positioned car is slower than the rest, it will get to the end point slowly, others will catch up and make a fleet.

1. we created a vector of pairs including the positions and the speed.
2. Reverse sorted the vector of pairs according to their position.
3. We took a vector (of course in float as the time can be in float) for tracking fleet numbers.
4. Calculated the time needed for each car and pushed it in the result vector.
5. If the newly pushed value is less or equal than the previous value, pop the newly pushed one.
    (Meaning, it has slower/equal speed with the forward car)
6. Fleet number will be the size of the vector result.

example:

target:     10
position:   [4,1,0,7]  
Speed:      [2,2,1,1]

So, After sorting, (7,1), (4,2), (1,2), (0,1) ----->(position, speed)

7th positioned car will reach goal first no matter what.
    it will reach in 3 sec. res = (3)
4th positioned car time = 3 sec. same as 7th one. so, same fleet. 
    res = (3)
1st position - t = 4.5 sec, another fleet.
    res = (3, 4.5)
0th position t = 10 sec, another fleet.
    res = (3, 4.5, 10)

*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> stack;
        for (auto& p : pair) {
            stack.push_back((double)(target - p.first) / p.second);
            if (stack.size() >= 2 &&
                stack.back() <= stack[stack.size() - 2])
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};