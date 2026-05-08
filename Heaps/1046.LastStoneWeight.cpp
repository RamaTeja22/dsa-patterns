/* Time Complexity: O(N log N) for building the Max Heap, and O(log N) for each of the N-1 iterations of the while loop, resulting in O(N log N) overall.
Space Complexity: O(N) for the Max Heap.
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        int i;
        priority_queue<int>pq;
        for(i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int one = pq.top();
            pq.pop();
            int two=pq.top();
            pq.pop();
            if(one>two){
                pq.push(one-two);
            }
        }
        return pq.empty()?0:pq.top();
    }
};