// #include <iostream>
// using namespace std;

// #define MAX 100

// class Queue {
//     int arr[MAX];
//     int front, rear;
// public:
//     Queue() {
//         front = -1;
//         rear = -1;
//     }

//     bool isEmpty() {
//         return (front == -1);
//     }

//     bool isFull() {
//         return (rear == MAX - 1);
//     }

//     void enqueue(int x) {
//         if (isFull()) {
//             cout << "Queue Overflow!\n";
//             return;
//         }
//         if (front == -1) front = 0;
//         arr[++rear] = x;
//         cout << x << " enqueued.\n";
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Queue Underflow!\n";
//             return;
//         }
//         cout << arr[front] << " dequeued.\n";
//         if (front == rear) {
//             front = rear = -1;
//         } else {
//             front++;
//         }
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is empty.\n";
//             return;
//         }
//         cout << "Queue: ";
//         for (int i = front; i <= rear; i++) cout << arr[i] << " ";
//         cout << endl;
//     }

//     void peek() {
//         if (isEmpty()) cout << "Queue is empty.\n";
//         else cout << "Front element: " << arr[front] << endl;
//     }
// };

// int main() {
//     Queue q;
//     int choice, val;

//     do {
//         cout << "\n--- Simple Queue Menu ---\n";
//         cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;
//         switch (choice) {
//             case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
//             case 2: q.dequeue(); break;
//             case 3: cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is not Empty\n"); break;
//             case 4: cout << (q.isFull() ? "Queue is Full\n" : "Queue is not Full\n"); break;
//             case 5: q.display(); break;
//             case 6: q.peek(); break;
//             case 7: cout << "Exiting...\n"; break;
//             default: cout << "Invalid choice!\n";
//         }
//     } while (choice != 7);
//     return 0;
// }






// /////////////////////2///////////////////////////////



// #include <iostream>
// using namespace std;

// #define MAX 5

// class CircularQueue {
//     int arr[MAX];
//     int front, rear;
// public:
//     CircularQueue() {
//         front = rear = -1;
//     }

//     bool isEmpty() {
//         return (front == -1);
//     }

//     bool isFull() {
//         return ((rear + 1) % MAX == front);
//     }

//     void enqueue(int x) {
//         if (isFull()) {
//             cout << "Circular Queue Overflow!\n";
//             return;
//         }
//         if (front == -1) front = 0;
//         rear = (rear + 1) % MAX;
//         arr[rear] = x;
//         cout << x << " enqueued.\n";
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Circular Queue Underflow!\n";
//             return;
//         }
//         cout << arr[front] << " dequeued.\n";
//         if (front == rear) {
//             front = rear = -1;
//         } else {
//             front = (front + 1) % MAX;
//         }
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Circular Queue is empty.\n";
//             return;
//         }
//         cout << "Circular Queue: ";
//         int i = front;
//         while (true) {
//             cout << arr[i] << " ";
//             if (i == rear) break;
//             i = (i + 1) % MAX;
//         }
//         cout << endl;
//     }

//     void peek() {
//         if (isEmpty()) cout << "Circular Queue is empty.\n";
//         else cout << "Front element: " << arr[front] << endl;
//     }
// };

// int main() {
//     CircularQueue cq;
//     int choice, val;
//     do {
//         cout << "\n--- Circular Queue Menu ---\n";
//         cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;
//         switch (choice) {
//             case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
//             case 2: cq.dequeue(); break;
//             case 3: cout << (cq.isEmpty() ? "Queue is Empty\n" : "Queue is not Empty\n"); break;
//             case 4: cout << (cq.isFull() ? "Queue is Full\n" : "Queue is not Full\n"); break;
//             case 5: cq.display(); break;
//             case 6: cq.peek(); break;
//             case 7: cout << "Exiting...\n"; break;
//             default: cout << "Invalid choice!\n";
//         }
//     } while (choice != 7);
//     return 0;
// }




// ///////////////////3////////////////////////////




// #include <iostream>
// using namespace std;

// #define MAX 100

// class Queue {
//     int arr[MAX];
//     int front, rear;
// public:
//     Queue() { front = rear = -1; }

//     bool isEmpty() { return (front == -1); }
//     bool isFull() { return (rear == MAX - 1); }

//     void enqueue(int x) {
//         if (isFull()) { cout << "Queue Overflow!\n"; return; }
//         if (front == -1) front = 0;
//         arr[++rear] = x;
//     }

//     int dequeue() {
//         if (isEmpty()) { cout << "Queue Underflow!\n"; return -1; }
//         int val = arr[front];
//         if (front == rear) front = rear = -1;
//         else front++;
//         return val;
//     }

//     int size() { return (isEmpty() ? 0 : rear - front + 1); }

//     void display() {
//         if (isEmpty()) { cout << "Queue is empty.\n"; return; }
//         for (int i = front; i <= rear; i++) cout << arr[i] << " ";
//         cout << endl;
//     }

// };

// void interleave(Queue &q) {
//     int n = q.size();
//     if (n % 2 != 0) {
//         cout << "Queue size must be even!\n";
//         return;
//     }

//     Queue firstHalf;
//     for (int i = 0; i < n/2; i++) {
//         firstHalf.enqueue(q.dequeue());
//     }

//     while (!firstHalf.isEmpty()) {
//         q.enqueue(firstHalf.dequeue());
//         q.enqueue(q.dequeue());
//     }
// }

// int main() {
//     Queue q;
//     q.enqueue(4);
//     q.enqueue(7);
//     q.enqueue(11);
//     q.enqueue(20);
//     q.enqueue(5);
//     q.enqueue(9);

//     cout << "Original Queue: ";
//     q.display();

//     interleave(q);

//     cout << "Interleaved Queue: ";
//     q.display();
//     return 0;
// }





// ////////////////////////////4//////////////////////////////




// #include <iostream>
// using namespace std;

// #define MAX 256

// class Queue {
//     char arr[MAX];
//     int front, rear;
// public:
//     Queue() { front = rear = -1; }

//     bool isEmpty() { return (front == -1); }
//     bool isFull() { return (rear == MAX - 1); }

//     void enqueue(char x) {
//         if (isFull()) return;
//         if (front == -1) front = 0;
//         arr[++rear] = x;
//     }

//     char dequeue() {
//         if (isEmpty()) return '\0';
//         char val = arr[front];
//         if (front == rear) front = rear = -1;
//         else front++;
//         return val;
//     }

//     char getFront() {
//         if (isEmpty()) return '\0';
//         return arr[front];
//     }
// };

// void firstNonRepeating(string s) {
//     int freq[256] = {0};
//     Queue q;

//     for (char c : s) {
//         freq[c]++;
//         q.enqueue(c);

//         while (!q.isEmpty() && freq[q.getFront()] > 1) {
//             q.dequeue();
//         }

//         if (q.isEmpty()) cout << -1 << " ";
//         else cout << q.getFront() << " ";
//     }
// }

// int main() {
//     string s = "aabc";
//     cout << "Input: " << s << endl;
//     cout << "Output: ";
//     firstNonRepeating(s);
//     return 0;
// }





// //////////////5////////////////



// #include <iostream>
// using namespace std;

// #define MAX 100

// class Queue {
//     int arr[MAX];
//     int front, rear;
// public:
//     Queue() { front = rear = -1; }

//     bool isEmpty() { return (front == -1); }
//     bool isFull() { return (rear == MAX - 1); }

//     void enqueue(int x) {
//         if (isFull()) return;
//         if (front == -1) front = 0;
//         arr[++rear] = x;
//     }

//     int dequeue() {
//         if (isEmpty()) return -1;
//         int val = arr[front];
//         if (front == rear) front = rear = -1;
//         else front++;
//         return val;
//     }

//     int size() { return (isEmpty() ? 0 : rear - front + 1); }

//     int getFront() {
//         if (isEmpty()) return -1;
//         return arr[front];
//     }
// };

// class StackTwoQ {
//     Queue q1, q2;
// public:
//     void push(int x) {
//         q2.enqueue(x);
//         while (!q1.isEmpty()) {
//             q2.enqueue(q1.dequeue());
//         }

//         Queue temp = q1;
//         q1 = q2;
//         q2 = temp;
//     }

//     void pop() {
//         if (q1.isEmpty()) { cout << "Stack Underflow!\n"; return; }
//         cout << q1.dequeue() << " popped.\n";
//     }

//     void top() {
//         if (q1.isEmpty()) { cout << "Stack is empty!\n"; return; }
//         cout << "Top element: " << q1.getFront() << endl;
//     }
// };

// int main() {
//     StackTwoQ st;
//     st.push(10);
//     st.push(20);
//     st.top();
//     st.pop();
//     st.top();
//     return 0;
// }




// ////////////////////5 b /////////////////////////////




// #include <iostream>
// using namespace std;

// #define MAX 100

// class Queue {
//     int arr[MAX];
//     int front, rear;
// public:
//     Queue() { front = rear = -1; }

//     bool isEmpty() { return (front == -1); }
//     bool isFull() { return (rear == MAX - 1); }

//     void enqueue(int x) {
//         if (isFull()) return;
//         if (front == -1) front = 0;
//         arr[++rear] = x;
//     }

//     int dequeue() {
//         if (isEmpty()) return -1;
//         int val = arr[front];
//         if (front == rear) front = rear = -1;
//         else front++;
//         return val;
//     }

//     int size() { return (isEmpty() ? 0 : rear - front + 1); }

//     int getFront() {
//         if (isEmpty()) return -1;
//         return arr[front];
//     }
// };

// class StackOneQ {
//     Queue q;
// public:
//     void push(int x) {
//         q.enqueue(x);
//         int sz = q.size();
//         for (int i = 0; i < sz - 1; i++) {
//             q.enqueue(q.dequeue());
//         }
//     }

//     void pop() {
//         if (q.isEmpty()) { cout << "Stack Underflow!\n"; return; }
//         cout << q.dequeue() << " popped.\n";
//     }

//     void top() {
//         if (q.isEmpty()) { cout << "Stack is empty!\n"; return; }
//         cout << "Top element: " << q.getFront() << endl;
//     }
// };

// int main() {
//     StackOneQ st;
//     st.push(10);
//     st.push(20);
//     st.top();
//     st.pop();
//     st.top();
//     return 0;
// }
