/*
Trick: Use a depth counter to keep track of the current level of nested parentheses. For each character:
- If it's '(', increment the depth counter. If the depth is greater than 1, it means we are inside an outer parenthesis, so we add it to the result string.
- If it's ')', decrement the depth counter. If the depth is greater than 0 after decrementing   it, it means we are still inside an outer parenthesis, so we add it to the result string.
Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(n) for the result string.
*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=0;
        string res="";
        for(char c:s){
            if(c=='('){
                if(depth!=0){
                    res+=c;
                }
                depth++;
            }else if(c==')'){
                depth--;
                if(depth!=0){
                    res+=c;
                }
            }
        }
        return res;
    }
};