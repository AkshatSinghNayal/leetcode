class Solution {
public:
    // DSU functions
    int find(vector<int>& parent, int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]); // path compression
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int maxi = *max_element(deadline.begin(), deadline.end());
        int n  = deadline.size();
        vector<pair<int,int>> ans;

        // store {deadline, profit} as before
        for(int i = 0; i<n ;i++){
            ans.push_back({deadline[i],profit[i]}); 
        }

        // sort by profit descending
        sort(ans.begin(),ans.end(), [](auto &a , auto &b){
            return a.second > b.second;
        });

        vector<int> jobs(maxi,-1);

        // DSU parent array for slots 1..maxi
        vector<int> parent(maxi + 1);
        for(int i = 0; i <= maxi; i++) parent[i] = i;

        for(auto it : ans) {
            int d = it.first;
            int availableSlot = find(parent, d); // find latest free slot <= d

            if(availableSlot > 0) {  // slot exists
                jobs[availableSlot - 1] = it.second; // assign profit
                parent[availableSlot] = availableSlot - 1; // mark slot filled
            }
        }

        int count = 0, totalProfit = 0;
        for(auto it : jobs){
            if(it != -1 ){
                count++; 
                totalProfit += it;
            }
        }

        return { count, totalProfit }; 
    }
};
