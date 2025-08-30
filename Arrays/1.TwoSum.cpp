class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>cc;
        vector<int>res;
        int i;
        for(i=0;i<n;i++){
            if(cc.find(target-nums[i])!=cc.end()){
                res.push_back(i);
                res.push_back(cc[target-nums[i]]);
                return res;
            }
            cc[nums[i]]=i;
        }
        return res;
    }
};