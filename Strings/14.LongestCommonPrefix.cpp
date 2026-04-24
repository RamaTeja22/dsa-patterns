// Just sort the whole vector lexicographically
// Now just compare the first and last string to extract the common prefix.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref="";
        sort(strs.begin(),strs.end());
        string first=strs[0];
        int n=strs.size();
        string last=strs[n-1];
        int n1=first.length();
        int i;
        for(i=0;i<n1;i++){
            if(first[i]==last[i]){
                pref+=first[i];
            }
            else{
                break;
            }
        }
        return pref;
    }
};