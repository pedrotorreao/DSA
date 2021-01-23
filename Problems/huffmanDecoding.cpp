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
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

void decode_huff(node *root, string s)
{
}