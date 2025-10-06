// Space O(n) solution
class Solution {
public:
    int pivotIndex1(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n),suffix(n);
        int i;
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
            suffix[n-1-i]=suffix[n-i]+nums[n-i-1];
        }
        for(i=0;i<n;i++){
            if(prefix[i]==suffix[i])
            return i;
        }
        return -1;
    }

    // O(1) Space Complexity

    int pivotIndex(vector<int>& nums){
        int total = accumulate(nums.begin(),nums.end(),0);
        int i,left=0,n=nums.size();
        for(i=0;i<n;i++){
            if(left==(total-nums[i])/2.0){
                return i;
            }
            left+=nums[i];
        }
        return -1;
    }
};