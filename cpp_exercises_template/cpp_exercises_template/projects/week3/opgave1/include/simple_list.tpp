#include "simple_list.h"

template <typename Object>
void List<Object>::clear() {
	Node *p = head->next;
	while (p != tail) {
		Node *t = p->next;
		delete p;
		p = t;
		head->next = t;
	}
}

template <typename Object>
void List<Object>::push_front(const Object x) {
    Node *p = new Node(x, head);
    head = p;

    if (theSize == 0) {
        tail = p;
    }

    theSize++;
}

template <typename Object>
inline void List<Object>::insert_mid(int position, const Object x) 
{

    if (position == 0) throw std::invalid_argument("Positionen er ikke i midten.\n");

    if (position > theSize) throw std::out_of_range("Dit input er større end listen.\n");

    Node* temp = head;
    Node* newNode = new Node(x);

    for (int i = 0; i < position - 2; ++i) {
        temp = temp->next; // Min midlertidige pointer hopper videre til det næste element i listen, svarende til lige før den position det nye objekt skal ind på.
    }
    newNode->next = temp->next;
    temp->next = newNode;

    theSize++;

}

template <typename Object>
inline void List<Object>::push_end(Object x)
{
    Node* newNode = new Node(x); // tildeler en plads på heapen til en pointer der peger på et objekt på størrelse med Object

    if (theSize == 0) {
        head = newNode;
        tail = newNode; // Tildeler objektets/listens head og tail til samme Node nu der kun er én. 
    } else {
        tail->next = newNode; 
        tail = newNode;
		newNode->next = nullptr;
    }

    theSize++;
}

template <typename Object>
inline void List<Object>::delete_front()
{
	if (theSize == 0) throw std::invalid_argument("Listene r tom. Brug en anden funktion.");
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	theSize--;
	if (theSize == 0) tail = nullptr;
}

template <typename Object>
inline void List<Object>::delete_back()
{
	if (empty()) {
		throw std::invalid_argument("Listen er tom.");

	} else if (theSize == 1) {
			clear();
	}
	
	else {
		Node* temp = head;

			while (temp->next->next != nullptr) {
				temp = temp->next;
			}

		Node* target = temp->next;

		tail = temp;
		tail->next = nullptr;
		delete target;

		theSize--;
		}
}

template <typename Object>
inline void List<Object>::delete_middle(int position)
{
	if (position > theSize) {
		throw std::invalid_argument("Listen er ikke så lang.");
	}

	Node* temp = head;
	Node* target;

	for (int i = 0; i < position -1; ++i) {
		temp = temp->next;
	}
	target = temp->next;
	temp->next = target->next;

	delete target;
	theSize--;

}

template <typename Object>
inline void List<Object>::reverse()
{
	Node* prev = nullptr;
	Node* current = head;
	Node* next = nullptr;

	tail = head;

	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;

}

template <typename Object>
inline std::string List<Object>::print_list() const
{
	std::stringstream result;
	Node* temp = head;

	while (temp != nullptr) {
		result << temp->data << ", ";
		temp = temp->next;
	}

    return result.str();
}

template <typename Object>
Object List<Object>::pop_front()
{
    Node *p = head->next;
	Object x = p->data;
	head->next = p->next;
	theSize--;
	delete p;
	return x;
}

template <typename Object>
Object List<Object>::find_kth(int pos) {
	assert(pos >= 0 && pos < theSize);
	Node *p = head->next;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	return p->data;
}

