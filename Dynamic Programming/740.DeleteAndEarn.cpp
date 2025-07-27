class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        // use map because we it sorts the keys by default.
        map<int,int>points;
        int i;
        for(i=0;i<n;i++){
            points[nums[i]]+=nums[i];
        }
        vector<int>sortedVals(n,0);
        sortedVals.clear();
        for(auto[val,pts]:points){
            sortedVals.push_back(val);
        }
        int prev=-1,prevMax=0,currMax=0,newMax=0;
        // prevMax corresponds to max just before adjacent, currMax corresponds to the just adjacent element
        for(int val: sortedVals){
            int take = points[val];
            if(prev!=-1 && val-prev == 1){
                newMax = max(currMax,take+prevMax);
            }
            else{
                newMax=take+currMax;
            }
            prev=val;
            prevMax=currMax;
            currMax=newMax;
        }
        return newMax;
    }
};