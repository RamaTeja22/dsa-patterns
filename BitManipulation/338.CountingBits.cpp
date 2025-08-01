// When it comes to even numbers, i.e, 2,4,6,8, their binary should be like '10', '100', '110', '1000' so one notable difference is their unit digit is always 0, which means when you call >> 1- shift one bit rightwards and also means dividing by 2- would cause no change to the count of '1' in the binary string.

// Vice versa, when you meet odd numbers, shifting one bit rightwards always eliminates one '1' digit from original binary string, that is why we should "compensate" one '1' character to the count.

// To sum up, when you meet even number the count of '1's is always the same as its half number, on the other hand, remember to plus one to the odds' half number.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1);
        int i;
        for(i=1;i<=n;i++){
            res[i]=res[i/2]+i%2;
        }
        return res;
    }
};