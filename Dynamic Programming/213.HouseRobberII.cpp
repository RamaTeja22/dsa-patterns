/*
    Since the circle creates a dependency only between the first and last elements, we can break the circle into two linear scenarios. We force a choice:
    Scenario A: We rob the first house. Consequently, we cannot rob the last house.
    Effective Range: Houses 0 to n-2.
    Scenario B: We skip the first house. Consequently, we can rob the last house (if optimal).
    Effective Range: Houses 1 to n-1.
    The answer is simply: max(rob_linear(nums[0...n-2]), rob_linear(nums[1...n-1])).
*/
class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end){
        if(start>end)
        return 0;
        int i;
        int prev1=0,prev2=0;
        for(i=start;i<=end;i++){
            int current=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=current;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        int option1=robLinear(nums,0,n-2);
        int option2=robLinear(nums,1,n-1);
        return max(option1,option2);
    }
};