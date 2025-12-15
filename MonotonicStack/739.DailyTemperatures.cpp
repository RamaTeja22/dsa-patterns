class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>res(n,0);
        int i;
        stack<int>st;
        for(i=0;i<n;i++){
            while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};