class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int m = nums.at(0);
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(i) == m) count++;
            else count--;
            if (count == 0) {
                m = nums.at(i);
                count = 1;
            }
        }
        
        return m;
    }
};