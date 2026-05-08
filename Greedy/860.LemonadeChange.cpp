/*
Time Complexity: O(N) for iterating through the bills array, where N is the number of customers.
Space Complexity: O(1) for using a constant amount of space to keep track of the
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int i,five=0,ten=0,twenty=0;
        for(i=0;i<n;i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five<1)
                return false;
                five--;
                ten++;
            }
            else if(bills[i]==20){
                if(five<1)
                return false;
                if(five<3 && ten<1)
                return false;
                if(ten>0){
                    ten--;
                    five--;
                }
                else{
                    five-=3;
                }
                twenty++;
            }
        }
        return true;
    }
};