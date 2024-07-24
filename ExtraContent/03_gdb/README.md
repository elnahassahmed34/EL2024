# GDB Power

## USE :
1.  basics commands ( next -stepinto - finish-run-breakpoint-etc)
2.  calling methods anywhere
3.  watch and break under conditions
4.  trip inside memory and registers everywhere and backtracking in stack
5.  assign variables and displaying®
6.  record steps and go back and forward
7.  tui
8.  remotely debugging 
9.  attach with pid
10. python inside gdb
11. shell inside gdb
12. gdbfiles
13.  threads
14. signals
15. core-dump file
16.  assembly view_and disassembly view

## 1. Debug Symbol Table
### Overview
The debug symbol table contains metadata about the program's source code, including variable names, data structures, and line numbers. This information is crucial for debugging as it maps the executable's machine code back to the human-readable source code.

### Compilation with Debug Symbols
To include debugging information in your executable, use the -g flag during compilation:

```bash
g++ -g -o program main.cpp
```
This command generates an executable program with embedded debugging information.

### GDB and Debug Symbols
GDB uses the symbol table to provide meaningful insights, such as displaying variable values, setting breakpoints, and showing call stacks. Without debug symbols, GDB can only show raw memory addresses, making debugging significantly harder.

## 2. Debug Basic Commands
Starting GDB
```bash
gdb executable
```
Starts GDB with the specified executable.

Running the Program
```gdb
(gdb) run
```
Starts program execution.

Exiting GDB
```gdb
(gdb) quit
```
Exits GDB.

## 3. Break and Print
### Breakpoints
Breakpoints allow you to pause program execution at specific points. Set breakpoints at function names or line numbers:

```gdb
(gdb) break main
(gdb) break 42  # Line 42
```

```
###Breakpoints####
break
b
break Function Name
break File Name:Line Number
break Line Number
break *Address
break ... if Condition

info breakpoints
enable 
disable
delete

print ####

print variable  
p variable 
p &variable  ----address 

info locals
```

### Printing Variables
Inspect variable values using the print command:

```gdb
(gdb) print variable_name
(gdb) print *pointer_name  # For pointer dereferencing
```

## 4. Watch and Display
### Watchpoints
Watchpoints halt execution when a specified memory location's value changes:

```gdb
(gdb) watch variable_name
```
```
#watch 
watch  
watch var ==2
#display 
display info [[
undisplay id  
#overwrite    
 set var x=4   
set var d.x=14
```


### Display Commands
Automatically display variable values after each step or continue command:

```gdb
(gdb) display variable_name
```

## 5. Call
### Function Calls
You can call functions manually during a debugging session to inspect or modify the program's state:

```gdb
(gdb) call function_name(args)
```
This can be useful for testing functions in isolation.

## 6. Stack Smash
### Stack Smashing
Stack smashing occurs when a program writes more data to a buffer located on the stack than it was allocated, potentially overwriting return addresses or other control information.

### GDB and Stack Smashing
GDB can help identify stack smashing by detecting stack corruption and stopping the program:

```gdb
(gdb) run
```
Program received signal SIGSEGV, Segmentation fault.

## 7. Segmentation Fault
### Overview
A segmentation fault occurs when a program tries to access memory that it shouldn't. This can happen due to dereferencing null or invalid pointers, buffer overflows, or other memory access issues.

### Debugging Segmentation Faults
Use GDB to locate the cause:

```gdb
(gdb) run
(gdb) backtrace  # Shows the call stack at the point of crash
```

## 8. Reverse Debugging
### Overview
Reverse debugging allows you to step backward through the program's execution, which can be incredibly useful for identifying the source of an error.

Reverse Commands
```gdb
(gdb) reverse-step
(gdb) reverse-continue
```
These commands are not always available, depending on your GDB version and whether the program is compiled with reverse debugging support.


```
record 
reverse-continue (‘rc’) — Continue program being debugged but run it in reverse.
reverse-finish — Execute backward until just before the selected stack frame is called.
reverse-next (‘rn’) — Step program backward, proceeding through subroutine calls.
reverse-step (‘rs’) — Step program backward until it reaches the beginning of a previous source line.
```


## 9. Remote Debugging on Raspberry Pi
### Setup
Remote debugging involves running GDB on a host machine and controlling a target device (e.g., Raspberry Pi) over a network.

GDB Server on Raspberry Pi
On the Raspberry Pi, start GDB server:

```bash
gdbserver :1234 program
```
This starts the program on the Pi and waits for a GDB connection on port 1234.

Connecting from Host
On the host machine:

```gdb
gdb program
(gdb) target remote pi_address:1234
```
Replace pi_address with the Raspberry Pi's IP address.

## 10. Debug on Process Over Raspberry Pi
Attaching to a Running Process
You can attach GDB to a running process using its PID (Process ID):

```gdb
gdb program
(gdb) attach PID
```
This allows you to debug without restarting the process.

## 11. File and Commands
### Loading Core Dumps
To analyze a core dump file:

```gdb
gdb program corefile
```

### Scripting with Commands
You can use command files to automate GDB sessions:
```gdb
gdb -x commands.gdb program
```
Where commands.gdb contains GDB commands.

12. GDB Shell and Python
### GDB Shell
GDB provides a shell interface to execute system commands:

```gdb
(gdb) shell command
```
### Python Scripting
GDB can be extended with Python scripts for custom debugging tasks:

```python
# Sample Python script for GDB
import gdb

class HelloWorld(gdb.Command):
    def __init__(self):
        super(HelloWorld, self).__init__("hello", gdb.COMMAND_USER)

    def invoke(self, arg, from_tty):
        gdb.write("Hello, World!\n")

HelloWorld()
```
Load this script in GDB using:

```gdb
(gdb) source script.py
```
## 13. GDB ARM
### Cross-Debugging
For ARM-based systems, such as Raspberry Pi, you may need a cross-debugger:

```bash
arm-none-eabi-gdb program
This is especially relevant for embedded systems development.
```

## 14. Core Dump
### Generating Core Dumps
Core dumps are files that capture the memory state of a running program at a particular time, typically when the program crashes.

To enable core dumps:

```bash
ulimit -c unlimited  # Remove core dump size limit
```
To generate a core dump, you can either configure the system to do so on a crash or manually create one using:

```bash
kill -SIGSEGV PID
Replace PID with the process ID of the program.
```
### Analyzing Core Dumps
To analyze a core dump:

```gdb
gdb program corefile
```
This command loads the core dump into GDB, allowing you to inspect the state of the program at the time of the crash.

