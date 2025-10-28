class Solution {
public:

    int helper ( TreeNode* root  ){
        if(root == nullptr ) return 0;   // ✅ keep 0, not level-based

        int left = helper( root->left ) ;
        int right = helper( root->right ) ;
        // ✅ fix: handle skewed tree (when one side is missing)
        if( left ==0 ) return right+1 ; 
        if( right== 0 ) return left +1 ; 
        return 1 + min(left,right); 
        // ✅ fix: min instead of max for minDepth
    }

    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0; // ✅ add for empty tree

        return helper( root ) ;

       
        
    }
};
