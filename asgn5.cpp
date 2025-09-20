//   Que.1

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, NULL};
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) { insertAtBeginning(val); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next) {
            Node* newNode = new Node{val, temp->next};
            temp->next = newNode;
        }
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (temp) {
            Node* newNode = new Node{val, temp->next};
            temp->next = newNode;
        }
    }
    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) { deleteBeginning(); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found!" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before a node\n4. Insert after a node\n";
        cout << "5. Delete from beginning\n6. Delete from end\n7. Delete specific node\n";
        cout << "8. Search\n9. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Enter key and value: "; cin >> key >> val; list.insertBefore(key, val); break;
            case 4: cout << "Enter key and value: "; cin >> key >> val; list.insertAfter(key, val); break;
            case 5: list.deleteBeginning(); break;
            case 6: list.deleteEnd(); break;
            case 7: cout << "Enter key: "; cin >> key; list.deleteNode(key); break;
            case 8: cout << "Enter key: "; cin >> key; list.search(key); break;
            case 9: list.display(); break;
        }
    } while (choice != 0);
    return 0;
}



// Que.2



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node* &head, int val) {
    Node* newNode = new Node{val, NULL};
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int countAndDelete(Node* &head, int key) {
    int count = 0;

    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

int main() {
    Node* head = NULL;
    int arr[] = {1,2,1,2,1,3,1};
    for (int x : arr) insertEnd(head, x);
    cout << "Original List: ";
    display(head);
    int key = 1;
    int cnt = countAndDelete(head, key);
    cout << "Count of " << key << "is " << cnt << endl;
    cout << "Updated List: ";
    display(head);

    return 0;
}



// Que.3 



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node* &head, int val) {
    Node* newNode = new Node{val, NULL};
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

int findMiddle(Node* head) {
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    Node* head = NULL;
    int arr[] = {1,2,3,4,5};
    for (int x : arr) insertEnd(head, x);
    cout << "Middle element is : " << findMiddle(head) << endl;
    return 0;
}


//Que.4



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node* &head, int val) {
    Node* newNode = new Node{val, NULL};
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    Node* head = NULL;
    int arr[] = {1,2,3,4};
    for (int x : arr) insertEnd(head, x);

    cout << "Original List: ";
    display(head);
    head = reverse(head);
    cout << "Reversed List: ";
    display(head);

    return 0;
}
