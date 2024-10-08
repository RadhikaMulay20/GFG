//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector<int> diagonal(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// vector<int> leftView_2(node *root)
// {
//   // Your code here
  

    

//     }
//     for(auto i: topnode){
//         ans.push_back(i.second);
//     }
//     return ans ;
// }

void solve(Node*root  , int hd , map<int,vector<int>>&mp)
{
    if(root==NULL)return;
    mp[hd].push_back(root->data);
    solve(root->left , hd+1 , mp);
    solve(root->right , hd , mp);
    
}
vector<int> diagonal(Node *root)
{
   // your code here
       vector<int>ans;
       if(root==NULL)return ans;
       map<int,vector<int>>mp;
       solve(root , 0 , mp);
       // 12 11 12 7 1 12 14 11 N 7 3 6 4 12 7 14 14 N 2 10 8 7
       for(auto i : mp){
           for(auto j : i.second){
               ans.push_back(j);
           }
       }
       return ans;
       
}

    // q.push(make_pair(root, make_pair(0,0)));

    // while(!q.empty()){

    //     pair<Node*,pair<int,int> >temp=q.front();
    //     q.pop();

    //     Node* front=temp.first;
    //     int hd=temp.second.first;
    //     int lvl=temp.second.second;

    //     nodes[hd][lvl].push_back(front->data);
        
        

    //     if(front->left){
    //         q.push(make_pair(front->left, make_pair(hd+1, lvl+1)));
    //     }
    //     if(front->right){
    //         q.push(make_pair(front->right, make_pair(hd, lvl+1)));
    //     }

        


    // }
    // for(auto i :nodes){
    //     for(auto j: i.second){
    //         for(auto k: j.second){
    //             ans.push_back(k);
    //         }
    //     }

    // }
    // return ans ;

