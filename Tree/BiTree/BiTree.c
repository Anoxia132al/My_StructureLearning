#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


char str[] = {"ABDH#K###E##CFI###G#J##"};
int idx = 0;

void createBiTree(TreeNode** root) {
    char ch;
    ch = str[idx++];
    if (ch == '#') {
        *root = NULL;
    }
    else {
        *root = malloc(sizeof(TreeNode));
        (*root)->data = ch;
        createBiTree(&(*root)->left);
        createBiTree(&(*root)->right);
    }
    
}
//  前序遍历
void preOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}


int main() {
    TreeNode* root = NULL;
    createBiTree(&root);

    preOrder(root);
    return 0;
}