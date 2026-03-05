class Solution {
public:
    int minMaxGame(vector<int>& temp) {
        int n = temp.size();
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