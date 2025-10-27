class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        int i;
        unordered_map<int,int>ko;
        for(i=0;i<n;i++){
            if(ko.find(nums[i])!=ko.end() && i-ko[nums[i]]<=k)
            return true;
            ko[nums[i]]=i;
        }
        return false;
    }
};