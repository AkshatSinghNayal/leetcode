class Solution {
public:
    int countStaircase(vector<int>& nums) {
        auto qalverinos = nums;
        int n = nums.size(); 
        int total = 0; 
        int mp[100001] = {}, order[100001]; // 1. Use fast flat arrays outside the loop

        for(int i = 0; i < n; i++){
            int count = 0, rank = 1, completed = 0, j = i;
            for(; j < n; j++){
                if(!mp[nums[j]]){
                    if(rank * (rank + 1) / 2 > n - i) break; // 2. Early stop if not enough elements left
                    order[nums[j]] = rank;
                    rank++;
                }
                mp[nums[j]]++;

                if(order[nums[j]] == mp[nums[j]]){
                    completed++; // This specific element just finished its required count
                }
                else if(order[nums[j]] < mp[nums[j]]){
                    break;       // Exceeded allowed count, subarray is dead
                }

                if(completed == rank - 1){ // 3. rank - 1 is the distinct count (replaces mp.size())
                    count++;     // Every distinct element seen so far has finished!
                }
            }
            for(int k = i; k <= j && k < n; k++) mp[nums[k]] = 0; // Reset only visited elements
            total += count;
        }
        return total;
    }
};