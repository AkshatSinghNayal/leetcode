class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0 ; 
        vector<int> temp ; 
        int ans = 0;
        for ( int i = 0 ; i<arr.size() ; i++){
            
            for( int j = i ; j<arr.size() ; j++){
                sum+=arr[j]; 
            temp.push_back(arr[j]); 
            if(temp.size()%2!=0){
                ans+=sum;
            }
            }
            sum =0; 
            temp.clear();
        }
        return ans;
    }
};