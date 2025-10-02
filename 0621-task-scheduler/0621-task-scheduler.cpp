class Solution {
public:
int leastInterval(vector<char>& tasks, int n) {
if (n == 0) {
return tasks.size();
}

    // Step 1: Count frequencies
    vector<int> freq(26, 0);
    for (int i = 0; i < tasks.size(); i++) {
        char c = tasks[i];
        freq[c - 'A']++;
    }

    // Step 2: Push frequencies into max heap
    priority_queue<int> pq;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            pq.push(freq[i]);
        }
    }

    int time = 0;

    // Step 3: Process tasks in cycles of n+1
    while (!pq.empty()) {
        vector<int> temp;
        int executed = 0;

        // pick up to n+1 tasks
        for (int i = 0; i <= n; i++) {
            if (!pq.empty()) {
                int cur = pq.top();
                pq.pop();

                cur = cur - 1;
                executed++;

                if (cur > 0) {
                    temp.push_back(cur);
                }
            }
        }

        // push remaining tasks back into heap
        for (int i = 0; i < temp.size(); i++) {
            pq.push(temp[i]);
        }

        // Step 4: Add time
        if (pq.empty()) {
            // no more tasks left, only add executed tasks
            time = time + executed;
        } else {
            // tasks still left, must count whole cycle
            time = time + (n + 1);
        }
    }

    return time;
}

};
