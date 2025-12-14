class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,-1);
        stack<int>st; // store indices
        int i;
        // Traverse the array twice, circular simulation
        for(i=0;i<2*n;i++){
            // This means the current elem is eligible as greater right element of someone.
            while(!st.empty()&&nums[st.top()]<nums[i%n]){
                res[st.top()]=nums[i%n];
                st.pop();
            }
            // Only push from first pass to avoid reprocessing
            if(i<n){
                st.push(i);
            }
        }
        return res;
    }
};