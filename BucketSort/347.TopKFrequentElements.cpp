// O(n) Time Complexity O(n) Extra Space (Buckets)
// Heap Based Solution would be O(n logk) but more memory efficient

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        int i;
        // Need to size this to n+1 because [1] here we need to bucket 1 in 1 bucket. 0,1 so size is 2, we are directly accessing index, defining size is essential
        vector<vector<int>>buckets(n+1);
        unordered_map<int,int>cnt;
        for(i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        for(auto& s:cnt){
            buckets[s.second].push_back(s.first);
        }
        for(i=n;i>=0;i--){
            if(buckets[i].size()>0){
                int sz=buckets[i].size();
                for(int j=0;j<sz;j++){
                    res.push_back(buckets[i][j]);
                    if(res.size()>=k)
                    return res;
                }
            }
        }
        return res;
    }
};