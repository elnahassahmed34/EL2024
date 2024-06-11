# Embedded Linux Diploma

## Why Learn Python for Embedded Linux?

Python is an essential programming language in the context of embedded Linux due to its versatility and ease of use. Here are some key reasons why we focus on Python in this diploma:

- **Rapid Prototyping**: 
- **Rich Libraries**: 
- **Easy Integration**: 
- **Automation**: 
- **Community Support**: 



## Python Interpreter = Compiler in C/C++


## Create Your First "Hello, World!" Program


### Steps to Create "Hello, World!"


1. **Write the following code in the file:**

    ```python
    print("Hello, World!")
    ```

2. Run the script from the terminal
    ```sh
    python3 hello.py
    ```    


## Python Data Types 

1. Integer (int)
Integers represent whole numbers without any decimal point. They can be positive or negative.

Example:

```python
x = 5
y = -10
```

2. Float (float)
Floats represent real numbers with a decimal point. They can also be positive or negative.

```python
pi = 3.14
temperature = -23.5
```

3. String (str)
Strings are sequences of characters, enclosed within single quotes (') or double quotes (").

```python
name = 'Alice'
message = "Hello, world!"
```

4. Boolean (bool)
Booleans represent truth values, True or False.

```python
is_sunny = True
is_raining = False
```

5. List (list)
Lists are ordered collections of items, which can be of different types. They are mutable, meaning their elements can be changed after creation.

```python
numbers = [1, 2, 3, 4, 5]
names = ['Alice', 'Bob', 'Charlie']
```

6. Tuple (tuple)
Tuples are similar to lists but are immutable, meaning their elements cannot be changed after creation.

```python
coordinates = (10, 20)
colors = ('red', 'green', 'blue')
```

7. Dictionary (dict)
Dictionaries are unordered collections of key-value pairs. They are mutable and indexed by keys.


```python
person = {'name': 'Alice', 'age': 30, 'city': 'New York'}
grades = {'math': 90, 'science': 85, 'history': 88}
```

8. Set (set)
Sets are unordered collections of unique elements. They are mutable but do not allow duplicate items.


```python
unique_numbers = {1, 2, 3, 4, 5}
unique_letters = {'a', 'b', 'c', 'd'}
```

## Code Flow in Python

1. Sequential Execution

Python code is executed line by line from top to bottom. Each statement is executed in the order in which it appears.

Example:

```python
print("Start")
x = 5
y = 10
print(x + y)
print("End")
```

2. Conditional Statements
Conditional statements allow for decision-making in the code. The if, elif, and else keywords are used to execute different blocks of code based on certain conditions.

Example:

```python
x = 10
if x > 5:
    print("x is greater than 5")
elif x == 5:
    print("x is equal to 5")
else:
    print("x is less than 5")
```

3. Loops
Loops are used to repeat a block of code multiple times. The two main types of loops in Python are for loops and while loops.

- For Loop
The for loop is used to iterate over a sequence (e.g., list, tuple, dictionary, set, or string).

Example:

```python
for i in range(5):
    print(i)
```

- While Loop
The while loop is used to repeat a block of code as long as a condition is true.

Example:

```python
count = 0
while count < 5:
    print(count)
    count += 1
```

4. Function Calls
Functions are blocks of reusable code that perform a specific task. Functions are defined using the def keyword and are called by their name followed by parentheses.

- Defining a Function
Example:

```python
def greet(name):
    print("Hello, " + name + "!")

greet("Alice")
```

- Returning Values from Functions
Functions can return values using the return keyword.

Example:

```python
Copy code
def add(a, b):
    return a + b

result = add(5, 3)
print(result)
``` 

5. Combining Concepts
These concepts can be combined to create more complex and functional programs.

Example:

```python
def check_even_odd(number):
    if number % 2 == 0:
        return "even"
    else:
        return "odd"

for i in range(1, 11):
    print(f"{i} is {check_even_odd(i)}")
```

Understanding the code flow in Python is essential for writing efficient and effective programs. Sequential execution, conditional statements, loops, and functions are the building blocks of Python programming.


