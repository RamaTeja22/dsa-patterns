#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        // dp[i][j] = side length of largest square ending at (i, j)
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxSide = 0;

        // Traverse each cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    // Base case: first row or first column
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // Extend the square
                        dp[i][j] = 1 + min({ dp[i-1][j],      // above
                                             dp[i][j-1],      // left
                                             dp[i-1][j-1] }); // diagonal
                    }

                    // Update the maximum side length
                    maxSide = max(maxSide, dp[i][j]);
                }
                // else: dp[i][j] = 0 (already initialized)
            }
        }

        return maxSide * maxSide;
    }
};