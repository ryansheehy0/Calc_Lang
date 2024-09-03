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
Variables are case sensitive and can only have alphabetical characters

```C++
x = 10
y = 10
```

## Printing calculations

```C++
200 / 4 * (x * y)
```

## Comments
Everything after `#` is a comment

## Predefined variables
- pi = 3.141592654
- e = 2.718281828

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
- Test 6
	- Handle decimal points
	- Add predefined variables
	- Adjust line numbers
- Test 7
	- Add comments

## Future features
- Printing strings with `"`s
- More functions
	- sqrt()
	- % for fmod in cmath
	- abs()
	- floor(), ceil(), trunc() for truncate
	- log(), ln()
	- sin(), cos(), tan()
		- Radian versions
		- Inverse
		- cosh
	- fact() for factorial. Should support decimal numbers.
	- rand outputs random number from 0 to 1
- imports
	- import filepath
	- Just copies and pastes the file at that location
	- Need pragma once stuff. Do by default.

## Syntax Highlighting
- 10 or 11 root groups
This is in order.
- Comments. Green. comment.line.number-sign
	- `#.*`
- Variables. Light blue. variable.other.cl
	- `[a-zA-Z]`
- Operations. White. keyword.operator.cl
	- `[\^\*\/\+\-\=]`
- Literals. Light green. constant.numeric
	- `[0123456789.-]`
- Parenthesis. Yellow
	- `[()]`