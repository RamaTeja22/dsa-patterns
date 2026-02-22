class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)
        return 0;
        int res=INT_MIN;
        int i=0,j=0;
        unordered_map<char,int>cc;
        while(j<n && i<=j){
            if(cc.find(s[j])!=cc.end()){
                // We don't erase our map, so there is a possibility cc[s[j]] is outside the sliding window and hence could be less than existing start of sliding window i
                i=max(i,cc[s[j]]+1);
            }
            cc[s[j]]=j;
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};