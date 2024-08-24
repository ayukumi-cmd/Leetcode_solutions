class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> idxMap;
    RandomizedSet() { }

    bool insert(int val) {
        if (idxMap.find(val) != idxMap.end()) return false;
        nums.push_back(val);
        idxMap[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (idxMap.find(val) == idxMap.end()) return false;
        int last_num = nums.back();
        int rm_idx= idxMap[val];
        idxMap[last_num] = rm_idx;
        nums[rm_idx] = last_num;
        nums.pop_back();
        idxMap.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};