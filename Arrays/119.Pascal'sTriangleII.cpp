 vector<int> getRow(int rowIndex) {
        vector<int>res(rowIndex+1,0);
        res[0]=1;
        int i,j;
        for(i=1;i<=rowIndex;i++){
            for(j=i;j>=1;j--){
                res[j]+=res[j-1];
            }
        }
        return res;
    }