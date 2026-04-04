// iterate over each character, treat it as the center and try expanding left and right.
// Handle both odd length and even length palindromic substrings
class Solution {
public:
    void expand(int l, int r, int& start, int& maxLen,int n, string s){
        while(l>=0 && r<=n-1 && s[l]==s[r]){
            int len = r-l+1;
            if(len>maxLen){
                start=l;
                maxLen=len;
            }
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
       int n=s.length();
       int start=0,maxLen=1;
       int i;
       for(i=0;i<n;i++){
        expand(i,i,start,maxLen,n,s);
        expand(i,i+1,start,maxLen,n,s);
       }
       return s.substr(start,maxLen);
    }
};