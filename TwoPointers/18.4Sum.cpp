class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i,j;
        for(i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(j=i+1;j<n-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1])
                continue;
                long long newTarget = (long long)target-(nums[i]+nums[j]);
                int left=j+1;
                int right=n-1;
                while(left<right){
                    if(nums[left]+nums[right]==newTarget){
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right && nums[left]==nums[left+1]){
                            left++;
                        }
                        while(left<right && nums[right]==nums[right-1]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if(nums[left]+nums[right]<newTarget){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return res;
    }
};