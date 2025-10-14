class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        int i,j;
        for(i=0;i<numRows;i++){
            vector<int>cc(i+1,1);
            for(j=1;j<i;j++){
                cc[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(cc);
        }
        return res;
    }
};