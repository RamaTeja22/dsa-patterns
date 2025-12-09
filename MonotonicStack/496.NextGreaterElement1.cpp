class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    int m= nums1.size();
    unordered_map<int, int> mp;
    stack<int> st;
    int i;
    for(i=n-1;i>=0;i--){
        while(!st.empty() && nums2[i]>st.top()){
            st.pop();
        }
        if(!st.empty()){
            mp[nums2[i]]=st.top();
        }
        st.push(nums2[i]);
    }
    for(i=0;i<m;i++){
        nums1[i]=mp.find(nums1[i])!=mp.end() ? mp[nums1[i]] : -1;
    }
    return nums1;
  }
};