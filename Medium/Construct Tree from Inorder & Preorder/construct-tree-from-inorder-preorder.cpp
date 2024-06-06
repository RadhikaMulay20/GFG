//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
int mapping(int in[], int n, map<int, queue<int> > &m){
        for(int i=0; i<n; i++){
            m[in[i]].push(i);
        }
    }
    Node* solve(int in[], int pre[], int &index, int instart, int inend, int n, map<int, queue<int> > &m){
        if(index>=n || instart>inend){
            return NULL;
        }
        int element = pre[index++];
        Node* root = new Node(element);
        int position = m[element].front();
        m[element].pop();
        root->left = solve(in, pre, index, instart, position-1, n, m);
        root->right = solve(in, pre, index, position+1, inend, n, m);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int index = 0;
        map<int, queue<int> > m;
        mapping(in, n, m);
        Node* root = solve(in, pre, index, 0, n-1, n, m);
        return root;
        // Code here
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends