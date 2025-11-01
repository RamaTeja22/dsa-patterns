class RandomizedSet {
public:
    unordered_map<int,int>b;
    vector<int>a;
    RandomizedSet() {
        a.clear();
    }
    
    bool insert(int val) {
        if(b.count(val)){
            return false;
        }
        b[val]=a.size();
        a.push_back(val);
        return true;
    }
    
    bool remove(int val) {
       if(!b.count(val)){
            return false;
       } 
       int index = b[val];
       if(index<a.size()-1){
        int lastNum = a.back();
        b[lastNum]=index;
        a[index]=lastNum;
       }
       b.erase(val);
       a.pop_back();
       return true;
    }
    
    int getRandom() {
        int n= a.size();
        return a[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */