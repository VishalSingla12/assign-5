#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() {
        head = nullptr;
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            temp = temp->next;
        }
        cout << "\n";
    }
    void countAndDeleteOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        
        cout << "Count: " << count << "\n";
        while (head != nullptr && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->data == key) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }
        
        cout << "Updated Linked List: ";
        display();
    }
    ~SingleLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SingleLinkedList sll;
    cout << "Creating list: 1->2->1->2->1->3->1\n";
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(1);
    sll.insertAtEnd(3);
    sll.insertAtEnd(1);
    
    cout << "Original Linked List: ";
    sll.display();
    
    int key = 1;
    cout << "\nSearching for key: " << key << "\n";
    sll.countAndDeleteOccurrences(key);
    SingleLinkedList userList;
    int n, value, searchKey;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        userList.insertAtEnd(value);
    }
    
    cout << "Your list: ";
    userList.display();
    
    cout << "Enter key to count and delete: ";
    cin >> searchKey;
    
    userList.countAndDeleteOccurrences(searchKey);
    
    return 0;
}