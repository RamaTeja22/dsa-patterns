 static bool cc(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0)
        return 0;
        sort(intervals.begin(),intervals.end(),cc);
        int end = intervals[0][1];
        int i,cnt=1;
        for(i=1;i<n;i++){
            if(intervals[i][0]>=end){
                end = intervals[i][1];
                cnt++;
            }
        }
        return n-cnt;
    }