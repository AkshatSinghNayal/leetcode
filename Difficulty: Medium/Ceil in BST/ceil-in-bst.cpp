class Solution {
  public:
    int findCeil(Node* root, int x) {
      int ans=-1 ; 
      while( root ){
          if( root->data<x ){
              root = root->right ; 
          }
          else{
              ans = root->data;
              root = root->left; 
              
          }
      }
      return ans ; 
    }
};
