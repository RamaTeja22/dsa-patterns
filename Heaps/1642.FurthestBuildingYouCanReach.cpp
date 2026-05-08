/*
Trick: Use a Max Heap to keep track of the largest jumps (height differences) that we have encountered so far. Always use bricks for the current jump, and if we run out of bricks, we can replace the largest jump with a ladder. This way, we can maximize the distance we can reach with the given number of bricks and ladders.
Time Complexity: O(N log N) for the heap operations, where N is the number of buildings.
Space Complexity: O(N) for the heap.
*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        int i;
        // Max Heap
        priority_queue<int>pq;
        for(i=0;i<n-1;i++){
            int diff = heights[i+1]-heights[i];
            if(diff<=0)
            continue;
            pq.push(diff);
            // Always use bricks, when bricks are exhausted, trace back to history and correct that mistake with ladder.
            bricks-=diff;
            if(bricks<0){
                if(ladders>0){
                    ladders--;
                    bricks+=pq.top();
                    pq.pop();
                }else{
                    return i;
                }
            }
        }
        return n-1;
    }
};