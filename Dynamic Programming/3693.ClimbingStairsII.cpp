class Solution {
public:
    int mini(int a,int b,int c){
        int mi=min(a,b);
        return min(mi,c);
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,0);
        int i;
        dp[1]=costs[0]+1;
        int one=INT_MAX,two=INT_MAX,three=INT_MAX;
        for(i=2;i<=n;i++){
            one = costs[i-1]+1+dp[i-1];
            two=costs[i-1]+4+dp[i-2];
            if(i>=3){
                three=costs[i-1]+9+dp[i-3];
            }
            dp[i]=mini(one,two,three);
        }
        return dp[n];
    }
};