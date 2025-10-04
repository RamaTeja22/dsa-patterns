class Solution {
public:
    int dfs(int i,bool canBuy,int n,vector<vector<vector<int>>>&dp, vector<int>& prices,int k){
        if(i>=n || k<=0)
        return 0;
        if(dp[i][canBuy][k]!=-1)
        return dp[i][canBuy][k];
        int nothing = dfs(i+1,canBuy,n,dp,prices,k);
        if(canBuy){
            int buy = dfs(i+1,false,n,dp,prices,k)-prices[i];
            dp[i][canBuy][k]=max(nothing,buy);
        }
        else{
            int sell = dfs(i+1,true,n,dp,prices,k-1)+prices[i];
            dp[i][canBuy][k]=max(nothing,sell);
        }
        return dp[i][canBuy][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return dfs(0,true,n,dp,prices,k);
    }
};