class Solution {
public:
    string removeDuplicates(string s, int k){
        int i=0,j;
        int n=s.length();
        vector<int>count(n);
        for(j=0;j<n;i++,j++){
            s[i]=s[j];
            count[i]=i>0&&s[i-1]==s[j]?count[i-1]+1:1;
            if(count[i]==k){
                i-=k;
            }
        }
        return s.substr(0,i);
    }
};

// Alternative Solution using stack
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(char c:s){
            if(st.empty() || st.top().first!=c){
                st.push({c,1});
            }
            else{
                st.top().second++;          
                if(st.top().second==k){
                    st.pop();
                }
            }
        }
        string res="";
        while(!st.empty()){
            res=string(st.top().second,st.top().first)+res;
            st.pop();
        }
        return res;
    }
};