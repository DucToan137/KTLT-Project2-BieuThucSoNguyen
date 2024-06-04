#pragma once
#include<iostream>
#include<string>

using namespace std;

template <class T>
struct Node {
	T data;
	Node* pNext;
};

template <class T>
struct Stack {
	Node<T>* top;
};

template <class T>
void Init(Stack<T>& s) {
	s.top = nullptr;
}

template <class T>
Node<T>* CreateNode(T val) {
	Node<T>* p = new Node<T>;
	if (p == nullptr) {
		return nullptr;
	}
	p->data = val;
	p->pNext = nullptr;
	return p;
}

template <class T>
bool IsEmpty(Stack<T> s) {
	return s.top == nullptr;
}

template <class T>
bool Push(Stack<T>& s, T val) {
	Node<T>* p = CreateNode(val);
	if (p == nullptr) {
		return false;
	}
	if (IsEmpty(s)) {
		s.top = p;
	}
	else {
		p->pNext = s.top;
		s.top = p;
	}
	return true;
}

template <class T>
bool Pop(Stack<T>& s) {
	if (IsEmpty(s)) {
		return false;
	}
	Node<T>* p = s.top;
	s.top = s.top->pNext;
	delete p;
	return true;
}

template <class T>
T Top(Stack<T> s) {
	if (IsEmpty(s)) {
		return NULL;
	}
	return s.top->data;
}



