# Calc Lang
A very simple calculator programming language used to learn how compilers work.
- Inspiration: https://www.youtube.com/watch?v=unh6aK8WMwM
- You can only assign variables and print results.

## Order of Operations

| Symbol     | Description                 |
|------------|-----------------------------|
| `()`s      | Parenthesis                 |
| `^`        | Exponents                   |
| `*` or `/` | Multiplication and division |
| `+` or `-` | Addition and subtraction    |
| `=`        | Assignment                  |

## Creating variables
- Variables are case sensitive and can only have alphabetical characters

```C++
x = 10
y = 10
```

## Printing calculations

```C++
200 / 4 * (x * y)
```

## Tests
- Test1
	- Printing one line of calculations with 1 digit literals
- Test2
	- Printing multiple lines of 1 digit literals
- Test3
	- Using multi digit literals
- Test4
	- Using parenthesis
- Test4
	- Assigning and using variables

- Test 5
	- Handling negative numbers

## Future features
- Predefined variables
- Single line comments with `//`s
- Printing strings with `"`s
- More functions
	- sqrt()
	- % or mod()
	- abs() or | |
	- floor(), ceil(), trunc() for truncate
	- log(), ln()
	- sin(), cos(), tan()
		- Radian versions
		- Inverse
		- cosh
	- x! for factorial
	- rand() outputs random number from 0 to 1
- imports
	- import filepath
	- Just copies and pastes the file at that location
- Syntax highlighting

## Probably Not
- Implicit multiplication. `xy`
	- Probably not. What if you have 3 variables. `x`, `y`, and `xy`? How do you know if you are doing implicit multiplication or using another variable?
	- There is also a confusion for the order of operations
	- Maybe have a space between them?