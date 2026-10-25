class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size(); 
        int total = 0; 
        for(int i = 0;i<n ;i++ ){
            unordered_map<int,int>mp,order;
            unordered_set<int>seen;
            int count = 0, rank = 1, completed = 0; // <-- add completed = 0
for(int j = i; j < n; j++){
    mp[nums[j]]++;
    if(!seen.count(nums[j])){
        order[nums[j]] = rank;
        rank++;
        seen.insert(nums[j]); 
    }

    if(order[nums[j]] == mp[nums[j]]){
        completed++; // This specific element just finished its required count
    }
    else if(order[nums[j]] < mp[nums[j]]){
        break;       // Exceeded allowed count, subarray is dead
    }

    if(completed == mp.size()){
        count++;     // Every distinct element seen so far has finished!
    }
}
            total+=(count);
        }
        return total;
    }
};