// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int , vector<int> , less<int>> q; 
        for(int i = 0 ; i< k ; i++){
            q.push(arr[i]);
        }
         for( int j = k ; j<arr.size() ; j++){
             if( arr[j] < q.top()){
                 q.pop();
                 q.push(arr[j]);
             }
         }
        return q.top();
    }
};