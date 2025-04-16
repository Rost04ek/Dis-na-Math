#include "Converter.h"
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <cmath>
#include <cstring>

int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Додає елемент у стек
void push(Node *&head, datatype key) {
    Node *tmp = new Node;
    tmp->key = key;
    tmp->next = head;
    tmp->previous = nullptr;
    if (head != nullptr)
        head->previous = tmp;
    head = tmp;
}

// Видаляє елемент зі стеку
void pop(Node *&head) {
    if (head == nullptr) return;
    Node *tmp = head;
    head = head->next;
    if (head != nullptr)
        head->previous = nullptr;
    delete tmp;
}

// Виводить стек (для відлагодження)
void show(Node *head) {
    while (head != nullptr) {
        std::cout << head->key << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Реверсує слова у рядку (операнди/оператори)
datatype reverse(datatype str) {
    std::vector<std::string> tokens;
    std::string token;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') {
            token += str[i];
        } else if (!token.empty()) {
            tokens.push_back(token);
            token.clear();
        }
    }
    if (!token.empty()) tokens.push_back(token);
    std::reverse(tokens.begin(), tokens.end());
    datatype result;
    for (auto& t : tokens) {
        result += t + " ";
    }
    return result;
}

// Перетворення інфіксного виразу у постфіксний
datatype InfixToPostfix(datatype str) {
    datatype result = "";
    Node *head = nullptr;
    for (size_t i = 0; i < str.length(); i++) {
        if (std::isspace(str[i])) continue;
        if (std::isalnum(str[i])) {
            datatype number;
            while (i < str.length() && std::isalnum(str[i])) {
                number += str[i];
                i++;
            }
            i--;
            result += number + " ";
        }
        else if (str[i] == '(') {
            push(head, std::string() + str[i]);
        }
        else if (str[i] == ')') {
            while (head != nullptr && head->key != "(") {
                result += head->key + " ";
                pop(head);
            }
            if (head != nullptr && head->key == "(")
                pop(head);
        }
        else if (std::strchr("+-*/^", str[i])) {
            while (head != nullptr && head->key != "(" &&
                   priority(head->key[0]) >= priority(str[i])) {
                result += head->key + " ";
                pop(head);
            }
            push(head, std::string() + str[i]);
        }
    }
    while (head != nullptr) {
        result += head->key + " ";
        pop(head);
    }
    return result;
}

// Перетворення інфіксного виразу у префіксний
datatype InfixToPrefix(datatype str) {
    std::reverse(str.begin(), str.end());
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
    datatype postfix = InfixToPostfix(str);
    return reverse(postfix);
}

// Перетворення постфіксного виразу у інфіксний
datatype PostfixToInfix(datatype str) {
    std::istringstream iss(str);
    std::string token;
    std::stack<datatype> st;
    while (iss >> token) {
        if (std::isalnum(token[0])) {
            st.push(token);
        } else if (token.length() == 1 && std::strchr("+-*/^", token[0])) {
            if (st.size() < 2) return "Помилка!";
            datatype b = st.top(); st.pop();
            datatype a = st.top(); st.pop();
            st.push("(" + a + token + b + ")");
        }
    }
    return st.empty() ? "Помилка!" : st.top();
}

// Перетворення префіксного виразу у інфіксний
datatype PrefixToInfix(datatype str) {
    std::istringstream iss(str);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) tokens.push_back(token);
    std::stack<datatype> st;
    for (int i = tokens.size() - 1; i >= 0; --i) {
        if (std::isalnum(tokens[i][0])) {
            st.push(tokens[i]);
        } else if (tokens[i].length() == 1 && std::strchr("+-*/^", tokens[i][0])) {
            if (st.size() < 2) return "Помилка!";
            datatype a = st.top(); st.pop();
            datatype b = st.top(); st.pop();
            st.push("(" + a + tokens[i] + b + ")");
        }
    }
    return st.empty() ? "Помилка!" : st.top();
}

// Обчислення результату двох чисел за оператором
double count(double a, double b, char operation) {
    switch (operation) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

// Обчислення значення постфіксного виразу
double countPostfix(datatype str) {
    std::istringstream iss(str);
    std::string token;
    std::stack<double> st;
    while (iss >> token) {
        if (std::isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) {
            st.push(std::stod(token));
        } else if (token.length() == 1 && std::strchr("+-*/^", token[0])) {
            if (st.size() < 2) return 0;
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            st.push(count(a, b, token[0]));
        }
    }
    return st.empty() ? 0 : st.top();
}

// Обчислення значення префіксного виразу
double countPrefix(datatype str) {
    std::istringstream iss(str);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) tokens.push_back(token);
    std::stack<double> st;
    for (int i = tokens.size() - 1; i >= 0; --i) {
        if (std::isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i].length() > 1)) {
            st.push(std::stod(tokens[i]));
        } else if (tokens[i].length() == 1 && std::strchr("+-*/^", tokens[i][0])) {
            if (st.size() < 2) return 0;
            double a = st.top(); st.pop();
            double b = st.top(); st.pop();
            st.push(count(a, b, tokens[i][0]));
        }
    }
    return st.empty() ? 0 : st.top();
}