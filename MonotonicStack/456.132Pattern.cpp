class Solution {
public:
    bool find132pattern(vector<int>& nums) {
      int n = nums.size();
      stack<int>st; // for finding potential 'j'
      int i;
      int third=INT_MIN;  // best candidate for 'k'
      for(i=n-1;i>=0;i--){
        int num = nums[i]; // 'i'
        // i<k check
        if(num<third)
        return true;
        // pop all elements smaller than 'i'
        while(!st.empty() && st.top()<num){
            third=st.top();
            st.pop();
        }
        st.push(num);
      }
      return false;
    }
};