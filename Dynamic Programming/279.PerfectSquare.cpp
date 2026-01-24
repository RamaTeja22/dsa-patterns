// Variation of Coin Change, generate coin by generating perfect squares.
class Solution {
public:
    int numSquares(int n) {
        int i;
        vector<int>dp(n+1,n+1);
        dp[0]=0;
        vector<int>coins;
        for(i=1;i*i<=n;i++){
            coins.push_back(i*i);
        }
        for(i=1;i<=n;i++){
            for(int coin:coins){
                if(i>=coin){
                    dp[i]=min(dp[i],1+dp[i-coin]);
                }
            }
        }
        return dp[n];
    }
};