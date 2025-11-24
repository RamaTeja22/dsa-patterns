class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>numbers(n);
        numbers.clear();
        int i;
        for(i=1;i<n;i++){
            fact*=i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k--;
        string res="";
        while(true){
            res+=to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.empty())
            break;
            k=k%fact;
            fact/=numbers.size();
        }
        return res;
    }
};