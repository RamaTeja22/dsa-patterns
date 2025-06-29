  int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        freq[0]=-1;
        int maxLength=0;
        int i,cnt=0;
        for(i=0;i<n;i++){
            if(nums[i]==0){
                cnt--;
            }
            else{
                cnt++;
            }
            if(freq.find(cnt)!=freq.end()){
            maxLength = max(maxLength,i-freq[cnt]);
            }
            else{
                freq[cnt]=i;
            }
        }
        return maxLength;
    }