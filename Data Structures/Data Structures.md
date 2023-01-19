# C++ Data Structures

## Table of Contents

<!-- TOC depthFrom:1 depthTo:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [C++ Data Structures](#c-data-structures)
	- [Table of Contents](#table-of-contents)
	- [1.0 Data Structures](#10-data-structures)
		- [1 Overview](#11-overview)
		- [2 Vector `std::vector`](#12-vector-stdvector)
		- [3 Deque `std::deque`](#13-deque-stddeque)
		- [4 List `std::list` and `std::forward_list`](#14-list-stdlist-and-stdforward_list)
		- [5 Map `std::map` and `std::multimap` and `std::unordered_map`](#15-map-stdmap-and-stdmultimap-and-stdunordered_map)
		- [6 Set `std::set` and `std::multistd` and `std::unordered_set`](#16-set-stdset-and-stdmultistd-and-stdunordered_set)
		- [7 Stack `std::stack`](#17-stack-stdstack)
		- [8 Queue `std::queue`](#18-queue-stdqueue)
		- [9 Priority Queue `std::priority_queue`](#19-priority-queue-stdpriority_queue)
		- [10 Pair `std::pair`](#110-pair-stdpair)
<!-- /TOC -->


## 1.0 Data Structures
### 1.1 Overview

![ComplexityChart](General/Complexity%20Chart.png "Complexity Chart")

![DataStructureSelection](General/Data%20Structures%20Selection.png "Data Structures Selection")
-------------------------------------------------------
### 1.2 Vector `std::vector`

Vectors are sequence containers that have dynamic size. In other words, vectors are dynamic arrays. Just like arrays, vector elements are placed in contiguous storage location so they can be accessed and traversed using iterators. To traverse the vector we need the position of the first and last element in the vector which we can get through begin() and end() or we can use indexing from 0 to size().

**Use for**
* Simple storage
* Adding but not deleting
* Serialization
* Quick lookups by index
* Easy conversion to C-style arrays
* Efficient traversal (contiguous CPU caching)

**Do not use for**
* Insertion/deletion in the middle of the list
* Dynamically changing storage
* Non-integer indexing

**Time Complexity**

| Operation    | Time Complexity |             what do?!                                            |
|--------------|-----------------|------------------------------------------------------------------|
| at()         |          `O(1)` |Returns the reference to the element at a particular position (can also be done using ‘[ ]’ operator)|    
| back()       |          `O(1)` |Returns the reference to the last element. Its time complexity is |
| begin()      |          `O(1)` |Returns an iterator pointing to the first element of the vector   |                                        
| clear()  |          `O(N)` |Deletes all the elements from the vector and assign an empty vector                                                                  |
| empty() |          `O(1)` |Returns a boolean value, true if the vector is empty and false if the vector is not empty                                                                  | 
| end()  |          `O(1)` |Returns an iterator pointing to a position which is next to the last element of the vector                                                                  |
| erase()   |          `O(N + M) where N is the number of the elements erased and M is the number of the elements moved` | Deletes a single element or a range of elements                                                                  |
| front()  |          `O(1)` |Returns the reference to the first element                                                                  |
| insert() | `O(N + M) where N is the number of elements inserted and M is the number of the elements moved` |Inserts new elements into the vector at a particular position|
| pop_back() |`O(1)`|Removes the last element from the vector |
| push_back() |`O(1)`| Inserts a new element at the end of the vector|
|resize()|`O(N) where N is the size of the resized vector`|Resizes the vector to the new length which can be less than or greater than the current length|
|size()|`O(1)`|Returns the number of elements in the vector

**Initialization**
```c++
vector<int> a;                                       // empty vector of ints
vector<int> b (5, 10);                                // five ints with value 10
vector<int> c (b.begin(),b.end());                     // iterating through second
vector<int> d (c);                                   // copy of c
```

**Traverse**
```c++
void traverse(vector<int> v)
{
    vector <int>::iterator it;
    for(it = v.begin();it != v.end();++it)
        cout << *it <<  ‘ ‘;
    cout << endl;
    for(int i = 0;i < v.size();++i)
        cout << v[i] << ‘ ‘;
    cout << endl;
 }
```

**Example Code**
```c++
std::vector<int> v;

//---------------------------------
// General Operations
//---------------------------------

// Size
unsigned int size = v.size();

// Insert head, index, tail
v.insert(v.begin(), value);             // head
v.insert(v.begin() + index, value);     // index
v.push_back(value);                     // tail

// Access head, index, tail
int head = v.front();       // head
head = v[0];                // or using array style indexing

int value = v.at(index);    // index
value = v[index];           // or using array style indexing

int tail = v.back();        // tail
tail = v[v.size() - 1];     // or using array style indexing

// Iterate
for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
v.erase(v.begin());             // head
v.erase(v.begin() + index);     // index
v.pop_back();                   // tail

// Clear
v.clear();
```
**Implementation**
```c++
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v;
    vector <int>::iterator it;
    v.push_back(5);
    while(v.back() > 0)
        v.push_back(v.back() - 1);
    for(it = v.begin(); it != v.end();++it)
        cout << *it << ' ';
    cout << endl;
    for(int i = 0;i < v.size();++i)
        cout << v.at(i) << ' ';
    cout << endl;
    while(!v.empty())
    {
        cout << v.back() << ' ';
        v.pop_back();
    }
    cout << endl;
    return 0;
}
```
**Output**
```c++
5 4 3 2 1 0
5 4 3 2 1 0
0 1 2 3 4 5
```
-------------------------------------------------------
### 1.3 Deque `std::deque`

In C++, the STL deque is a sequential container that provides the functionality of a double-ended queue data structure.

In a regular queue, elements are added from the rear and removed from the front. However, in a deque, we can insert and remove elements from both the front and rear.

**Use for**
* Similar purpose of `std::vector`
* Basically `std::vector` with efficient `push_front` and `pop_front`

**Do not use for**
* C-style contiguous storage (not guaranteed)

**Notes**
* Pronounced 'deck'
* Stands for **D**ouble **E**nded **Que**ue

**Time Complexity**

| Operation    | Time Complexity |             what do?!                                            |
|--------------|-----------------|------------------------------------------------------------------|
| push_back()  |          `O(1)` 		|inserts element at the back|
| push_front() |          `O(1)`|inserts element at the front|
| pop_back()  |          `O(1)` 		|removes element from the back|
| pop_front()  |          `O(1)` 		|removes element from the front|
| front() |          `O(1)` 		|returns the element at the front|
| back()  |          `O(1)` 		|returns the element at the back|
| size()   |          `O(1)` 		|returns the number of elements|
| empty()  |          `O(1)` 		|returns true if the deque is empty|
|at()|`O(n)`|sets/returns the element at specified index|

**Iteration**
```c++
for(int i = 0 ; i < n ; ++i){
      scanf("%d", &x);
      dq.push_back(x);
}
for(int i = 0 ; i < n ; ++i)
    printf("%d ", dq[i]);
for(int x : dq)
    printf("%d ", x);
for(auto x = dq.begin() ; x!=dq.end() ; ++x)
    printf("%d ", *x);
```

**Example Code**
```c++
std::deque<int> d;

//---------------------------------
// General Operations
//---------------------------------

// Insert head, index, tail
d.push_front(value);                    // head
d.insert(d.begin() + index, value);     // index
d.push_back(value);                     // tail

// Access head, index, tail
int head = d.front();       // head
int value = d.at(index);    // index
int tail = d.back();        // tail

// Size
unsigned int size = d.size();

// Iterate
for(std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
d.pop_front();                  // head
d.erase(d.begin() + index);     // index
d.pop_back();                   // tail

// Clear
d.clear();
```
-------------------------------------------------------
### 1.4 List `std::list` and `std::forward_list`

List is a sequence container which takes constant time in inserting and removing elements. List in STL is implemented as Doubly Link List.
The elements from List cannot be directly accessed. For example to access element of a particular position ,you have to iterate from a known position to that particular position.

**Use for**
* Insertion into the middle/beginning of the list
* Efficient sorting (pointer swap vs. copying)

**Do not use for**
* Direct access

**Time Complexity**

| Operation    | Time Complexity |             what do?!                                            |
|--------------|-----------------|------------------------------------------------------------------|
| begin()  |          `O(1)` |It returns an iterator pointing to the first element in list|
| end() |          `O(1)` |It returns an iterator referring to the theoretical element(doesn’t point to an element) which follows the last element|
| empty()  |          `O(1)` |It returns whether the list is empty or not.It returns 1 if the list is empty otherwise returns 0|
| assign()  |          `O(n)` | It assigns new elements to the list by replacing its current elements and change its size accordingly|
| back() |          `O(1)` |It returns reference to the last element in the list|
| erase()  |          `O(n)` |It removes a single element or the range of element from the list|
| front()   |          `O(1)` |It returns reference to the first element in the list|
| push_back()  |          `O(1)` |It adds a new element at the end of the list, after its current last element|
|push_front()|`O(1)`|It adds a new element at the beginning of the list, before its current first element|
|remove()|`O(n)`|It removes all the elements from the list, which are equal to given element|
|pop_back()|`O(1)`|It removes the last element of the list, thus reducing its size by 1|
|pop_front()|`O(1)`|It removes the first element of the list, thus reducing its size by 1|
|insert()|`O(n)`|It insert new elements in the list before the element on the specified position|
|reverse ()|`O(n)`|It reverses the order of elements in the list|
|size()|`O(1)`| It returns the number of elements in the list|

**Implementation**
```c++
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list <int> LI;
    list <int>::iterator it;
    //inserts elements at end of list
    LI.push_back(4);
    LI.push_back(5);

    //inserts elements at beginning of list
    LI.push_front(3);
    LI.push_front(5);

    //returns reference to first element of list
    it = LI.begin();

    //inserts 1 before first element of list
    LI.insert(it,1);

    cout<<"All elements of List LI are: " <<endl;
    for(it = LI.begin();it!=LI.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //reverse elements of list
    LI.reverse();

    cout<<"All elements of List LI are after reversing: " <<endl;
    for(it = LI.begin();it!=LI.end();it++)
    {
         cout<<*it<<" ";
    }
    cout<<endl;

    //removes all occurences of 5 from list
    LI.remove(5);

    cout<<"Elements after removing all occurence of 5 from List"<<endl;
    for(it = LI.begin();it!=LI.end();it++)
    {
         cout<<*it<<" ";
    }
    cout<<endl;

    //removes last element from list
    LI.pop_back();
    //removes first element from list
    LI.pop_front();
    return 0;
}
```
**Output**
```c++
All elements of List LI are: 
1 5 3 4 5 
All elements of List LI are after reversing: 
5 4 3 5 1 
Elements after removing all occurrence of 5  from List
4 3 1
```
-------------------------------------------------------
### 1.5 Map `std::map` and `std::multimap` and `std::unordered_map`

Maps are containers which store elements by mapping their value against a particular key. It stores the combination of key value and mapped value following a specific order. Here key value are used to uniquely identify the elements mapped to it. The data type of key value and mapped value can be different. Elements in map are always in sorted order by their corresponding key and can be accessed directly by their key using bracket operator ([ ]).

|     cmp           |    Map             | Multimap|
|---------------|---------------------|------------------|
|1        | It stores unique key-value pair where each key is unique   | It can store duplicate key-value pair where keys may not be unique|
|2  | 	Using count() function on a map can only return two values which is either 0 or 1  | Using count() function on a multimap can return any non-negative integer |  
|3     | Accessing Value of any key is easy and directly accessible       | Accessing value of any key is not easy and is not directly accessible |
|4  | Deleting in a map using key will delete only one key-value pair  | Deleting in a multimap using key will delete all the key-value pair having same key|                      
|5   | Map can be used when a simple look up table having unique key-value pairs is required for quickly accessing to the value using the key  | Multimap can be used when grouping of values together using the keys are required|

*Multimap* is nothing different than a normal map except the fact that in a multimap mutiple values can have the same key.And other factors are just the same between a Map and a Multimap.

**Use for**
* Key-value pairs
* Constant lookups by key
* Searching if key/value exists
* Removing duplicates
* `std::map`
    * Ordered map
* `std::unordered_map`
    * Hash table

**Do not use for**
* Sorting

**Notes**
* Typically ordered maps (`std::map`) are slower than unordered maps (`std::unordered_map`)
* Maps are typically implemented as *binary search trees*

**Time Complexity**

**`std::map`**

| Operation    | Time Complexity |             what do?!                                            |
|--------------|-----------------|------------------------------------------------------------------|
| at( )              |     `O(log(n))` |Returns a reference to the mapped value of the element identified with key|
| count( )       |     `O(log(n))` |searches the map for the elements mapped by the given key and returns the number of matches.As map stores each element with unique key, then it will return 1 if match if found otherwise return 0|
| find( )       |     `O(log(n))` |Searches the map for the element with the given key, and returns an iterator to it, if it is present in the map otherwise it returns an iterator to the theoretical element which follows the last element of map|
| clear( )   |     `O(n)` |clears the map, by removing all the elements from the map and leaving it with its size 0|
|begin( )|`O(1)`|returns an iterator(explained above) referring to the first element of map|
|end( )|`O(1)`|returns an iterator referring to the theoretical element(doesn’t point to an element) which follows the last element|
|insert( )|`O(log(n)), when only element is inserted and O(1) when position is also given`|insert a single element or the range of element in the map|
|erase( )|`O(log(n))`|removes a single element or the range of element from the map|
|empty( )|`O(1)`|checks whether the map is empty or not. It doesn’t modify the map.It returns 1 if the map is empty otherwise returns 0|


**`std::unordered_map`**

| Operation    | Time Complexity |             what do?!                                            |
|--------------|-----------------|------------------------------------------------------------------|
| insert()|`Single element insertions:Average case: constant.Worst case: linear in container size.Multiple elements insertion:Average case: linear in the number of elements inserted.Worst case: N*(size+1): number of elements inserted times the container size plus one.` |insert one or more key-value pairs|
| count()|`Average case: linear in the number of elements counted.Worst case: linear in container size.`|returns 1 if key exists and 0 if not|
| find()|`Average case: constant.Worst case: linear in container size.` |returns the iterator to the element with the specified key|
| at()  | `Average case: constant.Worst case: linear in container size.` |returns the element at the specified key|
|size()|`O(1)`|returns the number of elements|
|empty()|`O(1)`|returns true if the unordered map is empty|
|erase()|`Average case: Linear in the number of elements removed (which is constant for versions (1) and (2)).Worst case: Linear in the container size.`|removes elements with specified key|
|clear()|`O(n)`|removes all elements|

**Initialize Map**
```c++
map <char ,int > mp;

mp[‘b’]  = 1;
```
**Initialize an Unordered Map**
```c++
unordered_map<string, int> unordered_map1 = {
  {"One", 1},
  {"Two", 2},
  {"Three", 3}
};
```
**Example Code**
```c++
std::map<std::string, std::string> m;

//---------------------------------
// General Operations
//---------------------------------

// Insert
m.insert(std::pair<std::string, std::string>("key", "value"));

// Access by key
std::string value = m.at("key");

// Size
unsigned int size = m.size();

// Iterate
for(std::map<std::string, std::string>::iterator it = m.begin(); it != m.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove by key
m.erase("key");

// Clear
m.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists by key
bool exists = (m.find("key") != m.end());

// Count the number of elements with a certain key
unsigned int count = m.count("key");
```
**Implementation**
```c++
#include <iostream>
#include <map>
using namespace std;
int main(){
    map <char,int> mp;
    map <char,int> mymap,mymap1;

    //insert elements individually in map with the combination of key value and value of element
    mp.insert(pair<char,int>('a',2));   //key is 'c' and 2 is value.
    mp.insert(pair<char,int>('b',1));
    mp.insert(pair<char,int>('c',43));

    //inserts elements in range using insert() function in map 'mymap'.
    mymap.insert(mp.begin(),mp.end());

    //declaring iterator for map
    map <char,int>::iterator it;

    //using find() function to return reference of element mapped by key 'b'.
    it = mp.find('b');

    //prints key and element's value.
    cout<<"Key and element's value of map are: ";
    cout<<it->first<<" and "<<it->second<<endl;

    //alternative way to insert elements by mapping with their keys.
    mymap1['x'] = 23;
    mymap1['y'] = 21;

    cout<<"Printing element mapped by key 'b' using at() function : "<<mp.at('b')<<endl;

    //swap contents of 2 maps namely mymap and mymap1.
    mymap.swap(mymap1);

    /* prints swapped elements of mymap and mymap1 by iterating all the elements through    
        using   iterator. */
    cout<<"Swapped elements and their keys of mymap are: "<<endl;
    for(it=mymap.begin();it!=mymap.end();it++)
    {
    cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"Swapped elements and their keys of mymap1 are: "<<endl;
    for(it=mymap1.begin();it!=mymap1.end();it++)
    {
    cout<<it->first<<" "<<it->second<<endl;
    }
    //erases element mapped at 'c'.
    mymap1.erase('c');

    //prints all elements of mymap after erasing element at 'c'.

    cout<<"Elements of mymap1 after erasing element at key 'c' : "<<endl;
    for(it=mymap1.begin();it!=mymap1.end();it++)
    {
    cout<<it->first<<" "<<it->second<<endl;
    }

    //erases elements in range from mymap1
    mymap1.erase(mymap1.begin(),mymap1.end());

    cout<<"As mymap1 is empty so empty() function will return 1 : " << mymap1.empty()<<endl;

    //number of elements with key = 'a' in map mp.
    cout<<"Number of elements with key = 'a' in map mp are : "<<mp.count('a')<<endl;

    //if mp is empty then itmp.empty will return 1 else 0.
    if(mp.empty())
    {
        cout<<"Map is empty"<<endl;
    }
    else
    {
        cout<<"Map is not empty"<<endl;
    }

    return 0;
}
```
**Output**
```c++
Key and element's value of map are: b and 1
Printing element mapped by key 'b' using at() function : 1
Swapped elements and their keys of mymap are: 
x 23
y 21
Swapped elements and their keys of mymap1 are: 
a 2
b 1
c 43
Elements of mymap1 after erasing element at key 'c' : 
a 2
b 1
As mymap1 is empty so empty() function will return 1 : 1
Number of elements with key = 'a' in map mp are : 1
Map is not empty
```
-------------------------------------------------------
### 1.6 Set `std::set` and `std::multistd` and `std::unordered_set`

Sets are containers which store only unique values and permit easy look ups. The values in the sets are stored in some specific order (like ascending or descending). Elements can only be inserted or deleted, but cannot be modified. We can access and traverse set elements using iterators just like vectors.

|     cmp           |     set             | unordered_set|
|---------------|---------------------|------------------|
|Ordering        | increasing  order(by default)   | no ordering|
|Implementation  | `Self balancing BST` `like Red-Black Tree`  | Hash Table|  
|search time     | log(n)              | `O(1) -> Average` `O(n) -> Worst Case`|
|Insertion time  | log(n) + Rebalance  | Same as search|                      
|Deletion time   | log(n) + Rebalance  | Same as search|

**Use unordered_set when**
* We need to keep a set of distinct elements and no ordering is required.
* We need single element access i.e. no traversal

```c++
multiset<int> ms; 
//the same as set but allows Duplicates.
```
**Use for**
* Removing duplicates
* Ordered dynamic storage

**Do not use for**
* Simple storage
* Direct access by index

**Notes**
* Sets are often implemented with binary search trees

**Time Complexity**

| Operation    | Time Complexity |             what do?!                                            |
|--------------|-----------------|------------------------------------------------------------------|
| begin()       |     `O(1)`|  Returns an iterator to the first element of the set                                                                | 
| clear()       |     `O(N) where N is the size of the set` |Deletes all the elements in the set and the set will be empty                                                                  |
| count()         |     `O(log(n))` | Returns 1 or 0 if the element is in the set or not respectively                                                                 |
|empty()|`O(n)`|Returns true if the set is empty and false if the set has at least one element|
|end()|`O(1)`|Returns an iterator pointing to a position which is next to the last element|
|erase()|`O(N) where N is the number of element deleted`|Deletes a particular element or a range of elements from the set|
|find()|`O(log(n))`|Searches for a particular element and returns the iterator pointing to the element if the element is found otherwise it will return the iterator returned by end()|
|insert()|`O(log(n))`|insert a new element|
|size()|`O(1)`|Returns the size of the set or the number of elements in the set|

**Traverse**
```c++
void traverse(set<int> s)
{
    set <int>::iterator it;
    for(it = s.begin();it != s.end();++it)
        cout << *it <<  ‘ ‘;
    cout << endl;
}
```

**Example Code**
```c++
std::set<int> s;

//---------------------------------
// General Operations
//---------------------------------

// Insert
s.insert(20);

// Size
unsigned int size = s.size();

// Iterate
for(std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove
s.erase(20);

// Clear
s.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists
bool exists = (s.find(20) != s.end());

// Count the number of elements with a certain value
unsigned int count = s.count(20);
```
**Implementation**
```c++
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set <int> s;
    set <int>::iterator it;
    int A[] = {3, 5, 2, 1, 5, 4};
    for(int i = 0;i < 6;++i)
        s.insert(A[i]);
    for(it = s.begin();it != s.end();++it)
        cout << *it << ' ';
    cout << endl;
    return 0;
}
```
**Output**
```c++
1 2 3 4 5
```
-------------------------------------------------------
### 1.7 Stack `std::stack`

Stack is a container which follows the LIFO (Last In First Out) order and the elements are inserted and deleted from one end of the container. The element which is inserted last will be extracted first.

**Use for**
* First-In Last-Out operations
* Reversal of elements

**Time Complexity**

| Operation    | Time Complexity |             what do?!                                            |
|--------------|-----------------|------------------------------------------------------------------|
| push( )         |          `O(1)` |Insert element at the top of stack |
| pop( )          |          `O(1)` |removes element from top of stack|
| top( )         |          `O(1)` |access the top element of stack|
|empty( )|`O(1)`|checks if the stack is empty or not|
|size( )|`O(1)`|returns the size of stack|

**Declaration**
```c++
stack<int> s;
```

**Example Code**
```c++
std::stack<int> s;

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Push
s.push(20);

// Size
unsigned int size = s.size();

// Pop
s.pop();

// Top
int top = s.top();
```
**Implementation**
```c++
#include <iostream>
#include <stack>

using namespace std;
int main( )
{
    stack <int> s;  // declaration of stack

    //inserting 5 elements in stack from 0 to 4.
    for(int i = 0;i < 5; i++)
    {
        s.push( i ) ;
    }

    //Now the stack is {0, 1, 2, 3, 4}

    //size of stack s
    cout<<”Size of stack is: ” <<s.size( )<<endl;

    //accessing top element from stack, it will be the last inserted element.
    cout<<”Top element of stack is: ” <<s.top( ) <<endl ;

    //Now deleting all elements from stack 
    for(int i = 0;i < 5;i++)
    {
        s.pop( );
    }

    //Now stack is empty,so empty( ) function will return true.

    if(s.empty())
    {
        cout <<”Stack is empty.”<<endl;
    }
    else
    {
        cout <<”Stack is Not empty.”<<endl;
    }

    return 0;

}
```
**Output**
```c++
Size of stack is: 5
Top element of stack is: 4
Stack is empty.
```
-------------------------------------------------------
### 1.8 Queue `std::queue`

Queue is a container which follows FIFO order (First In First Out) . Here elements are inserted at one end (rear ) and extracted from another end(front) .

**Use for**
* First-In First-Out operations
* Ex: Simple online ordering system (first come first served)
* Ex: Semaphore queue handling
* Ex: CPU scheduling (FCFS)

**Notes**
* Often implemented as a `std::deque`

**Time Complexity**

| Operation    | Time Complexity |             what do?!                                            |
|--------------|-----------------|------------------------------------------------------------------|
|push( )|`O(1)`|inserts an element in queue at one end(rear )|
|pop( )|`O(1)`|deletes an element from another end if queue(front)|
|front( )|`O(1)`|access the element on the front end of queue|
|empty( )|`O(1)`|checks if the queue is empty or not|
|size( )|`O(1)`|returns the size of queue|

**Declaration**
```c++
queue <int> q;
```
**Example Code**
```c++
std::queue<int> q;

//---------------------------------
// General Operations
//---------------------------------

// Insert
q.push(value);

// Access head, tail
int head = q.front();       // head
int tail = q.back();        // tail

// Size
unsigned int size = q.size();

// Remove
q.pop();
```
**Implementation**
```c++
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    char qu[4] = {'a', 'b', 'c', 'd'};        
    queue <char> q;
    int N = 3;                            // Number of steps
    char ch;
    for(int i = 0;i < 4;++i)
        q.push(qu[i]);
    for(int i = 0;i < N;++i) {
            ch = q.front();
    q.push(ch);
            q.pop();
    }
    while(!q.empty()) {
        printf("%c", q.front());
        q.pop();
    }
    printf("\n");
    return 0;
}
```
**Output**
```c++
dabc
```
-------------------------------------------------------
### 1.9 Priority Queue `std::priority_queue`

A priority queue is a container that provides constant time extraction of the largest element, at the expense of logarithmic insertion. It is similar to the heap in which we can add element at any time but only the maximum element can be retrieved. In a priority queue, an element with high priority is served before an element with low priority.

**Use for**
* First-In First-Out operations where **priority** overrides arrival time
* Ex: CPU scheduling (smallest job first, system/user priority)
* Ex: Medical emergencies (gunshot wound vs. broken arm)

**Notes**
* Often implemented as a `std::vector`

**Time Complexity**

| Operation    | Time Complexity |             what do?!                                            |
|--------------|-----------------|------------------------------------------------------------------|
|push( )|`O(logN)`|Inserts a new element in the priority queue|
|pop( )|`O(logN)`| Removes the largest element from the priority queue|
|top( )|`O(1)`|Returns a reference to the largest element in the priority queue|
|empty( )|`O(1)`|Returns true if the priority queue is empty and false if the priority queue has at least one element|
|size( )|`O(1)`|Returns the number of element in the priority queue|

**Declaration**
```c++
priority_queue<int> pq;
```

**Example Code**
```c++
std::priority_queue<int> p;

//---------------------------------
// General Operations
//---------------------------------

// Insert
p.push(value);

// Access
int top = p.top();  // 'Top' element

// Size
unsigned int size = p.size();

// Remove
p.pop();
```
**Implementation**
```c++
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}
```
**Output**
```c++
20
10
5
```
-------------------------------------------------------
### 1.10 Pair `std::pair`

Pair is a container that can be used to bind together a two values which may be of different types. Pair provides a way to store two heterogeneous objects as a single unit.

**inititialization**
```c++
pair <int, char> p1;                    // default
pair <int, char> p2 (1, ‘a’);            // value inititialization
pair <int, char> p3 (p2);               // copy of p2
```
We can also initialize a pair using make_pair() function. make_pair(x, y) will return a pair with first element set to x and second element set to y.

```c++
p1 = make_pair(2, ‘b’);
```
To access the elements we use keywords, first and second to access the first and second element respectively.

```c++
cout << p2.first << ‘ ‘ << p2.second << endl;
```

**Implementation**
```c++
#include <iostream>
#include <utility>

using namespace std;

int main()
{
    pair <int, char> p;
    pair <int, char> p1(2, 'b');
    p = make_pair(1, 'a');
    cout << p.first << ' ' <<  p.second << endl;
    cout << p1.first << ' ' << p1.second << endl;
    return 0;
}
```
**Output**
```c++
1 a
2 b
```
