#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
struct Node {
    char data;
    int frequency;
    Node *left, *right;

    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(Node* a, Node* b) const {
        return a->frequency > b->frequency;
    }
};

Node* buildHuffmanTree(map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;

    // Create nodes for each character and their frequencies
    for (const auto& pair : frequencies) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    return pq.top();
}

void generateHuffmanCodes(Node* root,string code,map<char,string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '$') {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

void encode(map<char, int>& frequencies) {
    Node* root = buildHuffmanTree(frequencies);

    map<char,string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << '\n';
    }
}

int main() {
    
    
    map<char, int> frequencies;
    //string inputString;
    cout<<"How many Characters are in the String"<<endl;
    int n;
    cin>>n;
    cout << "Enter the character and frequencies of each character:\n";
    for (int i = 0; i < n; ++i) {char ch;
        int freq;
        std::cout << "Character " << i + 1 << " : ";
        std::cin >> ch;
        std::cout << "Frequency: ";
        std::cin >> freq;
        frequencies[ch] = freq;
    }
   
   // getline(cin, inputString);

    /* Calculate frequencies of characters in the input string
    for (char ch : inputString) {
        frequencies[ch]++;
    }*/   




    encode(frequencies);

    return 0;
}
