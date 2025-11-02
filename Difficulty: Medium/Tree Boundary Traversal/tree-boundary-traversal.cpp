/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    bool isLeaf( Node* root ){
        if( root->left == nullptr && root->right ==nullptr ){
            return true; 
        }
        return false ;
    }
    
    void addLeft ( Node* root , vector<int> &result ){
        Node* curr = root->left ; 
        while( curr!= nullptr ) {
            if(!isLeaf(curr)) result.push_back(curr->data); 
            
            if(curr->left) curr=curr->left; 
            else curr= curr->right  ; 
        }
    }
    
    void addRight( Node* root , vector<int> &result){
        vector<int> temp ; 
        Node* curr = root->right ; 
        while( curr!=nullptr ){
            if(!isLeaf(curr)) temp.push_back(curr->data); 
            
            if(curr->right) curr=curr->right; 
            else curr = curr->left ; 
        }
        
        int size = temp.size()-1 ;
        for( int i = size ; i>= 0 ; i--){
            result.push_back( temp[i]);
        }
    }
    
    void addLeaf( Node* root , vector<int> &result  ){
        if( root == nullptr ) return ; 
        if(isLeaf( root )){
             result.push_back(root->data); 
             return ; 
        }
        addLeaf( root->left , result); 
        addLeaf( root->right, result );
    }
  
    vector<int> boundaryTraversal(Node *root) {
      vector<int> result ; 
        if(!root) return result ;
        if( !isLeaf(root)) result.push_back( root->data ); 
        
      addLeft( root , result );
      addLeaf ( root , result ) ; 
      addRight( root , result ) ;
      
      
      return result;
     
     
      
    }
};