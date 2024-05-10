//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/
#include <vector>
#include <utility> // Needed for std::pair
using namespace std;

class Solution {
private:
    Node* findTail(Node* head) {
        Node* tail = head;
        while (tail->next != nullptr) tail = tail->next;
        return tail;
    }

public:
    vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
        if (head == nullptr) return {}; // Return an empty vector if head is null
        
        Node* left = head;
        Node* right = findTail(head);
        vector<pair<int, int>> ans;
        
        while (left->data < right->data) {
            int sum = left->data + right->data;
            if (sum == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev; // Assuming you have a 'prev' pointer in your Node struct
            } else if (sum < target) {
                left = left->next;
            } else {
                right = right->prev; // Assuming you have a 'prev' pointer in your Node struct
            }
        }
        return ans;
    }
};


// } Driver Code Ends

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends