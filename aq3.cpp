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
    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        Node* slow = head;  
        Node* fast = head;  
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cout << "Middle element: " << slow->data << "\n";
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
    SingleLinkedList userList;
    int n, value;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid input!\n";
        return 0;
    }
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        userList.insertAtEnd(value);
    }
    
    cout << "Your list: ";
    userList.display();
    
    
    userList.findMiddle();
    
    return 0;
}