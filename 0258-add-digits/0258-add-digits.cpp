class Solution {
public:
    int helperFunction(long long num) {
        long long sum = 0;
        long long temp = num;

        while (temp) {              
            sum += temp % 10;
            temp /= 10;
        }

        return (int)sum;
    }

    int addDigits(int num) {
        if (num == 0) return 0;

        while (num >= 10) {            
            num = helperFunction(num);
        }

        return num;
    }
};
