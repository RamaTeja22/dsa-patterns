/*
Trick: Use a greedy approach with a max heap to schedule courses. Sort courses by their deadlines and for each course, if we can take it, we add it to our schedule. If not, we check if replacing the longest course we've taken with the current course improves our schedule.
Time Complexity: O(n log n) where n is the number of courses.
Space Complexity: O(n) for the priority queue.
*/
class Solution {
public:
    static bool customSort(vector<int>& v1,vector<int>& v2){
        if(v1[1]==v2[1])
        return v1[0]<v2[0];
        return v1[1]<v2[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),customSort);
        priority_queue<int>pq;
        int curr_time=0;
        for(auto& course: courses){
            int duration=course[0];
            int deadline=course[1];
            curr_time+=duration;
            pq.push(duration);
            if(curr_time>deadline){
                curr_time-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};