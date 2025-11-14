/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMax(Node *root) {
     int maxi = INT_MIN ; 
     while( root ){
         maxi = max( maxi , root->data); 
         root = root->right ; 
     }
     return maxi ; 
        
    }

    int findMin(Node *root) {
        
        int mini = INT_MAX ; 
        while( root ){
            mini = min ( mini , root->data ); 
            root = root->left ;
        }
        return mini ;
    }
};