class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row==0)
        return;
        int col = matrix[0].size();
        int i,j;
        vector<bool>rowTracker(row,false);
        vector<bool>colTracker(col,false);
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(matrix[i][j]==0){
                    rowTracker[i]=true;
                    colTracker[j]=true;
                }
            }
        }

        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(rowTracker[i] || colTracker[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

// The above solution is not O(1) space, so optimal solution is still possible.