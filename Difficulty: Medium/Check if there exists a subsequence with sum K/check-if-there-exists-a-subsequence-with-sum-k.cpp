class Solution {
  public:
    
    bool helperFunction( vector<int>& arr , int k , int n , int index , int sum ){
            
        if( index == arr.size()){
            if(sum == k) return true; 
            return false ; 
        }
        if( sum == k ) return true; 
        if( sum>= k ) return false;
        
        if( helperFunction( arr , k , n , index+1 , sum+arr[index])) return true;
        if( helperFunction( arr , k , n , index+1 , sum)) return true;
        
        return false ;
    }
  
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        
        return helperFunction( arr , k , n , 0 , 0);
        
    }
};