/*
��������:

������������ � ���������� STL

Class Iterator{

Itertor& operator++()// ���������� ��������

Iterator operator++(int)//����������� ��������

T operator*(); // ������� ���� ������ ���� ����� ��������

friend bool operator!=(const Iterator& other_first, cosnt Itertor& other_second){

}


friend bool operator==(const Iterator& other_first, cosnt Itertor& other_second){
	retunr !(&other_first == &other_second);
}

Iterator& operator--() // ���������� ����� ���������
Iterator operator--(int) // ����������� ����� ���������

Iterator operator+(int n) // ������� �� �� ++ � �� ������
Iterator operator-(int n) // ������� �� �� -- � �� ������

friend int operator-(const Iterator& first, const Iterator& second) // ����� ���������� ����� ����� �����������

bool operator<
bool operator>
bool operator>=
bool operator<=

};
*/

/*

����:

T* ptr; // ����� ��������

���

int index;
T* start;

public:

Iterator() {}
Iterator(T* ptr);

class Vector{

iterator begin(){
	return Iterator(m_data);
}

iterator end(){
	return Iterator(m_data + m_size);
}

*/