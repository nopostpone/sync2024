

struct Node {
    Node *parent;
    Node *left;
    Node *right;
    int value;
};

struct Set {
    Node *root = nullptr;

    Node *find(int value) {
        Node *current = root;
        while (current != nullptr) {
            if (value < current->value) {
                current = current->left;
                continue;
            }
            if (value > current->value) {
                current = current->right;
                continue;
            }
            break;
        }
        return current;
    }

    Node *equal_range(int value) {
        Node *current = root;
        while (current != nullptr) {
            if (value < current->value) {
                current = current->left;
                continue;
            }
            if (value > current->value) {
                current = current->right;
                continue;
            }
            break;
        }
        return current;
    }

    bool insert(int value) {
        Node *node = new Node;
        node->value = value;
        node->left = node->right = nullptr;

        Node **pnext = &root;
        while (*pnext != nullptr) {
            if (value < (*pnext)->value) {
                pnext = &(*pnext)->left;
                continue;
            }
            if (value > (*pnext)->value) {
                pnext = &(*pnext)->right;
                continue;
            }
            return false;
        }

        if (pnext == nullptr) {
            root = node;
        } else {
            *pnext = node; 
        }

        return true;
    }
}