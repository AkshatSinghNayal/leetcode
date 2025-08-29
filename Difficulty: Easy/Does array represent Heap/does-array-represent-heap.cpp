class Solution {
  public:
    
    bool heapify(int arr[], int index, int n) {
        int largest = index; 
        int left = index*2 + 1; 
        int right = index*2 + 2; 
        
        if(left < n && arr[left] > arr[largest]){
            largest = left; 
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
         
        if(largest != index){
            return false;  // parent smaller than child → not a max heap
        }
        
        // Recursively check left and right subtrees
        bool leftCheck = (left < n) ? heapify(arr, left, n) : true;
        bool rightCheck = (right < n) ? heapify(arr, right, n) : true;
        
        return leftCheck && rightCheck;  // RETURN combined result
    }
  
    bool isMaxHeap(int arr[], int n) {
        // Check all non-leaf nodes
        for(int i = n/2 - 1; i >= 0; i--){
            if(!heapify(arr, i, n)) return false;
        }
        return true;
    }
};
