#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

Queue::Queue() :elements(0), rear(NULL), front(NULL) {}

Queue::~Queue() {
	unsigned el = items();
	for (unsigned i = 0; i<el; i++)
		remove();
}
unsigned Queue::items()const {
	return elements;
}

char* Queue::remove() {
	//if (front == NULL) die("underflow");
	Node *t = front;
	char* data = t->data;
	//data = (char*)malloc(sizeof(char) * 100);
	front = t->next;
	//delete t;
	elements--;
	return data;
}
void Queue::add(const char* item) {
	Node *t = new Node;
	//t->data = item;
	t->data = (char*)malloc(sizeof(char) * 100);
	strcpy(t->data, item);
	t->next = NULL;
	if (front == NULL)
		front = t;
	else {
		Node *t2 = rear;
		t2->next = t;
	}
	rear = t;
	elements++;
}

void Queue::addforstat(const char* item, const int lvl) {
	Node *t = new Node;
	//t->data = item;
	t->data = (char*)malloc(sizeof(char) * 100);
	strcpy(t->data, item);
	t->monstrlvl = lvl;
	t->next = NULL;
	if (front == NULL)
		front = t;
	else {
		Node *t2 = rear;
		t2->next = t;
	}
	rear = t;
	elements++;
}

void  Queue::show() const {
	Node *t = front;
	for (unsigned i = 0; i<items(); i++, t = t->next)
		cout << t->data << " Lvl " << t->monstrlvl << '\n';
}

bool die(const char* &msg) {
	cout << "Error: " << msg;
	exit(EXIT_FAILURE);
}