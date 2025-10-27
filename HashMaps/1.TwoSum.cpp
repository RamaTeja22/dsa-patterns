class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        int n=nums.size();
        unordered_map<int,int>hm;
        int i;
        for(i=0;i<n;i++){
            if(hm.find(target-nums[i])!=hm.end()){
                res.push_back(hm[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            hm[nums[i]]=i;
        }
        return res;
    }
};