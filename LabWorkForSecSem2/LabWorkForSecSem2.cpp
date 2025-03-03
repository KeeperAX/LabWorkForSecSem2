#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

short kol = 0;

struct List {
    Node* front;
    Node* last;

    List() : front(nullptr), last(nullptr) {}

    void addnum(int num) {
        Node* newNode = new Node(num);
        if (last == nullptr) {
            front = last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    void changeList() {
        Node* current = front;
        while (current != nullptr) {
            if (current->data < 0) {
                kol++;
                Node* newNode = new Node(0); 
                newNode->next = current->next;
                current->next = newNode;
                current = newNode; 
            }
            current = current->next;
        }
    }

    void removeNum() {
        Node* current = front;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data < 0) {
                if (prev == nullptr) { 
                    front = current->next;
                    delete current;
                    current = front;
                }
                else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            }
            else {
                prev = current;
                current = current->next;
            }
        }
        last = prev;
    }
    void remove() {
        if (front == nullptr)
            return;
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            last = nullptr;
        delete temp;
    }

    void print() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    List myList;
    cout << "\tВведи числа (0 - начало обработки)" << endl;
    int num;
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        else {
            myList.addnum(num);
        }
    }

    cout << "Список без изменений: ";
    myList.print();
    myList.changeList();
    cout << "\nСписок с добавленными нулями после отрицательного числа: ";
    myList.print();
    myList.removeNum();
    cout << "\nСписок с удаленными отрицательными числами: ";
    myList.print();
    cout << "\nКол-во отрицательных чисел: " << kol << endl;

    while (!myList.isEmpty()) {
        myList.remove(); 
    }

    return 0;
}
