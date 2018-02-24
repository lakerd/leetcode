class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> degrees;
        for (int num : nums) {
            degrees[num]++;
        }
        int maxFreq = 0;

        for (const auto& entry : degrees) {
            if (entry.second > maxFreq) {
                maxFreq = entry.second;
            }
        }
        int answer = -1;
        int len = nums.size();
        for (const auto& entry : degrees) {
            if (entry.second != maxFreq) {
                continue;
            }
            int curFirst = -1;
            int curLast;
            int freqNum = entry.first;
            for (int i = 0; i < len; ++i) {
                if (nums[i] == freqNum) {
                    if (curFirst == -1) {
                        curFirst = i;
                        curLast = i;
                    } else {
                        curLast = i;
                    }
                }
            }
            if (answer == -1) {
                answer = curLast - curFirst + 1;
            } else {
                answer = min(answer, curLast - curFirst + 1);
            }
        }
        return answer;
    }
};
