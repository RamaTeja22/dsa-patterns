#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum coins needed to make amount i
        vector<int> dp(amount + 1, amount + 1);  // initialize with "infinity"
        dp[0] = 0;  // 0 coins to make 0

        // For each amount from 1 to 'amount'
        for (int i = 1; i <= amount; i++) {
            // Try each coin
            for (int coin : coins) {
                if (coin <= i) {  // can we use this coin?
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] is still > amount, it means we couldn't make it
        return dp[amount] > amount ? -1 : dp[amount];
    }
};