#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }
        
        bool used = false;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                if (used) return false;
                used = true;
                if (i - 1 == 0) {
                    nums[i - 1] = nums[i];
                } else {
                    if (i - 2 >= 0) {
                        if (nums[i - 2] <= nums[i]) {
                            nums[i - 1] = nums[i];
                        } else {
                            nums[i] = nums[i - 1];
                        }
                    } else {
                        nums[i - 1] = nums[i];
                    }
                }
            }
        }
        return true;
    }
};

using namespace std;

int main()
{
    vector<int> v {2,3,3,2,4};
    Solution s;
    cout << s.checkPossibility(v) << endl;
    return 0;
}
