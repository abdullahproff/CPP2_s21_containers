#ifndef CPP2_S21_CONTAINERS_SRC_S21_CONTAINERS_H_
#define CPP2_S21_CONTAINERS_SRC_S21_CONTAINERS_H_

#include <algorithm>  // Для использования copy
#include <cmath>
#include <initializer_list>
#include <iostream>  // стандартная библиотека
#include <limits>
#include <stdexcept>

using namespace std;  // пространства имен

namespace s21 {
template <class T>
class vector {
 public:
  using value_type = T;
  using size_type = size_t;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using pointer = T *;

 private:
  size_type size_;
  size_type capacity_;
  value_type *container;

 public:
  // Конструкторы
  // конструктор по умолчанию
  vector() {
    size_ = 0;
    capacity_ = 0;
    container = nullptr;
  }
  // Параметризованный конструктор
  vector(size_type n) {
    size_ = n;
    capacity_ = n;  // Пусть capacity равен n для простоты
    container = new value_type[n];
  }
  // создает вектор, инициализированный с использованием initializer_list
  // конструктор списка инициализаторов
  vector(initializer_list<value_type> const &items) {
    size_ = items.size();
    capacity_ = size_;
    container = new value_type[size_];

    // Инициализация вектора элементами из списка инициализаторов
    size_type index = 0;
    for (const auto &item : items) {
      container[index++] = item;
    }
  }
  // Конструктор копирования
  vector(const vector &v) {
    size_ = v.size_;
    capacity_ = v.capacity();
    container = new value_type[capacity_];
    // Копирование элементов из вектора v в текущий вектор
    copy(v.container, v.container + size_, container);
  }
  // переместить конструктор
  vector(vector &&v) {
    // Перемещаем ресурсы из v в текущий объект
    size_ = v.size_;
    capacity_ = v.capacity_;
    container = v.container;
    // Сброс состояния v, чтобы избежать удаления ресурсов в деструкторе
    v.size_ = 0;
    v.capacity_ = 0;
    v.container = nullptr;
  }
  // Деструктор
  ~vector() { delete[] container; }

  // Доступ к элементам
  // доступ к указанному элементу с проверкой границ
  reference at(size_type pos) {
    if (pos >= size_) {
      throw out_of_range("Index out of range");
    }
    return container[pos];
  }
  // Доступ к указанному элементу
  reference operator[](size_type pos) {
    size_type less_zero = 0;
    if (this->size_ < pos || less_zero > pos) {
      throw out_of_range("Index out of range");
    }
    return container[pos];
  }
  // доступ к первому элементу
  const_reference front() {
    if (this->size_ == 0) {
      throw out_of_range("Out of range");
    }
    return *container;
  }
  // доступ у последнему элементу
  const_reference back() {
    if (this->size_ == 0) {
      throw out_of_range("Out of range");
    }
    return *(container + size_ - 1);
  }
  // прямой доступ к базовому массиву
  pointer data() { return container; }

  // возвращает итератор в начало
  iterator begin() const {
    if (this->size_ < 1) {
      throw std::out_of_range("Контейнер пуст.");
    }
    return container;
  }
  // возвращает итератор до конца
  iterator end() const {
    if (this->size_ < 1) {
      throw std::out_of_range("Контейнер пуст.");
    }
    return container + size_;
  }

  // публичные методы для доступа к информации
  // Проверяет пуст ли контейнер
  bool empty() const {
    return size_ == 0;  // если пустой 0 если не пустой то 1
  }
  // возвращает количество элементов
  size_type size() const { return size_; }
  // возвращает максимально возможное количество элементов
  size_type max_size() const {
    char bits =
        63;  // Определение переменной bits и установка ее значения по умолчанию
    //в 63 (размер void* на большинстве 64-битных систем).
    if (sizeof(void *) == 4) {  // Проверка размера указателя void*.
      // Если размер void* равен 4 байтам, устанавливаем bits в 31.
      bits = 31;
    }
    // Вычисление и возвращение максимального размера вектора, основанного на
    // размере элемента и значения bits.
    return static_cast<size_type>(pow(2, bits)) / sizeof(value_type) - 1;
  }
  // выделяет хранилище элементов размера и копирует текущие элементы массива
  // в вновь выделенный массив
  void reserve(size_type size) {
    size_type less_zero = 0;
    if (less_zero > size) {
      throw out_of_range("Out of range");
    } else {
      // Выделение нового хранилища
      value_type *new_container = new value_type[size];
      // Копирование текущих элементов в новый массив
      for (size_type i = 0; i < size_; ++i) {
        new_container[i] = container[i];
      }
      // Освобождение старого хранилища
      delete[] container;
      // Обновление указателя на хранилище и емкости
      container = new_container;
      capacity_ = size;
    }
  }
  // возвращает количество элементов, которые могут храниться в
  // выделенном на данный момент хранилище
  size_type capacity() const { return capacity_; }
  // уменьшает использование памяти за счет освобождения неиспользуемой памяти
  void shrink_to_fit() {
    if (capacity_ > size_) {
      value_type *new_data = new value_type[size_];
      copy(container, container + size_, new_data);
      delete[] container;
      container = new_data;
      capacity_ = size_;
    }
  }

  // публичные методы для изменения контейнера
  // очищает содержимое
  void clear() noexcept { size_ = 0; }
  // вставляет элементы в конкретную позицию и возвращает итератор, указывающий
  // на новый элемент
  iterator insert(iterator pos, const_reference value) {
    size_type index = pos - container;
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }
    for (size_type i = size_; i > index; --i) {
      container[i] = container[i - 1];
    }
    container[index] = value;
    ++size_;
    return container + index;
  }
  // стирает элемент в позиции
  void erase(iterator pos) {
    size_type index = pos - container;
    for (size_type i = index; i < size_ - 1; ++i) {
      container[i] = container[i + 1];
    }
    --size_;
  }
  // добавляет элемент в конец
  void push_back(const_reference value) {
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }
    container[size_] = value;
    size_++;
  }
  // удаляет последний элемент
  void pop_back() { --size_; }
  // меняет содержимое
  void swap(vector &other) {
    std::swap(container, other.container);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_SRC_S21_CONTAINERS_H_