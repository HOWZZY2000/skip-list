#include "sk.h"
using namespace std;

int main() {
    Node* start = new Node(INT_MIN);
    Node* end = new Node(INT_MAX);
    start->after = end;
    SKlist m_list(start);
    string cmd;
    int k, v;
    srand(time(NULL));
    try {
        while (cin >> cmd ) {
            try { 
                if ( cmd == "r" ) { //reset the skip list to base form
                    m_list.reset();
                } else if ( cmd == "x" ) { //delete and exit
                    m_list.clear();
                    exit(0);
                } else if ( cmd == "i" ) { //insert key valye pair
                    cin >> k >> v;
                    m_list.insert(k, v);
                } else if ( cmd == "d" ) { //delete key
                    cin >> k;
                    m_list.remove(k);
                } else if ( cmd == "s" ) { //search key
                    cin >> k;
                    m_list.search(k);
                } else if (cmd == "p") { //print
                    m_list.display();
                } else if (cmd == "s") { //print status
                    cout << "The height is: " << m_list.height << endl;
                    cout << "Total number of items: " << m_list.num_item << endl;
                    cout << "Total number of nodes: " << m_list.nodes << endl; 
                } else {
                    throw std::invalid_argument(cmd + " is Invalid syntasx");
                }
            } catch (std::invalid_argument & e) {
                std::cerr << e.what() << std::endl;
                m_list.clear();
                exit(1);
            }  // catch
        }
    } catch(ios::failure &) {
        cerr << "invalid" << endl;
        m_list.clear();
        exit(2);
    }
}