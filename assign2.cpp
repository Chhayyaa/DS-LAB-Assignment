#include <iostream>
using namespace std;
#include <string>

// Que. 1 -------

// int binarySearch(int arr[], int n, int key) {
//     int start = 0, end = n - 1;
    
//     while(start <= end) {
//         int mid = (start + end) / 2;
        
//         if(arr[mid] == key)
//             return mid;
//         else if(arr[mid] < key)
//             start = mid + 1;
//         else
//             end = mid - 1;
//     }
    
//     return -1; // Not found
// }

// int main() {
//     int arr[] = {5, 10, 20, 30, 40, 50, 60};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int key = 30;

//     int result = binarySearch(arr, n, key);

//     if(result != -1)
//         cout << "Element found at index: " << result << endl;
//     else
//         cout << "Element not found." << endl;
    
//     return 0;
// }


// Que. 2 --------


// void bubbleSort(int arr[], int n) {
//     for(int i = 0; i < n - 1; i++) {
//         for(int j = 0; j < n - i - 1; j++) {
//             if(arr[j] > arr[j + 1])
//                 swap(arr[j], arr[j + 1]);
//         }
//     }
// }

// int main() {
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     bubbleSort(arr, n);

//     cout << "Sorted array: ";
//     for(int i = 0; i < n; i++)
//         cout << arr[i] << " ";
    
//     return 0;
// }



// Que. 3----


// int findMissing(int arr[], int n) {
//     int total = (n + 1) * (n + 2) / 2;  // Sum of 1 to n+1
//     int sum = 0;
    
//     for(int i = 0; i < n; i++)
//         sum += arr[i];
        
//     return total - sum;
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 6, 7, 8};  // 5 is missing
//     int n = sizeof(arr)/sizeof(arr[0]);

//     cout << "Missing number: " << findMissing(arr, n) << endl;
    
//     return 0;
// }



// Que. 4-------

// ----part a----


// int main() {
//     char str1[100] = "Hello ";
//     char str2[] = "World";

//     strcat(str1, str2);

//     cout << "Concatenated String: " << str1 << endl;
//     return 0;
// }


//---part b---


// int main() {
//     char str[] = "OpenAI";
//     int len = strlen(str);

//     for(int i = len - 1; i >= 0; i--)
//         cout << str[i];
    
//     cout << endl;
//     return 0;
// }


//----part c---


// bool isVowel(char c) {
//     c = tolower(c);
//     return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
// }

// int main() {
//     char str[] = "Beautiful Day";
//     char result[100];
//     int j = 0;

//     for(int i = 0; str[i] != '\0'; i++) {
//         if(!isVowel(str[i])) {
//             result[j++] = str[i];
//         }
//     }
//     result[j] = '\0';

//     cout << "After removing vowels: " << result << endl;
//     return 0;
// }


// --part d----


// int main() {
//     char str[5][20] = {"Banana", "Apple", "Mango", "Cherry", "Blueberry"};
//     char temp[20];

//     for(int i = 0; i < 5 - 1; i++) {
//         for(int j = i + 1; j < 5; j++) {
//             if(strcmp(str[i], str[j]) > 0) {
//                 strcpy(temp, str[i]);
//                 strcpy(str[i], str[j]);
//                 strcpy(str[j], temp);
//             }
//         }
//     }

//     cout << "Sorted Strings:\n";
//     for(int i = 0; i < 5; i++)
//         cout << str[i] << endl;

//     return 0;
// }


//---part e----


// int main() {
//     char c;
//     cout << "Enter uppercase character: ";
//     cin >> c;

//     if(c >= 'A' && c <= 'Z')
//         c = c + 32;

//     cout << "Lowercase: " << c << endl;
//     return 0;
// }



// Que. 7



// int main() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;
//     int arr[100];
//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++) cin >> arr[i];

//     int inversions = 0;
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] > arr[j]) {
//                 inversions++;
//             }
//         }
//     }

//     cout << "Number of inversions: " << inversions << endl;

//     return 0;
// }




// Que. 8


// int countDistinct(int arr[], int n) {
//     int count = 0;

//     for(int i = 0; i < n; i++) {
//         bool isDistinct = true;

//         for(int j = 0; j < i; j++) {
//             if(arr[i] == arr[j]) {
//                 isDistinct = false;
//                 break;
//             }
//         }

//         if(isDistinct)
//             count++;
//     }

//     return count;
// }

// int main() {
//     int arr[] = {10, 20, 10, 30, 20, 40, 50};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Total number of distinct elements: " << countDistinct(arr, n) << endl;

//     return 0;
// }







class Diagonal {
    int *arr;
    int n;
public:
    Diagonal(int size) {
        n = size;
        arr = new int[n];
    }
    void set(int i, int j, int val) {
        if (i == j) arr[i] = val;
    }
    int get(int i, int j) {
        return (i == j) ? arr[i] : 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};
