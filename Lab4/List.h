#ifndef LIST_H
#define LIST_H

typedef int datatype;

struct Node {
    datatype key;
    Node* next;
    Node* previous;
};

void push(Node*& head, datatype key);
void pop(Node*& head);
void show(Node* head);
void enqueue(Node*& front, Node*& rear, datatype data);
void dequeue(Node*& front);
void addBegin(Node*& first, Node*& last, datatype data);
void addEnd(Node*& first, Node*& last, datatype data);
void delBegin(Node*& first, Node*& last);
void delEnd(Node*& first, Node*& last);
Node* search(Node* first, datatype data);
void addMid(Node*& first, Node*& last, datatype data, datatype key);
void delMid(Node*& first, Node*& last, datatype key);

#endif
