// Limit should treated as a state variable, as on caching, we have states possible with and without limit

class Solution {
public:
    int dfs(int i,bool canBuy,int n,vector<vector<vector<int>>>&dp,vector<int>& prices,int limit){
        if(i>=n || limit<=0)
        return 0;
        if(dp[i][canBuy][limit]!=-1)
        return dp[i][canBuy][limit];
        int nothing = dfs(i+1,canBuy,n,dp,prices,limit);
        if(canBuy){
            int buy = dfs(i+1,false,n,dp,prices,limit)-prices[i];
            dp[i][canBuy][limit]=max(buy,nothing);
        }
        else{
            int sell = dfs(i+1,true,n,dp,prices,limit-1)+prices[i];
            dp[i][canBuy][limit]=max(sell,nothing);
        }
        return dp[i][canBuy][limit];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return dfs(0,true,n,dp,prices,2);
    }
};