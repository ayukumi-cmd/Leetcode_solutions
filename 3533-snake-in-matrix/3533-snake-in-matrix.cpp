class Solution {
public:
    int finalPositionOfSnake(int girdSize, vector<string>& commands) {
        int x = 0, y = 0, n = commands.size();
        for(int i = 0; i < n; i++){
            string s = commands[i];
            if(s == "UP"){
                x--;
            }
            else if(s == "DOWN"){
                x++;
            }
            else if(s == "RIGHT"){
                y++;
            }
            else{
                y--;
            }
        }
        return (x * girdSize) + y;
    }
};