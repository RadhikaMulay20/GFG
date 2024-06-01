//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(), v.end());

        int n = v.size();

        // If the length is odd, return the middle element
        if (n % 2 != 0) {
            return v[n / 2];
        }
        // If the length is even, return the floor value of the average of the two middle elements
        else {
            int middle1 = v[(n / 2) - 1];
            int middle2 = v[n / 2];
            return (middle1 + middle2) / 2;
        }
		    // Code here.
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends