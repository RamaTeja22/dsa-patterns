class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<3)
        return 0;
        int currSum=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int first=0,second=1,third=n-1;
        for(first=0;first<n-2;first++){
            if(first>0 && nums[first]==nums[first-1])
            continue;
            second=first+1;
            third=n-1;
            while(second<third){
                int curr_sum=nums[first]+nums[second]+nums[third];
                if(curr_sum==target){
                    return target;
                }
                if(abs(curr_sum-target)<abs(currSum-target)){
                    currSum=curr_sum;
                }
                if(curr_sum<target){
                    second++;
                }
                else{
                    third--;
                }
            }
        }
        return currSum;
    }
};