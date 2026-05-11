/*
Trick: Use Breadth First Search (BFS) to update the matrix. Start from all 0s and propagate the distances to adjacent cells level by level.
Time Complexity: O(M*N) where M is the number of rows and N is the number of columns in the matrix.
Space Complexity: O(M*N) for the queue storing the positions of 0s.1
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>res(m,vector<int>(n,-1));
        int i,j;
        queue<pair<int,int>>q;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dirs{{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(auto& dir:dirs){
                int newR=r+dir[0];
                int newC=c+dir[1];
                if(newR>=0 && newR<m && newC>=0 && newC<n && res[newR][newC]==-1){
                    res[newR][newC]=1+res[r][c];
                    q.push({newR,newC});
                }
            }
        }
        return res;
    }
};