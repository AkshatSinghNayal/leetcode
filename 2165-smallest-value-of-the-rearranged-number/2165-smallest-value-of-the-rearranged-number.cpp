class Solution {
public:
    long long smallestNumber(long long num) {
        map<int, long long> mp;
        long long temp = num;
        bool flag = (num < 0);

        if (flag) temp = -temp;
        if (num == 0) return 0;

        while (temp > 0) {
            mp[temp % 10]++;
            temp /= 10;
        }

        long long sum = 0;

        if (flag) {
            // FIX 1: Loop from 9 down to 0 instead of 0 to 9
            for (int ele = 9; ele >= 0; ele--) {
                while (mp[ele] > 0) {
                    sum = sum * 10 + ele;
                    mp[ele]--;
                }
            }
            return -sum;
        } else {
            bool first = true;

            for (auto& [ele, count] : mp) {
                if (ele == 0) continue;

                if (first) {
                    sum = ele;
                    count--;
                    first = false;

                    // FIX 2: Moved your zero-loop right here!
                    while (mp[0] > 0) {
                        sum *= 10;
                        mp[0]--;
                    }
                }

                while (count > 0) {
                    sum = sum * 10 + ele;
                    count--;
                }
            }
        }

        return sum;
    }
};