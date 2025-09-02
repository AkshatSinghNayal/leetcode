class Solution {
public:

    bool maxHeap(Node* tree, int length) {
        if (tree == nullptr) return true; // base case
        int largest = tree->data;

        if (tree->left && tree->left->data > largest) return false;
        if (tree->right && tree->right->data > largest) return false;

        // Check left and right subtrees
        return maxHeap(tree->left, length) && maxHeap(tree->right, length);
    }

    bool CBT(Node* tree, int length, int index) {
        if (tree == nullptr) return true;
        if (index >= length) return false;

        bool left = CBT(tree->left, length, 2 * index + 1);
        bool right = CBT(tree->right, length, 2 * index + 2);

        return left && right;
    }

    int lengthOfTree(Node* tree) {
        if (tree == nullptr) return 0; // count all nodes
        return 1 + lengthOfTree(tree->left) + lengthOfTree(tree->right);
    }

    bool isHeap(Node* tree) {
        int length = lengthOfTree(tree);
        return CBT(tree, length, 0) && maxHeap(tree, length);
    }
};
