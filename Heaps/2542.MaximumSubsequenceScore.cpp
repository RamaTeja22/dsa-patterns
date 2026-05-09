
/*
Trick: Sort the pairs in descending order of nums2 values. Then, use a min-heap to maintain the k elements with the highest nums1 values among the selected elements. This ensures that we always have the best possible subsequence score.
Time Complexity: O(N log N) for sorting and heap operations, where N is the number of elements.
Space Complexity: O(N) for the heap and the sorted array.
*/
class Solution {
public:
    static bool customSort(pair<int,int>&p1,pair<int,int>&p2){
        if(p1.second==p2.second)
        return p1.first>p2.first;
        return p1.second>p2.second;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>al;
        int i;
        long long maxScore=0;
        for(i=0;i<n;i++){
            al.push_back({nums1[i],nums2[i]});
        }
        sort(al.begin(),al.end(),customSort);
        priority_queue<int,vector<int>,greater<int>>pq;
        long long currSum=0;
        for(i=0;i<n;i++){
            int nums2=al[i].second;
            int nums1=al[i].first;
            currSum+=nums1;
            pq.push(nums1);
            if(pq.size()>k){
                currSum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                long long currScore=(long long)nums2*currSum;
                if(currScore>maxScore){
                    maxScore=currScore;
                }
            }
        }
        return maxScore;
    }
};