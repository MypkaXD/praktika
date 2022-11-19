#include <iostream>
#include <initializer_list>

#define size_t int

template <class T>
class Vector {
private:
	size_t m_size = 0;
	T* m_data = nullptr;
public:
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
		iterator operator++(size_t) {
			iterator temp = m_ptr;
			m_ptr += 1;
			return temp;
		}

		iterator& operator--() {
			m_ptr -= 1;
			return *this;
		}
		iterator operator--(size_t) {
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
		bool operator!=(const iterator& other) {
			return (m_ptr != other.m_ptr);
		}
		bool operator==(const iterator& other) {
			return (m_ptr == other.m_ptr);
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
	Vector() {}
	Vector(size_t size) {
		if (size <= 0)
			throw ("ERROR: size should be greaater than zero");
		m_size = size;
		m_data = new T[m_size];
	}
	Vector(const Vector& other) {
		m_size = other.m_size;
		delete[] m_data;
		m_data = new T[m_size];
		iterator i(begin());
		iterator k(other.begin());
		for (k; k != other.end(); ++k) {
			i = k;
			++i;
		}
	}
	Vector(const std::initializer_list<T>& list) {
		m_data = new T[list.size()];
		size_t count = 0;
		for (auto it = list.begin(); it < list.end(); ++it) {
			m_data[count] = *it;
			count++;
		}
	}

	T& operator[](const size_t index) noexcept{
		return m_data[index];
	}

	const iterator begin() const {
		return iterator(m_data);
	}
	const iterator end() const {
		return iterator(iterator(begin()) + m_size);
	}


	friend std::ostream& operator<<(std::ostream& out, const Vector& other) {
		out << "[\t";
		iterator k(other.begin());
		for (k; k != other.end();++k) {
			out << *k << "\t";
		}
		out << "]";
		return out;
	}
};

int main() {

	Vector<int> v({1,2,3,4,5});
	Vector<int> v1(3);
	Vector<int>::iterator count(v1.begin());
	for (count; count < v1.end(); ++count)
		*count = 1;
	std::cout << v1;


	return 0;
}