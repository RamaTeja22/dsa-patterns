/*
Greedy Approach: O(n) Time Complexity O(1) Extra Space
The idea is to keep track of the farthest reachable index at each step and the rightmost index that can be reached with the current number of jumps.
While DP takes O(n^2) time, this greedy approach optimizes it to O(n) by only iterating through the array once and updating the farthest reachable index and the rightmost index for jumps accordingly.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
        return 0;
        int i=0,right=0,farthest=0,jumps=0;
        for(i=0;i<n-1;i++){
            farthest=max(farthest,i+nums[i]);
            if(i==right){
                right=farthest;
                jumps++;
                if(right>=n-1)
                break;
            }
        }
        return jumps;
    }
};