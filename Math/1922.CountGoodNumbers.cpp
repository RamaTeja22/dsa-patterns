class Solution {
const int MOD = 1e9+7;
public:
    
    long long pow(long long x, long long n){
        long long res=1;
        while(n>0){
            if(n%2==0){
                n/=2;
                x=(x*x)%MOD;
            }
            else{
                res=(x*res)%MOD;
                n--;
            }
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long evenPow = pow(5,even);
        long long oddPow = pow(4,odd);
        return (evenPow*oddPow)%MOD;
    }
};