class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0')
        return 0;
        int n = s.length();
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        int i;
        for(i=2;i<=n;i++){
            char onesDigit = s[i-1];
            if(onesDigit >= '1' && onesDigit <= '9'){
                dp[i]+=dp[i-1];
            }
            char twosDigit = s[i-2];
            int num = (twosDigit-'0')*10 + (onesDigit-'0');
            if(num>=10 && num<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};