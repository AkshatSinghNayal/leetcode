class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size(); 
        int total = 0; 
        for(int i = 0;i<n ;i++ ){
            unordered_map<int,int>mp,order;
            unordered_set<int>seen;
            int count =0 ; int rank = 1;
            for(int j = i; j<n; j++ ){
                mp[nums[j]]++;
                if(!seen.count(nums[j])){
                    order[nums[j]] = rank;
                    rank++;
                    seen.insert(nums[j]); 
                }

                if( j - i + 1 == mp.size() * rank / 2 and order[nums[j]] == mp[nums[j]] ){
                    count++;
                }
                else if( order[nums[j]] < mp[nums[j]] or mp.size() * rank / 2 > n - i ){
                    break;
                }
            }
            total+=(count);
        }
        return total;
    }
};