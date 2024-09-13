//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int>& arr) {
    vector<int> pos;
    vector<int> neg;
    int size = arr.size();
    
    // Separate positive and negative numbers into two vectors
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            neg.push_back(arr[i]);
        } else {
            pos.push_back(arr[i]);
        }
    }
    
    int j = 0, k = 0;
    int i = 0;
    
    // Alternate between positive and negative numbers
    while (j < pos.size() && k < neg.size()) {
        if (i % 2 == 0) {
            arr[i++] = pos[j++];
        } else {
            arr[i++] = neg[k++];
        }
    }
    
    // If there are remaining positive numbers, fill them
    while (j < pos.size()) {
        arr[i++] = pos[j++];
    }
    
    // If there are remaining negative numbers, fill them
    while (k < neg.size()) {
        arr[i++] = neg[k++];
    }
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends