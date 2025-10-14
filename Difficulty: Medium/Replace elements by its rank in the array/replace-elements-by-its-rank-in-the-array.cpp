// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        unordered_map<int,int> mp ;
        vector<int> ans = arr ; 
        sort(ans.begin(),ans.end());
        int prev = -1; 
        int rank = 1 ; 
        for( int i = 0; i<ans.size() ; i++){
            if( prev != ans[i]){
                mp[ans[i]] = rank++; 
            }
            prev = ans[i];
        }
        for( int i =0 ; i<arr.size() ; i++){
            ans[i]=mp[arr[i]]; 
        }
        return ans ; 
    }
};
