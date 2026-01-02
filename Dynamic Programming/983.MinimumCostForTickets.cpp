class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n=days.size();
       unordered_set<int>travelDays(days.begin(),days.end());
       int i;
       int lastDay = days.back();
       vector<int>dp(lastDay+1,0);
       for(i=1;i<=lastDay;i++){
        if(travelDays.find(i)==travelDays.end()){
            dp[i]=dp[i-1];
        }
        else{
            int dayPass = dp[i-1]+costs[0];
            int weekPass = dp[max(0,i-7)]+costs[1];
            int monthPass = dp[max(0,i-30)]+costs[2];
            dp[i]=min(dayPass,min(weekPass,monthPass));
        }
       }
       return dp[lastDay];
    }
};