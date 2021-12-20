#include<iostream>
#include<climits>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



class BST {
    // Define the data members
    BinaryTreeNode<int> *root;

   public:
    BST() {
        // Implement the Constructor
        root = NULL;

    }

    ~BST(){
        delete root;
    }

    private:

    bool search(int data, BinaryTreeNode<int> *node){
        if(node == NULL){
            return false;
        }

        if(node->data == data){
            return true;
        }else if(node->data > data){
            return search(data, node->left);
        }else{
            return search(data, node->right);
        }
    }

    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int> *node){
        if(node == NULL){
            BinaryTreeNode<int> *newNode= new BinaryTreeNode<int>(data);
            return newNode;
        }

        if(data <= node->data){
            node->left= insert(data, node->left);
        }else{
            node->right= insert(data, node->right);
        }

        return node;
    }

//    int smallest(BinaryTreeNode<int> *node){
//        if(node == NULL){
//            return INT_MAX;
//        }
//
//        return min(node->data, min( smallest(node->left), smallest(node->right)));
//    }

    BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int> *node){
        if(node == NULL){
            return node;
        }

        if(node->data == data){
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }else if(node->left == NULL ){
                BinaryTreeNode<int> *temp= node->right;
                node->right= NULL;
                delete node;
                return temp;
            }else if(node->right == NULL){
                BinaryTreeNode<int> *temp= node->left;
                node->left= NULL;
                delete node;
                return temp;
            }else{
            // if the node to be deleted has both left and right child then replace value of the given node with either the min. value node from rightChild or max. value node from leftChild                                                 
                BinaryTreeNode<int> *minNode= node->right;
                while(minNode->left != NULL){
                    minNode= minNode->left;
                }
                node->data= minNode->data;
                node->right= remove(minNode->data, node->right);
                return node;
            }
        }else if(data < node->data){
            node->left= remove(data, node->left);
        }else{
            node->right= remove(data, node->right);
        }

        return node;
    }

    void print(BinaryTreeNode<int> *node){
    	if(node == NULL){
            return;
        }

        cout<<node->data<<':';
        if(node->left){
            cout<<"L:"<<node->left->data<<',';
        }

        if(node->right){
            cout<<"R:"<<node->right->data;
        }
        cout<<endl;

        print(node->left);
        print(node->right);
    }

    public:
	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) {
        // Implement the remove() function
        root= remove(data, root);
    }

    void print() {
        // Implement the print() function
        print(root);
    }

    void insert(int data) {
        // Implement the insert() function
        this->root= insert(data, root);
    }

    bool search(int data) {
		// Implement the search() function
        return search(data, root);
    }
};

int main(){
    BST b1;
    b1.insert(7);
    b1.insert(5);
    b1.insert(3);
    b1.insert(6);
    b1.insert(9);
    b1.insert(8);
    b1.insert(11);
    b1.print();
    cout<<endl;
    b1.remove(7);
    cout<<"After deleting 7: "<<endl;
    b1.print();
    cout<<endl;

    return 0;
}



