#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

typedef struct node *node_ptr;
typedef struct node {
    char symbol;
    int frequency;
    node_ptr left;
    node_ptr right;
} node_t;

struct compare {
    bool operator()(node_ptr p, node_ptr q) {
        return p->frequency > q->frequency;
    }
};

int T1, T2;
typedef priority_queue<node_ptr, vector<node_ptr>, compare> PriorityQueue;
string str1[104], str2[104];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

node_ptr create_node(char symbol, int frequency) {
    node_ptr node = (node_ptr) malloc(sizeof(node_t));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

void huffman(int n, PriorityQueue &PQ) {
    for (int i = 1; i <= n - 1; i++) {
        node_ptr p = PQ.top();
        PQ.pop();
        node_ptr q = PQ.top();
        PQ.pop();
        node_ptr r = create_node('+', p->frequency + q->frequency);
        r->left = p;
        r->right = q;
        PQ.push(r);
    }
}

void preorder(node_ptr root) {
    if (root != NULL) {
        cout << root->symbol << ":" << root->frequency << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node_ptr root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->symbol << ":" << root->frequency << " ";
        inorder(root->right);
    }
}

void make_encoder(node_ptr node, string code, map<char, string> &encoder) {
    if (node->symbol != '+') encoder[node->symbol] = code;
    else {
        make_encoder(node->left, code + "0", encoder);
        make_encoder(node->right, code + "1", encoder);
    }
}

void decode(node_ptr root, node_ptr node, string s, int i) {
    if (i <= s.length()) {
        if (node->symbol != '+') {
            cout << node->symbol;
            decode(root, root, s, i);
        } else {
            if (s[i] == '0') decode(root, node->left, s, i + 1);
            else decode(root, node->right, s, i + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> freq(n);
    vector<char> symbol(n);
    for (int i = 0; i < n; i++)
        cin >> symbol[i];
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    PriorityQueue PQ;
    for (int i = 0; i < n; i++)
        PQ.push(create_node(symbol[i], freq[i]));

    huffman(n, PQ);
    node_ptr root = PQ.top();

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;


    cin >> T1;
    for (int i = 0; i < T1; i++)
        cin >> str1[i];
    cin >> T2;

    for (int i = 0; i < T2; i++)
        cin >> str2[i];

    for (int i = 0; i < T1; i++) {
        map<char, string> rets;
        make_encoder(root, str1[i], rets);
        for (int j = 0; j < str1[i].size(); j++) {
            string tmp = rets[str1[i][j]];
            for (int k = 0; k < tmp.size(); k++) {
                if (isdigit(tmp[k])) cout << tmp[k];
            }
        }
        cout << "\n";
    }

    for (int i = 0; i < T2; i++) {
        decode(root, root, str2[i], 0);
        if (i == T2 - 1) continue;
        cout << "\n";
    }
}

int main() {
    FastIO();
    solve();
    return 0;
}