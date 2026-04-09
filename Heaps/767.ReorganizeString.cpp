class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        // Count Freqs
        vector<int>count(26,0);
        int i;
        for(char c:s){
            count[c-'a']++;
        }
        priority_queue<pair<int,char>>pq;
        // Dummy Prev Character
        pair<int,char>prev={-1,'#'};
        for(i=0;i<26;i++){
            if(count[i]>0){
                pq.push({count[i],'a'+i});
            }
        }
        string res="";
        while(!pq.empty()){
            pair<int,char>curr=pq.top();
            pq.pop();
            res+=curr.second;
            curr.first--;
            // "Blocked" from being used in current step
            if(prev.first>0){
                pq.push(prev);
            }
            prev=curr;
        }
        return res.length()==n?res:"";
    }
};