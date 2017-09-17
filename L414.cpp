class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2)
            return std::max(nums[0], nums[1]);
        
        std::set<int> s;
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        
        for (int num : nums) {
            if (q.size() < 3 && s.find(num) == s.end()) {
                q.push(num);
                s.insert(num);
                continue;
            }
            
            int top = q.top();
            if (num > top && s.find(num) == s.end()) {
                q.pop();
                q.push(num);
                s.erase(top);
                s.insert(num);
            }
        }
        
        int last;
        if (q.size() < 3) {
            while (q.size() > 0) {
                last = q.top();
                q.pop();
            }
            return last;
        }

        return q.top();
    }
};