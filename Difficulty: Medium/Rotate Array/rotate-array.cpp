class Solution {
  public:
    
    void reverseArr ( vector<int>& arr , int start , int end  ){
        while( start < end ){
            swap( arr[start++] , arr[end--]); 
        }
    }
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
       int n = arr.size() ; 
       d= d%n ; 
       reverseArr( arr , 0 , d-1 ); 
       reverseArr( arr , d , n-1 ) ;
       reverseArr( arr , 0 , n-1 ) ;
       
       
    }
};