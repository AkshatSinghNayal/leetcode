class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int totalSum = 0 ; 
        int n  = arr.size() ; 
        for( int i  = 0  ; i<arr.size() ; i++){
            int totalSub = (i+1)*(n-i); 

            int totalOdd = (totalSub+1)/2; 
            totalSum+= totalOdd*arr[i];
        }
        return totalSum;

    }
};