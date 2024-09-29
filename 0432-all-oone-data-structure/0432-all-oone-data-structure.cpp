
class AllOne {
public:
    map<string, int> key_freq;
    map<int, set<string>> freq_keys;

    AllOne() {}

    void inc(string key) {
        int freq = key_freq[key];
        
        if (freq > 0) {
            freq_keys[freq].erase(key);
            if (freq_keys[freq].empty()) {
                freq_keys.erase(freq);
            }
        }
        
        key_freq[key]++;
        freq_keys[key_freq[key]].insert(key);
    }
    
    void dec(string key) {
        if (key_freq.count(key) == 0) return;
        
        int freq = key_freq[key];
        
        freq_keys[freq].erase(key);
        if (freq_keys[freq].empty()) {
            freq_keys.erase(freq);
        }
        
        if (freq == 1) {
            key_freq.erase(key);
        } else {
            key_freq[key]--;
            freq_keys[key_freq[key]].insert(key);
        }
    }
    
    string getMaxKey() {
        if (freq_keys.empty()) return "";
        return *(freq_keys.rbegin()->second.begin());
    }
    
    string getMinKey() {
        if (freq_keys.empty()) return "";
        return *(freq_keys.begin()->second.begin());
    }
};
