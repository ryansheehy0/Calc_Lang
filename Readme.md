# Calc Lang
A very simple calculator programming language used to learn how compilers work.
- You can only create variables and print results.

## Order of Operations

| Order | Symbol     | Description                 |
|-------|------------|-----------------------------|
| 1     | `()`s      | Parenthesis                 |
| 2     | `^`        | Exponents                   |
| 3     | `xy`       | Implicit multiplication     |
| 4     | `*` or `/` | Multiplication and division |
| 5     | `+` or `-` | Addition and subtraction    |
| 6     | `=`        | Assignment                  |

## Creating variables
- Variables are case sensitive and can only have alphabetical characters

```C++
x = 10
y = 10
```

## Printing calculations

```C++
200 / 4(x * y)
// Outputs: 0.5
```

## Comments
- There is only single line comments with `//`s

## Tests
- Test1
	- Creating variables
	- Simple calculation with 1 digit literals
- Test2
	- Multi digit literals
- Test3
	- Using variables
- Test4
	- Using parenthesis and implicit multiplication
- Test5
	- Using comments