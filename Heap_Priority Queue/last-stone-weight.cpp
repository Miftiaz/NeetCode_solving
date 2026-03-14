//link: https://neetcode.io/problems/last-stone-weight/question

/*

Using maxHeap 

O(nlogn)

1. Create the heap.
2. Get the top value as largest element of now. pop it
   get the top value as second largest element. pop.
3. Two case:
    i. They are equal: do nothing.
    ii. Second largest is smaller than largest: push (first - second)
4. At last return the topmost value (if only 1 is there) or 0.

*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        for (int stone: stones) {
            pq.push(stone);
        }

        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            if(second < first){ 
                pq.push(first - second);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

/*

Using Bucket Sort:

Time complexity: 
O(n+w)

Space complexity: 
O(w)
Where
n is the length of the stones array and w is the maximum value in the stones array.

1. Find the largest element.
2. make an array (buckets) of zeros of size maxStone + 1
3. fill in the buckets with which weighted stone occurs in what number.
    e.g if [3, 3, 4], bucket = [0, 0, 0, 2, 1, 0]
4. Define first and second (largest and second largest) for now. (these are indice of the bucket)
5. Iterate from the largest index of the array (maxStone one)
6. Iterate until first gets to 0 index.
7. if largest element of now if there even times, they cancel each other. So, just move on to the previous index. 
8. determine the second largest index (which is not 0 and it's value is not 0)
9. If it's zero, then only one value is there. return first.
10.else sec = j
11. Do the execution.
12. determine the first. as these are smashed, we may find a sec greater than that of now. 
    e.g sec = 2, new value (first - sec) is greater than sec.
13. return first.

*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxStone = 0;
        for(int stone: stones) {
            maxStone = max(stone, maxStone);
        }

        vector <int> bucket(maxStone+1, 0);

        for(int stone: stones) {
            bucket[stone]++;
        }

        int first = maxStone, sec = maxStone;
        while(first > 0){
            if(bucket[first]%2 == 0){
                first--;
                continue;
            }

            int j = min(first - 1, sec);
            while(j > 0 && bucket[j] == 0){
                j--;
            }
            if(j == 0) return first;

            sec = j;

            bucket[first]--;
            bucket[sec]--;
            bucket[first - sec]++;

            first = max(first-sec, sec);
        }
        return first;
    }
};