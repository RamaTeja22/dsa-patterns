/*
Trick: Use Breadth First Search (BFS) to simulate the rotting process. Start from all initially rotten oranges and propagate the rotting to adjacent fresh oranges level by level.
Time Complexity: O(M*N) where M is the number of rows and N is the number of columns in the grid.
Space Complexity: O(M*N) for the queue storing the positions of rotten oranges.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>al;
        int fresh=0,minutes=0;
        int i,j;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    al.push({i,j});
                }
            }
        }

        vector<pair<int,int>>dirs{{-1,0},{1,0},{0,1},{0,-1}};
        if(fresh==0)
        return 0;
        while(!al.empty() && fresh!=0){
            minutes++;
            int size=al.size();
            for(i=0;i<size;i++){
                pair<int,int>curr=al.front();
                al.pop();
                for(auto d:dirs){
                    int r=curr.first+d.first;
                    int c=curr.second+d.second;
                    if(r>=0 && r<row && c>=0 && c<col && grid[r][c]==1){
                        grid[r][c]=2;
                        fresh--;
                        al.push({r,c});
                    }
                }
            }
        }

        return fresh==0?minutes:-1;
    }
};