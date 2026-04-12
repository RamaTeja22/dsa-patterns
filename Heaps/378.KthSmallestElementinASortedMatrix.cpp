class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        int col=matrix[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int i,j;
        // Initialize Min Heap with first element of each row
        for(i=0;i<row;i++){
            pq.push({matrix[i][0],i,0});
        }
        int res=0;
        // Pop K Times
        while(k--){
            auto curr=pq.top();
            pq.pop();
            int val = curr[0];
            int r=curr[1];
            int c=curr[2];
            res=val;
            // Push the next element in each row
            if(c<col-1){
                pq.push({matrix[r][c+1],r,c+1});
            }
        }
        return res;
    }
};