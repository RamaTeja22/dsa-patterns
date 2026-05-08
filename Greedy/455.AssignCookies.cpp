/*
After sorting, the greed pointer moves only if greed satisfied, but cookie pointer always moves as it is either consumed or smaller for the current greed.
Time Complexity: O(N log N + M log M) for sorting the arrays, where N is the number of children and M is the number of cookies.
Space Complexity: O(1) if we don't count the space used by the sorting algorithm.
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children=g.size();
        int cookies=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        while(i<children && j<cookies){
            if(g[i]<=s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};