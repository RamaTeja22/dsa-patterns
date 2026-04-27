class Solution {
public:
    void generateP(int index,vector<int>& nums,vector<vector<int>>&res, int n){
        if(index>=n){
            res.push_back(nums);
            return;
        }
        int i;
        for(i=index;i<n;i++){
            swap(nums[index],nums[i]);
            generateP(index+1,nums,res,n);
            swap(nums[index],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        generateP(0,nums,res,n);
        return res;
    }
};