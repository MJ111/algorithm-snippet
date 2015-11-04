// http://web.cs.ucla.edu/~umut/cs32/slides/w9/w9.pdf
// Given a sorted array, build the best BST.

Node* buildBST(int array[], int start, int end)
{
 if (start > end)
 return NULL;

 int mid = (start + end) / 2;
 Node* root = new Node(array[mid]);
 Node* left = buildBST(array, start, mid - 1);
 Node* right = buildBST(array, mid + 1, end);
 root->m_left = left;
 root->m_right = right;
 return root;
}