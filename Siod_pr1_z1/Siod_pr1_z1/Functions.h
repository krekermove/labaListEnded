#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

//Фукция ввода данных с консоли
template <typename T>
T List<T>::input_data() {
    DataType data;
    cout << "Enter element name: " << endl;
    cin >> data.name;
    cout << "Enter element symbol: " << endl;
    cin >> data.symbol;
    cout << "Enter element weight: " << endl;
    cin >> data.weightA;
    cout << "Enter element zap: " << endl;
    cin >> data.zap;
    cout << "-------------------------" << endl;
    return data;
}

//Добавление элемента в конец списка
template <typename T>
void List<T>::push_back(T data) {
    fout.open(path, fstream::out | fstream::app);
    if (head == nullptr) {
        head = new Node<T>(data);
        if (!this->fout.is_open()) {
            cout << "File not found" << endl;
        }
        else {
            this->fout << "\n" << head->data.name << "    ";
            this->fout << head->data.symbol << "    ";
            this->fout << head->data.weightA << "    ";
            this->fout << head->data.zap;
            cout << "Data recorded succesfully" << endl;
            getchar();
            getchar();
        }
    }
    else {
        Node<T>* cur = this->head;
        while (cur->pNext != nullptr) {
            cur = cur->pNext;
        }
        cur->pNext = new Node<T>(data);
        cur = cur->pNext;
        if (!this->fout.is_open()) {
            cout << "File not found" << endl;
            getchar();
            getchar();
        }
        else {
            this->fout << "\n" << cur->data.name << " ";
            this->fout << cur->data.symbol << " ";
            this->fout << cur->data.weightA << " ";
            this->fout << cur->data.zap;
            cout << "Data recorded succesfully" << endl;
            getchar();
            getchar();
        }
    }
    Size++;
    fout.close();
}

//Вывод нужного элемента в консоль
template <typename T>
void List<T>::write_node() {
    char symbol[3];
    cout << "Enter element symbol:" << endl;
    cin >> symbol;
    int flag = 0;
    Node<T>* cur = this->head;
    while (cur != nullptr) {
        if (symbol == cur->data.symbol) {
            cout << cur->data.name << endl;
            cout << cur->data.symbol << endl;
            cout << cur->data.weightA << endl;
            cout << cur->data.zap << endl;
            flag++;
        }
        cur = cur->pNext;
    }
    if (flag == 0) {
        cout << "Not found" << endl;
        getchar();
        getchar();
    }
}

//Удаление узла списка
template <typename T>
void List<T>::delete_node() {

    int index;
    cout << "Enter index:" << endl;
    cin >> index;
    if (index == 1) {
        Node<T>* temp = head;
        head = head->pNext;
        delete temp;
        cout << "Deleted" << endl;
        cout << "-------------------------" << endl;
        rewrite_file();
    }
    else if (index == Size) {
        Node<T>* cur = head;
        Node<T>* temp;
        int count = 1;
        while (count != index - 1) {
            cur = cur->pNext;
            count++;
        }
        temp = cur->pNext;
        cur->pNext = nullptr;
        delete(temp);
        cout << "Deleted" << endl;
        cout << "-------------------------" << endl;
        rewrite_file();
    }
    else {
        Node<T>* cur = head;
        Node<T>* temp;
        int count = 1;
        while (count != index - 1) {
            cur = cur->pNext;
            count++;
        }
        temp = cur->pNext;
        cur->pNext = cur->pNext->pNext;
        delete temp;
        cout << "Deleted" << endl;
        cout << "-------------------------" << endl;
        rewrite_file();
    }
}

//Поиск элемента с наибольшей массой
template <typename T>
void List<T>::search() {

    Node<T>* cur = this->head;
    Node<T>* temp = this->head;
    double max_weight = 0;
    while (cur != nullptr) {
        if (cur->data.weightA > max_weight) {
            max_weight = cur->data.weightA;
            temp = cur;
        }
        cur = cur->pNext;
    }
    if (max_weight == 0) {
        cout << "Not found" << endl;
        cout << "-------------------------" << endl;
    }
    else {
        cout << "Element with max weight:" << endl;
        cout << temp->data.name << endl;
        cout << temp->data.symbol << endl;
        cout << temp->data.weightA << endl;
        cout << temp->data.zap << endl;
        cout << "-------------------------" << endl;
    }
    getchar();
    getchar();
}

//Вывод в консоль всех элементов
template <typename T>
void List<T>::show() {
    Node<T>* cur = this->head;
    int k = 0;
    system("CLS");
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else {
        cout << "|  N |          Name                 |    Symbol   |   Weight   |   Zap   |" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        while (cur != nullptr) {
            printf("|%3d | %-29s |%12s |%11.2f |%8.2f |\n", ++k, cur->data.name,
                cur->data.symbol, cur->data.weightA, cur->data.zap);
            cur = cur->pNext;
        }
    }
    getchar();
    getchar();
}

//Редактирование указанного узла спика
template <typename T>
void List<T>::edit() {
    int index;
    int count = 1;
    char menu;
    cout << "Enter index: " << endl;
    cin >> index;
    Node<T>* cur = this->head;
    while (count != index) {
        cur = cur->pNext;
        count++;
    }
    do {
        system("CLS");
        cout << "1. Edit name" << endl;
        cout << "2. Edit symbol" << endl;
        cout << "3. Edit weight" << endl;
        cout << "4. Edit zap" << endl;
        cout << "5. Exit" << endl;
        menu = getchar();
        switch (menu)
        {
        case '1': cout << "Enter new name: "; cin >> cur->data.name; break;
        case '2': cout << "Enter new symbol: "; cin >> cur->data.symbol; break;
        case '3': cout << "Enter new weight: "; cin >> cur->data.weightA; break;
        case '4': cout << "Enter new zap: "; cin >> cur->data.zap; break;
        }
    } while (menu != '5');
    rewrite_file();
}

//Удаление списка
template <typename T>
void List<T>::delete_list() {
    fout.open(path, fstream::trunc);
    Node<T>* temp = this->head;
    while (temp)
    {
        head = temp->pNext;
        delete temp;
        temp = head;
    }
    cout << "List succesfully deleted";
    getchar();
    getchar();
}


template <typename T>
void List<T>::read_file() {
    fin.open(path, fstream::in);
    if (this->fin.is_open()) {
        while (!this->fin.eof()) {
            if (head == nullptr) {
                head = new Node<T>();
                this->fin >> head->data.name;
                this->fin >> head->data.symbol;
                this->fin >> head->data.weightA;
                this->fin >> head->data.zap;
            }
            else {
                Node<T>* cur = this->head;
                while (cur->pNext != nullptr) {
                    cur = cur->pNext;
                }
                cur->pNext = new Node<T>();
                cur = cur->pNext;
                this->fin >> cur->data.name;
                this->fin >> cur->data.symbol;
                this->fin >> cur->data.weightA;
                this->fin >> cur->data.zap;
            }
        }
        cout << "Data recorded succesfully";
    }
    else {
        cout << "File not opened";
    }
    fin.close();
    getchar();
    getchar();
}


template <typename T>
void List<T>::rewrite_file() {
    fout.open(path, fstream::trunc | fstream::out);
    Node<T>* current = this->head;
    while (current != nullptr) {
        this->fout << "\n" << current->data.name << " ";
        this->fout << current->data.symbol << " ";
        this->fout << current->data.weightA << " ";
        this->fout << current->data.zap;
        current = current->pNext;
    }
    cout << "Data recorded succesfully" << endl;
    fout.close();
    getchar();
    getchar();
}