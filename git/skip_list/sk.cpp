#include "sk.h"
using namespace std;

int SKlist::generateHeight() {
    int i = 0;
    for (; (int)rand()% 2 == 1; i++) {}
    return i;
}

vector<Node*> SKlist::getPredecessors(int k) {
    Node* p = root;
    vector<Node*> stack;
    stack.push_back(p);
    while (p->below) { // keep dropping down until reach the bottom
        p = p->below;
        while (p->after->key < k) {
            p = p->after; // move to the right
        }
        stack.push_back(p); // this is next predecessor
    }
    return stack;
}

void SKlist::search(int k) {
    vector<Node*> stack = getPredecessors(k);
    Node* top = stack.back(); // predecessor of k in the bottom
    if (top->after->key == k) cout << "Value: " << top->after->value << endl; //FOUND
    else cout << "ERROR KEY NOT FOUND " << endl; // NOT FOUND
}

void SKlist::insert(int k, int v) {
    int h = generateHeight(); // random tower height
    cout << "The height generated is: " << h << endl;
    while (height <= h) { // increase skip-list height id needed
        Node* start = new Node(INT_MIN); 
        Node* end = new Node(INT_MAX);
        start->after = end;
        start->below = root;
        end->below = root->after;
        root = start;
        height++; // update status
    }

    vector<Node*> stack = getPredecessors(k);
    Node* p = stack.back();
    stack.pop_back();
    Node* tmp = p->after;
    Node* zbelow = new Node(k, v); // insert key value pair in the bottom
    p->after = zbelow;
    zbelow->after = tmp;
    nodes++; // update status

    while (h > 0) { // insert key value at upper level if needed
        p = stack.back();
        stack.pop_back();
        tmp = p->after;
        Node* z = new Node(k);
        p->after = z;
        z->after = tmp;
        z->below = zbelow;
        zbelow = z;
        nodes++; // update status
        h--;
    }
    num_item++; // update status
}

void SKlist::remove(int k) {
    vector<Node*> stack = getPredecessors(k);
    int not_found = 1;
    while (!stack.empty()) {
        Node* p = stack.back();
        stack.pop_back(); // predecessor of k in some layers
        if (p->after->key == k) {
            if (not_found) {
                num_item--; // update status
                not_found = 0;
            }
            Node* tmp = p->after->after;
            delete p->after;
            p->after = tmp;
            nodes--; // update status
        } else break; // no more copies of k
    }
    if (not_found) {
        cout << "ERROR KEY NOT FOUND" << endl; // not found deleted key
        return;
    }
    Node* p = root;
    while (p->below->after->key == INT_MAX) {
        // the two top lists are both only sentinels, remove one 
        Node* tmp = p->below->below;
        delete p->below;  // remove first sentinel at top
        p->below = tmp;
        tmp = p->after->below->below;
        delete p->after->below; // remove second sentinel at top
        p->after->below = tmp;
        height--; // update status
    }
}

void SKlist::clear() {
    int count = 0;
    Node* vertical = root; 
    while (vertical) { // delete vertically
        Node* horizontal = vertical;
        Node* tmp0 = vertical->below;
        while (horizontal) { // delete horizontally
            Node* tmp1 = horizontal->after;
            count++;
            delete horizontal;
            horizontal = tmp1;
        }
        vertical = tmp0;
    }
    root = nullptr;
    height = 0;
    num_item = 0;
    nodes = 0;
    cout << "Deletion complete, total of delete: " << count << endl;
}

void SKlist::reset() {
    clear();
    Node* start = new Node(INT_MIN);
    Node* end = new Node(INT_MAX);
    start->after = end;
    root = start;
}

vector<int> SKlist::bottom_num() {
    Node* vertical = root;
    vector<int> result;
    while (vertical->below) {
        vertical = vertical->below;
    }
    while (vertical) {
        result.push_back(vertical->key);
        vertical = vertical->after;
    }
    return result;
}

void SKlist::display() {
    Node* vertical = root;
    vector<int> bottom = bottom_num();
    while (vertical) {
        Node* horizontal = vertical;
        int num = 0;
        while (horizontal && num < bottom.size()) {
            string k = "";
            if (horizontal->key == bottom[num]) {
                if (horizontal->key == INT_MIN) {
                    k = "-inf ";
                } else if (horizontal->key == INT_MAX) {
                    k = " - inf";
                } else {
                    k = "- " + to_string(horizontal->key) + " ";
                }
                cout << k;
                num++;
                horizontal = horizontal->after;
            } else {
                k = "---";
                int x = bottom[num];
                while (x) { // get integer length
                    k+= "-";
                    x/=10;
                }
                cout << k; 
                num++; 
                continue;
            }
        }
        cout << endl;
        vertical = vertical->below;

    }
}

