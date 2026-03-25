class Solution{
    public :
    int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> freq;
    for(char t : tasks) freq[t]++;

    priority_queue<int> pq;
    for(auto &p : freq) pq.push(p.second);

    int time = 0;

    while(!pq.empty()){
        vector<int> temp;
        int cycle = n + 1;

        while(cycle-- && !pq.empty()){
            int count = pq.top(); pq.pop();
            if(count - 1 > 0) temp.push_back(count - 1);
            time++;
        }

        for(int c : temp) pq.push(c);

        if(pq.empty()) break;

        time += cycle + 1; // idle time
    }

    return time;
}
}; 