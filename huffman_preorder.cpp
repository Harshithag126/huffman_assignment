/*
Assignment: Huffman Coding Preorder  
 
Algorithm:
1. Create leaf nodes for each character and insert them into a min-heap (priority queue).
2. Repeatedly extract the two nodes with the smallest frequencies and merge them 
   into a new node. Insert the new node back into the heap until only one node remains.
3. Perform a preorder traversal. Assign '0' to left branches and '1' to right branches.
4. Record codes when a leaf node is reached.

Time Complexity: O(n log n)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(int f, Node* l, Node* r) : ch('\0'), freq(f), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) const {
        return a->freq > b->freq;
    }
};

void preorder(Node* root, string code, vector<pair<char,string>> &codes) {
    if (!root) return;
    if (!root->left && !root->right)
        codes.push_back({root->ch, code.empty() ? "0" : code});
    preorder(root->left, code + "0", codes);
    preorder(root->right, code + "1", codes);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int n;
    cout << "Enter the number of distinct characters: ";
    cin >> n;
    cin.ignore(); // ignore newline

    string S;
    cout << "Enter the characters (without spaces): ";
    cin >> S;
    if (S.length() != n) {
        cout << "Error: Number of characters doesn't match input count.\n";
        return 1;
    }

    vector<int> freq(n);
    cout << "Enter the frequencies separated by spaces: ";
    for (int i = 0; i < n; i++) cin >> freq[i];

    // Create min-heap
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < n; i++)
        pq.push(new Node(S[i], freq[i]));

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node(left->freq + right->freq, left, right);
        pq.push(parent);
    }

    Node* root = pq.top();
    vector<pair<char,string>> codes;
    preorder(root, "", codes);

    // Print codes
    cout << "\nCharacter codes:\n";
    for (auto &p : codes)
        cout << p.first << " : " << p.second << "\n";

    // Print preorder codes space-separated
    cout << "\nPreorder codes (space-separated):\n";
    for (size_t i = 0; i < codes.size(); i++) {
        cout << codes[i].second;
        if (i + 1 < codes.size()) cout << "   ";
    }
    cout << "\n";

    freeTree(root);
    return 0;
}
