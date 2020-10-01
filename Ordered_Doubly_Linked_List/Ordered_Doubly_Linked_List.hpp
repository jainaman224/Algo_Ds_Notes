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
        Node* prev;
        Node(){ next = prev = nullptr; }
        Node(T& item, Node* prev, Node* next){
            this->item = item;
            this->prev = prev;
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

        void insertOrdered(T& item, int (*cmp)(const T& t1, const T& t2));
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
        current->prev = current->next = nullptr;
        delete current;
        current = first;
    }
    size=0;
}

template <class T>
void List<T>::insertSingle (T& x) {
    this->first=this->last=new Node(x, nullptr, nullptr);
}

template <class T>
bool List<T>::emptyList() {
    return (this->size == 0);
}

template <class T>
void List<T>::insertOrdered (T& x, int (*cmp)(const T& t1, const T& t2)) {

    if(emptyList()){
        insertSingle(x);
        this->size++;
        return;
    }

    Node *temp = this->first;
    Node* data = new Node(x, nullptr, nullptr);

    while(temp!=nullptr){
        if ((*cmp)(x,(temp->item))>0){
            if (temp->prev==nullptr){
                data->prev=nullptr;
                this->first=data;
                data->next=temp;
                temp->prev=data;
                size++;
                return;
            }
            else{
                data->next=temp;
                data->prev=temp->prev;
                temp->prev->next=data;
                temp->prev=data;
                size++;
                return;
            }
        }
        else if (temp->next==nullptr){
            temp->next=data;
            data->prev=temp;
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

    Node *current = this->last;
    Node *current1 = current->prev;
    current1->next = nullptr;

    delete current;
    this->last = aux1;
    size--;
}

#endif // LIST_H
