#include <cassert>
#include <exception>
#include <string>
#include <sstream>
#include <iostream>

#ifndef _LIST_H_
#define _LIST_H_



template <typename Object>
class List {
  private:
	struct Node {
	    Object  data;
	    Node   *next;

		Node(Object d, Node* n = nullptr) : data(d), next(n) {}
	};
	int   theSize;
	Node *head;
	Node *tail;

	
  public:
	List() {
		theSize = 0;
		head = nullptr; tail = nullptr;

	}

	~List() { clear(); delete head; delete tail; }

	int size() { return theSize; }
	bool empty() { return (size() == 0); }

	void clear();
	void push_front(const Object x);
    void insert_mid(int position, const Object x);
    void push_end(Object x);

	void delete_front();
	void delete_back();
	void delete_middle(int position);

	void reverse();

	std::string print_list() const;
    
	Object pop_front();
	Object find_kth(int pos);
};

#include "simple_list.tpp"

#endif

