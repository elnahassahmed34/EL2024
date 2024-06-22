# Python Dictionary Methods

A dictionary in Python is an unordered collection of key-value pairs. Each key must be unique, and the values can be of any data type. Dictionaries are used to store data values like a map.

## Creating a Dictionary

```python
# Creating a dictionary
my_dict = {
    'name': 'John',
    'age': 30,
    'city': 'New York'
}
```

Dictionary Methods

1. dict.clear()
Removes all items from the dictionary.

```python
my_dict.clear()
print(my_dict)  # Output: {}
```

2. dict.copy()
Returns a shallow copy of the dictionary.

```python
my_dict = {'name': 'John', 'age': 30, 'city': 'New York'}
copy_dict = my_dict.copy()
print(copy_dict)  # Output: {'name': 'John', 'age': 30, 'city': 'New York'}
```

3. dict.get(key, default=None)
Returns the value of the specified key. If the key does not exist, it returns the default value.

```python
age = my_dict.get('age')
print(age)  # Output: 30
nickname = my_dict.get('nickname', 'Unknown')
print(nickname)  # Output: Unknown
```

4. dict.items()
Returns a view object that displays a list of a dictionary's key-value tuple pairs.

```python
items = my_dict.items()
print(items)  # Output: dict_items([('name', 'John'), ('age', 30), ('city', 'New York')])
```

5. dict.keys()
Returns a view object that displays a list of all the keys in the dictionary.

```python
keys = my_dict.keys()
print(keys)  # Output: dict_keys(['name', 'age', 'city'])
```

6. dict.values()
Returns a view object that displays a list of all the values in the dictionary.

```python
values = my_dict.values()
print(values)  # Output: dict_values(['John', 30, 'New York'])
```

7. dict.pop(key, default=None)
Removes the specified key and returns the corresponding value. If the key is not found, the default value is returned.

```python
age = my_dict.pop('age')
print(age)  # Output: 30
print(my_dict)  # Output: {'name': 'John', 'city': 'New York'}
```

8. dict.popitem()
Removes and returns the last key-value pair inserted into the dictionary.

```python
last_item = my_dict.popitem()
print(last_item)  # Output: ('city', 'New York')
print(my_dict)  # Output: {'name': 'John'}
```
9. dict.setdefault(key, default=None)
Returns the value of the specified key. If the key does not exist, inserts the key with the specified default value.

```python
name = my_dict.setdefault('name', 'Doe')
print(name)  # Output: John

nickname = my_dict.setdefault('nickname', 'JD')
print(nickname)  # Output: JD
print(my_dict)  # Output: {'name': 'John', 'nickname': 'JD'}
```

10. dict.update([other])
Updates the dictionary with the key-value pairs from another dictionary or an iterable of key-value pairs.

```python
my_dict.update({'age': 30, 'city': 'New York'})
print(my_dict)  # Output: {'name': 'John', 'nickname': 'JD', 'age': 30, 'city': 'New York'}
```
11. dict.fromkeys(seq, value)
Creates a new dictionary with keys from the specified sequence and values set to the specified value.

```python
keys = ['a', 'b', 'c']
new_dict = dict.fromkeys(keys, 0)
print(new_dict)  # Output: {'a': 0, 'b': 0, 'c': 0}
```
## Conclusion
Python's dictionary methods provide a rich set of tools for managing key-value pairs efficiently. Whether you need to add, remove, or update items, there are methods available to help you accomplish your tasks with ease.



# Introduction to Object-Oriented Programming (OOP) in Python

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects", which are instances of classes. A class can be thought of as a blueprint for creating objects. OOP allows for organizing code into modular, reusable structures.

## Basic Concepts

- **Class**: A blueprint for creating objects (instances).
- **Object**: An instance of a class.
- **Constructor**: A special method called when an object is instantiated.
- **Destructor**: A special method called when an object is destroyed.
- **Method**: A function defined within a class.

## Simple Class with Constructor and Destructor

### Class Definition

A class is defined using the `class` keyword. The constructor method is `__init__` and the destructor method is `__del__`.

```python
class MyClass:
    """
    This is a simple class example.
    """

    def __init__(self, name):
        """
        Constructor method.
        """
        self.name = name
        print(f"{self.name} is created.")

    def __del__(self):
        """
        Destructor method.
        """
        print(f"{self.name} is destroyed.")

# Creating an instance of MyClass
obj = MyClass("Instance1")
# Deleting the instance
del obj
```

## Class Methods
Class methods are functions defined within a class. They can operate on data (attributes) contained within the class.

```python
class MyClass:
    """
    This is a simple class example.
    """

    def __init__(self, name):
        """
        Constructor method.
        """
        self.name = name

    def greet(self):
        """
        A simple class method.
        """
        return f"Hello, {self.name}!"

# Creating an instance of MyClass
obj = MyClass("Instance1")
print(obj.greet())  # Output: Hello, Instance1!
```

## Special Methods: __str__ and __doc__
### __str__ Method
The __str__ method returns a string representation of the object, which is useful for printing.

```python
class MyClass:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        """
        String representation of the object.
        """
        return f"MyClass instance with name: {self.name}"

obj = MyClass("Instance1")
print(obj)  # Output: MyClass instance with name: Instance1
```

### __doc__ Attribute
The __doc__ attribute stores the documentation string of the class or method.

```python
class MyClass:
    """
    This class demonstrates the use of the __doc__ attribute.
    """

    def __init__(self, name):
        """
        Constructor method.
        """
        self.name = name

print(MyClass.__doc__)  # Output: This class demonstrates the use of the __doc__ attribute.
print(MyClass.__init__.__doc__)  # Output: Constructor method.
```
## Conclusion
This guide provides a brief introduction to Object-Oriented Programming in Python, covering the basics of class definition, constructors, destructors, class methods, and special methods. OOP is a powerful paradigm that helps in organizing and structuring code in a modular and reusable way.



