/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node *N) {
    if (N == NULL)
        return -1;
    return N->ht;
}


int max(int a, int b) {
    return (a > b) ? a : b;
}

node* newNode(int val) {
    node* N = new node(); 
    N->val = val;
    N->left = NULL;
    N->right = NULL;
    N->ht = 0; 
    return N;
}

node *rightRotate(node *y) {
    node *x = y->left;
    node *T2 = x->right;

 
    x->right = y;
    y->left = T2;

    
    y->ht = max(height(y->left), height(y->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *leftRotate(node *x) {
    node *y = x->right;
    node *T2 = y->left;

    
    y->left = x;
    x->right = T2;

    x->ht = max(height(x->left), height(x->right)) + 1;
    y->ht = max(height(y->left), height(y->right)) + 1;

   
    return y;
}


int getBalanceFactor(node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


node * insert(node * root, int val) {
    // 1. Perform standard BST insertion
    if (root == NULL)
        return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    else 
        return root; // Equal keys are not allowed in this strictly defined BST

    // 2. Update the height of this ancestor node
    root->ht = 1 + max(height(root->left), height(root->right));

    // 3. Get the balance factor of this ancestor node
    int balance = getBalanceFactor(root);

    // 4. If the node becomes unbalanced, handle the 4 rotation cases

    // Left Left Case
    if (balance > 1 && val < root->left->val)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && val > root->right->val)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the (unchanged) node pointer
    return root;
}
