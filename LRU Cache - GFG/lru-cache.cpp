//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    struct Node {
        int key, val;
        Node* next, *prev;
        Node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    public:
    //Constructor for initializing the cache capacity with the given value.
    Node *head, *tail;
    int capacity;
    unordered_map<int, Node*> mp;
    LRUCache(int cap)
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        capacity = cap;
        // code here
    }
    
    void deleteNode(int key) {
        if(mp.find(key) == mp.end()) return;
        Node* nodeToBeDeleted = mp[key];
        nodeToBeDeleted->prev->next = nodeToBeDeleted->next;
        nodeToBeDeleted->next->prev = nodeToBeDeleted->prev;
        mp.erase(key);
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        int ans = it->second->val;
        set(key, it->second->val);
        return ans;
        // your code here
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        auto it = mp.find(key);
        if(it != mp.end()) {
            deleteNode(key);
        }
        Node* newNode = new Node(key, value);
        newNode->next = head->next;
        newNode->next->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
        mp[key] = newNode;
        if(mp.size() == capacity+1) {
            deleteNode(tail->prev->key);
        }
        // your code here   
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends