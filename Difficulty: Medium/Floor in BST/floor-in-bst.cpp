// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
     
      int maxi = INT_MIN; ;
      while( root ){
          if( root->data > x){
              root = root->left; 
          }
          else{
              maxi = max( maxi , root->data); 
              root = root->right; 
          }
      }
      return ( maxi == INT_MIN ) ? -1 : maxi ; 
    }
};