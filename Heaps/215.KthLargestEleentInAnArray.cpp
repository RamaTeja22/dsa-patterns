class Solution {
public:
    // Max Heap Solution
    // Time Complexity: O(N log N) for building the Max Heap, and O(log N) for each of the K iterations of the while loop, resulting in O(N log N) overall.
    // Space Complexity: O(N) for the Max Heap.
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq;
        int i;
        for(i=0;i<n;i++){
            pq.push(nums[i]);
        }
        k--;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }

    // Min Heap Solution
    // Time Complexity: O(N log K) for building the Min Heap, and O(log K) for each of the N-K iterations of the while loop, resulting in O(N log K) overall.
    // Space Complexity: O(K) for the Min Heap.
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int i;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};