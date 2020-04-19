/* 
Burkhard Keller Tree is a popular String Matching Algorithm which is used to
perform spell checks based on the concept of Levenshtein distance.
*/
#include <iostream>
#include <vector>
#include <map>

typedef std::vector< std::string > strlist;
// Defining the Node 
class Node {
    public:
        std::map< int, Node* > TreeEdge;
        std::string Name;
};


// Defining the BK Tree
class BKTree {
    public:
        strlist search(std::string Name, int target_dist);
        void insert_into(strlist& list);

        BKTree(std::string& Root_STR);
        ~BKTree();

    private:
        Node* root;
        void insert(std::string& Name, Node*& node);
        void search(Node* node, std::string& Name, int target_dist, strlist& suggestion_points);
        int min(int& a, int& b, int& c);
        int d(std::string& test, std::string& comp);
        void delete_node(Node* node);
};

// Constructor to initialize the BK Tree
BKTree::BKTree(std::string& Root_STR) {
    root = new Node();
    root -> Name = Root_STR;
}
// Destructor to remove any memory in the BK Tree
BKTree::~BKTree(){
    delete_node(root);
}

// Insertion Operation into BK Tree
void BKTree::insert_into(strlist& Names){
    for (auto& i : Names)
        insert(i, root);
}

void BKTree::insert(std::string& Name, Node*& node){

    if (node == nullptr){
        node = new Node();
        node -> Name = Name;
    }
    else {
        int dist = d( Name, node -> Name );
        insert(Name, node -> TreeEdge[dist]);
    }
}

// Deletion Operation in BK Tree
void BKTree::delete_node(Node* node){

    if (node == nullptr)
        return;

    for(auto& i : node->TreeEdge)
        delete_node(i.second);

    delete node;
}

// Search Operation in BK Tree
strlist BKTree::search(std::string Name, int target_dist){
    strlist suggestion_points;

    search(root, Name, target_dist, suggestion_points);

    return suggestion_points;
}

void BKTree::search(Node* node, std::string& Name, int target_dist, strlist& suggestion_points){
    if(node == nullptr)
        return;

    int dist = d(Name, node->Name);

    if (dist <= target_dist)
        suggestion_points.push_back(node->Name);

    int start = dist - target_dist;
    if (start < 0) start = 1;
    
    for(int i = start; i < dist + target_dist; i++)
        search(node->TreeEdge[i], Name, target_dist, suggestion_points); 
}

int BKTree::min(int& a, int& b, int& c){
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

// Calculating the Levenshtein distance
int BKTree::d(std::string& test, std::string& comp){
    int m = test.length();
    int n = comp.length();
	  std::vector< int > v0( n + 1 );
	  std::vector< int > v1( n + 1 );
    for(int i = 0; i < n; i++)
        v0[i] = i;
    for(int i = 0; i < m; i++){
        v1[i] = i + 1;
        for (int j = 0; j < n; j++){
            int dCost = v0[j + 1] + 1;
            int iCost = v1[j] + 1;
            int sCost = v0[j];
            if (test[i] != comp[j])
                sCost ++;

            v1[j + 1] = min(dCost, iCost, sCost);
        }
        v0 = v1;
    }
    return v0.back();
}

// Driver Function
int main(void){
    std::string Name = "Root";
    BKTree tree( Name );
    std::cout << "Enter the Strings in the Dictionary: (Press 1 to exit)" << std::endl;
    strlist dictionary;
    dictionary = {};
    std::string input;
    while(std::cin >> input){
      if(input == "1") { break; }
      dictionary.push_back( input );
    }

    tree.insert_into( dictionary );
    std::string searchStr;
    std::cout << "Enter the String that needs to be checked:"<< std::endl;
    std::cin >> searchStr;
    strlist test = tree.search( searchStr, 2 );
    for(auto& i : test)
        std::cout << i << std::endl;
    return 0;
}

/*
Sample Input: 
dictionary={"hell","help","shel","smell","fell","felt","oops","pop","oouch","halt"};
Sample Output: 
pop
*/
