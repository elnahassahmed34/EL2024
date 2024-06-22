# String Operations in Python 

An overview of common string operations in Python along with examples for each operation.

1. Creating Strings
Strings in Python can be created using single quotes, double quotes, or triple quotes for multi-line strings.

Example:

```python
single_quote_string = 'Hello'
double_quote_string = "World"
triple_quote_string = '''This is'''
```

2. String Concatenation
Strings can be concatenated using the + operator.

Example:

```python
greeting = 'Hello' + ' ' + 'World'
print(greeting)  # Output: Hello World
```

3. String Repetition
Strings can be repeated using the * operator.

Example:

```python
repeated_string = 'Hello' * 3
print(repeated_string)  # Output: HelloHelloHello
```

4. String Length
The length of a string can be determined using the len() function.

Example:

```python
string_length = len('Hello World')
print(string_length)  # Output: 11
```

5. String Indexing
Individual characters in a string can be accessed using indexing. Indexing starts at 0.

Example:

```python
my_string = 'Hello'
first_char = my_string[0]
last_char = my_string[-1]
print(first_char)  # Output: H
print(last_char)   # Output: o
```

6. String Slicing
Substrings can be obtained using slicing. The syntax is string[start:end].

Example:

```python
my_string = 'Hello World'
substring = my_string[0:5]
print(substring)  # Output: Hello
```

7. String Methods
Python provides several built-in methods for string manipulation.

upper()
Converts all characters to uppercase.

Example:

```python
my_string = 'hello'
upper_string = my_string.upper()
print(upper_string)  # Output: HELLO
```

lower()
Converts all characters to lowercase.

Example:

```python
my_string = 'HELLO'
lower_string = my_string.lower()
print(lower_string)  # Output: hello
```
strip()
Removes leading and trailing whitespace.

Example:

```python
my_string = '  hello  '
stripped_string = my_string.strip()
print(stripped_string)  # Output: hello
```
replace()
Replaces a substring with another substring.

Example:

```python
my_string = 'Hello World'
new_string = my_string.replace('World', 'Python')
print(new_string)  # Output: Hello Python
```
split()
Splits a string into a list of substrings based on a delimiter.

Example:

```python
my_string = 'Hello World'
split_string = my_string.split(' ')
print(split_string)  # Output: ['Hello', 'World']
```
join()
Joins a list of strings into a single string with a specified delimiter.

Example:

```python
words = ['Hello', 'World']
joined_string = ' '.join(words)
print(joined_string)  # Output: Hello World
```

These are some of the fundamental string operations in Python. Understanding them is crucial for effective string manipulation and processing.


# Types of Functions in Python README

An overview of different types of functions in Python, including normal functions (with or without return values), functions with default or assigned values, variadic functions, and lambda functions.

1. Normal Functions
- Void Functions
A void function performs an action but does not return a value.

Example:

```python
def greet(name):
    print(f"Hello, {name}!")

greet("Alice")
```
- Functions with Return Values
A function that performs an action and returns a value.

Example:

```python
def add(a, b):
    return a + b

result = add(5, 3)
print(result)  # Output: 8
```

2. Functions with Default or Assigned Values
A function can have parameters with default values, which are used if no arguments are provided during the function call.

Example:

```python
def greet(name="World"):
    print(f"Hello, {name}!")

greet()        # Output: Hello, World!
greet("Alice") # Output: Hello, Alice!
```
3. Variadic Functions
Variadic functions can accept a variable number of arguments. These are defined using *args for a tuple of positional arguments and **kwargs for a dictionary of keyword arguments.

- Using *args
Allows a function to accept any number of positional arguments.

Example:

```python
def sum_all(*args):
    return sum(args)

result = sum_all(1, 2, 3, 4)
print(result)  # Output: 10
```
- Using **kwargs
Allows a function to accept any number of keyword arguments.

Example:

```python
def print_details(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")

print_details(name="Alice", age=30, city="New York")
# Output:
# name: Alice
# age: 30
# city: New York
```

4. Lambda Functions
Lambda functions are small anonymous functions defined using the lambda keyword. They can have any number of arguments but only one expression.

Example:

```python
add = lambda x, y: x + y
print(add(5, 3))  # Output: 8

#Using lambda with higher-order functions like `map`, `filter`, and `sorted`
numbers = [1, 2, 3, 4, 5]
squared_numbers = list(map(lambda x: x ** 2, numbers))
print(squared_numbers)  # Output: [1, 4, 9, 16, 25]

#Filtering even numbers
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print(even_numbers)  # Output: [2, 4]
```

Understanding these different types of functions allows for more flexible and powerful code in Python. Each type has its specific use case and can be utilized to create more efficient and readable code.


# Python Modules: A Comprehensive Guide
An Overview on Python modules, covering their creation, usage, and best practices.

1. Creating a Module
Creating a module is straightforward. Simply create a new .py file and add your code to it. For example, create a file named mymodule.py:

```python
# mymodule.py

def greet(name):
    return f"Hello, {name}!"

class Calculator:
    def add(self, a, b):
        return a + b

pi = 3.14159
```

This file defines a function greet(), a class Calculator, and a variable pi. It can now be used as a module in other Python scripts.

2. Using a Module
To use the mymodule module in another Python script, you need to import it using the import statement. Here's an example of how to use the mymodule module:

```python
# main.py

import mymodule

# Using the greet function
print(mymodule.greet("Alice"))

# Using the Calculator class
calc = mymodule.Calculator()
print(calc.add(2, 3))

# Using the pi variable
print(f"The value of pi is {mymodule.pi}")
You can also import specific attributes from a module using the from ... import ... syntax:
```

```python
# main.py

from mymodule import greet, Calculator, pi

print(greet("Bob"))
calc = Calculator()
print(calc.add(5, 7))
print(f"The value of pi is {pi}")
```

3. Standard Library Modules
Python comes with a rich standard library of modules that provide a wide range of functionality, from file I/O and system calls to web protocols and data serialization. You can import and use these modules just like any other module. Some commonly used standard library modules include:

- os: Provides a way to interact with the operating system
- sys: Provides access to some variables used or maintained by the Python interpreter.
- math: Provides access to mathematical functions.
- datetime: Supplies classes for manipulating dates and times.
- json: Provides methods for working with JSON data.

Example:

```python
import os
import sys
import math
import datetime
import json

print(os.getcwd())  # Get current working directory
print(sys.version)  # Get Python version
print(math.sqrt(16))  # Calculate the square root
print(datetime.datetime.now())  # Get current date and time
print(json.dumps({"name": "John", "age": 30}))  # Convert dictionary to JSON string
```

4. Third-Party Modules
In addition to the standard library, you can install and use third-party modules using the Python Package Index (PyPI). The pip tool is used to install these modules. For example, to install the requests module, run:

```sh
pip install requests
```
Then, you can use the requests module in your script:

```python
import requests

response = requests.get("https://api.github.com")
print(response.json())
```

- Conclusion
Modules are a fundamental concept in Python that facilitate code organization, reuse, and maintainability. By understanding how to create, use, and manage modules, you can write cleaner and more efficient Python code. Whether using built-in modules, third-party libraries, or your own custom modules, the modular approach will greatly enhance your coding practice.




# overview of commonly used list methods in Python:

## Adding Elements
1. append(x)

Adds an item x to the end of the list.
Example: 
- lst.append(4)
- insert(i, x)

2. Inserts an item x at a specified index i.
Example: 
- lst.insert(2, 'a')
- extend(iterable)

3. Extends the list by appending all items from an iterable (list, tuple, etc.).
Example: 
- lst.extend([1, 2, 3])

## Removing Elements
remove(x)

1. Removes the first occurrence of item x.
Example: 
- lst.remove('a')
- pop([i])

2. Removes and returns the item at index i (defaults to the last item if i is not specified).
Example: 
- lst.pop(1)
- clear()

3. Removes all items from the list.
Example: 
- lst.clear()

## Querying and Searching
1. index(x[, start[, end]])

 Returns the index of the first occurrence of x within the specified bounds.
Example: 
- lst.index(4)
- count(x)

2. Returns the number of times x appears in the list.
Example: 
- lst.count(4)

## Sorting and Reversing
1. sort(key=None, reverse=False)
Sorts the list in place.
Example: 
- lst.sort(reverse=True)
2. reverse()
Reverses the elements of the list in place.
Example: 
- lst.reverse()

## Copying
copy()
- Returns a shallow copy of the list.
Example: 
- new_list = lst.copy()

## Summary of Method Usage
```python
lst = [3, 1, 2]
lst.append(4)        # [3, 1, 2, 4]
lst.insert(1, 'a')   # [3, 'a', 1, 2, 4]
lst.extend([5, 6])   # [3, 'a', 1, 2, 4, 5, 6]
lst.remove('a')      # [3, 1, 2, 4, 5, 6]
item = lst.pop(2)    # [3, 1, 4, 5, 6], item = 2
lst.clear()          # []
````

This provides a quick overview of the main list methods in Python, summarizing their functionality and common usage examples.


# Python Data Structures: Tuple and Set Methods

This document provides an overview of commonly used methods for two important Python data structures: tuples and sets. Understanding these methods will help you work more effectively with these structures in your Python programs.

## Tuple Methods

Tuples are immutable sequences in Python. They are similar to lists, but unlike lists, tuples cannot be changed after their creation. Here are some useful tuple methods and operations:

### 1. `count()`

The `count()` method returns the number of times a specified value appears in the tuple.

**Syntax:**
```python
tuple.count(value)
```
Example:

```python
my_tuple = (1, 2, 3, 2, 2, 4)
print(my_tuple.count(2))  # Output: 3
```

2. index()
The index() method finds the first occurrence of a specified value and returns its position.

Syntax:

```python
tuple.index(value, start, end)
```

value: The item to search for.
start: (Optional) The starting index from which to search.
end: (Optional) The ending index up to which to search.
Example:

```python
my_tuple = (1, 2, 3, 2, 4)
print(my_tuple.index(2))  # Output: 1
print(my_tuple.index(2, 2))  # Output: 3 (search starts from index 2)
```

3. Tuple Unpacking
Tuple unpacking allows you to assign each item in a tuple to a variable.

Example:

```python
my_tuple = (1, 2, 3)
a, b, c = my_tuple
print(a, b, c)  # Output: 1 2 3
```

## Set Methods

Sets are unordered collections of unique elements. They are useful for membership testing and eliminating duplicate entries. Here are some commonly used set methods:

1. add()
The add() method adds an element to the set. If the element is already present, it does nothing.

Syntax:

```python
set.add(element)
```
Example:

```python
my_set = {1, 2, 3}
my_set.add(4)
print(my_set)  # Output: {1, 2, 3, 4}
```

2. remove()
The remove() method removes a specified element from the set. If the element is not present, it raises a KeyError.

Syntax:

```python
set.remove(element)
#Example:

my_set = {1, 2, 3}
my_set.remove(2)
print(my_set)  # Output: {1, 3}
```

3. discard()
The discard() method removes a specified element from the set. If the element is not present, it does nothing.

Syntax:

```python
set.discard(element)
#Example:

my_set = {1, 2, 3}
my_set.discard(2)
my_set.discard(4)  # No error even though 4 is not in the set
print(my_set)  # Output: {1, 3}
```

4. union()
The union() method returns a new set with all elements from the set and all other specified sets.

Syntax:

```python
set.union(*other_sets)
#Example:

set1 = {1, 2, 3}
set2 = {3, 4, 5}
result = set1.union(set2)
print(result)  # Output: {1, 2, 3, 4, 5}
```

5. intersection()
The intersection() method returns a new set with elements that are common to the set and all other specified sets.

Syntax:

```python
set.intersection(*other_sets)
#Example:

set1 = {1, 2, 3}
set2 = {2, 3, 4}
result = set1.intersection(set2)
print(result)  # Output: {2, 3}
```

6. difference()
The difference() method returns a new set with elements that are in the set but not in the other specified sets.

Syntax:

```python
set.difference(*other_sets)
#Example:

set1 = {1, 2, 3}
set2 = {2, 3, 4}
result = set1.difference(set2)
print(result)  # Output: {1}
```

7. clear()
The clear() method removes all elements from the set.

Syntax:

```python
set.clear()
#Example:

my_set = {1, 2, 3}
my_set.clear()
print(my_set)  # Output: set()
```

## Conclusion
Tuples and sets are fundamental data structures in Python, each with unique characteristics and methods. Tuples provide a way to store ordered, immutable collections, while sets offer efficient membership tests and unique element storage. By mastering these methods, you can write more effective and efficient Python code.


# PyAutoGUI: Python Automation for Mouse and Keyboard

PyAutoGUI is a Python module that allows you to programmatically control the mouse and keyboard. It is a powerful tool for automating tasks on your computer, such as moving the mouse, clicking, typing, and taking screenshots.

## Installation

To install PyAutoGUI, you can use `pip`:

```bash
pip install pyautogui
```

Basic Usage

1. Importing the Module
To use PyAutoGUI, you need to import it into your script:

```python
import pyautogui
```

2. Mouse Control
Moving the Mouse
You can move the mouse to a specific position on the screen using the moveTo() method:

```python
pyautogui.moveTo(100, 100, duration=1)  # Move to (100, 100) in 1 second
```

- Clicking
You can perform mouse clicks using the click() method:

```python
pyautogui.click(100, 100)  # Click at (100, 100)
```

- Dragging
You can drag the mouse while holding down a button using the dragTo() method:

```python
pyautogui.dragTo(200, 200, duration=1, button='left')  # Drag to (200, 200) in 1 second
```

3. Keyboard Control
- Typing
You can type text using the typewrite() method:

```python
pyautogui.typewrite('Hello, world!', interval=0.1)  # Type with 0.1-second interval between each character
```

- Pressing Keys
You can press a single key using the press() method or multiple keys using the hotkey() method:

```python
pyautogui.press('enter')  # Press the Enter key
pyautogui.hotkey('ctrl', 'c')  # Press Ctrl+C
```


4. Taking Screenshots
You can take a screenshot using the screenshot() method and save it to a file:

```python
screenshot = pyautogui.screenshot()
screenshot.save('screenshot.png')  # Save the screenshot to a file
```

5. Finding On-Screen Images
You can locate an image on the screen using the locateOnScreen() method. This is useful for GUI automation tasks where you need to click on a specific button or icon:

```python
location = pyautogui.locateOnScreen('button.png')
print(location)  # Output: Box(left=100, top=200, width=50, height=50)
```

## Examples
- Automating a Simple Task
Here's an example of how to automate a simple task of opening a text editor and typing some text:

```python
import pyautogui
import time

# Wait for 5 seconds to give you time to open the text editor
time.sleep(5)

# Move to the text editor and click to focus
pyautogui.moveTo(200, 200, duration=1)
pyautogui.click()

# Type some text
pyautogui.typewrite('This is an automated message.', interval=0.1)
pyautogui.press('enter')
pyautogui.typewrite('PyAutoGUI makes automation easy!', interval=0.1)
```

## Conclusion
PyAutoGUI is a versatile library for automating mouse and keyboard actions in Python. With its simple and intuitive API, you can quickly write scripts to automate repetitive tasks on your computer.


# Beautiful Soup: Web Scraping with Python

Beautiful Soup is a Python library for pulling data out of HTML and XML files. It provides Pythonic idioms for iterating, searching, and modifying the parse tree, which is extremely useful for web scraping tasks.

## Installation

To install Beautiful Soup, you can use `pip`:

```bash
pip install beautifulsoup4
```
You will also need a parser, such as lxml or html.parser:

```bash
pip install lxml
```

Basic Usage
1. Importing the Module
To use Beautiful Soup, you need to import it along with a parser, such as lxml:

```python
from bs4 import BeautifulSoup
import requests
```

2. Creating a Beautiful Soup Object
First, you need to fetch the HTML content of the web page you want to scrape:

```python
url = 'http://example.com'
response = requests.get(url)
html_content = response.content

#Then, create a Beautiful Soup object:
soup = BeautifulSoup(html_content, 'lxml')  # You can also use 'html.parser'
```

3. Navigating the Parse Tree
- Finding Elements
You can find elements using methods like find(), find_all(), and select():

```python
# Find the first <h1> tag
h1_tag = soup.find('h1')
print(h1_tag.text)

# Find all <p> tags
p_tags = soup.find_all('p')
for p in p_tags:
    print(p.text)

# Find elements using CSS selectors
css_selection = soup.select('div > p')
for element in css_selection:
    print(element.text)
```

- Accessing Attributes
You can access an element's attributes using dictionary-like notation:

```python
# Find the first <a> tag and get its href attribute
a_tag = soup.find('a')
print(a_tag['href'])
```

4. Modifying the Parse Tree
You can modify the parse tree by adding, removing, or changing elements and attributes:

```python
# Add a new tag
new_tag = soup.new_tag('p')
new_tag.string = 'This is a new paragraph.'
soup.body.append(new_tag)

# Remove a tag
soup.find('p').decompose()
```

5. Example: Extracting All Links
Here's an example of how to extract all the links from a web page:

```python
url = 'http://example.com'
response = requests.get(url)
soup = BeautifulSoup(response.content, 'lxml')

links = soup.find_all('a')
for link in links:
    print(link.get('href'))
```

## Conclusion
Beautiful Soup is a powerful and flexible tool for web scraping in Python. It makes it easy to parse HTML and XML documents, navigate the parse tree, and extract or modify content.









//tasks

