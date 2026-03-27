class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> mp; 
        long long prefix = 0;
        mp[0]=1;
        long count = 0; 
        for(auto& it : arr){
            prefix^=it;
            const long needed = prefix^k; 
            if(mp.count(needed)){
                count+=mp[needed];
            }
            mp[prefix]++;
        }
        // for(auto& it : mp ){
        //     cout<< it.first << '-' << it.second<<" " ;
        // }
        return count;
    }
};