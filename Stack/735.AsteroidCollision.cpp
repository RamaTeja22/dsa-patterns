class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector<int>st;
        for(int asteroid:asteroids){
            while(!st.empty() && st.back()>0 && asteroid<0){
                if(st.back() > abs(asteroid)){
                    asteroid=0;
                    break;
                }
                else if(st.back()==abs(asteroid)){
                    st.pop_back();
                    asteroid=0;
                    break;
                }
                else{
                    st.pop_back();
                }
            }
            if(asteroid!=0)
            st.push_back(asteroid);
        }
        return st;
    }
};