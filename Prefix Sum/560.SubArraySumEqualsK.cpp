// Can't use Sliding Window as negative Integers are also allowed.
// So we need to maintain map of Prefix Sum counts
// Core Idea is We need to find how many
// currSum - prevSum = k
// => prevSum = currSum - k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>cnt;
        int i;
        int currSum=0;
        cnt[0]=1;
        int res=0;
        for(i=0;i<n;i++){
            currSum+=nums[i];
            if(cnt.find(currSum-k)!=cnt.end()){
                res+=cnt[currSum-k];
            }
            cnt[currSum]++;
        }
        return res;
    }
};
