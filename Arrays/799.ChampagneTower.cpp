class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>currRow(1,poured);
        int i,j;
        for(i=0;i<=query_row;i++){
            vector<double>nextRow(i+2,0);
            for(j=0;j<i+1;j++){
                if(currRow[j]>1){
                    nextRow[j]+=(currRow[j]-1)*0.5;
                    nextRow[j+1]+=(currRow[j]-1)*0.5;
                    currRow[j]=1;
                }
            }
            if(i!=query_row){
                currRow=nextRow;
            }
        }
        return currRow[query_glass];
    }
};