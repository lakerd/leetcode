class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int> result;
        if (len == 0) {
            return result;
        }
        if (len == 1) {
            return nums;
        }

        int count1 = 0;
        int count2 = 0;

        int a = 0;
        int b = 1;

        for (int num : nums) {
            if (num == a) {
                ++count1;
            } else if (num == b) {
                ++count2;
            } else if (count1 == 0) {
                count1 = 1;
                a = num;
            } else if (count2 == 0) {
                count2 = 1;
                b = num;
            } else {
                --count1;
                --count2;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == a) {
                ++count1;
            } else if (num == b) {
                ++count2;
            }
        }

        if (count1 > len / 3) result.push_back(a);
        if (count2 > len / 3) result.push_back(b);

        return result;
    }
};
