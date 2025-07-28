class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();

        // dp[i][j] = length of common subarray ending at A[i-1] and B[j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLength = 0;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
                // else: dp[i][j] = 0 (already initialized)
            }
        }

        return maxLength;
    }
};