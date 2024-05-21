//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insert(stack<int> &s, int x) {
    // Base case: if stack is empty or top of stack is less than or equal to x
    if(s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }
    
    // Recursive case
    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}

void SortedStack::sort() {
    // Base case: if stack is empty, return
    if(s.empty()) {
        return;
    }
    
    // Remove the top element
    int temp = s.top();
    s.pop();
    
    // Sort the remaining stack
    sort();
    
    // Insert the top element back in the sorted stack
    insert(s, temp);
}