#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
vector<int> Tree[N];

// Simple DFS count of all nodes in a subtree
int countSubtreeNodes(int node, int parent) {
    int count = 1; // count the node itself
    for (int child : Tree[node]) {
        if (child != parent) {
            count += countSubtreeNodes(child, node);
        }
    }
    return count;
}

int main() {
    // Sample tree
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6

    Tree[1] = {2, 3};
    Tree[2] = {1, 4, 5};
    Tree[3] = {1, 6};
    Tree[4] = {2};
    Tree[5] = {2};
    Tree[6] = {3};

    int root = 1;
    int leftChild = 2;
    int rightChild = 3;

    int leftCount = countSubtreeNodes(leftChild, root);
    int rightCount = countSubtreeNodes(rightChild, root);

    cout << "Left subtree node count = " << leftCount << endl;
    cout << "Right subtree node count = " << rightCount << endl;

    return 0;
}
