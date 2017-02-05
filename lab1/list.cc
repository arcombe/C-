#include <iostream>
#include "list.h"

using namespace std;

List::List() {
	first = nullptr;
}

List::~List() {
	if(first==nullptr) return;

	Node* curr = first->next;
	while (curr != nullptr){
		delete first;
		first = curr;
		curr = curr->next;
	}
	delete first;
	first=nullptr;
}

bool List::exists(int d) const {
	Node* n = first;
	while (n != nullptr){
		if(n->value == d){
			return true;
		}
		n = n->next;
	}
	return false;
}

int List::size() const {
	int count = 0;
	Node* n = first;
	while (n != nullptr){
		count ++;
		n = n->next;
	}
	return count;
}

bool List::empty() const {
	return first == nullptr;
}

void List::insertFirst(int d) {

	if (List::empty())
	{
		first = new Node(d, nullptr);
	} else {
		Node* n = first;
		Node* m = new Node(d, n);
		first = m;
	}

}
bool List::compare(int x, int y, DeleteFlag df){
	switch (df) {
		case DeleteFlag::EQUAL: return x==y;
		case DeleteFlag::LESS: return x<y;
		case DeleteFlag::GREATER: return x>y;
		default: return false;
	}
}

void List::remove(int d, DeleteFlag df) {
	Node* curr = first;
	Node* prev = nullptr;
		while (curr != nullptr){
			if (compare(curr->value, d, df) and prev != nullptr){
				prev->next = curr->next;
				delete curr;
				break;
			} else if (compare(curr->value, d, df)){
				prev = first;
				first = curr->next;
				delete prev;
				break;
			}
			prev = curr;
			curr = curr->next;
		}


}

void List::print() const {
	if (List::empty()){
		cout << "List is empty" << endl;
	}else {
		Node* n = first;
		while (n != nullptr){
			cout << n->value << " ";
			n = n->next;
		}
		cout << endl;
	}

}
