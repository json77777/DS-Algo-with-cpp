#include <bits/stdc++.h>
using namespace std;

class LRUcache{
    private:
        int size = 2;
    public:
        // hashmap: key -> value
        unordered_map<int, int> mp;
        
        // DLL
        class Node {
            public:
            int data;
            Node* next;
            Node* prev;

            public:
            Node(int x) {
                data = x;
                next=NULL;
                prev=NULL;
            }

            public:
            Node(int x, Node* n, Node* p) {
                data = x;
                next=n;
                prev=p;
            }
        };

        // initialize head, tail
        Node* head = nullptr;
        Node* tail = nullptr;

        // map to find node by key in O(1)
        unordered_map<int, Node*> nodeMap;

        void insertTail(Node*&head, Node*& tail, int x) {
            if(tail==nullptr) {
                head=new Node(x);
                tail = head;
                return;
            }
            Node* newNode = new Node(x,nullptr,tail);
            tail->next=newNode;
            tail=newNode;
        }

        // delete a specific node (not just head/tail)
        void deleteNode(Node*& head, Node*& tail, Node* node) {
            if(node == head && node == tail) {
                head = nullptr;
                tail = nullptr;
            }
            else if(node == head) {
                head = head->next;
                head->prev = nullptr;
            }
            else if(node == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            node->next = nullptr;
            node->prev = nullptr;
            delete node;
        }

        void printList(Node* head) {
            while(head != nullptr) {
                cout << head->data << " ";
                head = head->next;
            }
            cout << endl;
        }

        // getKey
        int get(int key) {
            if(mp.find(key) == mp.end()) {
                return -1;
            }
            // move to MRU (tail)
            Node* node = nodeMap[key];
            deleteNode(head, tail, node);
            insertTail(head, tail, key);
            nodeMap[key] = tail;
            return mp[key];
        }

        // put pair
        void put(int key, int value) {
            if(mp.find(key) != mp.end()) {
                // key exists: update value, move to MRU
                mp[key] = value;
                Node* node = nodeMap[key];
                deleteNode(head, tail, node);
                insertTail(head, tail, key);
                nodeMap[key] = tail;
                return;
            }
            if((int)mp.size() >= size) {
                // evict LRU (head)
                int evictKey = head->data;
                deleteNode(head, tail, head);
                mp.erase(evictKey);
                nodeMap.erase(evictKey);
            }
            // insert new
            insertTail(head, tail, key);
            nodeMap[key] = tail;
            mp[key] = value;
        }
};

int main() {
    LRUcache cache;

    cache.put(1, 10);
    cache.put(2, 20);
    cout << "get(1): " << cache.get(1) << endl;  // 10

    cache.put(3, 30);
    cout << "get(2): " << cache.get(2) << endl;  // -1

    cache.put(4, 40);
    cout << "get(1): " << cache.get(1) << endl;  // -1
    cout << "get(3): " << cache.get(3) << endl;  // 30
    cout << "get(4): " << cache.get(4) << endl;  // 40

    return 0;
}