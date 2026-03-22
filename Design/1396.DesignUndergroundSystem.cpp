// By using Vector, just retrieving the item for checkout would be O(n),
// Hashmap is the key for O(1) retrieval,
// By storing combo of Source System & Destination station in the statsMap, again
// retrieval is O(1) for computing stats. 

class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>checkInInfo;
    unordered_map<string,pair<int,int>>statsMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInInfo[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> checkInData=checkInInfo[id];
        string start=checkInData.first;
        int startTime=checkInData.second;
        string combo=start+"->"+stationName;
        int travelTime=t-startTime;
        statsMap[combo].first+=travelTime;   
        statsMap[combo].second++;
        checkInInfo.erase(id);
     }
    
    double getAverageTime(string startStation, string endStation) {
        string reqd=startStation+"->"+endStation;
        double total=statsMap[reqd].first;
        int count = statsMap[reqd].second;
        double avg=(double)(total/count);
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */