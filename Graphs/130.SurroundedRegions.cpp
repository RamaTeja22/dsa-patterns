/*
Trick: Use Depth First Search (DFS) to mark all 'O' cells that are connected to the border. Then, flip all remaining 'O' cells to 'X' and restore the marked cells to 'O'.
Time Complexity: O(M*N) where M is the number of rows and N is the number of columns in the matrix.
Space Complexity: O(M*N) for the recursive call stack in the worst case.
*/
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,int m,int n){
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }
        board[i][j]='A';
        dfs(i+1,j,board,m,n);
        dfs(i-1,j,board,m,n);
        dfs(i,j+1,board,m,n);
        dfs(i,j-1,board,m,n);
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int i,j;
        
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(0, j, board, m, n);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, board, m, n);
        }
        
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, board, m, n);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board, m, n);
        }

         for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; 
                } else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};