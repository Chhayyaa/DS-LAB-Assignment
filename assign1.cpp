#include <iostream>
#include <vector>
using namespace std;


const int MAX = 100;
int arr[MAX];
int n = 0;

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void display() {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void insert() {
    int pos, value;
    if (n == MAX) {
        cout << "Array is full.\n";
        return;
    }
    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;
    if (pos < 0 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> value;
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = value;
    n++;
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete (0 to " << n - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

void linearSearch() {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found.\n";
}


 void reverseArray() {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    cout << "Array reversed.\n";
}

void matrixMultiplication() {
    int a[10][10], b[10][10], c[10][10] = {0};
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible.\n";
        return;
    }

    cout << "Enter matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    cout << "Enter matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];

    cout << "Resultant matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

void transposeMatrix() {
    int a[10][10], t[10][10];
    int r, c;

    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];

    cout << "Transpose matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
}



void q1(){
     int choice;
    do {
        cout << "\nMENU :\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    
}

void q2(){
    // int n;
    // cout << "Enter number of rows: ";
    // cin >> n;

    // vector<vector<int>> arr(n);
    const int n=5;
    int arr[n];

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
       
    }
    for (int i=0;i<n/2;i++){
        for(int j=n-1;j<n/2;j--){
            if(arr[i]==arr[j]){
                cout<<"duplicate"<<arr[j];
            }
        }
    }


}


void q4(){

     int choice;
    do {
        
        cout << "1. PART a\n2. PART b\n3.PART c\n4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: reverseArray(); break;
            case 2: matrixMultiplication(); break;
            case 3: transposeMatrix(); break;
            case 4: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

}

void q5() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nSum of each row:\n";
    for (int i = 0; i < n; i++) {
        int sumr = 0;
        for (int j = 0; j < m; j++) {
            sumr += arr[i][j];
        }
        cout << "Row " << i << " sum = " << sumr << endl;
    }

    cout << "\nSum of each column:\n";
    for (int j = 0; j < m; j++) {
        int sumc = 0;
        for (int i = 0; i < n; i++) {
            sumc += arr[i][j];
        }
        cout << "Column " << j << " sum = " << sumc << endl;
    }
}

int main() {
    char ch;
    cout << "Enter question no.\n";
    cin >> ch;
    
    switch (ch) {
        case '1': q1(); break;
        case '2': q2(); break;
        //case '3': q3(); break;
        case '4': q4(); break;
        case '5': q5(); break;
        default: cout << "Invalid option.\n";
    }

    return 0;
}
