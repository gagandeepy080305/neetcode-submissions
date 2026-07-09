class TimeMap {
public://optimal , approach 3 : composite structure approach
unordered_map<string,map<int,string>>store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!store.count(key))return "";
        auto &mp = store[key];
        auto it = mp.upper_bound(timestamp);
        if(it == mp.begin())return "";
        --it;
        return it->second;
    }
};
