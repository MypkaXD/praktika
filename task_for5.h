/*
Пишем список


template <class T>
class List{
	Node<T> * first = nullptr;
public:
	List(){}
	explacive List(size_t size){}
	List(const T elem){}
	List(const List& other){}
	List(const List&& other) noexcept{}
	//впихнуть класс итераторов
	List(const std::inilizer_list& other){}
	~List(){}
	List& operator=(cosnt List& other){}
	List& operator=(const List&& other){}
	void assign(iterator first, iterator last){}
	bool empty() const; // O(1) or O(n)
	size_t size();// O(1) or O(n)
	void clear(){}// удалить элементы контейнера
	begin and end();
	void merge(){}//сливает два списка в один
	void sort(){}//сортировка списка быстрая или слиянием O(nlogn) бинарный поиск НЕ НАДО юзать
	Node* insert_after(Node* prev, T value){}// если нет итератора
	iterator insert_after(iterator prev, T value){}// если есть итератора
	Node* erase_after(Node* prev)//удаляет элемент после того, который пришел
	void push_front(T value);
	void pop_front();
};

*/


/*
template <class T>
class List {
public:
	template <class T>
	struct Node {
		T m_element;
		Node* m_next = nullptr;
		Node(T element, Node* next) :
			m_element(element), m_next(next) {
		}
	};
	class iterator {
	private:
		T* m_ptr = nullptr;
	public:
		iterator(T* ptr) : m_ptr(ptr) {}
		iterator(const iterator& other) : m_ptr(other.m_ptr) {}
		~iterator() {
			m_ptr = nullptr;
		}
		iterator& operator=(const iterator& other) {
			m_ptr = other.m_ptr;
			return *this;
		}

		iterator& operator++() {
			m_ptr += 1;
			return *this;
		}
		iterator operator++(int) {
			iterator temp = m_ptr;
			m_ptr += 1;
			return temp;
		}

		iterator& operator--() {
			m_ptr -= 1;
			return *this;
		}
		iterator operator--(int) {
			iterator temp = m_ptr;
			m_ptr -= 1;
			return temp;
		}

		iterator operator+(size_t n) { // двигает не на ++ а на больше
			iterator temp = m_ptr + n;
			return temp;
		}
		iterator operator-(size_t n) { // двигает не на -- а на больше
			iterator temp = m_ptr - n;
			return temp;
		}

		T& operator*() {
			return *m_ptr;
		}
		bool operator<(const iterator& other) {
			if (m_ptr < other.m_ptr) return true;
			else return false;
		}
		friend bool operator!=(const iterator& first, const iterator& second) {
			return (first.m_ptr != second.m_ptr);
		}
		friend bool operator==(const iterator& first, const iterator& second) {
			return !(second == first);
		}
		friend size_t operator-(const iterator& first, const iterator& second) { // найти расстояние между двумя инетаротами
			return size_t(first.m_ptr - second.m_ptr);
		}
	};
private:
	Node* m_first = nullptr;
	size_t m_size = 0;
public:
	List() {}
	//List(size_t size, T elem) {
	//	if (size == 0)
	//		return;
	//	m_first = new Node(elem);
	//	Node<T>* temp = m_first;
	//	for (size_t count = 0; count < size; count++) {
	//		temp->m_next = new Node(elem);
	//		temp = temp->m_next;
	//	}
	//}
	explicit List(size_t size) {
		if (size == 0)
			return;
		m_first = new Node();
		Node<T>* temp();
		for (size_t count = 0; count < size; count++) {
			temp->m_next = new Node();
			temp = temp->m_next;
		}
	}
	//List(const List& other) {
	//	Node* listPtr = other.m_first;
	//	if (!listPtr) return;
	//	first = new Node();
	//
	//}
	~List() {
		clear();
	}

	void clear()
	{
		while (m_size)
		{
			pop_front();
		}
	}

	bool empty() {
		return m_size;
	}

	T& operator[](const int index)
	{
		int counter = 0;

		Node<T>* current = this->m_first;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->m_element;
			}
			current = current->m_next;
			counter++;
		}
	}

	size_t getSize() {
		return m_size;
	}

	void push_back(T elem) {
		if (m_first == nullptr)
		{
			m_first = new Node<T>(elem);
		}
		else
		{
			Node<T>* current = this->m_first;

			while (current->m_next != nullptr)
			{
				current = current->m_next;
			}
			current->m_next = new Node<T>(elem);

		}

		m_size++;
	}

	void push_front(T data)
	{
		m_first = new Node<T>(data, m_first);
		m_size++;
	}

	void removeAt(int index);
	void pop_front();
	void pop_back();

	friend List& operator<<(std::ostream& out, const List* other) {
		out << "SIXE IS = " << getSize() << "\n";
		for (size_t count = 0; count < m_size; count++) {

		}
	}
};

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->m_first;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->m_next;

		previous->m_next = toDelete->m_next;

		delete toDelete;

		m_size--;
	}

}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = m_first;

	m_first = m_first->m_next;

	delete temp;

	m_size--;

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(m_size - 1);
}

*/