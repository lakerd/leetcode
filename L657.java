class Solution {
public:
    bool judgeCircle(string moves) {
        int vert = 0;
        int horiz = 0;
        
        for (auto c : moves) {
            if (c == 'U') vert++;
            else if (c == 'D') vert--;
            else if (c == 'L') horiz--;
            else if (c == 'R') horiz++;
        }
        
        return vert == 0 && horiz == 0;
    }
};
