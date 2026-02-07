# Pointers (C / C++)

## What is a Pointer?
A pointer stores the address of another variable.

## Declaration
```c
int *p;
```

## Example
```c
int x = 10;
int *p = &x;
```

## Dereferencing
```c
printf("%d", *p);
```

## Pointer Arithmetic
- p + 1
- p - 1

## Pointers vs References (C++)
```cpp
int &ref = x;
```

## Common Errors
- Uninitialized pointers
- Dangling pointers