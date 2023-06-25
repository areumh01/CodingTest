#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> answer(2);

struct Node {
    int x; int y; Node* left; Node* right; int index;
    Node(int x, int y, int index) {
        this->x = x;
        this->y = y;
        this->index = index;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void make_tree(Node* root, Node* target) {
    if (root->x > target->x) {
        if (root->left == nullptr) root->left = target;
        else make_tree(root->left, target);
    }
    else {
        if (root->right == nullptr) root->right = target;
        else make_tree(root->right, target);
    }
}

bool comp(Node* a, Node* b) {
    if (a->y != b->y) {
        return a->y > b->y;
    }
    else return a->x < b->x;
}

void preOrder(Node* node) {
    answer[0].push_back(node->index + 1);
    if (node->left != nullptr) preOrder(node->left);
    if (node->right != nullptr) preOrder(node->right);
}

void postOrder(Node* node) {
    if (node->left != nullptr) postOrder(node->left);
    if (node->right != nullptr) postOrder(node->right);
    answer[1].push_back(node->index + 1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node*> nodeVec;
    for (int i = 0; i < nodeinfo.size(); i++) {
        Node* n = new Node(nodeinfo[i][0], nodeinfo[i][1], i);
        nodeVec.push_back(n);
    }
    sort(nodeVec.begin(), nodeVec.end(), comp);
    for (int i = 1; i < nodeVec.size(); i++) {
        make_tree(nodeVec[0], nodeVec[i]);
    }
    preOrder(nodeVec[0]);
    postOrder(nodeVec[0]);
    return answer;
}