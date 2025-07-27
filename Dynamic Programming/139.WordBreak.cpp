class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<bool>dp(n+1,false);
        int i,j;
        dp[0]=true;
        for(i=1;i<=n;i++){
            for(j=0;j<i;j++){
                if(dp[j] && wordSet.find(s.substr(j,i-j))!=wordSet.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};