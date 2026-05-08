/*
Trick: Sort the people in descending order of height, and if two people have the same height, sort them in ascending order of the number of people in front of them. Then, insert each person into the result list at the index equal to the number of people in front of them. This way, we ensure that taller people are placed before shorter people, and the number of people in front of each person is correctly maintained.
Time Complexity: O(N^2) for the sorting and insertion operations, where N is the number of people.
Space Complexity: O(1) if we don't count the space used by the sorting algorithm.
*/
class Solution {
public:
    static bool customSort(vector<int>&v1, vector<int>&v2){
        if(v1[0]==v2[0])
        return v1[1]<v2[1];
        return v1[0]>v2[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>res;
        sort(people.begin(),people.end(),customSort);
        for(auto& person: people){
            res.insert(res.begin()+person[1],person);
        }
        return res;
    }
};