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