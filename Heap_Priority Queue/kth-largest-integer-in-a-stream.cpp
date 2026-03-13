//link: https://neetcode.io/problems/kth-largest-integer-in-a-stream/question

/*

This solution is not optimal but easy to understand. O(m*n logn) time complexity

1. define a vector and an integer variable as a property for the class. 
2. assign the k and nums to the property when constructor is called. (all values are stored)
3. When add function is called, push the value to to array.
4. Sort it.
5. Return the (n-k)th value as it's the kth largest element.

*/

class KthLargest {
public:
    vector <int> arr;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->arr = nums;
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(arr.begin(), arr.end());
        return arr[arr.size() - k];
    }
};

/*

The optimal solution using minheap. O(m∗logk) where m is the number of calls made to add()

Why not maxHeap?
- a max heap would require removing the largest element k−1 times before reaching the kth largest.

We don't care about if all the values are stored or not. So, no need to store all of the values when constructor is called.
We just need the kth largest element.
So, store only k number of values to the heap.

1. When constructor is called, 
    - assign k to the property
    - for every number in the nums array,
        add the number in the minHeap.
        if size of the heap is more than k, delete the smallest number by poping the heap.
2. when add() is called, 
    - push the value to the heap,
    - if size of the heap is more than k, delete the smallest number by poping the heap.
    - return the top as the heap contains only k values and the top is the minimum of them aka kth largest element.

Example:

1, 2, 3, 4, 5   k = 4

So, we'll store only 2, 3, 4, 5 and 2 is the 4th largest number. we won't keep 1, as it never will be 4th largest number as we already have
4 numbers greater than 1. 

If add (0) is called, heap = 0, 2, 3, 4, 5   n = 5
so, pop. heap = 2, 3, 4, 5.
return top, which will return 2 again.

*/

class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> minHeap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};