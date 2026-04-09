class Solution {
public:
    // we just need to calculate how many idle spots are required.
    int leastInterval(vector<char>& tasks, int n) {
        int sz=tasks.size();
        int i;
        int max=0,maxCount=0;
        // maxCount tells us if there are multiple tasks with max frequency
        vector<int>count(26,0);
        for(i=0;i<sz;i++){
            count[tasks[i]-'A']++;
            if(max==count[tasks[i]-'A']){
                maxCount++;
            }
            else if(max<count[tasks[i]-'A']){
                maxCount=1;
                max=count[tasks[i]-'A'];
            }
        }

        int partCount = max-1;
        // if A & B are tasks with equal max freq, AB is treated as single unit X, so we subtract those from n.
        int partLength = n-(maxCount-1);
        int empty=partCount*partLength;
        // remaining spots for tasks other than max
        int available = sz-max*maxCount;
        int idle = std::max(0,empty-available);
        return idle+sz;
    }
};