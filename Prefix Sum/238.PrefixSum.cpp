class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        vector<int>left(n,1);
        vector<int>right(n,1);
        int i;
        for(i=1;i<n;i++){
            left[i]=nums[i-1]*left[i-1];
            right[n-1-i]=nums[n-i]*right[n-i];
        }
        for(i=0;i<n;i++){
            res[i]=left[i]*right[i];
        }
        return res;
    }
};