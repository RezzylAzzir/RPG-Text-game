#pragma once
#include <iostream>
#include <string>
using namespace std;
//bool die(const char* &msg);

class Queue{
public:
	Queue();
	~Queue();
	void add(const char*  item);
	void addforstat(const char*  item, const int lvl);
	char* remove();
	unsigned items() const;
	void show() const;
	struct Node {
		char* data;
		int monstrlvl;
		Node *next;
	};
	Node *rear;
	Node *front;
	unsigned elements;
private:
	
};