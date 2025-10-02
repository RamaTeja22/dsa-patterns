class Solution {
public:
    int dfs(int i,bool canBuy,vector<vector<int>>&dp,int n,vector<int>& prices){
        if(i>=n)
        return 0;
        if(dp[i][canBuy]!=-1)
        return dp[i][canBuy];
        int cooldown = dfs(i+1,canBuy,dp,n,prices);
        if(canBuy){
            int buy = dfs(i+1,false,dp,n,prices)-prices[i];
            dp[i][canBuy] = max(cooldown,buy);
        }
        else{
            int sell = dfs(i+2,true,dp,n,prices)+prices[i];
            dp[i][canBuy]=max(cooldown,sell);
        }
        return dp[i][canBuy];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return dfs(0,true,dp,n,prices);
    }
};