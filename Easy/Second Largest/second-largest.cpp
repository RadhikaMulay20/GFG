//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    if (n < 2)
        return -1;

    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;

    // Find the largest element
    for (int i = 0; i < n; ++i) {
        if (arr[i] > firstLargest) {
            firstLargest = arr[i];
        }
    }

    // Find the second largest distinct element
    for (int i = 0; i < n; ++i) {
        if (arr[i] != firstLargest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest != INT_MIN) {
        return secondLargest;
    }

    return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends