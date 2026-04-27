#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
Node *lca(Node *root, int v1,int v2) {
        // We will walk down the tree until we find the split point
        while (root != NULL) {
            // If both v1 and v2 are smaller than root, LCA is in the left subtree
            if (v1 < root->data && v2 < root->data) {
                root = root->left;
            }
            // If both v1 and v2 are greater than root, LCA is in the right subtree
            else if (v1 > root->data && v2 > root->data) {
                root = root->right;
            }
            // If they are on different sides, or one is equal to the root, we found our LCA!
            else {
                return root;
            }
        }
        return NULL; // This line is just a fallback, ideally the loop returns the node
    }
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
