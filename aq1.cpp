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
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at beginning\n";
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
        cout << "Inserted " << value << " at end\n";
    }
    void insertBefore(int newValue, int targetValue) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->data == targetValue) {
            insertAtBeginning(newValue);
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != targetValue) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Target value " << targetValue << " not found\n";
            return;
        }
        
        Node* newNode = new Node(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << newValue << " before " << targetValue << "\n";
    }
    void insertAfter(int newValue, int targetValue) {
        Node* temp = head;
        while (temp != nullptr && temp->data != targetValue) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Target value " << targetValue << " not found\n";
            return;
        }
        
        Node* newNode = new Node(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << newValue << " after " << targetValue << "\n";
    }
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning\n";
        delete temp;
    }
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from end\n";
            delete head;
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        cout << "Deleted " << temp->next->data << " from end\n";
        delete temp->next;
        temp->next = nullptr;
    }
    void deleteSpecificNode(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Node with value " << value << " not found\n";
            return;
        }
        
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted node with value " << value << "\n";
        delete nodeToDelete;
    }
    void searchNode(int value) {
        Node* temp = head;
        int position = 1;
        
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << position << "\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        
        cout << "Node with value " << value << " not found\n";
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        cout << "List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
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
    int choice, value, target;
    
    while (true) {
        cout << "menu\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a value\n";
        cout << "4. Insert after a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search node\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                sll.insertAtBeginning(value);
                break;
                
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                sll.insertAtEnd(value);
                break;
                
            case 3:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Enter target value: ";
                cin >> target;
                sll.insertBefore(value, target);
                break;
                
            case 4:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Enter target value: ";
                cin >> target;
                sll.insertAfter(value, target);
                break;
                
            case 5:
                sll.deleteFromBeginning();
                break;
                
            case 6:
                sll.deleteFromEnd();
                break;
                
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                sll.deleteSpecificNode(value);
                break;
                
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                sll.searchNode(value);
                break;
                
            case 9:
                sll.display();
                break;
                
            case 0:
                cout << "Exiting program...\n";
                return 0;
                
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}