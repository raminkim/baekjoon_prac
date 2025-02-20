#include <iostream>
#include <map>

using namespace std;

int n;

struct node {
    string name;
    struct node *left;
    struct node *right;
};

map<string, node*> nodes; // A~Z까지의 노드를 저장할 맵.
struct node* head = nullptr;

void preorder(struct node *n) {
    if (n == nullptr) return;

    cout << n->name;
    preorder(n->left);
    preorder(n->right);
}

void inorder(struct node *n) {
    if (n == nullptr) return;

    inorder(n->left);
    cout << n->name;
    inorder(n->right);
}

void postorder(struct node *n) {
    if (n == nullptr) return;

    postorder(n->left);
    postorder(n->right);
    cout << n->name;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--) {
        string p, c1, c2; // 부모, 자식노드1, 자식노드2
        cin >> p >> c1 >> c2;

        if (nodes.find(p) == nodes.end()) { // 부모 노드가 없는지 체크.
            nodes[p] = new node{p, nullptr, nullptr};
        }
        struct node* parent = nodes[p];

        if (c1 != ".") { // 왼쪽 자식 노드를 추가
            if (nodes.find(c1) == nodes.end()) {
                nodes[c1] = new node{c1, nullptr, nullptr};
            }
            parent->left = nodes[c1];
        }
        if (c2 != ".") { // 오른쪽 자식 노드를 추가
            if (nodes.find(c2) == nodes.end()) {
                nodes[c2] = new node{c2, nullptr, nullptr};
            }
            parent->right = nodes[c2];
        }
    }
    head = nodes["A"];
    preorder(head); cout << endl;
    inorder(head); cout << endl;
    postorder(head); cout << endl;

    // 동적 할당 메모리 해제.
    for (auto& pair: nodes) {
        delete pair.second;
    }
    
    return 0;
}