#ifndef LIST_H
#define LIST_H

using namespace std;

template<class T>
class List
{
    class Node{
    public:
        friend class List<T>;
        T item{};
        Node* next;
        Node(){ next = nullptr; }
        Node(T& item, Node* next){
            this->item = item;
            this->next = next;
        }
    };
    Node* first;
    Node* last;
    int size;
    public:
        List();
        ~List();
        bool emptyList();
        void insertSingle (T& x); 
    	
        void insertOrdered(T& item);
        void deleteLast();
    	
        friend std::ostream& operator<< (std::ostream& out, List<T>& list){
            Node *current= list.first;
            while(current != nullptr){
                out << current->item << endl;
                current = current->next;
            }
            return out;
        }
        int size() {return size;}
};

template<class T>
List<T>::List(){
    first = last = new Node();
    size = 0;
}

template<class T>
List<T>::~List(){
    Node* current = first;
    while(first != nullptr){
        first = first->next;
        current->next = nullptr;
        delete current;
        current = first;
    }
    size=0;
}

template <class T>
void List<T>::insertSingle (T& x) {
    this->first=new Node(x, nullptr);
}

template <class T>
bool List<T>::emptyList() {
    return (this->size == 0);
}

template <class T>
void List<T>::insertOrdered (T& x) {

    if(emptyList()){ 
        insertSingle(x); 
        this->size++;
        return;
    }

    Node *temp = this->first;
    Node* data = new Node(x, nullptr);

    while(temp!=nullptr){
        if (x<temp->next->item){
                data->next=temp->next;
                temp->next=data;
                size++;
                return;
            }
        }
        else if (temp->next==nullptr){
            temp->next=data;
            data->next=nullptr;
            this->last=data;
            size++;
            return;
        }
        temp=temp->next;
    }
}

template <class T>
void List<T>::deleteLast () {
    if (emptyList()) 
        return;

    Node *current = this->first;
    Node *aux;
    while(current->next->next!=nullptr) current=current->next;
    aux=current->next;
    current->next=nullptr;
    delete aux;
    this->last = current;
    size--;
}

#endif // LIST_H

