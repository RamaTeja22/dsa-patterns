/*
Trick: Use a stack to check if the parentheses are balanced. For each opening parenthesis, push it onto the stack. For each closing parenthesis, check if it matches the most recent opening parenthesis.
Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(n) for the stack.
*/
class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(n%2==1)
        return false;
        stack<char>st;
        unordered_map<char,char>al={{']','['},{')','('},{'}','{'}};
        int i;
        for(i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty())
                return false;
                if(st.top()!=al[s[i]])
                return false;
                st.pop();
            }
        }
        return st.empty();
    }
};