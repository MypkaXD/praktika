#include <iostream>
#include <initializer_list>

#define size_t int

template <class T>
class List {
	struct Node {
		T m_elem = T(); // элемент 
		Node* m_next = nullptr; // указатель на следующий элемент
		Node(T elem, Node* next) : m_elem(elem), m_next(next) {}
		Node(T elem) : m_elem(elem) {}
		Node() {}
		Node(const Node& other) {
			m_elem = other.m_elem;
			delete[] m_next;
			m_next = new Node();
			m_next = other.m_next;
		}
	};
	Node* m_first = nullptr;
public:
	List() {}
	explicit List(const size_t size) {
		if (size == 0)
			return;
		if (size < 0)
			throw ("ERROR: SIZE SHOULD BE GRERATER THAN ZERO");
		m_first = new Node();
		Node* temp = m_first;
		for (size_t count = 1; count < size; ++count) {
			temp->m_next = new Node();
			temp = temp->m_next;
		}
	}
	List(size_t size, T elem) {
		if (size == 0)
			return;
		m_first = new Node(elem);
		Node* temp = m_first;
		for (size_t count = 1; count < size; count++) {
			temp->m_next = new Node(elem);
			temp = temp->m_next;
		}
	}
	//List(const T& elem) {
	//	m_first = new Node(elem);
	//}
	List(const List<T>& other) {
		delete[] m_first;
		m_first = new Node(other.m_first->m_elem);
		Node* temp = m_first;
		for (size_t count = 1; count < other.size(); count++) { // есть ли другой способ? типо for (size_t count = 1; other.m_first->m_next!=nullptr; count++)???
			temp->m_next = new Node(other.m_first->m_elem);
			temp = temp->m_next;
		}
	}
	List(const std::initializer_list<T>& list) {
		delete[] m_first;
		m_first = new Node(*list.begin());
		Node* temp = m_first;
		for (auto it = list.begin() + 1; it < list.end(); ++it) {
			temp->m_next = new Node(*it);
			temp = temp->m_next;
		}
	}
	~List() {
		Node* temp = m_first;
		while (temp) {
			Node* temp2 = temp->m_next;
			delete[] temp;
			temp = temp2;
		}
	}
	List& operator=(const List& other) {
		if (this == &other)
			return *this;
		delete[] m_first;
		m_first = new Node(other.m_first->m_elem);
		Node* temp1 = m_first;
		Node* temp2 = other.m_first->m_next;
		for (size_t count = 1; count < other.size(); ++count) {
			temp1->m_next = new Node(temp2->m_elem);
			temp1 = temp1->m_next;
			temp2 = temp2->m_next;
		}
		return *this;
	}
	const size_t size() const noexcept {
		Node* temp = m_first;
		size_t count = 0;
		while (temp) {
			temp = temp->m_next;
			count++;
		}
		return count;
	}

	void print() {
		Node* temp = m_first;
		while (temp) {
			std::cout << temp->m_elem << "\t";
			temp = temp->m_next;
		}
	}

	void flip() {
		Node* temp = m_first;
		Node* it = m_first;
		Node* temp1 = nullptr;
		while (it) {
			temp = it->m_next;
			it->m_next = temp1;
			temp1 = it;
			it = temp;
		}
		m_first = temp1;
	}

	void merge(const List& other) {
		if (size() + other.size() == 0) return;
		Node* result = new Node(m_first->m_elem);
		Node* temp = result;
		Node* tempHop = m_first->m_next;
		for (size_t count = 1; count < size(); ++count) {
			temp->m_next = new Node(tempHop->m_elem);
			temp = temp->m_next;
			tempHop = tempHop->m_next;
		}
		tempHop = other.m_first;
		for (size_t count = 0; count < other.size(); ++count) {
			temp->m_next = new Node(tempHop->m_elem);
			temp = temp->m_next;
			tempHop = tempHop->m_next;
		}
		m_first = result;
	}

	const bool empty() const noexcept {
		return !size();
	}

	//void clear() {
	//	Node* temp = m_first;
	//	delete[] m_first;
	//	for (size_t count 0; count < size(); ++count) {
	//
	//	}
	//}

	void pop_front() {
		if (m_first == nullptr)
			throw("ERROR: the list is emptry");
		Node* temp = m_first->m_next;
		delete[] m_first;
		m_first = temp;
	}

	void push_front(const T& elem) {
		Node* temp1 = new Node(elem);
		Node* temp2 = m_first;
		m_first = temp1;
		m_first->m_next = temp2;
	}
};

int main() {
	/*
	List<int> l1({ 1,2,3 });
	l1.push_front(10);
	l1.print();
	std::cout << std::endl;
	l1.flip();
	l1.print();
	std::cout << std::endl;
	l1.pop_front();
	l1.print();
	std::cout << std::endl;
	l1.flip();
	l1.print();
	std::cout << std::endl;
	l1.push_front(10);
	std::cout << std::endl;
	l1.print();
	*/
	/*
	
	List<int> l2({ 5,4,56 });

	List<int> l3;
	l3 = l2;
	l3.print();
	l3 = l3;
	l3.print();
	std::cout << std::endl;
	l1.merge(l2);
	l1.print();
	*/


	/*
	List<int> list1(10, 2);
	list1.print();

	std::cout << list1.size() << std::endl;

	List<int> list2(14);
	list2.print();
	std::cout << list2.size() << std::endl;

	List<int> list3(list1);
	list3.print();
	std::cout << list3.size() << std::endl;

	List<int> list4({ 1,2,3 });
	list4.print();
	std::cout << list4.size() << std::endl;
	*/

	return 0;
}
