// The algorithm requires a second verification pass because the candidates found in the first pass might not actually be majority elements, but the remaining potential members.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cand1=0,cnt1=0,cand2=0,cnt2=0;
        int i;
        for(i=0;i<n;i++){
            if(nums[i]==cand1){
                cnt1++;
            }
            else if(nums[i]==cand2){
                cnt2++;
            }
            else if(cnt1==0){
                cand1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                cand2=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(i=0;i<n;i++){
            if(nums[i]==cand1){
                cnt1++;
            }
            else if(nums[i]==cand2){
                cnt2++;
            }
        }
        vector<int>res;
        if(cnt1>n/3){
            res.push_back(cand1);
        }
        if(cnt2>n/3){
            res.push_back(cand2);
        }
        return res;
    }
};