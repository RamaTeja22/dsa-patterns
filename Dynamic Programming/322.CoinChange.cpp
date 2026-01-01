// for each amount i from 1 to amount
// try every coin
// if c<=i
// dp[i]=min(dp[i],dp[i-c]+1)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        int i;
        // fill dp[i] to dp[amount]
        for(i=1;i<=amount;i++){
            for(int coin : coins){
                if(coin<=i){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};