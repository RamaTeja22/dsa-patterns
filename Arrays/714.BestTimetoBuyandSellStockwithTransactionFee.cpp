class Solution {
public:
    int dfs(int i,bool canBuy,int fee,int n,vector<int>& prices,vector<vector<int>>&dp){
        if(i>=n)
        return 0;
        if(dp[i][canBuy]!=-1)
        return dp[i][canBuy];
        int nothing = dfs(i+1,canBuy,fee,n,prices,dp);
        if(canBuy){
            int buy = dfs(i+1,false,fee,n,prices,dp)-prices[i];
            dp[i][canBuy] = max(nothing,buy);
        }
        else{
            int sell = dfs(i+1,true,fee,n,prices,dp)+prices[i]-fee;
            dp[i][canBuy]=max(nothing,sell);
        }
        return dp[i][canBuy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return dfs(0,true,fee,n,prices,dp);
    }
};