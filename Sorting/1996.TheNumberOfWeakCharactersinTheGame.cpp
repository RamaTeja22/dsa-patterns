class Solution {
public:
    static bool sortAttacks(vector<int>&v1, vector<int>&v2){
        if(v1[0]==v2[0])
        return v1[1]<v2[1];
        return v1[0]>v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        sort(properties.begin(),properties.end(),sortAttacks);
        int i,maxDefense=0,weak=0;
        for(auto& player: properties){
            if(player[1]<maxDefense){
                weak++;
            }
            maxDefense=max(maxDefense,player[1]);
        }
        return weak;
    }
};