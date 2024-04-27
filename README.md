C++ 98

## Automatic initialisation and descruction
Orthodox canonical class form (Coplien's form): 
```
class A {
   public:
      A ();                         // default constructor
      A (const A &obj);             // copy constructor
      ~A ();                        // destructor
      A &operator = (const A &obj); // copy assignment operator
};
```

### Constructor
* is a non-static member function of a class that is used to initialize objectss
* has no name
* cannot be called directly
* is invoked when initialization takes place
* is selected according to the rules of initialization
* **converting constructor** without explicit specifier 
* a constructor with a constexpr specifier make its type a LiteralType
* **default constructor** may be called without any argument
* **copy constructors** and **move constructors** take another object of the same type as the argument
* 1. initialization of direct bases, virtual bases, non-static data members 2. execution of the constructor body
* **member initializer (list)** = non-default initialization of the subobjects, must be specified for:
   + bases that cannot be default-initialized
   + non-static data members that cannot be initialized by default-initializatio
   + non-static data members that cannot be initialized by their default member initializer (members of reference and const-qualified types)
* `std::initializer_list<T>` provides access to an array of objects of type const T

## Inheritance
* super class = base class = parent class
* subclass = derived class = child class
* a constructor is not inherited
* a destructor is not inherited
* when a child class initilaies its instance, the constructors are called hierarchically, the destructors are called in the inverse order
* operator `=` is inherited, but hidden by the implicitely declared one

## Overloading
* different functions can have the same name provided they are distinguished by their parameter types 
* a child can have a function with the same name, this function becomes an independant funciton of the child
* to use the operator = of the Parent in the Child:
```
class Parent {
public:
  Parent& operator = (const Parent &obj) {
    return *this;
  }
};

class Child : public Parent {
public:
  Child& operator=(const Child &obj) {
    Parent::operator=(obj);
    return *this;
  }
}
```

## Incapsulation
* **incapsulated data** few parts of the program see them
* flexibility for changing

## Template
* allows functions and classes to operate with generic types  
* is parameterized by parameter(s) of three kinds:
   + type template parameters
   + non-type template parameters
   + template template parameters
* **function template** a parametric function definition, where a particular function instance is created by parameter value(s)
* **function definition** an instance of the template
* the compiler uses a function template to generate a function definition
* you could pass the address, instead of dereferenced value as a parameter
* **template specialization** defines a behaviour that is different from the standard template
* **class template** is not a class, it is a template used to create classes 
* is compile-time construct: a templated class / functon = before compiling replacing the template parameter with the actual one
* can be overloaded

## STL (Standard Template Library) (here: c++ 98 only)

### Standard containers 
* https://cplusplus.com/reference/stl/#:~:text=Standard%20Containers,the%20types%20supported%20as%20elements
* https://en.cppreference.com/w/cpp/container
* **container** класс, объекты которого хранят набор однотипных значений
* предоставляет средства доступа к своему содержимому
* эти средства доступа строятся на обобщении понятия “указатель на элемент массива”, iterator
* array : the only C’s built-in container 
* содержит
   + вложенный тип iterator (чтения-записи), begin(), end()
   + вложенный тип const_iterator (только чтения), cbegin(), cend()
   + функции-члены rbegin(), rend(), crbegin(), crend() для контейнеров с двунаправленными итераторами 
*  **allocator** класс для управления динамической памятью
   + allocate() для выделения памяти под заданное количество элементов
   + deallocate() 
   + construct() для вызова конструктора
   + destroy() для вызова деструктора
   + rebind() метафункция, позволяющая получить аналогичный аллокатор для элементов другого типа
* перегрузки операций << и >> помещены в пространство имён std из-за особенностей связывания имён в C++
* **sequence container = class template**
   + an object
   + stores a collection of other objects
   + manages the storage space
   + provides member functions to access its elements, either directly or through iterators
   + **value semantics** when you push an element into the queue, a copy is created, when you remove an object from the queue, that object is destroyed
   + `array` c++ 11
* **associative containers**
   + элементы всегда автоматически (без участия программиста) отсортированы
   + например, **хэш-таблица** неупорядоченный ассоциативный контейнер, используют два функтора: компаратор, задающий отношение “равно”, и хэш, задающий способ вычисления хэш-функции для элементов контейнера, возвращающий целое число
* **container adaptor**
   + is not a full container class
   + takes an existing STL container and express the essential features of the underlying container type
   + provides a restricted interface relying on an object of one of the class template, to make them behave differently
   + the underlying containers are mostly vector, list, deque
   + the underlying container's elements are accessed by the members of the container adaptor
   + **value semantics** when you push an element into the queue, a copy is created, when you remove an object from the queue, that object is destroyed
* two class templates share certain properties with containers, and are sometimes classified with them: bitset and valarray`

collection             |operations                                                                                                                     |other
-----------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------
**class templates:**   |                                                                                                                                                                        |
vector                 |[ ] at front back data size max_size capacity empty assign push_back pop_back insert erase swap clear emplace emplace_back resize reserve shrink_to_fit relational swap |≈ array, the size changes dynamically, dosn't reallocate each time, access O(1),  add last O(1)
deque                  |[ ] at front back assign push_back push_front pop_back pop_front insert erase swap clear emplace emplace_front emplace_back                                             |access O(1), add 1st / last O(1), no garantee contiguous storage, efficient with long sequences where reallocations is expensive
(linked) list          |front back assign emplace_front push_front pop_front emplace_back push_back pop_back emplace insert erase swap resize clear remove remove_if                            |splice unique merge sort reverse
**associative containers:**|                                                                                                                                                                     |
set (tree)             | key_comp value_comp find count lower_bound upper_bound equal_range insert erase swap clear emplace emplace_hint                                                        |unique elements following a specific order, the value = the key, each value is unique, elt cannot be modified, elt can be inserted/removed, internally the elements are sorted, implemented as binary search tree
map                    |[ ]* at* key_comp value_comp find count lower_bound* upper_bound* equal_range insert* erase swap clear emplace emplace_hint                                             |internally the elts are always sorted by keys, implemented as a binary search tree 
multiset               |       key_comp value_comp find count lower_bound upper_bound equal_range insert erase swap clear emplace emplace_hint                                                  |multiple elements can have equivalent values
multimap               |                                                                                                                                                                        |
**container adaptors:**|                                                                                                                                                                        |
stack                  | top push emplace pop swap                                                                                                                                              |not iterable, its underlying container is deque
queue                  | front back push emplace pop swap                                                                                                                                       | 
priority_queue (heap)  | top (the largest element O(1)) push emplace pop swap                                                                                                                   |add / remove O(ln n) 

\* upper bound return first element which is > value; if not, return end()  
\* lower bound return first element which is ≥ value; if not, return end()  
\* the only difference between `map.at('a')` and `map['a']`: `at` throws an exception the key is not present in the map, `[ ]` inserts such a key
\* `map.insert(pos, v)` optimizes the insertion time if pos points to the element that precedes the inserted element, `pos` is just a hint, does not force the new elt to be inserted at that position


### Iterator
* an object pointing to some element in a range of elements
* can iterate through these elements
* points at the memory addresses of STL containers
* ex: a pointer points to elements, can iterate through them using ++
* not all iterators have the same functionality of pointer
* std::iterator<Category, T, Distance = ptrdiff_t, Pointer = T*, Reference = T&> its base class
* the same interface for different standard containers:
    + `advance(it, n)`   advance iterator  сдвигает итератор it (принимает по ссылке) на заданное число шагов n (сдвиг назад при отрицательных значениях n определен для двунаправленных итераторов)  
    + `distance`  distance between iterators  
    + `begin`	   iterator to beginning  
    + `end`	      iterator to end, never refers to a valid element => we can't dereference end()
    + rbegin()    представить последовательность значений как диапазон перебираемый в обратном порядке
    + rend()      представить последовательность значений как диапазон перебираемый в обратном порядке
    + `prev(it)` `prev(it, n)`	   get iterator to previous element  
    + `next(it)` `next(it, n)`	   get iterator to next element, возвращают сдвинутый итератор
    + `back_inserter`	construct back insert iterator  
    + `front_inserter`	constructs front insert iterator  
    + `inserter`	            construct insert iterator  
    + `make_move_iterator`    construct move iterator  
* not for container adaptors
* `&*it` converts an iterator to a pointer
* `vector<int>::iterator it(...)` converts a pointer-to-int rvalue to `vector<int>::iterator`
* comparing iterators from two different containers leads to undefined behavior
* как правило, итератор нельзя использовать для модификации структуры контейнера без вызова функций самого контейнера
* the nature of an iterator
    + Input:	      scans forward (++) only once, reads
    + Output:	      scans forward only once, writes
    + Forward:	      scans forward multiple times, reads, writes
    + Bidirectional: scans back and forth multiple times (++ and --), reads, writes
    + Random Access: scans back and forth multiple times, access the container also non-sequentially ([ ]), reads, writes
    + Contiguous:	   scans back and forth multiple times, access the container also non-sequentially, logically adjacent elements are also physically adjacent in memory, reads, writes
* Классы итераторы-адаптеры:
    + reverse_iterator<Iterator> оборачивает объект двунаправленного итератора, обращая порядок обхода последовательности
    + move_iterator<Iterator> является обёрткой, подменяющей копирующее присваивание перемещением
    + back_insert_iterator<Container>, front_insert_iterator<Container>, insert_iterator<Container> итераторо вывода, реализующий операцию записи через вызов функции-члена push_back, указатель на который хранится в объекте итератора
    + istream_iterator<T, CharT = char, Traits = char_traits<CharT>, Dist = ptrdiff_t> итератор ввода, предназначенный для чтения из basic_istream<CharT, Traits> (в частности istream)
    + ostream_iterator<T, CharT = char, Traits = char_traits <CharT>> итератор вывода, предназначенный для записи в объект basic_ostream<CharT, Traits> (в частности, ostream)
* an iterator must be constructible, copy-constructible, copy-assignable, destructible, swappable
* пара итераторов задаёт **range** — последовательность значений (контейнер / часть контейнера / массив / файл / генерируется на ходу), которую можно перечислить, передвигая итератор
* range (c++ 11)
```
for (const unsigned int& i : s)
  std::cout << i << "  ";
```
* Класс характеристик iterator_traits<T>
    + value_type
    + reference тип ссылки, возвращаемой при разыменовании итератора
    + pointer тип указателя, возвращаемого при обращении к объекту итератора через operator->
    + difference_type значения смещений итераторов относительно друг друга
    + iterator_category тип, указывающий на набор поддерживаемых операций (random_access_iterator_tag, bidirectional_iterator_tag, forward_iterator_tag, input_iterator_tag, output_iterator_tag)

### `<algorithm>` header 
* https://en.cppreference.com/w/cpp/header/algorithm 
* there are algorithms in other headers also, for example `adjacent_difference` in `<numercic>` (https://en.cppreference.com/w/cpp/algorithm)
* **algorithm** = a function for searching, sorting, counting, manipulating, ... that operate on ranges of elements
* **functor** = **function object**
   + is a struct
   + has a call operator that does anything you want
   + is a class, объекты которого можно использовать как функции
   + технически это оформляется с помощью перегрузки operator()
   + operator() допускает перегрузку с произвольной сигнатурой => объекты функтора могут имитировать произвольные функции
   + Ex: обычные функции, передаваемые по указателю
   + Ex: **генератор**, не принимает аргументов, возвращает некоторую генерируемую последовательность значений, например генератор псевдослучайных чисел
   + Ex: **предикат**, возвращает булевское значение
      - используется, например, при фильтрации последовательностей
      - обычно являются одноместны (унарными)
      - **компаратор** двуместный (бинарные) предикаты, принимающие два параметра и отвечающие некоторому отношению между ними
   + задавать произвольные операции с помощью функторов
* **a range** = [first, last)  
* a **sorted with respect to a comparator `comp` sequence**: for every iterator `iter` pointing to the sequence and every non-negative integer n such that `iter + n` is a valid iterator pointing to an element of the sequence, `comp(*(iter + n), *iter) == false`
  
**Non-modifying sequence operations**  | .
---------------------------------------|---
for_each                               |applies a function to a range of elements
find, find_if, find_first_of, find_end, adjacent_find |
count, count_if                        |
mismatch                               |the first position where two ranges differ
equal                                  |if two sets of elements are the same
search, search_n                       |
**Modifying sequence operations**:     |
copy, copy_backward, uninitialized_copy|copies a range of elements to a new location
fill, fill_n, uninitialized_fill, uninitialized_fill_n|copy-assigns the given value to every element (N elements) in a range
replace, replace_if, replace_copy, replace_copy_if|copies a range, replacing elements satisfying specific criteria 
remove, remove_if, remove_copy, remove_copy_if|removes elements satisfying specific criteria
unique, unique_copy                    |removes consecutive duplicate elementse, creates a copy of a range that contains no consecutive duplicates
reverse, reverse_copy                  |reverses the order of elements in a range, creates a copy of a range that is reversed
rotate, rotate_copy                    |rotates the order of elements in a rangecopies and rotate a range of elements
swap, swap_ranges, iter_swap           |swaps two ranges / the elements pointed to by two iterators
transform                              |applies a func to a range of elements, storing results in a destination range; 1) an unary operation can be applied to the source range, on a per element basis, which ouputs the results in the destination range 2) a binary operation can be applied to both elements in the source and destination range, subsequently overwriting elements in the destination range; не гарантирует определенный порядок обработки
generate, generate_n                   |assigns the results of successive function calls to every element
**Sorting and related operations**:    | 
partition, stable_partition            |divides a range of elements into two groups (while preserving their relative order)
sort, stable_sort, partial_sort, partial_sort_copy, nth_element|
lower_bound, upper_bound               |an iterator to the first element not less than the given value
equal_range                            |range of elements matching a specific key
binary_search                          |if an element exists in a partially-ordered range
includes                               |if one sequence is a subsequence of another
set_union, set_intersection, set_difference, set_symmetric_difference |union, intersection, difference, the symmetric difference between two sets
merge, inplace_merge                   |merges two ordered ranges
push_heap, pop_heap                    |adds an element to a max heap, removes the largest element from a max heap
make_heap                              |creates a max heap out of a range of elements
sort_heap                              |turns a max heap into a range of elements sorted in ascending order
max, min, nax_element, min_element     |the greater of the given values, the largest element in a range
lexicographical_compare                |true if one range is lexicographically less than another
next_permutation, prev_permutation     |generates the next greater lexicographic permutation of a range of elements
accumulate                             |sums up or folds a range of elements
inner_product                          |the inner product of two ranges of element
partial_sum                            |the partial sum of a range of elements

### Functions STL
...

## Types
* **tag identifiers** for struct/union/enum 
* **ordinary identifiers** for typedef and other identifiers
* all struct/union/enum/class declarations act like they are implicitly typedef'ed
* a structure can notbe anonymous
* a union can be anonymous
* the only difference between a class and a struct:
  + a class: members and base classes are private by default 
  + a structure: members and base classes are public by default

### Structures, typedef
```
struct strName x;                        // ok
```
 
```
struct strName { ... };                  // strName (in the tag namespace) 
typedef struct strName typeName;         // and typeName (in the ordinary identifier namespace) both refer to the same thing
typeName x;                              // declare objects of type typeName
```

```
typedef struct strName { ... } typeName; // just an abbreviation
```

```
typedef struct { ... } typeName;         // declare an anonymous structure (the structure doesn't have a name in the tag namespace)
                                         // the structure has a name in the typedef namespace
                                         // create a typedef for it
                                         // it cannot be forward-declared
```

```
struct strName { ... };                  // a compiler error (because strName is only defined in the tag namespace)
strName x;
```

You can add a constructor to Height:
```
struct Height {
    Height(int f, int i) : feet(f), inches(i) { }
    int feet, inches;
};
```
This allows you to use:
```Person p("John Doe", 42, "Blonde", "Blue", Height(5, 7));```

### `std::string` 
* = `basic_string<char>`
* ≈ an array of char
* ≈ vector<char>
* initialized dinamically, not statically
* != text literal  

### `uintptr_t` data type (c, c++) 
* `unsigned int`
* stores a data pointer
* `void*` can be converted to `uintptr_t`, then back to `void*`, the result will compare equal to the original pointer
* typically is the same size as a pointer (may be larger or smaller, for ex on a hypothetical platform where `void*` is 32 bits, but only 24 bits of virtual address space are used, you could have a 24-bit `uintptr_t`)
* utilility: integer-specific operations on a pointer, to do something unusual with a pointer, for ex to invert all bits, you cast a pointer to `uintptr_t`, manipulate it as an int, then cast back

### `intptr_t` data type (c, c++)
...

### `m_data`

## Convertions, casts (c++ 98)
https://en.cppreference.com/w/cpp/language  

|                 | `char`               | `char*`                                                        | `std::string`                             | `int`                | `float`              | `double`
|-----------------|----------------------|----------------------------------------------------------------|-------------------------------------------|----------------------|----------------------|---------
| to `char*`      | ---                  | ---                                                            | c_str()  sscanf  stringstream             | itoa                 |                      |
| to `std::string`| sprintf  stringstream| =  string_constructor  stringstream  s.data()*  std::to_string*| ---                                       | sprintf  stringstream| sprintf  stringstream| sprintf  stringstream  ecvt  fevt gevt
| to `int`        |                      |                                                                | atoi  stringstream  sscanf  stoi*         | ---                  |                      |
| to `unsigned int`|                     |                                                                | strtoul stoul*                            | ---                  |                      |
| to `float`      |                      |                                                                | atof  strtof  stringstream  sscanf  stof* | implicit             | ---                  | implicit
| to `double`     |                      |                                                                | strtod  stringstream  sscanf  stod*       | implicit             | implicit             | ---
  
* С-style cast: `(int)x`, `int(x)` etc
    + casts off  `const` и `volatile`
    + int -> ptr
    + ptr -> int
    + Child* -> Parent*
    + Parent* -> Child*
    + casts pointers as reinterpret_cast
    + tries in turn:
        - const_cast
        - static_cast
        - static_cast, then const_cast
        - reinterpret_cast
        - reinterpret_cast, then const_cast
   + is not verified by the compiler => error possible, for ex, while convertign of const types or while changing the type of the data without checking the possible range of the types
   + should be avoided
* `const_cast<target-type ﻿>(expr) ﻿`
    + the simpliest cast
    + usage: to remove or add `const` or `volatile` (no other C++ cast is capable of removing it)
* `static_cast<target-type ﻿>(expr ﻿)` (06/ex00)		
    + usage: ordinary type conversions
    + ≈ implicit type conversions 
    + compile-time
    + explicitly performs involving lvalue-to-rvalue, array-to-pointer, function-to-pointer conversion 
    + can call explicit or implicit conversion functions
    + Parent      -> Child&
    + Parent*     -> Child*
    + Child*      -> Parent*
    + expr        -> void : discards the value of expression after evaluating it
    + ptr         -> void*
    + void*       -> ptr (any object type)
    + int         -> enumeration
    + enumeration -> enumeration
    + float       -> enumeration
    + void*       -> *T -> void\* -> the original value
* `dynamic_cast<target-type ﻿>(expr) ﻿`
    + usage: cast within an inheritance hierarchy, cast sideways or even up another chain, seeks out the desired object and returns it if possible
    + usage: to handle polymorphism
    + usage: to find the type of object
    + Parent should have a virtual function (in any case Parent always has a virtual destructor)
    + ptr / ref                       -> ptr / ref within an inheritance hierarchy
    + ptr / ref to a polymorphic type -> ptr / ref to any type
    + Parent                          -> Child*
    + Parent&                         -> Child& `Parent &p; try { Child &m = dynamic_cast<Child&>(p); } catch (bad_cast) { }` (safe downcast)
* `reinterpret_cast<target-type ﻿>(expr ﻿)`
    + usage: weird conversions, bit manipulations (like turning a raw data stream into actual data, or storing data in the low bits of a pointer to aligned data)
    + prt / ref                       -> prt / ref
    + prt / ref                       -> int
    + int                             -> prt / ref 
    + can't cas a value to a value
    + turns one type directly into another
    + cast the result back -> the original value
* `std::bit_cast` (c++20)
* `literal_cast`
* stringstream
  converts `INT_MAX + 1` to `INT_MIN`
```
template <typename T> T fromStr(const std::string& s) {
  std::istringstream iss(s);
  T v;
  iss >> v;
  return v;
}
template <typename T> std::string toStr(T v) {
  std::ostringstream oss;
  oss << v;
  return oss.str();
}
int i = fromStr<int>(toStr(5));
```
* stoi (c++ 11)
* stoul (c++ 11)  
* s.data() (c++11)  
* std::to_string (c++11)  
* stod (c++11) 

### Implicit conversion sequence 
* to convert an argument in a function call to the type of the corresponding parameter in a function declaration

#### Standard conversion sequences
1) Exact match includes the conversions:
    + identity conversions
    + lvalue-to-rvalue conversions
    + array-to-pointer conversions
    + qualification conversions
2) Promotion
    + integral and floating point promotions
3) Conversion includes the conversions:
    + int and float conversions
    + float-int conversions
    + pointer conversions
    + pointer-to-member conversions
    + boolean conversions

#### User-defined conversion sequences
Consists of :
* a standard conversion sequence
* a user-defined conversion
* a second standard conversion sequence

#### Ellipsis conversion sequences
Occurs when the compiler matches an argument in a function call with a corresponding ellipsis parameter

##  Value (c, c++)
* is the representation of some entity that can be manipulated by a program  
* this terminology is used to categorize expressions (and not values)  

**R-value**: 
* r = right side of the assignment operator
* content
* refers to an object that persists beyond a single expression
* can be l-values or non-l-values
* Ex: the programm is executing, it sees the expression 4 + 9 and generates 13 value, but there is no indications there to strore 13 => 13 is not l-value
  
**L-value**:
* l = left side of the assignment operator
* something that could be assigned to
* a variable or a de-referenced reference
* location
* a temporary value that does not persist beyond the expression that uses it    
* has storage addresses that are programmatically accessible to the running program (for ex, using &)
* Ex: the cariable x is declared and attributed the value 13
   
## Reference vs pointer
* `HumanA`: a reference or a pointer to the Weapon, and a reference is better since the Weapon exists from creation and never changes
* `HumanB`: a pointer to a Weapon, since the field is not set at creation time and the weapon can be NULL
* in the both cases, we can change the type of the weapon  

Reference:  
* is a dereferenced pointer
* объект, указывающий на данные, но не хранящий их = другое имя для объекта
* доступны операции копирования и разыменования (разыменование = получение объекта по ссылке)
* is an aliase for an existing variable !=  new variable  
* is a constant pointer, always points to the same variable, we can't change it (?)  
* doesn't occupy memory  
* can't point to nothing  
* if something should always exist and never change, use a references  
```
   std::string &sREF = s;
//             &sREF       the variable of the type 'reference to string'
//                     s   the variable the reference is declared to
```
  
Pointer:  
* can point to a non-existing address  
* if something should not always exist and can change, use a pointer
* указатель = целое число
* доступны операции с целыми числами

## File manipulations
C file manipulations:  
* FILE *fp  
* fopen, fclose, fwrite, fread, ftell, fseek, fprintf, fscanf, feof, fileno, fgets, fputs, fgetc, fputc  
* modes : r, w, a  
* `int my_int = 32; printf("%s", my_int)` fails  
* hard-coded maximum buffer sizes  

C++ file manipulations:  
* fstream f  
* f.open, f.close, f>>, f<<, f.seekg, f.seekp, f.tellg, f.tellp, f.read, f.write, f.eof  
* modes : ios::in, ios::out, ios::bin , ...  
* Fstream closes the files when they leave scope  
* how input and output type is defined by the variable type  
* dynamically sizing receiving strings based on the actual input  
* extensibility for user-defined types (you can teach streams how to handle your own classes)  
* exceptions  

## Namespace
* Anonymous namespaces make private things really private

## Resolution
* **lexical resolution** = **early binding** can be determined at compile time  
* **dynamic resolution** = **late binding** can be determined at run time

## Exceptions
* runtime_error общий тип исключений в процессе выполнения
• range_error полученный результат превосходит определенный допустимый диапазон
• overflow_error полученный результат превышает допустимый диапазон
• underflow_error полученный по итогу вычислений результат имеет недопустимые отрицательные значения
• logic_error логическая ошибка в программном коде
• domain_error когда для какого-нибудь значения, которое передается в функцию, результат не определен
• invalid_argument в процессе передаче некорректного аргумента в функцию
• length_error в случае попытки создать объект большего размера, чем это допустимо для данного типа
• out_of_range при попытке доступа к элементам, которые отсутствуют в допустимом диапазоне

## System call (c, c++)
* call to the kernel
* != call to a system library
* processus management: load, execute, exit, abort, fork, processus terminating, get/set process attributes, wait, signal, allocate, free
* file management: create, delete, open, close, read, write, reposition, get/set file attributes
* devicaes management: request device, release device, read, write, reposition, get/set device attributes, logically attach or detach devices
* information management: get/set time or date, get/set system data, get/set process, file, device attributes
* communications: create, delete communication connection, send, receive messages, transfer status information, attach or detach remote devices

## Pipe
* однонаправленный канал между процессами, который позволяет одному процессу пересылать данные другому, без необходимости создавать файлы на диске
* когда пайп рвется, процесс, который пытается туда писать получает SIGPIPE
* Наиболее простой вариант пайпа создает шелл Unix, между программами, запускаемыми из командной строки, разделенными символом «|»
  + `dmesg | less` создает пайп от программы dmesg к программе постраничного просмотра less
    - если less завершится, прежде чем получит весь вывод dmesg, dmesg будет преждевременно завершена сигналом SIGPIPE

## Socket
* сетевое соединение
* программа, работающая с сокетом, может получить SIGPIPE
### blocking sockets
* the command blocks until data arrives
* обслуживание каждого соединения в отдельном потоке 
* просто для программирования
* при современных нагрузках порождать поток на каждое соединение неприемлемо (расходы ОС на их переключение)
### non-blocking sockets
* программа не лишается управления при временной невозможности выполнить операцию (не пришли данные в случае recv(), нет места в буфере отправки в случае send() и прочее)
* программа лишь информируется об этом с помощью кода ошибки EWOULDBLOCK или EAGAIN
* if data is not available, the command returns EWOULDBLOCK
* постоянно вызывать потенциально блокирующую функцию, пока результат EWSAWOULDBLOCK, неэффективно 
* позвонялет либо принимать данные из сокета, либо отправлять их
  + приемлемо только если клиент и сервер обмениваются запросами в строгой очередности
* non-blocking send():
  + flag MSG_DONTWAIT
* non-blocking recv():
  + flag MSG_DONTWAIT
  + `int opt = 1; setsockopt(cs, SOL_SOCK, SO_NOSIGPIPE, (void *)&opt, sizeof(int))` = the socket doesn't generate SIGPIPE (not portable)
* fcntl, flag O_NONBLOCK 
* функция мультиплексор poll / select
  + блокирует выполнение программы, пока хотя бы один из набора сокетов не будет готов к работе
  + для сокетов, готовых к работе, соответствующая функция (например recv()) вызывается, пока не завершится с ошибкой WSAEWOULDBLOCK
  + let detect if the pipe is broken, even if you don't actually have to read or write to it
* неблокирующий режим для клиентов  обычно менее актуален
### three non-blocking I/O strategies
All require that the socket be set non-blocking
* call poll before you perform an I/O operation. You then attempt a single read or write operation only if you get a read or write hit from poll or select.
* attempt the read or write operation first. If it succeeds immediately, great. If not, wait for a poll hit before retrying the operation.
  + this method is the most common for writes
* call poll before you perform an I/O operation. You then attempt multiple reads or writes until you either finish everything you need to do or get a "would block" indication. When you get a "would block" indication, you wait until  poll tells you before you attempt another operation in that direction on that socket.
  + this method is the most common for reads
### The usual pattern is to use non-blocking file descriptors with poll() 
When getting ready to poll(),  
Always set POLLIN because you are always interested in reading what the other end of the socket has send you.  
Except if you have a large backlog of incoming data and you intentionally want to make the other end wait before sending more.  
Set POLLOUT only if you have outstanding data to send to the other end.  
Upon return from poll(), if it indicates that data is available to read,  
read it and do something with it  
Upon return from poll(), if it indicates that the socket is writable,  
Try sending your outstanding data.  
If you managed to write all of it, you're not going to set POLLOUT next time through the loop  
If you only managed to send some of it (or none of it) then keep the rest for later. You will set POLLOUT the next time through the loop.  
When you have new data to send (either in response to data you read or in response to some external event), you have two choices:  
Eagerly try to send some of it right away. You may successfully send none, some, or all of it. Just like with the previous case, keep the portion of the data that wasn't written for next time and plan to set POLLOUT the next time through the loop only if there was some data left.
Just keep a hold on the data and plan to set POLLOUT the next time through the loop. (This choice is often easier to program because you only need to handle writing data in one place in your loop but on the other hand it delays writing the data until the next time through the loop.)

### prevent SIGPIPE
  + writing to non-responding socket will cause a SIGPIPE and make my server crash
  + `signal(SIGPIPE, SIG_IGN)` = all the sockets don't generate SIGPIPE
  + `sigprocmask(SIG_BLOCK, NULL, &old_state)`
  + send, flag MSG_NOSIGNAL: не посылать SIGPIPE, если другая сторона обрывает соединение, turns the SIGPIPE behavior off on a per call basis (not portable), `send(...MSG_NOSIGNAL)` = write() without SIGPIPE
    - discord: * Add **MSG_NOSIGNAL** as a 4th argument for send, it will prevent your programm from crashing under certain condition,  Genre le client il fait legit connect();send();exit() ducoup il est plus rapide que toi. Et tu te tape des signal sigpipe
  + recv, flag MSG_NOSIGNAL: This  flag  turns  off raising of SIGPIPE on stream sockets when the other end disappears
  + just catching and ignoring the signal in a handler is not a good idea, you must note that the pipe is now defunct and modify the program's behaviour so it does not write to the pipe again 

## Signals 
* асинхронное уведомление процесса о каком-либо событии
* один из основных способов взаимодействия между процессами
* когда сигнал послан процессу, операционная система прерывает выполнение процесса
  + если процесс установил собственный обработчик сигнала, операционная система запускает этот обработчик, передав ему информацию о сигнале
  + если процесс не установил обработчик, то выполняется обработчик по умолчанию
* Сигналы посылаются:
  + из терминала, нажатием специальных Ctrl-C, Ctrl-\ SIGQUIT, Ctrl-Z, ...
  + ядром системы:
    - при возникновении аппаратных исключений (недопустимых инструкций, нарушениях при обращении в память, системных сбоях и т. п.);
    - ошибочных системных вызовах;
    - для информирования о событиях ввода-вывода;
  + одним процессом другому (или самому себе), с помощью системного вызова kill()
    - в том числе из shell, утилитой /bin/kill
* сигналы не могут быть посланы завершившемуся процессу, находящемуся в состоянии «зомби»
* для альтернативной обработки сигналов (за исключением SIGKILL и SIGSTOP), процесс может назначить свой обработчик или игнорировать их 
  + процесс с pid 1 (init) имеет право игнорировать или обрабатывать также KILL и STOP
  + the only thing you can do in a signal handler is modify a variable or exit
  + function signal() is obsolete
* SIGPIPE
  + you get SIGPIPE when you **write** to a pipe where there is no process with the read end of the pipe open
  + you get EOF (zero bytes read) when you **read** from a pipe that has no process with the write end of the pipe open
  + when you ignore SIGPIPE
    - you no longer get a SIGPIPE signal, but write() gets a EPIPE error
    - you should monitor the return value from write(), if it comes back with -1 and errno set to EINTR, you can assume you got interrupted by some signal, and most probably a SIGPIPE, especially if you don't have any other signal handling set
    - PS you should look at the return value from write() and read() anyway
  + an explicit SIGPIPE handler:
    - you can write a loop in main(), and have the signal handler set a flag which you test in the loop
* SIGINT
  + для остановки процесса пользователем с терминала
  + посылается программе, выполняемой на терминале
  + Ctrl+C
* SIGQUIT 
  + для остановки и указывающий, что система должна выполнить дамп памяти для процесса
  + обычно Ctrl+\, в Linux также Ctrl+4, или SysRq на виртуальном терминале
* SIGTERM
  + для запроса завершения процесса
  + посылается процессу утилитой kill по умолчанию
  + в отличие от SIGKILL этот сигнал может быть обработан или проигнорирован программой
* Ctrl+D is a keyboard input that typically represents the EOF character
  + when entered at the beginning of a line in a terminal, it signals the end of input to the terminal
  + it's commonly used to indicate the end of input when reading from stdin
  + it doesn't raise a signal like SIGPIPE
  + it's processed by the terminal or the program reading from stdin
  + EOF processing (Control-D) is handled in canonical mode; it actually means 'make the accumulated input available to read()'
    - if there is no accumulated input (if you type Control-D at the beginning of a line), then the read() will return zero bytes, which is then interpreted as EOF by programs
    - you can type more characters on the keyboard after that

## Memory
* delete[ ] frees an array created with new[ ]
* malloc allocates more memory that the programmes asked, puts the size of the block in the beginning on the bloc  
+-----+--------------------------     ----+  
| 100 |                           ...     |  
+-----+--------------------------     ----+  
^  ^  ^  
|  |  the address retured by `malloc`  
|  the size   
the real beginning of the bloc  
* free() reads the size of the bloc and so knows how much memory it should free
* you need to balance new with delete, new[] with delete[], malloc with free
  + well-written C++ will contain almost none of those, since you leave the responsibiltiy for dynamic memo­ry and lifetime management to suitable container or manager classes, most notably `std::vector` and `std::unique_ptr`

## Errors 
* **undefined behavior** it could work, it could crash, it could do something else

## Regular expressions
* std::regex (c++ 11)
* under UNIX-like systems you can use POSIX regex functions
* https://regex101.com/

## Specifiers

### public / private / protected data
* public members are accessible from outside the class  
* private: members cannot be accessed or viewed from outside the class  
* protected: members cannot be accessed from outside the class, however, they can be accessed in inherited classes

### public / private / protected function
* see private / public / protected data modifiers

### public / private / ptotected inheritance
* public: public data are inherited as public, protected data are inherited as protected 
* private: all inherited data become private
* protected: all inherited data become protected
* par default: `class  Par {}; class Child:  /* private */ Parent {};`
* par default: `class  Par {}; struct Child: /* public */  Parent {};`
* par default: `struct Par {}; class Child:  /* public  */ Parent {};`

### final class
* inheritance is prohibited

### final function
* prohibites `virtual` functions in the inherited classes 

### static variable in a function
* is initialized one time, the memory is allocated one time, the variable stores its value between the function calls during all the time of the executoin of the programm
* is stored in the memory segments .data и .bss (not heap, not stack)
* is slower than a non-static variable (the programm goes to another memory segment, vérifies if the variable is initialized)
* to be careful while multithreading

### static member of a class  
* belongs to the class, is not associated with a particular object, is the same for all the class instances
* if we crate three instances of the class, the constructor is called only one time
* can not be nitialized by a constructor
* definition of an object: out of the class, by `::`-operator
* declaration of an object: `static A a;`
* is called using the class name or through an object

### static class
* usage: to group ressembling methods, proprieties and fields
* usage: to prevent writing instance members/methods
* ≈ a class with only static methods and members
* formally C++ does not have static classes (Java-like languages like C# have no non-member functions, so they have static classes)
* can't be instanciated
* can't be inherited
* should have constructors / destructors as a usual class ?
* In C++, the namespace is more powerful thamn static class, because:
    + static methods have access to the classes private symbols
    + private static methods are still visible (if inaccessible) to everyone, which breaches somewhat the encapsulation
    + static methods cannot be forward-declared
    + static methods cannot be overloaded by the class user without modifying the library header
    + there is nothing that can be done by a static method that can't be done better than a (possibly friend) non-member function in the same namespace
    + namespaces have their own semantics (can be combined, can be anonymous, ...)

### static not member function 
* can't be called from other places

### static member function
* is not associated with a particular object, belongs to the class rather than objects of the class  
* basically a normal function that's nested inside of the scope of the class
* can be called using the class name or through an object  
* can access only static variables and functions  
* doesn't have `*this`
* can beused without instantiating if the class
* ia accessed by the class nale ou by the :: operator
* can call ony static functions, members, extern functions
* has the same scope as its class 

Example:
```
class MyClass {
 public:
  static void f();
};

void MyClass::f() {} // do not write 'static'

int main() {
  MyClass::f();
}
```
### abstract class
* contains (or inherits without redefinition) at least one pure virtual (abstract) function
* all the abstract methods of the parent must be implemented in the child
* may provide implementations of some methods
* cannot be instantiated  
* another way to prevent a class from being instantiated: make all the constructors `protected`
* C++ has no keyword `abstract`

### abstract function = pure virtual
* C++ has no keyword `abstract`  

### interface = pure abstract class 
* consists of only virtual member functions (only declarations)
* non-instancable

### override function
* explicit indication that the function is redefined
* `override` keyword is a C++11 extension

### const / mutable data
const function modifies passed by value const data &#9746;    
~~const~~ function modifies passed by value const data &#9746;     
const function modifies passed by ref const data &#9746;   
~~const~~ function modifies passed by ref const data &#9746;    
const function modifies casted const away const data &#9745; but not advised     
~~const~~ function modifies casted const away const data &#9745; but not advised    
constructor modifies const data &#9745;  
destructor&nbsp;&nbsp;modifies const data &#9745;   
  
`const int                 с = 3` &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;change the value &#9746;  
`const int       *         с    `   change the pointer &#9745;, change the value &#9746;  
`       int const *         с     ` change the pointer &#9745;, change the value &#9746;  
`       int       * const   с     ` change the pointer &#9746;, change the value &#9745;    
`       int const * const   с     ` change the pointer &#9746;, change the value &#9746;   
  
`const std::string& s = "AB";` OK, the temporary object is alive as long as the const ref is alive  
`      std::string& s = "AB";` NON, the temporary object disappeares

* mutable: we can modify a mutable class member through member functions even if the containing object is const

### const / mutable member funciton
* const function doest't change the object, does not modify any of the members of that class
* const function calls only const member functions  
* we can't change the return value of a const function
* we can have a constant version and a non-constant version of the same function
* `const int Cl::func() const;` 1st const = the returend object is const, 2nd const = the functin is const
* mutable != const

const&nbsp;&nbsp;&nbsp;obj.const member function &#9745;  
const&nbsp;&nbsp;&nbsp;obj.~~const~~ member function &#9746;     
const *obj.~~const~~ member function &#9746;  
const &obj.~~const~~ member function &#9746;  

### const not member function
* doesn't exist

### volatile data

### virtual data

### virtual member function
* a member function of a Parent, redefined by a Child (**polymorphic functions**)
* must be defined in Parent
* cannot be static
* a pointer to the Parent's function calls the Parent's virtual function and executes its Child’s version 
* a constructor can not be virtual
* if a class has any virtual function, it should have a virtual destructor
* classes not designed to be base classes or not designed to be used polymorphically should not declare virtual destructors
* a destructor can be virtual, must be defined even if it is declared pure-virtual
* a destructor of a non-final class with virtual functions is virtual (?)
* virtual destructors are useful when you might potentially delete an instance of a derived class through a pointer to base class

3 scenarios:  
`class IPar { virtual void f() = 0 } class Chld: public IPar { void f() {} }`  **IPar** defines a functionality, Child defines the realisation  
`class Par  { virtual void f()     } class Chld: public Par  { void f() {} }`  Child **overrides** a virtual function   
`class Par  {         void f()     } class Chld: public Par  { void f() {} }`  Child **hides** a non-virtual function   

 vtable (virtual functions table) :  
* ≈ hidden static data member of the class  
* every object of a polymorphic class is associated with (possibly multiple) vtable for its most-derived class  
* stores pointers to virtual functions 
* when a virtual function is called, the program finds the associated function by vtable   
* if an object of type A does not point to the vtable of A, then that object is actually a sub-object of something derived from A

### virtual inheritance
* prevents a lot of Children of a Parent (?) 

### template class

### template function
* allows functions and classes to operate with generic types. This allows a function or class declaration to reference via a generic variable another different class (built-in or newly declared data type) without creating full declaration for each of these different classes.

### extern data
a global variable becomes accessible in any file of the programm

### auto
* useless keyword before c++ 11
* a deduced type (c++ 11)

### using namespaces, using namespace members

### using declaration for class members

### using enumerators (C++ 20)

### using type alias, using alias template declaration (C++ 11)

### auto (c++ 20)
In any of the parameters of a function declaration: that declaration becomes an abbreviated function template declaration

### typedef
synonyme

### friend functon
* are not member functions
* have acces to its private variables and functions

### inline (c++ 17)

### explicit

### incomplete type
* Ex: `class A;`
* a class until the end of its definition  
* no keyword `incomplet`, just terminologie
* one cannot create objects of it
* the compiler does not know what are its members and what its memory layout is
* you may reffering to an incomplete type as a pointer
* you can declare a member to be a pointer or a reference to the incomplete type
* you can declare functions or methods which accepts/return incomplete types
* you can define functions or methods which accepts/return pointers/references to the incomplete type (but without using its members)
* you can not use it as a base class
* you can not use it to declare a member
* you can not define functions or methods using this type

### polymorphic class
defines or inherits a virtual function 

## other
* `#pragma once` is only intended to be used in headers, don't compile headers

## c++ 11
* Lambda Expressions
* Automatic Type Deduction
* decltype
* Uniform Initialization Syntax
* Deleted and Defaulted Functions
* nullptr
* Rvalue References
* New Smart Pointer Classes (shared_ptr, unique_ptr)
* More C++ Algorithms

# Linens
http://www.cplusplus.com  
https://github.com/42YerevanProjects/cpp_modules  
https://github.com/Saxsori/CPP_Modules  
https://github.com/ifanzilka/CPP_Module  
https://github.com/pasqualerossi/C-Plus-Plus  
https://github.com/SavchenkoDV/cpp_School21_Ecole42  
https://github.com/achrafelkhnissi/CPP_Modules  
https://github.com/Akadil/42project_cpp  
