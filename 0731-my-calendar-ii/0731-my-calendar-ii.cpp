class MyCalendarTwo {
public:
    vector<pair<int,int>> booked, dBooked;

    MyCalendarTwo() {

    }

    bool book(int startTime, int endTime) {
        int dStart, dEnd;
        vector<pair<int,int>> temp;

        if (!booked.empty()) {
            for (auto& [start, end] : booked) {

                if (start <= startTime && end >= startTime) {
                    dStart = max(start, startTime);
                    dEnd = min(end, endTime - 1);

                    for (auto& [s, e] : dBooked) {
                        if (max(s, dStart) <= min(e, dEnd))
                            return false;
                    }

                    temp.push_back({dStart, dEnd});
                }
                else if (startTime <= start) {
                    if (start <= endTime - 1) {

                        dStart = max(start, startTime);
                        dEnd = min(end, endTime - 1);

                        for (auto& [s, e] : dBooked) {
                            if (max(s, dStart) <= min(e, dEnd))
                                return false;
                        }

                        temp.push_back({dStart, dEnd});
                    }
                }
            }

            for (auto& it : temp)
                dBooked.push_back(it);
        }

        booked.push_back({startTime, endTime - 1});

        return true;
    }
};