/**
 * Program to print tree in top view
 * solved in solve()
 * Method 1: verticalOrder(), getMinMax(), printVerticalOrder();
 * Method 2: verticalOrder2(), getHoriznotalDistance();
 * */

#include <bits/stdc++.h>

using namespace std;

#define fastio()       ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD            1000000007
#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define endl           '\n'
#define vi             vector<int>
#define PI           3.141592653589793238462

//debug
// primitive types, string, vector, pair, ordered + unordered: map/set/multiset
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << ": "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

template <class T1>
void _print(T1 t)    { cerr << t; }

template <class T1> void _print(vector<T1> v) { cerr << "[ "; for (T1 i : v) { _print(i); cerr << " "; } cerr << "] "; }
template <class T1, class T2> void _print(pair<T1, T2> p) { cerr << "{" << p.F << "," << p.S << "}"; }
template <class T1, class T2> void _print(unordered_map<T1, T2> mp) { cerr << "[ "; for (auto i : mp) { _print(i); cerr << " "; } cerr << "]"; }
template <class T1, class T2> void _print(map<T1, T2> mp) { cerr << "[ "; for (auto i : mp) { _print(i); cerr << " "; } cerr << "]"; }
template <class T1> void _print(set <T1> v) {cerr << "[ "; for (T1 i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T1> void _print(unordered_set <T1> v) {cerr << "[ "; for (T1 i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T1> void _print(multiset <T1> v) {cerr << "[ "; for (T1 i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T1> void _print(unordered_multiset <T1> v) {cerr << "[ "; for (T1 i : v) {_print(i); cerr << " ";} cerr << "]";}
// debug ends

inline int power(int a, int b) { int x = 1; while (b) { if (b & 1) x *= a; a *= a; b >>= 1; } return x; }

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode() {
        left = NULL;
        right = NULL;
    }
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput_dfs() {
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
    newNode->left = takeInput_dfs();
    newNode->right = takeInput_dfs();
    return newNode;
}

void printDFS(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }
    cout << root->data << ": ";
    if (root->left) {
        cout << root->left->data << " ";
    }
    if (root->right) {
        cout << root->right->data << " ";
    }
    cout << endl;
    printDFS(root->left);
    printDFS(root->right);
}

BinaryTreeNode<int>* takeInput_bfs() {
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        // first enter data for left child then right
        BinaryTreeNode<int> *top = pendingNodes.front();
        pendingNodes.pop();
        cin >> data;
        if (data == -1) {
            top->left = NULL;
        } else {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(data);
            top->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cin >> data;
        if (data == -1) {
            top->right = NULL;
        } else {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(data);
            top->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printBFS(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *top = pendingNodes.front();
        pendingNodes.pop();
        cout << top->data << ": ";
        if (top->left) {
            cout << top->left->data << " ";
            pendingNodes.push(top->left);
        }
        if (top->right) {
            cout << top->right->data << " ";
            pendingNodes.push(top->right);
        }
        cout << endl;
    }
    cout << endl;
}

int countNodes(BinaryTreeNode<int> *root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void printPreorder(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

void printInorder(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// first in pair is height and second is diameter
pair<int, int> heightDiameter(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

// first: height, second: width
pair<int, int> diameter2(BinaryTreeNode<int> *root) {
    if (!root) {
        return {0, 0};
    }
    pair<int, int> left = diameter2(root->left);
    pair<int, int> right = diameter2(root->right);
    pair<int, int> res;
    res.F = 1 + max(left.F, right.F);
    res.S = max( (left.F + right.F), max(left.S, right.S));
    return res;
}

// used for determination of min. & max. horizontal dist. from root
// hd: denotes the horizontal distance between root and current node, initially 0
void getMinMax(BinaryTreeNode<int> *root, int &min, int &max, int hd) {
    if (!root) {
        return;
    }
    if (hd < min) {
        min = hd;
    }
    if (max < hd) {
        max = hd;
    }
    getMinMax(root->left, min, max, hd - 1);
    getMinMax(root->right, min, max, hd + 1);
}

// arguments: node & horizontal distance, this function's task is to go to the specified hd and print nodes
// traversal to specified horizontal distance is done by recursion
// curr: hd of the curr node
void printVertical(BinaryTreeNode<int> *root, int curr, int hd) {
    if (!root) {
        return;
    }
    if (curr == hd) {
        cout << root->data << " ";
    }
    printVertical(root->left, curr - 1, hd);
    printVertical(root->right, curr + 1, hd);
}

void verticalOrder(BinaryTreeNode<int> *root) {
    int min = 0, max = 0;
    getMinMax(root, min, max, 0);

    for (int i = min; i <= max; i++) {
        printVertical(root, 0, i);
        cout << endl;
    }
}

// implement over the tree, and save node->data in vector corresponding to same horizontal distance (hd)
void getHorizontalDistance(BinaryTreeNode<int> *root, map<int, vector<int>> &mp, int hd) {
    // base
    if (!root) {
        return;
    }
    mp[hd].pb(root->data);
    getHorizontalDistance(root->left, mp, hd - 1);
    getHorizontalDistance(root->right, mp, hd + 1);
}

void verticalOrder2(BinaryTreeNode<int> *root) {
    map<int, vector<int>> mp;
    getHorizontalDistance(root, mp, 0);
    for (auto i = mp.begin(); i != mp.end(); i++) {
        for (int j = 0; j < i->second.size(); j++) {
            cout << i->S[j] << " ";
        }
        cout << endl;
    }
}

// 1 2 3 -1 4 5 6 -1 -1 7 8 -1 -1 -1 -1 -1 -1
void solve() {
    BinaryTreeNode<int> *root = takeInput_bfs();
    cout << "BT:\n";
    printBFS(root);
    cout << "Num of nodes: " << countNodes(root); cout << endl;
    cout << "preorder: ";  printPreorder(root); cout << endl;
    cout << "inorder: ";  printInorder(root); cout << endl;
    cout << "Postorder: ";  printPostorder(root); cout << endl;
    cout << "Diameter: " << heightDiameter(root).S << endl;
    cout << "Diameter: " << diameter2(root).S << endl;
    cout << "Vertical Order: " << endl;
    verticalOrder(root);
    cout << "mapped: " << endl;
    verticalOrder2(root);
}

int32_t main()
{
    fastio()

#ifndef ONLINE_JUDGE
//    freopen("input.txt",  "r",  stdin);
//    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}