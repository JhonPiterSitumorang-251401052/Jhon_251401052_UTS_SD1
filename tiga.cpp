#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value) {
    if(top == MAX - 1){
        cout << "Stack Penuh!\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dalam stack\n";
    }
}
char pop() {
    if(top == -1){
        cout << "Stack kosong!\n";
    } else {
        cout << stack[top] << " ";
        top--;
    }
}

int main() {
    string kata;
    string kata2;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;
    cout << endl;

    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    cout << endl;
    while (top != -1) {
        cout << pop();
    }
    
    cout << "Masukkan kata setelah di balik oleh program : ";
    cin >> kata2;

    if(kata = kata2){
        cout << "PALINDROM";
    } else {
        cout << "Bukan PALINDROM";
    }
    cout << endl;

    return 0;
}