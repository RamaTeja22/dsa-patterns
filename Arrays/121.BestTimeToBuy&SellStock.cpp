// Brute Force :- O(n2), by mainitaing prefix minimum during single pass -> O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit=0,minPrice=prices[0];
        int i,j;
        for(i=1;i<n;i++){
            if(prices[i]>minPrice){
                int p = prices[i]-minPrice;
                maxProfit=max(maxProfit,p);
            }
             if(prices[i]<minPrice){
            minPrice = prices[i];
           }
        }
        return maxProfit;
    }
};