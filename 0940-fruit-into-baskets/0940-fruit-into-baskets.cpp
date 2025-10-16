class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp ;
        int left = 0 ; int right = 0 ;
        int n = fruits.size();
        int maxi = 0 ; 
        while(right<n){
            int fruit = fruits[right]; 
            mp[fruit]++; 
            while(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            maxi = max( maxi , right-left+1 );
            right++;
        }
        return maxi ; 
    }
};