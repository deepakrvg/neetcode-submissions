class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> temp = mp[key];
        auto it = upper_bound(temp.begin(), temp.end(), timestamp, [](int timestamp, const pair<string, int>& ts) {
            return timestamp < ts.second;
        });
        if (temp.size() == 0 || it == temp.begin()) return "";
        if (it != temp.end()) {
            it--;
            return temp[it - temp.begin()].first;
        }
        return temp[temp.size() - 1].first;
    }
};
