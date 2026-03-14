class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gasSum=accumulate(gas.begin(),gas.end(),0);
        int costSum=accumulate(cost.begin(),cost.end(),0);
        if(gasSum<costSum)
        return -1;
        int total=0;
        int i;
        for(i=0;i<n;i++){
            int index=i;
            while(total>=0 && index<n){
                total+=gas[index]-cost[index];
                index++;
            }
            if(total<0){
                total=0;
                continue;
            }
            else{
                return index;
            }
        }
        return -1;
    }
};