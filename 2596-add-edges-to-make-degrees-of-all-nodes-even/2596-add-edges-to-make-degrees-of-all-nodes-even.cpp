#include <vector>
#include <unordered_map>
#include <utility> // For std::pair

using namespace std;

// Define a custom hash function for std::pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // Hash combining
    }
};

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1, 0);
        unordered_map<pair<int, int>, int, pair_hash> mp;

        // Process the edges
        for (auto& it : edges) {
            pair<int, int> tp(it[0], it[1]);
            pair<int, int> tp2(it[1], it[0]);
            mp[tp]++;
            mp[tp2]++;
            degree[it[0]]++;
            degree[it[1]]++;
        }

        // Find nodes with odd degree
        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (degree[i] % 2) {
                odd.push_back(i);
            }
        }

        if (odd.size() == 0) {
            return true;
        }
        if (odd.size() != 4 && odd.size() != 2) {
            return false;
        }

        if (odd.size() == 2) {
            int a = odd[0], b = odd[1];
            pair<int, int> tp1(a, b);
            if (mp.find(tp1) == mp.end()) {
                return true;
            }
            for (int i = 1; i <= n; i++) {
                if (i != odd[0] && i != odd[1] && degree[i] % 2 == 0) {
                    if (mp.find({a, i}) == mp.end() && mp.find({b, i}) == mp.end()) {
                        return true;
                    }
                }
            }
            return false;
        }

        int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
        pair<int, int> tp1(a, b);
        pair<int, int> tp2(c, d);
        pair<int, int> tp3(a, c);
        pair<int, int> tp4(b, d);
        pair<int, int> tp5(a, d);
        pair<int, int> tp6(b, c);

        if (mp.find(tp1) == mp.end() && mp.find(tp2) == mp.end()) {
            return true;
        }
        if (mp.find(tp3) == mp.end() && mp.find(tp4) == mp.end()) {
            return true;
        }
        if (mp.find(tp5) == mp.end() && mp.find(tp6) == mp.end()) {
            return true;
        }

        return false;
    }
};
