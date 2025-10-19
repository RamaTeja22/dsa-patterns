 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int i;
        for(i=0;i<n;i++){
            if(res.empty() || intervals[i][0] > res.back()[1]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }

     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int n=intervals.size();
        // sort by start times
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0];
        });
        // push the first sorted interval
        res.push_back(intervals[0]);
        int i;
        for(i=1;i<n;i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            // conditional check to decide to merge into current or push a new interval
            if(currStart<=res.back()[1]){
                res.back()[1]=max(currEnd,res.back()[1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }