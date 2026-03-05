class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0) {
                    temp[i] = min(temp[2 * i], temp[2 * i + 1]);
                } else {
                    temp[i] = max(temp[2 * i], temp[2 * i + 1]);
                }
            }
            n/=2;
        }
        return temp[0]; 
    }
};