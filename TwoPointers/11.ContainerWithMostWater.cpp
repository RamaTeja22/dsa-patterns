class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0,currArea=0;
        int n=height.size();
        int left=0,right=n-1;
        while(left<right){
            currArea = min(height[left],height[right])*(right-left);
            area=max(area,currArea);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};