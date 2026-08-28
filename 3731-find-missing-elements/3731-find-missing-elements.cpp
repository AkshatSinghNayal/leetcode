class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int smallest = INT_MAX , largest = INT_MIN; 
        unordered_set<int>st; 
        vector<int>ans; 

        for(auto& it : nums ){
            st.insert(it); 
            smallest = min(smallest , it); 
            largest = max(largest , it ); 
        }

        for(int i  = smallest  ; i<= largest ; i++ ){
            if( !st.count(i)){
                ans.push_back(i);
            }
        }
        return ans; 
    }
};