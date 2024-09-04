
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>, int> mp; 
        int ans = INT_MIN;
        int x = 0, y = 0, side = 1;

        for(int i = 0; i < obstacles.size(); i++){
            mp.insert({{obstacles[i][0], obstacles[i][1]}, 1});
        }

        for(int i = 0; i < commands.size(); i++){
            int k = commands[i];
            int j = 0; 
            
            if(k >= 1 && k <= 9){
                if(side == 1){
                    for(j = 1; j <= k; j++){
                        if(mp.find({x, y + j}) != mp.end()){
                            break;
                        }
                    }
                    y += j - 1;
                }
                if(side == -1){
                    for(j = 1; j <= k; j++){
                        if(mp.find({x, y - j}) != mp.end()){
                            break;
                        }
                    }
                    y -= j - 1;
                }
                if(side == 2){
                    for(j = 1; j <= k; j++){
                        if(mp.find({x + j, y}) != mp.end()){
                            break;
                        }
                    }
                    x += j - 1;
                }
                if(side == -2){
                    for(j = 1; j <= k; j++){
                        if(mp.find({x - j, y}) != mp.end()){
                            break;
                        }
                    }
                    x -= j - 1;
                }
            } else if(k == -1){
                if(side == 1) { side = 2; }
                else if(side == -1) { side = -2; }
                else if(side == 2) { side = -1; }
                else if(side == -2) { side = 1; }
            } else if(k == -2){
                if(side == 1) { side = -2; }
                else if(side == -1) { side = 2; }
                else if(side == 2) { side = 1; }
                else if(side == -2) { side = -1; }
            }

            ans = max(ans, x * x + y * y);
        }

        return ans;
    }
};
