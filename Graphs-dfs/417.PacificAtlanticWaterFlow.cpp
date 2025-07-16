class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis, int prevHeight,vector<vector<int>>& heights, int rows, int cols  ){
        if(i<0 || i>=rows || j<0 || j>=cols || vis[i][j] || heights[i][j]<prevHeight){
            return;
        }
        vis[i][j]=true;
        dfs(i+1,j,vis,heights[i][j],heights,rows,cols);
        dfs(i-1,j,vis,heights[i][j],heights,rows,cols);
        dfs(i,j+1,vis,heights[i][j],heights,rows,cols);
        dfs(i,j-1,vis,heights[i][j],heights,rows,cols);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols = heights[0].size();
        vector<vector<bool>>pac(rows,vector<bool>(cols,false));
        vector<vector<bool>>at(rows,vector<bool>(cols,false));
        vector<vector<int>>res;
        int i=0,j=0;
        for(i=0;i<cols;i++){
            dfs(0,i,pac,0,heights,rows,cols);
            dfs(rows-1,i,at,0,heights,rows,cols);
        }
        for(j=0;j<rows;j++){
            dfs(j,0,pac,0,heights,rows,cols);
            dfs(j,cols-1,at,0,heights,rows,cols);
        }

        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                if(pac[i][j] && at[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};