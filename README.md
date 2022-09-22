# cplusplus_custom_string
A C++ custom string data structure inherited from custom vector data structure.  
一個繼承自定義CVector的自定義MyString資料結構。
### CVector
This vector can only store char type element(do not use template).  
此自定義vector只能儲存char type的元素(未使用Template)。
#### Methods
|Name |Function|
|-----|--------|
|getSize|Get the number of elements|  
| getCapacity |Get the capacity of CVector|
| shrink_to_fit |Let capacity=size|
| clear |Clear all elements|
| empty |Check if CVector is empty|
| front |Get a reference of front element|
| back |Get a reference of back element|
| push_back |Push a new element|
| pop_back |Pop up the back element|
|operator[]|Return a reference or a copy of element|
|operator==|Check if two CVector have same elements|
|operator!=|Check if two CVector have different elements|

### MyString
Mystring is inherited from CVector.  
Mystring繼承自CVector。
#### Methods
|Name |Function|
|-----|--------|
|append|Append two string|  
|substr|Get the substring(act as STL method)|
|insert|Insert into string(act as STL method)|
| clear |Clear all characters|
| empty |Check if Mystring is empty|
| front |Get a reference of front character|
| back |Get a reference of back character|
| push_back |Push a new character|
| pop_back |Pop up the back character|
|operator[]|Return a reference or a copy of character|
|operator==|Check if two Mystring is equal|
|operator!=|Check if two CVector is not equal|
