// Brute force is O(n2)
// Trick is skip till both left & right chars are same, the moment they are unequal => we only need to check s(i+1,j) and s(i,j-1) are pallindromes or not.
// So we 'll know deleting either that left or right solves the problem
class Solution {
public:
    bool isP(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
            return isP(s,i+1,j) || isP(s,i,j-1);
        }
        return true;
    }
};