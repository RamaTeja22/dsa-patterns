/* If you use Max Heap, you will get TLE, because you need to pop K times every time after adding an element to get the Kth largest element. So we can use Min Heap to store the k largest elements, and the top of the Min Heap is the k-th largest element. When we add a new element, we push it into the Min Heap, and if the size of the Min Heap exceeds k, we pop the smallest element. This way, we always keep the k largest elements in the Min Heap, and the top of the Min Heap is the k-th largest element.
Time Complexity: O(N log K) for the constructor, where N is the number of elements in the initial array, and O(log K) for each call to add.
Space Complexity: O(K) for the Min Heap. */
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        int i;
        int n=nums.size();
        for(i=0;i<n;i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};