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

    // use unordered_set   
       int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxLen=0;
        int i,right,left=0;
        unordered_set<char>al;
        for(right=0;right<n;right++){
            while(al.find(s[right])!=al.end()){
                al.erase(s[left]);
                left++;
            }
            al.insert(s[right]);
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};