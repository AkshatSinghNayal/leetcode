class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n  = nums1.size();
        int count = 0;
        int minEven = INT_MAX;
        int minOdd = INT_MAX ; 
        for(auto& it : nums1 ){
            if( it%2 == 0 ){ 
                count++; 
                minEven = min(minEven , it );
            }
            else{
                minOdd = min(minOdd , it); 
            }

            
        }
        if( count == n ) return true;

        return (minEven - minOdd <1 ) ? false : true ;
        



    }
};