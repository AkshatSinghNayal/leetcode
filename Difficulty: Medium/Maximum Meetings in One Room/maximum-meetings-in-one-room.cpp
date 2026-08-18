class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
       vector<tuple<int,int,int>>nums;
       
       for(int i  = 0 ;i<s.size() ; i++ ){
           nums.push_back({ s[i], f[i] , i}); 
       }
       
      sort( nums.begin() , nums.end(), [](const auto& a , const auto& b ){
            return get<1>(a) < get<1>(b) ; 
      }); 
       
       
       vector<int>ans; 
       int i = 0;
       while(i<nums.size()){
            auto [ start , end , index  ] = nums[i]; 
            int j=i+1; 
            while( j<nums.size() and get<0>(nums[j])<= end ){
                j++; 
            }
            ans.push_back(index+1);
            i=j;
       }
       sort(ans.begin() , ans.end()); 
       return ans; 
    }
};