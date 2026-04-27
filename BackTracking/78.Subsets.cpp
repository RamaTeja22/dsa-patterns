class Solution {
public:
    void dfs(int i, int n,vector<int>& nums,vector<int>& cc,vector<vector<int>>& res){
        if(i>=n){
            res.push_back(cc);
            return;
        }
        cc.push_back(nums[i]);
        dfs(i+1,n,nums,cc,res);
        cc.pop_back();
        dfs(i+1,n,nums,cc,res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>cc;
        vector<vector<int>>al;
        dfs(0,n,nums,cc,al);
        return al;
    }
};