

// #include <cassert>

enum Color {
    BLACK,
    RED,
};

enum Direction {
    LEFT,
    RIGHT,
};

struct Node {
    Node *parent;
    Node *left;
    Node *right;
    Color color;
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

    void rotate_left(Node *node) {
        Node *right = node->right;
        if (node->parent != nullptr) {
            if (node == node->parent->left) {
                node->parent->left = right;
            } else {
                node->parent->right = right;
            }
        }
        right->left = node;
        node->right = right->left;
    }

    void rotate_right(Node *node) {
        Node *left = node->left;
        if (node->parent != nullptr) {
            if (node == node->parent->left) {
                node->parent->left = left;
            } else {
                node->parent->right = left;
            }
        }
        left->right = node;
        node->left = left->right;
    }

    void fix_violation(Node *node) {
        while (true) {
            if (node->parent == nullptr) {
                node->color = BLACK;
                return;
            }
            Node *uncle;
            Direction parent_dir = node->parent->parent->left == node->parent ? LEFT : RIGHT;
            if (parent_dir) {
                uncle = node->parent->parent->right;
                parent_dir = true;
            } else {
                uncle = node->parent->parent->left;
                parent_dir = false;
            }

            Direction node_dir = node->parent->left == node ? LEFT : RIGHT;
            if (uncle->color == RED) {
                node->parent->color = uncle->color = BLACK;
                fix_violation(node->parent->parent);
            } else {
                if (node_dir == RIGHT && parent_dir == RIGHT) {
                    rotate_right(node->parent->parent);
                    std::swap(node->parent->color, node->parent->parent->color);
                    if (node->parent->parent->color == RED) {
                        fix_violation(node->parent->parent);
                    }
                } else if (node_dir == RIGHT and parent_dir == LEFT) {
                    rotate_right(node->parent);
                } else if (node_dir == LEFT and parent_dir == RIGHT) {
                    rotate_right(node->parent);
                } else {
                    rotate_left(node->parent);
                    std::swap(node->parent->color, node->parent->parent->color)
                }
            }
        }
    }

    bool insert(int value) {
        Node *node = new Node;
        node->value = value;
        node->left = node->right = nullptr;
        node->color = RED;

        Node **pnxt = &root;
        Node *parent = nullptr;
        while (*pnxt != nullptr) {
            parent = *pnxt;
            if (value < (*pnxt)->value) {
                pnxt = &(*pnxt)->left;
                continue;
            }
            if (value > (*pnxt)->value) {
                pnxt = &(*pnxt)->right;
                continue;
            }
            return false;
        }

        node->parent = parent;
        *pnxt = node;
        fix_violation(node);

        return true;
    }
};