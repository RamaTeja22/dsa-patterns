/*
Trick: Use a single counter to keep track of the balance of parentheses. For each character:
- If it's '(', increment the counter.
- If it's ')', decrement the counter.
If the counter becomes negative at any point, it means we have more closing parentheses than opening ones up to that point. We need to add opening parentheses to fix this. At the end, if the counter is positive, it means we have more opening parentheses than closing ones, so we need to add closing parentheses.
Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(1) since we are using only a constant amount of space for the counter.
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0,curr=0;
        for(char c:s){
            if(c=='('){
                curr++;
            }
            else if(c==')'){
                curr--;
            }
            if(curr<0){
                cnt+=-1*curr;
                curr=0;
            }
        }
        if(curr>0)
        cnt+=curr;
        return cnt;
    }
};