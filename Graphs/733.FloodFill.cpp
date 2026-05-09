/*
Trick: Use Depth First Search (DFS) to explore the connected components of the image. Start from the given pixel and change its color, then recursively do the same for its neighboring pixels (up, down, left, right) that have the same original color.
Time Complexity: O(N) for visiting each pixel at most once, where N is the total number of pixels in the image.
Space Complexity: O(N) for the recursion stack in the worst case when all pixels are the same color and we need to change all of them. In practice,
*/
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,int row, int col, int newColor,int originalColor){
        if(i<0||i>=row||j<0||j>=col||image[i][j]!=originalColor)
        return;
        image[i][j]=newColor;
        dfs(i+1,j,image,row,col,newColor,originalColor);
        dfs(i-1,j,image,row,col,newColor,originalColor);
        dfs(i,j+1,image,row,col,newColor,originalColor);
        dfs(i,j-1,image,row,col,newColor,originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        int originalColor=image[sr][sc];
        if(originalColor==color){
            return image;
        }
        int i,j;
        dfs(sr,sc,image,row,col,color,originalColor);
        return image;
    }
};