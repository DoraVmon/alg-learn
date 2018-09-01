#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void BTS_insert(TreeNode* node, TreeNode* insert_node) {
#if 0
    if(insert_node->val < node->val) {
        if (node->left != NULL) {
            BTS_insert(node->left, insert_node);
        }
        else {
            node->left = insert_node;
        }
    }
    else {
        if (node->right != NULL) {
            BTS_insert(node->right, insert_node);
        }
        else {
            node->right = insert_node;
        }
    }
#else
    while(node != insert_node) {
        if(insert_node->val < node->val) {
            if(node->left == NULL) {
                node->left = insert_node;
            }
            node = node->left;
        }
        else {
            if(node->right == NULL) {
                node->right = insert_node;
            }
            node = node->right;
        }
    }
#endif
}

bool BST_search(TreeNode* node, int val) {
#if 0
    if(node->val == val) {
        return true;
    }
    if(val < node->val) {
        if(node->left != NULL) {
            BST_search(node->left, val);
        }
        else {
            return false;
        }
    }
    else {
        if(node->right != NULL) {
            BST_search(node->right, val);
        }
        else {
            return false;
        }
    }
#else
    while(node != NULL) {
        if(val == node->val) {
            return true;
        }
        if(val < node->val) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return false;
#endif
}