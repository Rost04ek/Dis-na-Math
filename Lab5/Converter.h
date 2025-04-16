#pragma once
#include <string>

typedef std::string datatype;

struct Node
{
    datatype key;
    Node *next;
    Node *previous;
};

datatype InfixToPostfix(datatype str);
datatype InfixToPrefix(datatype str);
datatype PostfixToInfix(datatype str);
datatype PrefixToInfix(datatype str);
double countPostfix(datatype str);
double countPrefix(datatype str);
datatype reverse(datatype str);
double count(double a, double b, char operation);
void push(Node *&head, datatype key);
void pop(Node *&head);
void show(Node *head);