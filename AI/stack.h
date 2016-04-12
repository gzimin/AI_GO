 
#ifndef STACK_H
#define STACK_H
 
#include <cassert> // для assert
#include <iostream>
 
#include <iomanip> // для setw
using namespace std;
template <typename T>
class Stack
{
private:
    T *stackPtr;                      // указатель на стек
    const int size;                   // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека
public:
    Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
    Stack(const Stack<T> &);          // конструктор копирования
    ~Stack();                         // деструктор
 
    inline void push(const T & );     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека и вернуть его
    inline void printStack();         // вывод стека на экран
    inline const T &Peek(int ) const; // n-й элемент от вершины стека
    inline int getStackSize() const;  // получить размер стека
    inline T *getPtr() const;         // получить указатель на стек
    inline int getTop() const;        // получить номер текущего элемента в стеке
    inline T PoP();
};
 
// реализация методов шаблона класса STack
 
// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под стек
    top = 0; // инициализируем текущий элемент нулем;
}
 
// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
    size(otherStack.getStackSize()) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под новый стек
    top = otherStack.getTop();
 
    for(int ix = 0; ix < top; ix++)
        stackPtr[ix] = otherStack.getPtr()[ix];
}
 
// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr; // удаляем стек
}
 
// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
    // проверяем размер стека
    assert(top < size); // номер текущего элемента должен быть меньше размера стека
 
    stackPtr[top++] = value; // помещаем элемент в стек
}
 
// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
    // проверяем размер стека
    assert(top > 0); // номер текущего элемента должен быть больше 0

    stackPtr[--top]; // удаляем элемент из стека
    return stackPtr[top];
}

template <class T>
inline  T Stack<T>::PoP()
{

  return stackPtr[top];
}
// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
  //
  assert(nom <= top);
 
  return stackPtr[top - nom]; // вернуть n-й элемент стека
}
 
// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
    for (int ix = top - 1; ix >= 0; ix--)
        cout << "|" << setw(4) << stackPtr[ix] << endl;
}
 
// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}
 
// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::getPtr() const
{
    return stackPtr;
}
 
// вернуть размер стека
template <typename T>
inline int Stack<T>::getTop() const
{
    return top;
}
 
#endif // STACK_H
