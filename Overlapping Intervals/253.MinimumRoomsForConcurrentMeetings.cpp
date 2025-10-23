// always need to min and max while iterach each element => Heap
int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int rooms=1;
        int i;
        int n=start.size();
        vector<vector<int>>meetings(n,vector<int>(2,0));
        for(i=0;i<n;i++){
            meetings[i][0]=start[i];
            meetings[i][1]=end[i];
        }
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(i=0;i<n;i++){
            if(!pq.empty() && pq.top() <= meetings[i][1]){
                pq.pop();
            }
            pq.push(meetings[i][1]);
        }
        return pq.size();
    }