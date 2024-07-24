# GDB

## how to make it work
```
g++ -g -o HelloWorld main.cpp
gdb HelloWorld
```

```gdb
run
break main
n
n
print x
list
layout src
layout asm
x/32w $rsp
exit
```

```gdb
-start   s
run        r
-refresh
-continue   c
-next       n
-step       s
-finish     fin
-quit
```



