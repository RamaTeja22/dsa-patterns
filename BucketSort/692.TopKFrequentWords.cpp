class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<vector<string>>buckets(n+1);
        vector<string>res;
        unordered_map<string,int>freq;
        int i;
        for(i=0;i<n;i++){
            freq[words[i]]++;
        }
        for(auto& dict: freq){
            buckets[dict.second].push_back(dict.first);
        }
        for(i=n;i>=0;i--){
            if(!buckets[i].empty()){
                sort(buckets[i].begin(),buckets[i].end());
                for(string str:buckets[i]){
                    res.push_back(str);
                    if(res.size()>=k)
                    return res;
                }
            }
        }
        return res;
    }
};