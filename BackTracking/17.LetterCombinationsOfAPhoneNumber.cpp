class Solution {
public:
    void backtrack(string digits, string current, vector<string>&res,vector<string>&mapping,int index, int n){
        if(index>=n){
            res.push_back(current);
            return;
        }
        string letters = mapping[digits[index]-'0'];
        for(char c: letters){
            current.push_back(c);
            backtrack(digits,current,res,mapping,index+1,n);
            // it is currently, "ad"
            current.pop_back();
            // we are sending "a" to the next iteration, so res will be ae instead of ade
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return {};
        int n=digits.length();
        string current="";
        vector<string>res;
        vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtrack(digits,current,res,mapping,0,n);
        return res;
    }
};