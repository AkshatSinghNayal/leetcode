class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort( nums.begin() , nums.end() ,[](const auto& a , const auto& b ){
            return a[1]<b[1]; 
        });

        int n  = nums.size(); int count = 0; 
        // for(auto& it : nums ){
        //     for(auto& i : it ){
        //         cout << i << " "; 
        //     }
        //     cout<<endl; 
        // }
        
        int i  = 0; 
        while(i<n){
            int start = nums[i][0] , end = nums[i][1]; 
            int j  = i+1 ; 
            while( j < n and end > nums[j][0]){
                count++;
                j++;
            }
            i=j;
        }



        return count;

    }
};