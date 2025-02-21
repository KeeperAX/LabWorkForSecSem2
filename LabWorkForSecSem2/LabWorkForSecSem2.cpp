#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {} // Исправлено: передаем значение в конструктор
};

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

    void remove() {
        if (front == nullptr)
            return;
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            last = nullptr;
        delete temp;
    }

    void print() { // Изменено: теперь выводит все элементы
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl; // Для удобства вывода
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

    cout << "Числа: ";
    myList.print(); // Выводим все числа

    // Удаляем элементы и выводим их
    while (!myList.isEmpty()) {
        cout << "Удаленный элемент: " << myList.front->data << endl; // Выводим передний элемент
        myList.remove(); // Удаляем передний элемент
    }

    return 0;
}
