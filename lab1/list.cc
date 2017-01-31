#include <iostream>
#include "list.h"

using namespace std;

List::List() {
	first = nullptr;
}

List::~List() {
	Node* curr = first->next;
	Node* prev = first;
	while (curr != nullptr){
		delete prev;
		prev = curr;
		curr = curr->next;
	}
	delete curr;
	delete prev;
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
		Node* n = new Node(d, nullptr);
		first = n;
	} else {
		Node* n = first;
		Node* m = new Node(d, n);
		first = m;
	}

}

void List::remove(int d, DeleteFlag df) {
	Node* curr = first;
	Node* prev = nullptr;
	if (df == DeleteFlag::EQUAL){
		while (curr != nullptr){
			if (curr->value == d and prev != nullptr){
				prev->next = curr->next;
				break;
			} else if (curr->value == d){
				first = curr->next;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}  else if (df == DeleteFlag::LESS){
			while (curr != nullptr){
				if (curr->value < d and prev != nullptr){
					prev->next = curr->next;
					break;
				} else if (curr->value < d){
					first = curr->next;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
	}	else if (df == DeleteFlag::GREATER){
			while (curr != nullptr){
				if (curr->value > d and prev != nullptr){
					prev->next = curr->next;
					break;
				} else if (curr->value > d){
					first = curr->next;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
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

