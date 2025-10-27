// Brute - n2
// Sort -> just compare neighbours for duplicates nlogn
// HashSet - n
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>kk;
        int i;
        for(i=0;i<n;i++){
            if(kk.contains(nums[i])){
                return true;
            }
            kk.insert(nums[i]);
        }
        return false;
    }
};