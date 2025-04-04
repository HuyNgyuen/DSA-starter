#include <iostream>
#include <algorithm>
using namespace std;

// Cấu trúc Node
struct Node {
    int info, height, count;
    Node* left;
    Node* right;

    Node(int val) {
        info = val;
        height = 1;
        count = 1;
        left = right = nullptr;
    }
};

// Hàm phụ trợ
int Height(Node* n) {
    return n ? n->height : 0;
}

int BalanceFactor(Node* n) {
    return n ? Height(n->left) - Height(n->right) : 0;
}

void UpdateHeight(Node* n) {
    n->height = 1 + max(Height(n->left), Height(n->right));
}

// Quay cây
Node* RotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    UpdateHeight(y);
    UpdateHeight(x);

    return x;
}

Node* RotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    UpdateHeight(x);
    UpdateHeight(y);

    return y;
}

// Thêm nút
Node* Insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->info)
        root->left = Insert(root->left, key);
    else if (key > root->info)
        root->right = Insert(root->right, key);
    else {
        root->count++;
        return root;
    }

    UpdateHeight(root);
    int balance = BalanceFactor(root);

    // Quay nếu mất cân bằng
    if (balance > 1 && key < root->left->info)
        return RotateRight(root);
    if (balance < -1 && key > root->right->info)
        return RotateLeft(root);
    if (balance > 1 && key > root->left->info) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    if (balance < -1 && key < root->right->info) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }

    return root;
}

// Tìm node nhỏ nhất
Node* MinValueNode(Node* n) {
    Node* current = n;
    while (current->left) current = current->left;
    return current;
}

// Xóa nút
Node* Delete(Node* root, int key) {
    if (!root) return root;

    if (key < root->info)
        root->left = Delete(root->left, key);
    else if (key > root->info)
        root->right = Delete(root->right, key);
    else {
        if (root->count > 1) {
            root->count--;
            return root;
        }
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }

        Node* temp = MinValueNode(root->right);
        root->info = temp->info;
        root->count = temp->count;
        root->right = Delete(root->right, temp->info);
    }

    UpdateHeight(root);
    int balance = BalanceFactor(root);

    // Quay lại nếu mất cân bằng
    if (balance > 1 && BalanceFactor(root->left) >= 0)
        return RotateRight(root);
    if (balance > 1 && BalanceFactor(root->left) < 0) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    if (balance < -1 && BalanceFactor(root->right) <= 0)
        return RotateLeft(root);
    if (balance < -1 && BalanceFactor(root->right) > 0) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }

    return root;
}

// Tìm kiếm
bool Search(Node* root, int key) {
    if (!root) return false;
    if (key == root->info) return true;
    else if (key < root->info) return Search(root->left, key);
    else return Search(root->right, key);
}

// Duyệt cây
void InOrder(Node* root) {
    if (!root) return;
    InOrder(root->left);
    cout << root->info << " ";
    InOrder(root->right);
}

void PreOrder(Node* root) {
    if (!root) return;
    cout << root->info << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root) {
    if (!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->info << " ";
}

// Main
int main() {
    Node* root = nullptr;

    int values[] = {5, 2, 4, 8, 1, 9, 6};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i)
        root = Insert(root, values[i]);

    cout << "InOrder (LNR): ";
    InOrder(root); cout << endl;

    cout << "PreOrder (NLR): ";
    PreOrder(root); cout << endl;

    cout << "PostOrder (LRN): ";
    PostOrder(root); cout << endl;

    cout << "\nTim 4? " << (Search(root, 4) ? "Co" : "Khong") << endl;
    cout << "Tim 10? " << (Search(root, 10) ? "Co" : "Khong") << endl;

    root = Delete(root, 2);
    cout << "\nSau khi xoa 2, InOrder: ";
    InOrder(root); cout << endl;

    return 0;
}
