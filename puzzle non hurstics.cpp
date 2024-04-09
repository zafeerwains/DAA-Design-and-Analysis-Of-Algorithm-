#include <bits/stdc++.h>
using namespace std;
#define N 3

// state space tree nodes
struct Node {
    Node* parent; // stores the parent node of the current node
    int mat[N][N]; // stores matrix
    int x, y; // stores blank tile coordinates
    int level; // stores the number of moves so far
};

// Function to print N x N matrix
void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Function to allocate a new node
Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent) {
    Node* node = new Node;
    node->parent = parent;
    memcpy(node->mat, mat, sizeof node->mat);
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->level = level;
    node->x = newX;
    node->y = newY;
    return node;
}

// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// Function to check if (x, y) is a valid matrix coordinate
int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// print path from root node to destination node
void printPath(Node* root) {
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->mat);
    printf("\n");
}

// Function to solve N*N - 1 puzzle algorithm using BFS
void solve(int initial[N][N], int x, int y, int final[N][N]) {
    queue<Node*> q; // Use a queue to perform BFS

    Node* root = newNode(initial, x, y, x, y, 0, NULL);
    q.push(root); // Enqueue root

    while (!q.empty()) {
        Node* min = q.front();
        q.pop();

        // If min is an answer node
        if (memcmp(min->mat, final, sizeof(final)) == 0) {
            printPath(min);
            return;
        }

        // Do for each child of min, max 4 children for a node
        for (int i = 0; i < 4; i++) {
            if (isSafe(min->x + row[i], min->y + col[i])) {
                Node* child = newNode(min->mat, min->x, min->y, min->x + row[i], min->y + col[i], min->level + 1, min);
                q.push(child);
            }
        }
    }
}

// Driver code
int main() {
    int initial[N][N] = {
        {1, 2, 3},
        {5, 0, 6},
        {7, 8, 4}
    };

    int final[N][N] = {
        {1, 2, 3},
        {5, 8, 6},
        {0, 7, 4}
    };

    int x = 1, y = 2;

    solve(initial, x, y, final);

    return 0;
}
