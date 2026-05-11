/*
Trick: Use Topological Sorting (Kahn's Algorithm) to detect if there is a cycle in the directed graph. If we can process all courses, then there is no cycle and we can finish all courses.
Time Complexity: O(V + E) where V is the number of courses and E is the number of prerequisites.
Space Complexity: O(V) for the in-degree array and the queue.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);
        for(auto&preq: prerequisites){
            int course=preq[0];
            int pre=preq[1];
            adj[pre].push_back(course);
            inDegree[course]++;
        }
        int i;
        queue<int>q;
        for(i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            cnt++;
            for(int v:adj[curr]){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }
        return cnt==numCourses;
    }
};