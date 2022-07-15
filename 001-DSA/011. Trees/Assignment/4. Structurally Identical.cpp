bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if (!root1 && !root2) {
        return true;
    } else if (!root1 || !root2 || (root1->children.size() != root2->children.size())) {
        return false;
    }


    if (root1->data != root2->data) {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++) {
        if (!(areIdentical(root1->children[i], root2->children[i]))) {
            return false;
        }
    }

    return true;
}