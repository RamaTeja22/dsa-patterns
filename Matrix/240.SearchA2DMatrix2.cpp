// Start with top right and eliminate a row or column in each iteration
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int r=0;
        int c=col-1;
        while(r<row && c>=0){
            int curr=matrix[r][c];
            if(curr==target)
            return true;
            if(curr>target)
            c--;
            else
            r++;
        }
        return false;
    }
};