#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;


struct Atoms {
    char name[10];
    char symbol[3];
    double weightA;
    double zap;
};

typedef struct Atoms DataType;

template <typename T>
class List {

public:

    List();
    ~List();
    void push_back(T data);
    void write_node();
    void delete_node();
    T input_data();
    void search();
    void show();
    void edit();
    void delete_list();
    void read_file();
    void rewrite_file();
    ifstream fin;
    ofstream fout;
    string path;

private:

    template <typename T>
    class Node {
    public:
        T data;
        Node* pNext;

        Node() {
            this->pNext = nullptr;
        }

        Node(T data, Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node<T>* head;
    int Size = 0;

};

template <typename T>
List<T>::List() {

    head = nullptr;

}

template <typename T>
List<T>::~List() {

}