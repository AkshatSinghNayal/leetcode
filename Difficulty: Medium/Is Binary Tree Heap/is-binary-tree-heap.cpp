// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public: 
  
    bool Max( Node* tree  ){
        
       if (tree == nullptr) return true; // base case
        int largest = tree->data;

        if (tree->left && tree->left->data > largest) return false;
        if (tree->right && tree->right->data > largest) return false;

        // Check left and right subtrees
        return Max(tree->left) && Max(tree->right);
    }
  
    bool CBT( Node* tree  , int length , int index ){
        
        if( tree == nullptr) return true; 
        if( length<=index) return false ;
        
        bool left = CBT(tree->left , length , index*2+1);
        bool right = CBT(tree->right , length , index*2+2);
        
        
        return (left&&right) ;
    }
    
    int findLen(Node* tree){
        if( tree == nullptr) return 0 ; 
        
        return 1+findLen( tree->left) + findLen( tree->right);
    }
  
    bool isHeap(Node* tree) {
        
        int length = findLen( tree );
        if( CBT( tree , length , 0) && Max( tree )){
            return true ; 
        }
        return false; 
        
    }
};