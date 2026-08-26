class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        priority_queue<int , vector<int>, greater<int>>pq; 
        vector<pair<int,int>>nums; 
        for(int i  = 0 ;i< arr.size() ; i++ ){
            nums.push_back({arr[i],dep[i]}); 
        }
        sort(nums.begin() , nums.end()) ; 
        int maxi = 0;
        
        for(auto& it : nums ){
            int start = it.first , end = it.second; 
            while( !pq.empty() and pq.top() < start ){
                pq.pop(); 
            }
            pq.push(end); 
            maxi = max(maxi , (int)pq.size()); 
        }
        return maxi ;        
    }
};
