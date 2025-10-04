class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i;
        for(i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        // if we enter here, its implies digits has become 000..n
        vector<int>newNumber(n+1,0);
        newNumber[0]=1;
        return newNumber;
    }
};