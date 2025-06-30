 vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
        int i,n=intervals.size();
        vector<vector<int>>res;
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

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(n==0)
        return {newInterval};
        vector<vector<int>>cc;
        int i;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        cc = mergeIntervals(intervals);
        return cc;;
    }