class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(char cc:s){
            bool push=true;
            while(!st.empty() && st.top()==cc){
                st.pop();
                push=false;
            }
            if(push)
            st.push(cc);
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};