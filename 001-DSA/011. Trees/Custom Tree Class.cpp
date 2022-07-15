#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};


template <typename T>
class Tree {
private:
    TreeNode<T> *root;
    int count;

public:
    Tree() {
        count = 0;
    }

    bool isEmpty(void) {
        return root == nullptr;
    }



private:
    int getSize(TreeNode<T> *node) {
        if (node == NULL) {
            return 0;
        }

        int numNodes = 1;
        for (int i = 0; i < node->children.size(); i++) {
            numNodes += getSize(node->children[i]);
        }
        return numNodes;
    }

    // dfs recursive traverse
    TreeNode<T>* takeInput() {
        int rootData;
        cout << "Enter root data: ";
        cin >> rootData;
        TreeNode<T> *newNode = new TreeNode<T>(rootData);


        int n;
        cout << "Enter no. of children: ";
        cin >> n;
        count += n;

        for (int i = 0; i < n; i++) {
            TreeNode<T> *child = takeInput();
            newNode->children.push_back(child);
        }
        cout << endl;

        return newNode;
    }

    void print(TreeNode<T>* node) {
        if (node == NULL) {
            return;
        }

        cout << endl << node->data << ": ";
        for (int i = 0; i < node->children.size(); i++) {
            cout << node->children[i]->data << ' ';
        }

        for (int i = 0; i < node->children.size(); i++) {
            print(node->children[i]);
        }

    }

    TreeNode<T>* takeInputLevelWise() {
        int rootData;
        cout << "Enter root data: ";
        cin >> rootData;

        TreeNode<T> *newNode = new TreeNode<T>(rootData);

        queue<TreeNode<T> *> pendingNodes;
        pendingNodes.push(newNode);
        while (!pendingNodes.empty()) {
            TreeNode<T> *top = pendingNodes.front();
            pendingNodes.pop();
            int numChild;
            cout << "Enter no. of children of " << top->data << ": ";
            cin >> numChild;
            count += numChild;
            for (int i = 0; i < numChild; i++) {
                int childData;
                cout << "Enter child[" << i + 1 << "] data: ";
                cin >> childData;
                TreeNode<T> *child = new TreeNode<T>(childData);
                top->children.push_back(child);
                pendingNodes.push(child);
            }
            cout << endl;
        }
        return newNode;
    }

    void printLevelWise() {
        queue<TreeNode<T> *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty()) {
            TreeNode<T> *currNode = pendingNodes.front();
            pendingNodes.pop();
            cout << currNode->data << ": ";
            for (int i = 0; i < currNode->children.size(); i++) {
                cout << currNode->children[i]->data << ' ';
                pendingNodes.push(currNode->children[i]);
            }
            cout << endl;
        }
    }

    void printNodesAtLevelK(TreeNode<T> *node, int k) {
        if (node == NULL) {
            return;
        }

        if (k == 0) {
            cout << node->data << endl;
        }

        for (int i = 0; i < node->children.size(); i++) {
            printNodesAtLevelK(node->children[i], k - 1);
        }
    }

    void postorder(TreeNode<T> *node) {
        if (node == NULL) {
            return;
        }

        for (int i = 0; i < node->children.size(); i++) {
            postorder(node->children[i]);
        }

        cout << node->data << ' ';
    }

    void preorder(TreeNode<T> *node) {
        if (node == NULL) {
            return;
        }

        cout << root->data << ' ';
        for (int i = 0; i < root->children.size(); i++) {
            preorder(root->children[i]);
        }
    }

public:
    int getSize() {                        // returns number of node
        // Method 1: return count+1;
        //Method 2:
        return getSize(root);
    }

    void insert() {
        //root= takeInput();
        root = takeInputLevelWise();
    }

    void printTree() {
        // print(root);
        printLevelWise();
        cout << endl;
    }

    void printNodesAtLevelK() {
        int k;
        cout << "Enter the level: ";
        cin >> k;
        printNodesAtLevelK(root, k);
    }

    void printPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    void printPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

};

// sample input(takeInputLevelWise): 10 3 20 30 40 2 50 60 1 70 0 1 80 0 0 0
int main() {
    Tree<int> t;
    t.insert();
    t.printTree();
    cout << "\nSize: " << t.getSize() << endl;
    t.printNodesAtLevelK();
    t.printPostorder();
    t.printPreorder();
    return 0;
}



