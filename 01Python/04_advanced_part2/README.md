# Python OOP Concepts

## Inheritance
Inheritance allows a class (child) to inherit attributes and methods from another class (parent).

```python
class Parent:
    def __init__(self, name):
        self.name = name

    def greet(self):
        return f"Hello, {self.name}!"

class Child(Parent):
    def __init__(self, name, age):
        super().__init__(name)
        self.age = age

child = Child("John", 10)
print(child.greet())  # Output: Hello, John!
```

## Ordering of Constructors
In inheritance, the constructor of the parent class is called before the constructor of the child class.

```python
class Parent:
    def __init__(self):
        print("Parent constructor")

class Child(Parent):
    def __init__(self):
        super().__init__()
        print("Child constructor")

child = Child()
# Output:
# Parent constructor
# Child constructor
```

## super()
The super() function allows you to call methods from the parent class.

```python
class Parent:
    def greet(self):
        return "Hello from Parent!"

class Child(Parent):
    def greet(self):
        return super().greet() + " And hello from Child!"

child = Child()
print(child.greet())
# Output: Hello from Parent! And hello from Child!
```

## Multi-Level Inheritance
Multi-level inheritance is when a class inherits from a derived class, forming a hierarchy.

```python
class Grandparent:
    def __init__(self):
        print("Grandparent")

class Parent(Grandparent):
    def __init__(self):
        super().__init__()
        print("Parent")

class Child(Parent):
    def __init__(self):
        super().__init__()
        print("Child")

child = Child()
# Output:
# Grandparent
# Parent
# Child
```

## Private Member
Private members are declared by prefixing an attribute with __ (double underscore).

```python
class MyClass:
    def __init__(self):
        self.__private = "I am private"

    def get_private(self):
        return self.__private

obj = MyClass()
print(obj.get_private())  # Output: I am private
```

## Static Method
Static methods are defined using the @staticmethod decorator and do not operate on instance variables.

```python
class MyClass:
    @staticmethod
    def static_method():
        return "This is a static method"

print(MyClass.static_method())  # Output: This is a static method
```

## Declare Property
Properties can be used to manage the access to instance attributes.

```python
class MyClass:
    def __init__(self, value):
        self._value = value

    @property
    def value(self):
        return self._value

    @value.setter
    def value(self, new_value):
        self._value = new_value

obj = MyClass(10)
print(obj.value)  # Output: 10
obj.value = 20
print(obj.value)  # Output: 20
```

## Operator Overloading
Operator overloading allows you to define how operators work with user-defined objects.

```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __str__(self):
        return f"({self.x}, {self.y})"

p1 = Point(1, 2)
p2 = Point(3, 4)
p3 = p1 + p2
print(p3)  # Output: (4, 6)
```

# Python File Operations and Libraries

## File Operations

- Reading a File

```python
with open('example.txt', 'r') as file:
    content = file.read()
    print(content)
```

- Writing to a File
```python
with open('example.txt', 'w') as file:
    file.write("Hello, World!")
```
- Appending to a File
```python
with open('example.txt', 'a') as file:
    file.write("\nAppended text.")
```
## with Keyword
The with keyword is used to wrap the execution of a block of code. It ensures proper acquisition and release of resources.

```python
with open('example.txt', 'r') as file:
    content = file.read()
    print(content)
```

## CSV Library
The csv module implements classes to read and write tabular data in CSV format.

- Reading a CSV File
```python
import csv

with open('example.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        print(row)
```

- Writing to a CSV File
```python
import csv

with open('example.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["Name", "Age"])
    writer.writerow(["John", 30])
```

## OpenPyXL Library
openpyxl is a library to read/write Excel 2010 xlsx/xlsm/xltx/xltm files.

- Reading an Excel File
```python
import openpyxl

workbook = openpyxl.load_workbook('example.xlsx')
sheet = workbook.active
for row in sheet.iter_rows(values_only=True):
    print(row)
```
- Writing to an Excel File
```python
import openpyxl

workbook = openpyxl.Workbook()
sheet = workbook.active
sheet['A1'] = "Hello"
sheet['B1'] = "World"
workbook.save('example.xlsx')
```

## Pandas Library
Pandas is a powerful data manipulation and analysis library for Python.

```python
#Reading a CSV File
import pandas as pd

df = pd.read_csv('example.csv')
print(df)

#Writing to a CSV File
import pandas as pd

df = pd.DataFrame({
    'Name': ['John', 'Jane'],
    'Age': [30, 25]
})
df.to_csv('example.csv', index=False)

# Reading an Excel File
import pandas as pd

df = pd.read_excel('example.xlsx')
print(df)

# Writing to an Excel File

import pandas as pd

df = pd.DataFrame({
    'Name': ['John', 'Jane'],
    'Age': [30, 25]
})
df.to_excel('example.xlsx', index=False)
```

## Try/Except
The try block lets you test a block of code for errors. The except block lets you handle the error.

```python
try:
    with open('example.txt', 'r') as file:
        content = file.read()
        print(content)
except FileNotFoundError:
    print("File not found.")
except Exception as e:
    print(f"An error occurred: {e}")

```