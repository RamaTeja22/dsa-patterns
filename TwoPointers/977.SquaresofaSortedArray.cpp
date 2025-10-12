// Sorted Array, => largest in result array could either come up from leftmost/rightmost element always.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1,curr;
        int i;
        vector<int>res(n);
        for(curr=n-1;curr>=0;curr--){
            if(abs(nums[left])<abs(nums[right])){
                res[curr]=nums[right]*nums[right];
                right--;
            }
            else{
                res[curr]=nums[left]*nums[left];
                left++;
            }
        }
        return res;
    }
};