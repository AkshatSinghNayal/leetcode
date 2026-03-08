class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int index = n;
        int mini =INT_MAX; 

        for(int i  = 0 ; i< n ;i++ ){
            if( capacity[i]>= itemSize and mini > capacity[i] ){
                 
                mini = capacity[i];
                index = i; 
            }
        }
        cout << mini ; 
        return (index == n ) ? -1 : index ;
    }
};