/*
Trick: Use Depth First Search (DFS) to mark all 1s that are connected to the border. Then, count all remaining 1s.
Time Complexity: O(M*N) where M is the number of rows and N is the number of columns in the matrix.
Space Complexity: O(M*N) for the recursive call stack in the worst case.
*/
class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& grid,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1)
        return;
        grid[i][j]=0;
        dfs(i+1,j,grid,m,n);
        dfs(i-1,j,grid,m,n);
        dfs(i,j+1,grid,m,n);
        dfs(i,j-1,grid,m,n);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int i,j;
        for(j=0;j<n;j++){
            if(grid[0][j]==1) dfs(0,j,grid,m,n);
            if(grid[m-1][j]==1) dfs(m-1,j,grid,m,n);
        }
        for(i=0;i<m;i++){
            if(grid[i][0]==1) dfs(i,0,grid,m,n);
            if(grid[i][n-1]==1) dfs(i,n-1,grid,m,n);
        }

        int cnt=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};