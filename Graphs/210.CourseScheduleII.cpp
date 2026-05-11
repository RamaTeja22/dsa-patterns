/*
Trick: Use Topological Sorting (Kahn's Algorithm) to find the order of courses. If we can process all courses, then there is no cycle and we can finish all courses.
Time Complexity: O(V + E) where V is the number of courses and E is the number of prerequisites.
Space Complexity: O(V) for the in-degree array and the queue.
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>res;
        vector<int>inDegree(numCourses,0);
        int i;
        for(auto& preqs: prerequisites){
            int course=preqs[0];
            int pre=preqs[1];
            adj[pre].push_back(course);
            inDegree[course]++;
        }
        queue<int>q;
        for(i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            for(int v: adj[curr]){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }
        return res.size()==numCourses?res:vector<int>();
    }
};