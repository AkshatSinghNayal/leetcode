/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    bool isLeaf(Node* root ){
        return ( root->left == nullptr && root->right == nullptr ) ;
    }
    
    void helperFunction( Node* root , vector<vector<int>> &ans , vector<int> &temp ){
         
         if( root == nullptr ) return ; 
         
         if( isLeaf(root) ){
             temp.push_back(root->data); 
             ans.push_back(temp); 
             temp.pop_back();
             return ; 
         }
         
        temp.push_back( root->data );
        helperFunction( root->left , ans , temp ) ; 
        helperFunction( root->right , ans , temp ) ;
        
        temp.pop_back() ; 
        
    }
  
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans ; 
        if( root == nullptr ) return ans ;
        vector<int> temp ; 
        
        helperFunction( root , ans ,temp ) ; 
        
        return ans; 
        
    }
};