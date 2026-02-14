class Solution {
public:
    int countNibors(vector<vector<int>>& board, int i,int j, int row, int col){
        int a,b,cnt=0;
        for(a=i-1;a<=i+1;a++){
            for(b=j-1;b<=j+1;b++){
                if(a<0 || b<0 || a>=row || b>=col || (a==i && b==j))
                continue;
                if(board[a][b]==1 || board[a][b]==3)
                cnt++;
            }
        }
        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col= board[0].size();
        int i,j;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                int cmt=countNibors(board,i,j,row,col);
                if(board[i][j]==1){
                    if(cmt>=2 && cmt<=3){
                        board[i][j]=3;
                    }
                }
                else{
                    if(cmt==3){
                        board[i][j]=2;
                    }
                }
            }
        }

        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(board[i][j]<2){
                    board[i][j]=0;
                }
                else{
                    board[i][j]=1;
                }
            }
        }
    }
};