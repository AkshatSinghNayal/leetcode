class BusBooking {
public:
    vector<vector<int>> mp;
    int totalTime = 0;
    int count = 0;

    BusBooking(int n) {
        mp = vector<vector<int>>(n + 1, vector<int>(4, -1));
    }

    void toggle(string seat) {
        int sNo = stoi(seat.substr(1));
        char ch = seat[0];
        int idx = ch - 'A';

        if (mp[sNo][idx] == -1) {
            if (ch == 'B' || ch == 'C') {
                totalTime += 1;
                mp[sNo][idx] = 1;
            } else {
                if (ch == 'A') {
                    if (mp[sNo][1] != -1) {
                        totalTime += 3;
                        mp[sNo][idx] = 3;
                    } else {
                        totalTime += 1;
                        mp[sNo][idx] = 1;
                    }
                } else {
                    if (mp[sNo][2] != -1) {
                        totalTime += 3;
                        mp[sNo][idx] = 3;
                    } else {
                        totalTime += 1;
                        mp[sNo][idx] = 1;
                    }
                }
            }
            count++;
        } else {
            totalTime -= mp[sNo][idx];
            mp[sNo][idx] = -1;
            count--;
        }
    }

    int getTotalTime() {
        return totalTime;
    }

    int getMinTime() {
        return count;
    }
};