//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
       stack<char> s;

    for (char c : x) {
        if (c == '(' || c == '{' || c == '[') {
            // If opening bracket, push it onto the stack
            s.push(c);
        } else {
            // If closing bracket
            if (s.empty()) return false; // No corresponding opening bracket
            char top = s.top();
            s.pop();
            // Check if closing bracket matches the top of the stack
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    // Check if there are any remaining opening brackets in the stack
    return s.empty();
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends