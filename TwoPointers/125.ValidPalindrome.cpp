// 1. isalnum library method in C++ for doing alphanumeric check
// 2. no direct toLowerCase or toUpperCase in C++, iterate each character and do tolower()
class Solution {
public:
    bool isPalindrome(string s) {
        string normalized="";
        int i;
        int n=s.length();
        for(char c:s){
            if(isalnum(c)){
                normalized+=c;
            }
        }
        int n2=normalized.length();
        for (auto& x : normalized) {
        x = tolower(x);
        }
        int left=0,right=n2-1;
        while(left<=right){
            if(normalized[left]!=normalized[right])
            return false;
            left++;
            right--;
        }
        return true;
    }
};