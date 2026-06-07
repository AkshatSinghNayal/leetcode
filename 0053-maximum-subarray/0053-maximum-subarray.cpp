class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN; 
        int temp = 1e-5;
        int n = nums.size(); 
        for(auto& it : nums ){
            temp+=it;
            temp = max(temp , it ); 
            maxi = max(temp , maxi ); 
        }
        cout<<temp<< " " << maxi ;
        return maxi;
    }
};