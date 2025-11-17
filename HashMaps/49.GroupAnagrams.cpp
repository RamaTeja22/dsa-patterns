class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>cc;
        for(auto& str:strs){
            string key = str;
            sort(key.begin(),key.end());
            cc[key].push_back(str);
        }
        vector<vector<string>>res;
        for(auto& c2:cc){
            res.push_back(c2.second);
        }
        return res;
    }
};