/*
Trick: Use two counters to keep track of the minimum and maximum number of open parentheses that can be valid at any point in the string. For each character:
- If it's '(', increment both counters.
- If it's ')', decrement both counters.
- If it's '*', decrement the minimum counter (treating it as ')') and increment the maximum counter (treating it as '(').
If at any point the maximum counter becomes negative, return false. At the end, check if the minimum counter is zero to ensure all parentheses are balanced.
Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(1) since we are using only a constant amount of space for the
*/
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int mini=0,maxi=0;
        for(char c:s){
            if(c=='('){
                mini++;
                maxi++;
            }
            else if(c==')'){
                mini--;
                maxi--;
            }
            else{
                mini--;
                maxi++;
            }

            if(mini<0){
                mini=0;
            }
            if(maxi<0)
            return false;
        }
        return mini==0;
    }
};