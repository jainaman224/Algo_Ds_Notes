#include <iostream>
using namespace std;
#include "rb.h"

void menu() {
    cout << "\n__________________________________________";
    cout << "\n\n  --HEIGHT BALANCED BINARY SEARCH TREE--";
    cout << "\n          --(Red-Black-Tree)--";
    cout << "\n__________________________________________";
    cout << "\n\n1. Insert elements into the tree.";
    cout << "\n2. Search for an element.";
    cout << "\n3. PRE-ORDER Tree-Walk.";
    cout << "\n4. POST-ORDER Tree-Walk.";
    cout << "\n5. Remove an element from the tree.";
    cout << "\n6. Exit.";
    cout << "\n__________________________________________";
    cout << "\nYour Choice -- ";
}

int main() {
    RB_TREE demo;
    int info, input;
    menu();
    cin >> info;
    while (info != 6) {
        switch (info) {
            case 1:
                cout << "\nElement to be inserted -- ";
                cin >> input;
                demo.InsertNode(input);
                break;

            case 2:
                cout << "\nElement to be searched -- ";
                cin >> input;
                if (demo.TreeSearch(input)) {
                    cout << "Element found.\n";
                } else {
                    cout << "Element not found.\n";
                }
                break;

            case 3:
                cout << "Pre-Order Tree Walk ";
                demo.PreorderTraversal(demo.GetRoot());
                cout << endl;
                break;

            case 4:
                cout << "Post-Order Tree Walk ";
                demo.PostorderTraversal(demo.GetRoot());
                cout << endl;
                break;

            case 5:
                cout << "\nElement to be deleted? -- ";
                cin >> input;
                demo.Remove(input);
                break;

            default:
                cout << "Wrong Choice.\n";
        }
        cout << "\nAnything Else?";
        cin >> info;
    }
    cout << "\nTerminating.... ";
    return 0;
}
