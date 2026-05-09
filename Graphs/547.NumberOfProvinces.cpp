/*
Trick: Use Depth First Search (DFS) to explore the graph represented by the isConnected matrix. Each time we encounter an unvisited node, we perform a DFS to mark all nodes in the same province as visited. The number of times we initiate a DFS corresponds to the number of provinces.
Time Complexity: O(N^2) for traversing the isConnected matrix, where N is the number of cities.
Space Complexity: O(N) for the visited array and the recursion stack in the worst case.
*/
class Solution {
public:
    void dfs(int i,vector<vector<int>>& isConnected,vector<bool>& vis, int n){
        vis[i]=true;
        for(int neighbour=0;neighbour<n;neighbour++){
            if(isConnected[i][neighbour]==1 && !vis[neighbour]){
                dfs(neighbour,isConnected,vis,n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis,n);
                provinces++;
            }
        }
        return provinces;
    }
};