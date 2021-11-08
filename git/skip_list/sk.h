#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

// linked list node 
struct Node {
    int key, value;
    Node* after = nullptr;
    Node* below = nullptr;
    Node(int key) : key(key) {}
    Node(int key, int value) : key(key), value(value) {}
};

// skip list
struct SKlist {
    private:
        Node* root;
        std::vector<Node*> getPredecessors(int k); // Store the predecessors of k from root in a stack using vector
        int generateHeight(); // randomly generate an height with h ~ GE(1/2)
        std::vector<int> bottom_num(); // utility function, used for display
    public: //status
        int height = 0;
        int num_item = 0;
        int nodes = 0;

        SKlist(Node* root) : root(root) {};
        void search(int k); // serach the skiplist for the item with the given key and print the corresponding value or ERROR for key not found
        void insert(int k, int v); // insert an item(key, value) into the skip list
        void remove(int k); // delete the item with the given key from the skiplist or print ERROR for key not found
        void display(); // print the current skiplist
        void clear(); // delete the skiplist
        void reset(); // initialize an empty skiplist
};



