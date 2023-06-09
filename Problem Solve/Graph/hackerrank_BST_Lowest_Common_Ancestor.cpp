
/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    bool findNode(Node *root, int val){
        if (!root) return false;
        if(root->data == val) return true;
        return (root->data > val)?findNode(root->left, val):findNode(root->right, val);
    }

    Node* getLCA(Node* root, int v1, int v2){
        if(!root) return root;

        Node* child = (v2<root->data)? getLCA(root->left, v1, v2):getLCA(root->right, v1, v2);
        if(child) return child;
        if(root->left && (root->data==v2 && root->left->data==v1)) return root;
        if(root->right && (root->data==v1 && root->right->data==v2)) return root;
        if(findNode(root, v1) && findNode(root, v2)) return root;
        return NULL;
    }

    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        if(!root) return NULL;
        return (v1<v2)?getLCA(root, v1, v2):getLCA(root, v2, v1);
    }

};
