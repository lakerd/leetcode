class Solution {
public:
    int pop(unsigned x)
    {
        x = x - ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x + (x >> 4)) & 0x0F0F0F0F;
        x = x + (x >> 8);
        x = x + (x >> 16);
        return x & 0x0000003F;
    }

    vector<int> countBits(int num) {
        vector<int> v;
        for (int i = 0; i <= num; i++) {
            v.push_back(pop(i));
        }
        return v;
    }
};