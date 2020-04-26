import 'dart:io';

class Node{
    int value;
    Node leftNode;
    Node rightNode;

    Node(int val){
        this.value = val;
        this.leftNode = null;
        this.rightNode = null;
    }
    
    Node get left{
        return this.leftNode;
    }
    
    Node get right{
        return this.rightNode;
    }
    
    int get val{
        return this. value;
    }
    
    void set val(int x){
        this.value = x;
    }

    void set left(Node x){
        this.leftNode = x;
    }

    void set right(Node x){
        this.rightNode = x;
    }
}

Node root;

preOrderTraversal(Node x){
    if(x == null) return;
    print(x.val);
    preOrderTraversal(x.left);
    preOrderTraversal(x.right);
}

inOrderTraversal(Node x){
    if(x == null) return;
    inOrderTraversal(x.left);
    print(x.val);
    inOrderTraversal(x.right);
}

postOrderTraversal(Node x){
    if(x == null) return;
    postOrderTraversal(x.left);
    print(x.val);
    postOrderTraversal(x.right);
}

insertElement(Node x, int val){
    if(root == null){
        root == new Node(val);
        print(root.val);
        return;
    }
    if(x.val == val) return;
    if(x.val > val){
        if(x.left == null){
            Node newNode = new Node(val);
            x.left = newNode;
            return;
        }
        insertElement(x.left, val);
        return;
    }
    if(x.right == null){
        Node newNode = new Node(val);
        x.right = newNode;
        return;
    }
    insertElement(x.right, val);
    return;
}

searchTree(Node x, int val){
    if(x == null){
        print('Did not find $val in Tree!');
        return;
    }
    if(x.val == val){
        print('Found $val in Tree!');
        return;
    }
    if(x.val > val){
        searchTree(x.left, val);
        return;
    }
    if(x.val < val){
        searchTree(x.right, val);
        return;
    }
}

main() {
    int task = 0;
    print('Binary Search Tree Program');
    while(task != 3){
        print('0 - Display Tree\n1 - Insert Element in Tree \n2 - Search element in Tree\n3 - Quit\nSelect task:-');
        try{
            task = int.parse(stdin.readLineSync());
        } on Exception{
            print('Please enter valid Integer value!');
            continue;
        }
        switch(task){
            case 0:
                if(root == null){
                    print('Empty Tree!');
                }
                else{
                    print('Traversal Order:-\n1 - Preorder \n2 - Inorder \n3 - Postorder');
                    int val;
                    try{
                        val = int.parse(stdin.readLineSync());
                    } on Exception{
                        print('Please enter valid Integer value!');
                        continue;
                    }
                    switch(val){
                        case 1:
                            print('PreOrder Traversal');
                            preOrderTraversal(root);
                            break;
                        case 2:
                            print('InOrder Traversal');
                            inOrderTraversal(root);
                            break;
                        case 3:
                            print('PostOrder Traversal');
                            postOrderTraversal(root);
                            break;
                        default:
                            print('Please enter valid Integer value!');
                    }
                }
                break;
            
            case 1:
                int val = null;
                print('Enter value that needs to be inserted in Tree:-');
                try{
                    val = int.parse(stdin.readLineSync());
                } on Exception{
                    print('Please enter valid Integer value!');
                    continue;
                }
                if(val == null){
                    print('Failed to insert element in Tree!');
                    continue;
                }
                insertElement(root, val);
                print('Successfully inserted $val in Tree!');
                break;
            
            case 2:
                int val = null;
                print('Enter value that needs to be searched in Tree:-');
                try{
                    val = int.parse(stdin.readLineSync());
                } on Exception{
                    print('Failed to search element in Tree!');
                    continue;
                }
                if(val == null){
                    print('Failed to search element in Tree!');
                    continue;
                }
                searchTree(root, val);
                break;
            
            case 3:
                print('Binary Search Tree Program Complete');
                break;

            default:
                continue;
        }
    }
}

/*
Sample Input/Output:
Binary Search Tree Program
0 - Display Tree
1 - Insert element in Tree 
2 - Search element in Tree
3 - Quit
Select task:-
1
Enter value that needs to be inserted in Tree:- 
1
1
Successfully inserted 1 in Tree!
0 - Display Tree
1 - Insert element in Tree 
2 - Search element in Tree
3 - Quit
Select task:-
1
Enter value that needs to be inserted in Tree:- 
2
Successfully inserted 2 in Tree!
0 - Display Tree
1 - Insert element in Tree 
2 - Search element in Tree
3 - Quit
Select task:-
1
Enter value that needs to be inserted in Tree:- 
3
Successfully inserted 3 in Tree!
0 - Display Tree
1 - Insert element in Tree 
2 - Search element in Tree
3 - Quit
Select task:-
0
Traversal Order:-
1 - Preorder 
2 - Inorder 
3 - Postorder
1
PreOrder Traversal
1
2
3
0 - Display Tree
1 - Insert element in Tree 
2 - Search element in Tree
3 - Quit
Select task:-
0
0 - Display Tree
1 - Insert element in Tree 
2 - Search element in Tree
3 - Quit
Select task:-
0
Traversal Order:-
1 - Preorder 
2 - Inorder 
3 - Postorder
2
InOrder Traversal
1
2
3
0 - Display Tree
1 - Insert element in Tree 
2 - Search element in Tree
3 - Quit
Select task:-
0
Traversal Order:-
1 - Preorder 
2 - Inorder 
3 - Postorder
3
PostOrder Traversal
3
2
1
0 - Display Tree
1 - Insert element in Tree 
2 - Search element in Tree
3 - Quit
Select task:-
2
Enter value that needs to be searched in Tree:- 
2
Found 2 in Tree!
0 - Display Tree
1 - Insert element in Tree 
2 - Search element in Tree
3 - Quit
Select task:-
3
Binary Search Tree Program Complete
*/
