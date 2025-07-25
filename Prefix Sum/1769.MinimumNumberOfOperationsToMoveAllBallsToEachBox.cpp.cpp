class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        int i;
        vector<int>res(n,0);

        // Left Pass
        int totalMoves=0 // NO.of balls to the left
        int ballCount=0; // Total Moves Needed to bring all left balls to current box
        for(i=0;i<n;i++){
            res[i]=totalMoves;
            ballCount+=boxes[i]-'0'; // count for future boxes
            totalMoves+=ballCount; // each ball contributes 1 extra step for next box
        }
        totalMoves=0;
        ballCount=0;
        for(i=n-1;i>=0;i--){
            res[i]+=totalMoves;
            ballCount+=boxes[i]-'0';
            totalMoves+=ballCount;
        }
        return res;
    }
};