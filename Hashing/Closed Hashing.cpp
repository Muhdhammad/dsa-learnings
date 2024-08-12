#include <iostream>
using namespace std;

int hash1(int key, int n){
  return key % n;
}

int hash2(int key, int n){
  return 7 - (key % 7);
}

void insert(int arr[], int key, int n) {
    int index = key % n;
    int i = 0;

    while ( arr[(index + i) % n] != -1 && i < n) {
        i++;
   }

  if (i == n) {
            cout << "Full";
            return;
        }
  
  arr[(index + i) % n] = key;
}

void search(int arr[], int key, int n){
  int index = key % n;
    int i = 0;

    while ( arr[(index + i) % n] != -1 && i < n) {
      if(arr[(index + i) % n] == key){
        cout <<"Value found at index: " << (index + i) % n;
        return;
      }
        i++;
   }
  cout<<"value not found" <<endl;
  
}

void doublehash_insert(int arr[], int key, int n){
  int firstHash = hash1(key,n);
  int secondHash = hash2(key,n);


  int i = 0;
  while (arr[firstHash + (i*secondHash)] != -1 && i < n){
    i++;
  }

  if (i == n) {
            cout << "Full";
            return;
        }
  
  arr[(firstHash + (i*secondHash) % n)] = key;
  
}

void doublehash_search(int arr[], int key, int n){
  
  int firstHash = hash1(key,n);
  int secondHash = hash2(key,n);

  int i = 0;

  while(arr[firstHash + (i*secondHash)]%n != -1 && i < n){
    if(arr[firstHash + (i*secondHash)] == key){
      cout <<"Value found at index: " << (firstHash + (i*secondHash))%n;
      return;
    }
    i++;
  }
  cout << "Value not found" << endl;
}


int main() {
    int size = 10;
    int arr1[size];
    int arr2[size];


    // Initialize the hash table with -1
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i] = -1;
    }


    // Insert keys into the hash table
    insert(arr1, 10, size);
    insert(arr1, 11, size);
    insert(arr1, 21, size);
    insert(arr1, 31, size);
    insert(arr1, 32, size);
    insert(arr1, 19, size);
    insert(arr1, 59, size);


    doublehash_insert(arr2, 10, size);
    doublehash_insert(arr2, 11, size);
    doublehash_insert(arr2, 21, size);
    doublehash_insert(arr2, 31, size);
    doublehash_insert(arr2, 32, size);
    doublehash_insert(arr2, 19, size);
    doublehash_insert(arr2, 59, size);

    

    
  

    // Display the hash table
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": " << arr1[i] << endl;
    }
  cout <<endl;

for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": " << arr2[i] << endl;
    }

   

  
}


