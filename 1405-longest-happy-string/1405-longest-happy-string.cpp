class Solution {
public:
    class comp {
    public:
        bool operator()(const pair<int, char>& a, const pair<int, char>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

    string longestDiverseString(int a, int b, int c) {
        string result = "";
        priority_queue<pair<int, char>, vector<pair<int, char>>, comp> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();

            if (result.empty()) {
                int use1 = min(2, count);
                result += string(use1, ch);
                count -= use1;
                if (count > 0)
                    pq.push({count, ch});
                continue;
            }

            if (result.back() == ch) {
                if (pq.empty())
                    break; 
                auto [count2, ch2] = pq.top();
                pq.pop();
                int use2 = min(1, count2);
                result += string(use2, ch2);
                count2 -= use2;
                if (count2 > 0)
                    pq.push({count2, ch2});
                pq.push({count, ch});
            } else {
                int use1 = min(2, count);
                result += string(use1, ch);
                count -= use1;
                if (count > 0)
                    pq.push({count, ch}); 
            }
        }
        return result;

    }
};