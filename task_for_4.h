/*
Итератор:

Используется в конейнерах STL

Class Iterator{

Itertor& operator++()// префиксный итератор

Iterator operator++(int)//постфиксный итератор

T operator*(); // вернуть либо ссылку либо копию элемента

friend bool operator!=(const Iterator& other_first, cosnt Itertor& other_second){

}


friend bool operator==(const Iterator& other_first, cosnt Itertor& other_second){
	retunr !(&other_first == &other_second);
}

Iterator& operator--() // Префиксный минус интератор
Iterator operator--(int) // Постфиксный минут инетратор

Iterator operator+(int n) // двигает не на ++ а на больше
Iterator operator-(int n) // двигает не на -- а на больше

friend int operator-(const Iterator& first, const Iterator& second) // найти расстояние между двумя инетаротами

bool operator<
bool operator>
bool operator>=
bool operator<=

};
*/

/*

Поля:

T* ptr; // адрес элемента

или

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