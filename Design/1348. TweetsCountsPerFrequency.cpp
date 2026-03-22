class TweetCounts {
public:
    unordered_map<string,multiset<int>>al;
    TweetCounts() {
        al.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        al[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int delta = freq == "minute" ? 60 : freq == "hour" ? 3600 : 86400;
        int buckets=((endTime-startTime)/delta) + 1;
        vector<int>res(buckets,0);
        auto& times=al[tweetName];
        for(auto it=times.lower_bound(startTime);it!=times.end() && *it<=endTime; it++){
            int bucketIdx = (*it-startTime)/delta;
            res[bucketIdx]++;
        }
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */