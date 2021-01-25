/****************************************************************/
/*Problem: Tree - Huffman Decoding (HR)  ********/
/****************************************************************/
/*
-- Definition:
Huffman coding assigns variable length codewords to fixed length input characters based on 
their frequencies. More frequent characters are assigned shorter codewords and less frequent 
characters are assigned longer codewords. All edges along the path to a character contain a 
code digit. If they are on the left side of the tree, they will be a 0 (zero). If on the right, 
they'll be a 1 (one). Only the leaves will contain a letter and its frequency count. All 
other nodes will contain a null instead of a character, and the count of the frequency of all 
of it and its descendant characters. Again, input characters are only present in the leaves. 
Internal nodes have a character value of ϕ (NULL). To avoid ambiguity, Huffman encoding is a 
prefix free encoding technique. No codeword appears as a prefix of any other codeword.
To decode the encoded string, follow the zeros and ones to a leaf and return the character there. 

-- Summary:
You are given pointer to the root of the Huffman tree and a binary coded string to decode. You 
need to print the decoded string.

-- Inputs:
    <> root: a reference to the root node of the Huffman tree
    <> s: a Huffman encoded string

-- Outputs:
Output the decoded string on a single line.
*/
/* 
The structure of the node is:

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/
// ---------- SOLUTION -----------
void decode_huff(node *root, string s)
{
    string decoded{};
    node *currentNode = root;

    for (auto charac : s)
    {
        if (charac == '0')
        {
            currentNode = currentNode->left;
            if (!currentNode->left && !currentNode->right)
            {
                decoded += currentNode->data;
                currentNode = root;
            }
        }
        else
        {
            currentNode = currentNode->right;
            if (!currentNode->right && !currentNode->left)
            {
                decoded += currentNode->data;
                currentNode = root;
            }
        }
    }
    cout << decoded;
}
// ---------------------------------
// ------ Code provided by HR ------
/*
#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    
  	int freq;
    char data;
    node * left;
    node * right;
    
} node;

struct deref:public binary_function<node*, node*, bool> {
  	bool operator()(const node * a, const node * b)const {
        return a->freq > b->freq;
    }
};

typedef priority_queue<node *,vector<node*>, deref> spq;

node * huffman_hidden(string s) {

    spq pq;
    vector<int>count(256, 0);
  
    for(int i = 0; i < s.length(); i++) {
        count[s[i]]++;
    }
    
    for(int i = 0; i < 256; i++) {
        
        node * n_node = new node;
        n_node->left = NULL;
        n_node->right = NULL;
        n_node->data = (char)i;
        n_node->freq = count[i];
      
        if( count[i] != 0 )
        	pq.push(n_node);
      
    }
    
    while( pq.size() != 1 ) {
      
        node * left = pq.top();
        pq.pop();
        node * right = pq.top();
        pq.pop();
        node * comb = new node;
        comb->freq = left->freq + right->freq;
        comb->data = '\0';
        comb->left = left;
        comb->right = right;
        pq.push(comb);
      
    }
    
    return pq.top();
    
}

void print_codes_hidden(node * root, string code, map<char, string>&mp) {
    
  	if(root == NULL)
        return;
    if(root->data != '\0') {
        mp[root->data] = code;
    }
  
    print_codes_hidden( root->left, code+'0', mp );
    print_codes_hidden( root->right, code+'1', mp );
    
}

----> SOLUTION <-----

int main() {
    
  	string s;
    std::cin >> s;
  
    node * tree = huffman_hidden(s);
    string code = "";
  
    map<char, string> mp;
    print_codes_hidden(tree, code, mp);
    
    string coded;
  
    for(int i = 0; i < s.length(); i++) {
        coded += mp[s[i]];
    }
    
    decode_huff(tree, coded);
  
    return 0;
}
*/