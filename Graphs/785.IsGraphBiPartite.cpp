/*
Trick: Use Breadth First Search (BFS) to color the graph with two colors. If we can successfully color the entire graph with two colors such that no two adjacent nodes have the same color, then the graph is bipartite.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V) for the color array and the queue.
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        int i;
        for(i=0;i<n;i++){
            if(color[i]==-1){
                queue<int>q;
                q.push(i);
                color[i]=0;

                while(!q.empty()){
                    int u=q.front();
                    q.pop();
                    for(auto& v:graph[u]){
                        if(color[v]==-1){
                            color[v]=1-color[u];
                            q.push(v);
                        }else if(color[v]==color[u]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};