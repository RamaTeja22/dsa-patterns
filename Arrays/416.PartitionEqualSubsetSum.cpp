class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%2==1)
        return false;
        int target = total/2;
        unordered_set<int>sums;
        sums.insert(0);
        int i;
        for(i=0;i<n;i++){
            vector<int>newSums;
            for(int s:sums){
                int newSum = s+nums[i];
                if(newSum==target)
                return true;
                if(newSum<target)
                newSums.push_back(newSum);
            }

            for(int ns:newSums){
                sums.insert(ns);
            }
        }
        return sums.count(target);
    }
};