////////////////----1----------



// #include <iostream>
// using namespace std;

// #define MAX 100   

// struct Stack {
//     int arr[MAX];
//     int top;
// };

// void init(Stack &S) {
//     S.top = -1;
// }

// bool isEmpty(Stack &S) {
//     return (S.top == -1);
// }

// bool isFull(Stack &S) {
//     return (S.top == MAX - 1);
// }

// void push(Stack &S, int x) {
//     if (isFull(S)) {
//         cout << "Stack Overflow! Cannot push " << x << endl;
//     } else {
//         S.arr[++S.top] = x;
//         cout << x << " pushed into stack.\n";
//     }
// }

// void pop(Stack &S) {
//     if (isEmpty(S)) {
//         cout << "Stack Underflow!\n";
//     } else {
//         cout << S.arr[S.top--] << " popped from stack.\n";
//     }
// }

// void peek(Stack &S) {
//     if (isEmpty(S)) {
//         cout << "Stack is empty!\n";
//     } else {
//         cout << "Top element: " << S.arr[S.top] << endl;
//     }
// }

// void print(Stack &S) {
//     if (isEmpty(S)) {
//         cout << "Stack is empty!\n";
//     } else {
//         cout << "Stack elements : ";
//         for (int i = S.top; i >= 0; i--) {
//             cout << S.arr[i] << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     Stack S;
//     init(S);
//     int choice, value;

//     do {
//         cout << "\n=== Stack Menu ===\n";
//         cout << "1. Push\n";
//         cout << "2. Pop\n";
//         cout << "3. Check if Empty\n";
//         cout << "4. Check if Full\n";
//         cout << "5. Display Stack\n";
//         cout << "6. Peek\n";
//         cout << "7. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter value to push: ";
//                 cin >> value;
//                 push(S, value);
//                 break;
//             case 2:
//                 pop(S);
//                 break;
//             case 3:
//                 cout << (isEmpty(S) ? "Stack is empty.\n" : "Stack is not empty.\n");
//                 break;
//             case 4:
//                 cout << (isFull(S) ? "Stack is full.\n" : "Stack is not full.\n");
//                 break;
//             case 5:
//                 print(S);
//                 break;
//             case 6:
//                 peek(S);
//                 break;
//             case 7:
//                 cout << "Exiting...\n";
//                 break;
//             default:
//                 cout << "Invalid choice! Try again.\n";
//         }
//     } while (choice != 7);

//     return 0;
// }




//////////////--------------2-------------

// #include <iostream>
// using namespace std;

// #define MAX 100

// class Stack {
//     char arr[MAX];
//     int top;
// public:
//     Stack() { top = -1; }

//     void push(char c) {
//         if (top == MAX - 1) {
//             cout << "Stack Overflow\n";
//             return;
//         }
//         arr[++top] = c;
//     }

//     char pop() {
//         if (top == -1) {
//             cout << "Stack Underflow\n";
//             return '\0';
//         }
//         return arr[top--];
//     }

//     bool isEmpty() {
//         return (top == -1);
//     }
// };

// int main() {
//     char str[MAX];
//     cout << "Enter a string: ";
//     cin >> str;

//     Stack s;

//     // push each character
//     for (int i = 0; str[i] != '\0'; i++) {
//         s.push(str[i]);
//     }

//     cout << "Reversed String: ";
//     while (!s.isEmpty()) {
//         cout << s.pop();
//     }
//     cout << endl;

//     return 0;
// }

////////////////////////----3----------


// #include <iostream>
// using namespace std;

// #define MAX 100

// class Stack {
//     char arr[MAX];
//     int top;
// public:
//     Stack() { top = -1; }

//     void push(char c) { arr[++top] = c; }
//     char pop() { return arr[top--]; }
//     char peek() { return arr[top]; }
//     bool isEmpty() { return (top == -1); }
// };

// bool isBalanced(char exp[]) {
//     Stack s;
//     for (int i = 0; exp[i] != '\0'; i++) {
//         char ch = exp[i];

//         if (ch == '(' || ch == '{' || ch == '[')
//             s.push(ch);
//         else if (ch == ')' || ch == '}' || ch == ']') {
//             if (s.isEmpty()) return false;
//             char top = s.pop();
//             if ((ch == ')' && top != '(') ||
//                 (ch == '}' && top != '{') ||
//                 (ch == ']' && top != '['))
//                 return false;
//         }
//     }
//     return s.isEmpty();
// }


// int main() {
//     char exp[MAX];
//     cout << "Enter expression: ";
//     cin >> exp;

//     if (isBalanced(exp))
//         cout << "Balanced\n";
//     else
//         cout << "Not Balanced\n";

//     return 0;
// }

////////////////-------------4----------

#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool isEmpty() { return (top == -1); }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) // operand
            postfix[k++] = ch;

        else if (ch == '(')
            s.push(ch);

        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix[k++] = s.pop();
            s.pop(); // remove '('
        }
        else { // operator
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
                postfix[k++] = s.pop();
            s.push(ch);
        }
    }
    while (!s.isEmpty())
        postfix[k++] = s.pop();
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter Infix: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}


///////////-----5--------


// #include <iostream>
// #include <cmath>
// using namespace std;

// #define MAX 100

// class Stack {
//     int arr[MAX];
//     int top;
// public:
//     Stack() { top = -1; }
//     void push(int x) { arr[++top] = x; }
//     int pop() { return arr[top--]; }
//     bool isEmpty() { return (top == -1); }
// };

// int evaluatePostfix(char postfix[]) {
//     Stack s;

//     for (int i = 0; postfix[i] != '\0'; i++) {
//         char ch = postfix[i];

//         if (isdigit(ch)) {
//             s.push(ch - '0'); // convert char to int
//         }
//         else {
//             int val2 = s.pop();
//             int val1 = s.pop();

//             switch (ch) {
//                 case '+': s.push(val1 + val2); break;
//                 case '-': s.push(val1 - val2); break;
//                 case '*': s.push(val1 * val2); break;
//                 case '/': s.push(val1 / val2); break;
//                 case '^': s.push(pow(val1, val2)); break;
//             }
//         }
//     }
//     return s.pop();
// }

// int main() {
//     char postfix[MAX];
//     cout << "Enter Postfix: ";
//     cin >> postfix;

//     cout << "Evaluation = " << evaluatePostfix(postfix) << endl;

//     return 0;
// }
