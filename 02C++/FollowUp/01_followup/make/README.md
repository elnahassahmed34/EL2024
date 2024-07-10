# Makefile

## What is `make`?
`make` is a build automation tool that automates the process of compiling and linking source code into executable programs or libraries. It is used to manage dependencies and ensure that only the necessary parts of the code are recompiled.

## Build Environment
`make` works within a build environment to streamline the process of building software. It uses `Makefiles`, which define how the build process should be carried out.

## Why Learn `make`?
Learning `make` is essential for:
- Using it in Yocto with recipes to build embedded Linux distributions.
- Developing and compiling device drivers.
- Managing complex build processes efficiently.

## How to Use `make`?
1. Create a `Makefile` that specifies the build rules and dependencies.
2. Run the `make` command in the directory containing the `Makefile`.
3. `make` parses the `Makefile` and executes the commands defined to build the project.

## How to Write a `Makefile`?

### Basic Structure of a `Makefile`
A `Makefile` consists of rules, which have the following structure:
target: dependencies
command

```makefile
- `target`: The file or output that you want to build.
- `dependencies`: The files that the target depends on.
- `command`: The shell command(s) to build the target from the dependencies.

### Example of a Simple `Makefile`
```makefile
# This is a simple Makefile example

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files
SRCS = main.c utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = myprogram

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJS)
    $(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compile source files into object files
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
    rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean
```
## Explanation of the Example
- CC and CFLAGS: Define the compiler and compiler flags.
- SRCS and OBJS: Lists of source and object files.
- EXEC: The name of the final executable.
- all: The default target that depends on the executable.
- $(EXEC): Links the object files to create the executable.
- %.o: %.c: A pattern rule to compile source files into object files.
- clean: A target to clean up build files.
- .PHONY: Declares non-file targets to avoid conflicts.

This example demonstrates a basic Makefile for compiling and linking a C program with two source files (main.c and utils.c).

# Understanding `.PHONY` in Makefiles

## Introduction to `.PHONY`
`.PHONY` is a special directive in Makefiles that specifies certain targets as phony. Phony targets are not associated with files; instead, they represent commands or actions to be executed when specified.

## Purpose of `.PHONY`
The primary purpose of using `.PHONY` is to prevent conflicts between file names and target names. When a target is declared as phony, `make` will always execute the commands for that target, even if a file with the same name exists in the directory.

## Common Use Cases
- **Cleaning Up**: The `clean` target is often used to delete intermediate and output files. Declaring it as phony ensures it runs every time, even if a file named `clean` exists.
- **Building All Targets**: The `all` target is usually a shortcut for building all parts of the project. Making it phony avoids any issues if a file named `all` is present.
- **Other Utility Targets**: Targets like `install`, `test`, or `dist` that perform actions rather than creating files should also be declared as phony.

## Example Usage
Here's an example Makefile demonstrating the use of `.PHONY`:
```makefile
# Declare phony targets
.PHONY: all clean

# Default target
all: a.out

# Link object files to create executable
a.out: main.o add.o
	gcc -Wall -g -o a.out main.o add.o

# Compile main.c into main.o
main.o: main.c add.h
	gcc -Wall -g -c main.c -o main.o

# Compile add.c into add.o
add.o: add.c add.h
	gcc -Wall -g -c add.c -o add.o

# Clean up build files
clean:
	rm -f *.o a.out
  ```

## In this example:

- The .PHONY directive is used to declare all and clean as phony targets.
- The clean target removes intermediate and output files.
- The all target builds the main executable.

## Benefits of Using .PHONY
- Avoids Filename Conflicts: Ensures that the targets run correctly even if a file with the same name exists.
- Clarifies Intent: Makes it clear that the targets are for executing commands rather than producing files.
- Improves Makefile Reliability: Ensures consistent behavior by preventing make from mistaking a file for a target.
- By incorporating .PHONY in your Makefiles, you can create more reliable and maintainable build scripts.

# Makefile Basics

## Variables in Makefiles
Variables in Makefiles allow you to define and reuse values throughout the file, making it easier to manage and update the build process. You can define a variable using the `=` operator and then reference it using `$(VAR_NAME)`.

### Example
```makefile
# Define variables
CC = gcc
CFLAGS = -Wall -g

# Use variables
main.o: main.c add.h
	$(CC) $(CFLAGS) -c main.c -o main.o
```

- In this example, CC and CFLAGS are variables that store the compiler and compiler flags, respectively. They are then used in the command for compiling main.c into main.o.

## Automatic Variables
Automatic variables in Makefiles provide context-specific information about the current rule. They simplify the Makefile by reducing redundancy and making it more readable.

### Common Automatic Variables
- $@: Represents the name of the target being generated.
- $^: Represents the names of all the prerequisites, with spaces between them.
- $<: Represents the name of the first prerequisite.
Examples
```makefile
#Using $@
# Target to create executable
a.out: main.o add.o
	gcc -Wall -g -o $@ $^
#In this rule, $@ will be replaced with a.out, the target being created.

#Using $^
# Target to create executable
a.out: main.o add.o
	gcc -Wall -g -o a.out $^
#In this rule, $^ will be replaced with main.o add.o, the list of prerequisites.

#Using $<
# Rule to compile source file into object file
main.o: main.c add.h
	gcc -Wall -g -c $< -o $@
#In this rule, $< will be replaced with main.c, the first prerequisite, and $@ will be replaced with main.o, the target being created.
```

- By using these automatic variables, you can write more flexible and maintainable Makefiles that can easily adapt to changes in your project structure.


# Makefile Basics: Pattern Rules

## Pattern Rules in Makefiles

Pattern rules in Makefiles allow you to define generic rules for compiling or generating files based on their extensions or patterns. They are useful when you have multiple source files with a predictable naming convention and want to avoid writing individual rules for each file.

### `%o`, `%c` in Pattern Rules

In Makefiles, `%o` and `%c` are placeholders that match parts of filenames based on their patterns:

- **`%o`**: Matches any filename ending with `.o`, typically representing object files.
- **`%c`**: Matches any filename ending with `.c`, typically representing C source files.

### Example Usage

#### Rule for Compiling C Source Files into Object Files

```makefile
# Pattern rule to compile .c files into .o files
%.o: %.c
    gcc -c $< -o $@
```

### In this example:

- %c in %.c matches any .c file.
- %o in %.o matches the corresponding .o file.
- $< represents the first prerequisite (the .c file).
- $@ represents the target (the .o file).

### Benefits of Pattern Rules
- Automation: Reduces manual effort by automatically applying rules based on file extensions or patterns.
- Flexibility: Handles multiple files with similar naming conventions without repetitive rule definitions.
- Maintenance: Simplifies Makefiles and improves readability by abstracting common build tasks.
- Pattern rules (%o, %c) are powerful tools in Makefiles, enabling efficient and concise management of compilation tasks for projects with multiple source files.


# Makefile Basics: Built-in Functions

## 5. `wildcard`

The `wildcard` function in Makefiles expands wildcard characters (`*`, `?`, `[...]`) into a list of filenames, providing a convenient way to capture files that match a pattern within the Makefile.

### Syntax

```makefile
$(wildcard pattern)
pattern: Specifies a wildcard pattern to match filenames.
```
### Example Usage
```makefile
# Assign all .c files in the current directory to the variable SRCS
SRCS := $(wildcard *.c)

# Print the list of source files
$(info Source files: $(SRCS))
```

### Explanation
- $(wildcard *.c): This function expands to a space-separated list of all .c files in the current directory.
- It is useful for dynamically including or excluding files based on their names or extensions.
- The resulting list can then be used for targets, dependencies, or other operations within the Makefile.
- The wildcard function simplifies the process of handling file lists dynamically in Makefiles, enhancing flexibility and automation in build processes.

# Makefile Basics: Common Built-in Functions

## 2. `$(subst char, txt)`

The `subst` function substitutes every occurrence of a substring within a string with another substring.

### Syntax

```makefile
$(subst from, to, text)
from: The substring to be replaced.
to: The substring to replace with.
text: The string in which the substitution is to be made.
```
- Example Usage
```makefile
# Replace all occurrences of 'foo' with 'bar' in the string 'foo baz foo'
RESULT := $(subst foo, bar, foo baz foo)

# Print the result
$(info Result: $(RESULT))
```
### Explanation
- $(subst foo, bar, foo baz foo): Replaces foo with bar in the string foo baz foo, resulting in bar baz bar.
## 3. $(call)
The call function is used to call a user-defined function with arguments.

Syntax
```makefile
$(call function, param1, param2, ...)
```
- function: The name of the user-defined function.
- param1, param2, ...: The parameters to pass to the function.
Example Usage
```makefile
# Define a function to concatenate two strings
concat = $(1)$(2)

# Call the function with two parameters
RESULT := $(call concat, Hello, World)

# Print the result
$(info Result: $(RESULT))
Explanation
```
- $(call concat, Hello, World): Calls the concat function with Hello and World as arguments, resulting in HelloWorld.

## 4. $(foreach)
The foreach function iterates over a list of words, performing an operation for each word.

```makefile
$(foreach var, list, text)
```
var: The iteration variable.
list: The list of words to iterate over.
text: The text to evaluate for each word in the list.

```makefile
# List of items
ITEMS := apple banana cherry

# Generate a string with each item capitalized
RESULT := $(foreach item, $(ITEMS), $(shell echo $(item) | tr 'a-z' 'A-Z'))

# Print the result
$(info Result: $(RESULT))
Explanation
```
- $(foreach item, $(ITEMS), $(shell echo $(item) | tr 'a-z' 'A-Z')): Iterates over each item in ITEMS and converts it to uppercase, resulting in APPLE BANANA CHERRY.


# Makefile Basics: Implicit Rules

## Introduction to Implicit Rules

Implicit rules in Makefiles are predefined patterns that simplify the build process by automatically determining how to build certain types of files. These rules eliminate the need to explicitly define common compilation commands for standard file types, allowing for more concise and readable Makefiles.

## How Implicit Rules Work

Make uses a set of default implicit rules to determine how to build targets from their prerequisites. These rules cover common file types and operations, such as compiling C files into object files or linking object files into executables.

### Common Implicit Rules

1. **Compiling C Source Files to Object Files**

```makefile
   %.o: %.c
   	$(CC) $(CFLAGS) -c $< -o $@
```
- Pattern: %.o matches any .o file.
- Prerequisite: %.c matches any .c file with the same base name.
- Command: Compiles the .c file into a .o file.
- Linking Object Files to Create Executables

```makefile
%: %.o
	$(CC) $(LDFLAGS) $^ -o $@
```
- Pattern: % matches any file name.
- Prerequisite: %.o matches the corresponding .o file.
- Command: Links the .o file to create an executable.
- Using Implicit Rules
- To use implicit rules, simply list the targets and their prerequisites without specifying the command. Make will automatically apply the appropriate implicit rule.

Example Makefile Using Implicit Rules
```makefile
# Variables
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = 

# Source and object files
SRCS = main.c add.c
OBJS = $(SRCS:.c=.o)
TARGET = myapp

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
```
In this example:

- Compiling: Make will automatically use the implicit rule %.o: %.c to compile main.c and add.c into main.o and add.o.
- Linking: Make will use the implicit rule %: %.o to link main.o and add.o into the executable myapp.
- Customizing Implicit Rules
- You can override or customize implicit rules by defining your own patterns in the Makefile.

### Custom Implicit Rule Example
```makefile
# Custom rule to compile C++ files
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
```
- This custom rule tells Make to compile .cpp files into .o files using the C++ compiler and flags.

### Conclusion
Implicit rules simplify Makefiles by handling common patterns automatically. By understanding and utilizing these rules, you can write more concise and maintainable Makefiles. You can also customize implicit rules to suit specific needs, providing flexibility and control over the build process.


# Makefile Basics: Implicit Rule Variables

## Introduction

Makefiles use a variety of implicit rule variables to simplify the build process. These variables provide default values and can be customized to control the behavior of common rules.

### Important Implicit Rule Variables

1. **`CC`**
   - **Description**: The C compiler to use.
   - **Default**: `cc`
   - **Usage**:
     ```makefile
     CC = gcc
     ```

2. **`CFLAGS`**
   - **Description**: Flags to pass to the C compiler.
   - **Usage**:
     ```makefile
     CFLAGS = -Wall -g
     ```

3. **`CXX`**
   - **Description**: The C++ compiler to use.
   - **Default**: `g++`
   - **Usage**:
     ```makefile
     CXX = g++
     ```

4. **`CXXFLAGS`**
   - **Description**: Flags to pass to the C++ compiler.
   - **Usage**:
     ```makefile
     CXXFLAGS = -Wall -g
     ```

5. **`LDFLAGS`**
   - **Description**: Flags to pass to the linker.
   - **Usage**:
     ```makefile
     LDFLAGS = -lm
     ```

6. **`AR`**
   - **Description**: The archive-maintaining program; typically used to create static libraries.
   - **Default**: `ar`
   - **Usage**:
     ```makefile
     AR = ar
     ```

7. **`ARFLAGS`**
   - **Description**: Flags to pass to the archive-maintaining program.
   - **Usage**:
     ```makefile
     ARFLAGS = rcs
     ```

### Example Makefile Using Implicit Rule Variables

```makefile
# Variables
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = 
TARGET = myapp
SRCS = main.c add.c
OBJS = $(SRCS:.c=.o)

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Rule to link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
