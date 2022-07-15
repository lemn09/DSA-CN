template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode *right;
    BinaryTreeNode *left;

    BinaryTreeNode(T data) {
        this->data = data;
        right = NULL;
        left = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};
