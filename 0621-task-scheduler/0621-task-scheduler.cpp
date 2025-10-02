class Solution {
public:
int leastInterval(vector<char>& tasks, int n) {
if (n == 0) return tasks.size();


    vector<int> freq(26, 0);
    for (char c : tasks) freq[c - 'A']++;

    priority_queue<int> pq;
    for (int f : freq) if (f > 0) pq.push(f);

    int time = 0;
    while (!pq.empty()) {
        vector<int> temp;
        int executed = 0;

        // try to execute up to n+1 tasks in this cycle
        for (int i = 0; i <= n; ++i) {
            if (!pq.empty()) {
                int cur = pq.top(); pq.pop();
                cur--;
                executed++;
                if (cur > 0) temp.push_back(cur);
            }
        }

        // push unfinished tasks back into heap
        for (int v : temp) pq.push(v);

        // if there are still tasks left, this cycle was full length (n+1),
        // otherwise only count the tasks actually executed (no trailing idle).
        if (pq.empty()) time += executed;
        else time += (n + 1);
    }

    return time;
}

};
