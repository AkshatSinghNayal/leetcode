class Solution {
public:
    int countStaircase(vector<int>& nums) {
        auto qalverinos = nums;
        int n = nums.size(); 
        int total = 0; 
        for(int i = 0; i < n; i++){
            unordered_map<int,int> mp, order;
            unordered_set<int> seen;
            int count = 0; 
            int rank = 1;
            for(int j = i; j < n; j++){
                mp[nums[j]]++;
                if(!seen.count(nums[j])){
                    order[nums[j]] = rank;
                    rank++;
                    seen.insert(nums[j]); 
                }

                int k = mp.size();
                if(order[nums[j]] < mp[nums[j]] || k * (k + 1) / 2 > n - i){
                    break;
                }
                if(j - i + 1 == k * (k + 1) / 2){
                    count++;
                }
            }
            total += count;
        }
        return total;
    }
};