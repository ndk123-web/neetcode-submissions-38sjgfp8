class BST {
private:
    struct TreeNode {
        int key;
        TreeNode* left;
        TreeNode* right;

        // initialize left and right to nullptr
        TreeNode(int key) {
            this->key = key;
            this->left = nullptr; 
            this->right = nullptr;
        }
    };

    TreeNode* insert(TreeNode* root, int key) {
        if (!root) return new TreeNode(key);
        if (key < root->key) {
            root->left = insert(root->left,key);
        }
        else if (key > root->key) {
            root->right = insert(root->right,key); 
        }
        return root; // always root 
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->key) {
            root->left = deleteNode(root->left,key);
        }
        else if (key > root->key) {
            root->right = deleteNode(root->right,key);
        }
        else {
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minValueNode(root);
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);
        }

        return root; // always of root
    }

    bool search(TreeNode* root, int key) {
        if (!root) return false;
        if (key == root->key) return true;
        return key < root->key ? search(root->left,key) : search(root->right,key);
    }

    TreeNode* minValueNode(TreeNode* root) {
        while (root->left) root = root->left;
        return root;
    }

    TreeNode* root;

public:
    BST() : root(nullptr) {}

    void add(int key) {
        root = insert(root,key);
    }

    void remove(int key) {
        root = deleteNode(root,key);
    }

    bool contains(int key) {
        return search(root,key);
    }
};

class MyHashSet {
private:
    const int size = 10000;
    vector<BST> buckets;

    int hash(int key) {
        return (key % size);
    }

public:
    MyHashSet(): buckets(size) {
    }
    
    void add(int key) {
        int idx = hash(key);
        if (!contains(key)) {
            buckets[idx].add(key);
        }
    }
    
    void remove(int key) {
        int idx = hash(key);
        buckets[idx].remove(key);
    }
    
    bool contains(int key) {
        int idx = hash(key);
        return buckets[idx].contains(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */