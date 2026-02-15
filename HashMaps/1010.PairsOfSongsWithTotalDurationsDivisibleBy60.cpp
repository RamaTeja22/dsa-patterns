class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        unordered_map<int,int>freq;
        for(int cc: time){
            freq[cc%60]++;
        }
        long long res=0;
        if(freq[0]>1){
            long long cnt=freq[0];
            res+=cnt*(cnt-1)/2;
        }
        if(freq[30]>1){
            long long cnt=freq[30];
            res+=cnt*(cnt-1)/2;
        }
        int i;
        for(i=1;i<30;i++){
            res+=freq[i]*freq[60-i];
        }
        return (int)res;
    }
};