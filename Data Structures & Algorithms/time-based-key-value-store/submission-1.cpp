class TimeMap {
public://approach 2 : map based
unordered_map<string,map<int,string>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!mpp.count(key))return "";
        auto &mp = mpp[key];
        auto it = mp.upper_bound(timestamp);
        if(it == mp.begin())return "";
        --it;
        return it->second;
    }
};
