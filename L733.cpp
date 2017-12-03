#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor)
            return image;
        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void fill(vector<vector<int>>& image, size_t x, size_t y, int oldColor, int newColor) {
        if (x < 0 || y < 0)
            return;
        if (x >= image.size()) 
            return;
        if (y >= image[x].size())
            return;
        if (image[x][y] != oldColor)
            return;

        image[x][y] = newColor;

        fill(image, x + 1, y, oldColor, newColor);
        fill(image, x - 1, y, oldColor, newColor);
        fill(image, x, y + 1, oldColor, newColor);
        fill(image, x, y - 1, oldColor, newColor);
    }

};

int main() {
    Solution s;
    vector<vector<int>> v = {
        {0, 0, 0},
        {0, 1, 1},
    };
    s.floodFill(v, 1, 1, 1);

    for (auto x : v) {
        for (auto k : x) cout << k << " ";
        cout << "\n";
    }

    return 0;
}
