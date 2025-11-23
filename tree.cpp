#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

bool find(Node* root, int val) {
    if (!root) return false;
    if (root->val == val) return true;
    if (val < root->val)
        return find(root->left, val);
    return find(root->right, val);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void preorderNR(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* cur = s.top(); s.pop();
        cout << cur->val << " ";

        if (cur->right) s.push(cur->right);
        if (cur->left) s.push(cur->left);
    }
}

void inorderNR(Node* root) {
    stack<Node*> s;
    Node* cur = root;
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top(); s.pop();
        cout << cur->val << " ";
        cur = cur->right;
    }
}

void postorderNR(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* cur = s1.top(); s1.pop();
        s2.push(cur);

        if (cur->left) s1.push(cur->left);
        if (cur->right) s1.push(cur->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}

void bfs(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

int sumTree(Node* root) {
    if (!root) return 0;
    return root->val + sumTree(root->left) + sumTree(root->right);
}

int main() {
    Node* root = nullptr;
    root = insertBST(root, 5);
    insertBST(root, 3);
    insertBST(root, 7);
    insertBST(root, 1);
    insertBST(root, 4);

    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    cout << "Preorder 2: "; preorderNR(root); cout << endl;
    cout << "Inorder 2: "; inorderNR(root); cout << endl;
    cout << "Postorder 2: "; postorderNR(root); cout << endl;

    cout << "BFS: "; bfs(root); cout << endl;

    cout << "sum: " << sumTree(root) << endl;

    cout << "Find 4 → " << (find(root, 4) ? "DA" : "NE") << endl;

    return 0;
}
