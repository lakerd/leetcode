class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        
        string result = "";
        
        int sign = 0;
        if (num < 0)
            sign = 1;
        
        num = abs(num);
        while (num > 0) {
            int c = num % 7;
            if (c < 10)
                result += c + '0';
            else
                result += c + 'A' - 10;
            num /= 7;
        }
        
        reverse(result.begin(), result.end());
        return sign ? ("-" + result) : result;
    }
};
