class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        int placed = 0;
        int len = flowerbed.size();
        int i = 0;
        while (i < len) {
            while (i < len && flowerbed[i] == 1) {
                ++i;
            }
            if (i + 1 >= len) {
                placed += placeFlower(flowerbed, i);
            } else if (flowerbed[i + 1] == 0) {
                placed += placeFlower(flowerbed, i);
            }
            if (placed == n) {
                return true;
            }
            ++i;
        }
        return placed == n;
    }
    int placeFlower(vector<int>& flowerbed, int i) {
        if (i - 1 < 0) {
            flowerbed[i] = 1;
            return 1;
        }
        if (flowerbed[i - 1] == 0) {
            flowerbed[i] = 1;
            return 1;
        }
        return 0;
    }
};
