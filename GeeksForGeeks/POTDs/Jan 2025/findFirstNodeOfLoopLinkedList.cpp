/*
Given a head of the singly linked list. If a loop is present in the list then return the first node of the loop else return NULL.

Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

Examples:

Input:
1->(3)->2->4->(5)  from 5 it is looped back to 3
Output: 3
Explanation: We can see that there exists a loop in the given linked list and the first node of the loop is 3.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        if (head == NULL || head->next == NULL) return NULL;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;       //next
            fast = fast->next->next; //2 jumps
            
            if (slow == fast){   //when loop found
                slow = head;
                while (slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; //both pointers met in a node
            }
        }
        
        return NULL; //when no loop found
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        assert(k <= arr.size());
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        Node *ans = ob.findFirstNode(head);
        cout << (ans == NULL ? -1 : ans->data) << "\n";
        cout << "~\n";
    }
    return 0;
}