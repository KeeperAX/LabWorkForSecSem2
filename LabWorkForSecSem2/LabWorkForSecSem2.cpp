#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next; // Указатель на следующий узел

    Node(int value) : data(value), next(nullptr) {} // Конструктор
};

short kol = 0;

struct List {
    Node* front; // Указатель на первый узел
    Node* last;  // Указатель на последний узел

    List() : front(nullptr), last(nullptr) {} // Конструктор

    void addnum(int num) {
        Node* newNode = new Node(num); // Создаем новый узел
        if (last == nullptr) {
            front = last = newNode; // Если список пуст, новый узел становится первым и последним
        }
        else {
            last->next = newNode; // Добавляем новый узел в конец списка
            last = newNode; // Обновляем указатель на последний узел
        }
    }

    void changeList() {
        Node* current = front; // Начинаем с первого узла
        while (current != nullptr) {
            if (current->data < 0) { // Если текущее значение отрицательное
                kol++;
                Node* newNode = new Node(0); // Создаем новый узел со значением 0
                newNode->next = current->next; // Указываем, что следующий узел - это текущий
                current->next = newNode; // Вставляем новый узел после текущего
                current = newNode; // Переходим к новому узлу
            }
            current = current->next; // Переходим к следующему узлу
        }
    }

    void removeNum() {
        Node* current = front; // Начинаем с первого узла
        Node* prev = nullptr; // Указатель на предыдущий узел
        while (current != nullptr) {
            if (current->data < 0) { // Если текущее значение отрицательное
                if (prev == nullptr) {
                    front = current->next; // Если это первый узел, обновляем front
                    delete current; // Удаляем текущий узел
                    current = front; // Переходим к следующему узлу
                }
                else {
                    prev->next = current->next; // Удаляем текущий узел
                    delete current; // Удаляем текущий узел
                    current = prev->next; // Переходим к следующему узлу
                }
            }
            else {
                prev = current; // Обновляем предыдущий узел
                current = current->next; // Переходим к следующему узлу
            }
        }
        last = prev; // Обновляем указатель на последний узел
    }

    void searchnum(int num) {
        Node* current = front; // Начинаем с первого узла
        while (current != nullptr) {
            if (current->data == num) // Если нашли число
                kol++;
            current = current->next; // Переходим к следующему узлу
        }
    }

    void remove() {
        if (front == nullptr) // Если список пуст
            return;
        Node* temp = front; // Сохраняем указатель на первый узел
        front = front->next; // Обновляем front
        if (front == nullptr) // Если список стал пустым
            last = nullptr; // Обновляем last
        delete temp; // Удаляем первый узел
    }

    void print() {
        Node* current = front; // Начинаем с первого узла
        while (current != nullptr) {
            cout << current->data << " "; // Выводим данные узла
            current = current->next; // Переходим к следующему узлу
        }
        cout << endl; // Переход на новую строку
    }

    bool isEmpty() {
        return front == nullptr; // Проверяем, пуст ли список
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    List myList;
    cout << "Введите числа (0 - начало обработки): " << endl;
    int num;
    while (true) {
        cin >> num; // Читаем число
        if (num == 0) {
            break; // Выход из цикла, если введено 0
        }
        else {
            myList.addnum(num); // Добавляем число в список
        }
    }

    cout << "Список без изменений: ";
    myList.print();
    myList.changeList();
    cout << "Список с добавленными нулями после отрицательного числа: ";
    myList.print();
    myList.removeNum();
    cout << "Список с удаленными отрицательными числами: ";
    myList.print();

    int a;
    cout << "Введите число, количество которого нужно найти: ";
    cin >> a;
    myList.searchnum(a);
    cout << "Количество вхождений числа " << a << ": " << kol << endl;

    while (!myList.isEmpty()) {
        myList.remove(); // Удаляем все элементы списка
    }

    return 0;
}

