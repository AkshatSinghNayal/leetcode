class Solution {
public:
    
    void heapify(vector<int>& nums , int i , int n ){
        int largest = i ;
        int left  = 2*i + 1;
int right = 2*i + 2;
        if( left < n && nums[left] > nums[largest]){
            largest = left ;
        }
        if( right < n && nums[right] > nums[largest]){
            largest = right ;
        }

        if( largest != i ){
            swap( nums[ largest] , nums[i]); 
            heapify( nums , largest , n);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
       
       int n =nums.size();
       for( int i = n/2-1 ; i>=0 ;i--){
         heapify( nums , i , n );
       }
       for(int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);   // move current max to end
            heapify(nums, 0, i);      // re-heapify on reduced heap
        }

        return nums[n-k];
    }
};