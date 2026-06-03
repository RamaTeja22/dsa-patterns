/*
    Longest Common Subsequence
    Time Complexity: O(n1*n2)
    Space Complexity: O(n1*n2)
*/
// recursive approach
class Solution {
public:
    int lcs(int i,int j, string text1, string text2){
        if(i<0 || j<0)
        return 0;
        if(text1[i]==text2[j])
        return 1+lcs(i-1,j-1,text1,text2);
        return max(lcs(i-1,j,text1,text2),lcs(i,j-1,text1,text2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        return lcs(n1-1,n2-1,text1,text2);
    }
};

// Tabulation approach
 int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        int i,j;
        for(i=1;i<=n1;i++){
            for(j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }