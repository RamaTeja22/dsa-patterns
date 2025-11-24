class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int dir=1,top=0,bottom=row-1,left=0,right=col-1;
        int i,j;
        vector<int>res;
        while(top<=bottom && left<=right){
            if(dir==1){
                dir++;
                for(i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir==2){
                dir++;
                for(i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir==3){
                dir++;
                for(i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else{
                dir=1;
                for(i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};