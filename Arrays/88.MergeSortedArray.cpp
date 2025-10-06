// go from right to left in filling the nums1, decide each spot, who of nums1,nums2 will take it.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int firstptr=m-1;
        int secondptr=n-1;
        int combined=m+n-1;
        while(secondptr>=0){
        // we have to finish iterating nums2, as every element in nums2 needs to enter nums1.
            if(firstptr>=0 && nums1[firstptr]>nums2[secondptr]){
                // avoid index out of bounds in nums1, firstptr
                 nums1[combined]=nums1[firstptr];
                 firstptr--;
            }
            else{
                 nums1[combined]=nums2[secondptr];
                 secondptr--;
            }
            combined--;
        }
    }
};