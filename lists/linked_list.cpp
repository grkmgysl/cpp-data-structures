#include <iostream>
using namespace std;
//https://medium.com/@RobuRishabh/beginners-guide-to-linked-list-in-c-d8445ef906ab
//Class for nodes
class Node
{
private:
    int data;
    Node* pNext;

public:
    //constructor
    Node(int new_data, Node* new_pNext = nullptr){ //default nullptr
        data = new_data;
        pNext = new_pNext;
    };

    int getData(){
        return data;
    }
    void setData(int new_data){
        data = new_data;
    }

    Node* getpNext(){
        return pNext;
    }
    void setpNext(Node* new_pNext = nullptr){
        pNext = new_pNext;
    }
};

//Class for linked list
class LinkedList
{
private:
    Node* pHead;
public:
    //constructor
    LinkedList(){
        pHead = nullptr;
    };
    //Linkedlist functionalities
    void insertAtEnd(int value){

        Node* newNode = new Node(value); //create new node
        if (pHead == nullptr)
        {
            pHead = newNode; //if no elements exists, head is new element
        }
        else{
            Node* temp = pHead;
            while (temp->getpNext() != nullptr)//traversal to end node
            {
                temp = temp->getpNext();
            }
            temp->setpNext(newNode); 
        }
        
    }

    void insertByPosition(int value, int n){
        Node* newNode = new Node(value); //create new node

        if(n == 1){ //if position is 1 manipulate the head
            newNode->setpNext(pHead);
            pHead = newNode; 
            return;
        }

        //otherwise traverse to n-1th element
        Node* temp = pHead;
        for (int i = 0; i < n-2; i++)
        {
            temp = temp->getpNext();
        }
        newNode->setpNext(temp->getpNext()); 
        temp->setpNext(newNode);

    }

    void deleteByPosition(int n){
        if(pHead == nullptr){//checks if the list empty
            return; 
        }
        Node* temp1 = pHead;
        if(n == 1){ 
            pHead = temp1->getpNext(); //head = temp->next
            delete temp1;
            return;
        }
        
        for (int i = 0; i < n-2; i++)
        {
            temp1 = temp1->getpNext();
        }
        Node* temp2 = temp1->getpNext(); 
        temp1->setpNext(temp2->getpNext()); //temp1->next = temp1->next->next
        delete temp2;

    }

    void displayList(){
        Node* temp = pHead;
        while (temp != nullptr)
        {
            cout<< temp->getData() << "->";
            //cout<< temp->getpNext() << "->";
            temp = temp->getpNext();
        }
        cout<< "NULL" <<endl;
    }

    // Destructor to free all allocated memory
    ~LinkedList() {
        Node* temp;
        while (pHead) {
            temp = pHead;
            pHead = pHead->getpNext();
            delete temp;
        }
    }
};





int main(int argc, char const *argv[])
{
    LinkedList list;

    list.insertAtEnd(10);           //10
    list.insertAtEnd(20);           //10 - 20
    list.displayList();
    list.insertByPosition(30, 1);   //30 - 10 - 20
    list.displayList();
    list.insertByPosition(40, 2);   //30 - 40 - 10 - 20
    list.displayList();
    list.insertByPosition(50, 4);   //30 - 40 - 10 - 50 - 20
    list.displayList();
    list.deleteByPosition(1);       //40 - 10 - 50 - 20
    list.displayList();
    list.deleteByPosition(3);       //40 - 10 - 20


    cout << "Linked List: ";
    list.displayList();
    return 0;
}
