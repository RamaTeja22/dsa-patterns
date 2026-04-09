class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        int n=points.size();
        // Use a max Heap(we are holding k closest real time, getting rid of bigger points real time, we are not storing all data)
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        int i;
        for(i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            int d=x*x+y*y;
            // by putting distance as first parameter, the max Heap uses distance as the comparator
            pq.push({d,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        // With this, result will be in reverse order of k smallest points, if required in ascending order, reverse the vector.
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};