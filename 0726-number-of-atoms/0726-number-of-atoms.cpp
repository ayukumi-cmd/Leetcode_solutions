
class Solution {
public:

    string countOfAtoms(string formula) {
        int n = formula.length();
        
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());

        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr= st.top();
                st.pop();
                i++;
                string multiplier;
                while (i < formula.length() && isdigit(formula[i])) {
                    multiplier += formula[i];
                    i++;
                }
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& it : curr) {
                        curr[it.first] = (it.second) * mult;
                    }
                }

                for (auto& it : curr) {
                    st.top()[it.first] += it.second;
                }
            } else {
                string currAtom;
                currAtom += formula[i];
                i++;
                while (i < formula.length() && islower(formula[i])) {
                    currAtom += formula[i];
                    i++;
                }

                string currCount;
                while (i < formula.length() && isdigit(formula[i])) {
                    currCount += formula[i];
                    i++;
                }

                int count = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currAtom] += count;
            }
 
        }
        
        map<string, int> sortedMap(begin(st.top()), end(st.top()));

        string result;
        for (auto& it : sortedMap) {
            result += it.first;
            if (it.second> 1) {
                result += to_string(it.second);
            }
        }

        return result;
    }
};

