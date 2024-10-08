//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* make_tree()
{
	int n;
	cin>>n;
    
	Node* head=NULL;
	queue <Node*> q;

	for( ; n>0 ; n-=2 )
	{
		int a,b;
		char c;
		cin>> a >> b >> c;

        if(!head)
		{
			head = new Node(a);
			q.push(head);
		}

        Node* pick = q.front();
		q.pop();

		if(c == 'L')
		{
			pick->left = new Node(b);
			q.push( pick->left );
		}
		
		
		cin>> a >> b >> c;
		
		if(c == 'R')
		{
			pick->right = new Node(b);
			q.push( pick->right );
		}
	}
	return head;
}

long int sumBT(Node* root);


int main()
{
    int t;cin>>t;while(t--){
    	
    	Node* head = make_tree();
    
        cout<<sumBT(head)<<endl;
    }
	return 1;
}

// } Driver Code Ends


/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/
// Function should return the sum of all the elements
// of the binary tree
// long int sum(Node* root, long int &sum_total){
    
//      if (root==NULL){
//         return 0;
//     }
    
    
//     left = sumBT(root->left);
//     right = sumBT(root->right);
    
//     int sum_total=sum_total + left +right+ root->data;
//     return  sum_total + root->data; ;
// }

long int sumBT(Node* root)
{
    // Code here
    
    // long int sum_total=0;
    // return sum (root, sum_total)
    
    if (root == nullptr) return 0;
    return root->key + sumBT(root->left) + sumBT(root->right);
    
    
    
}