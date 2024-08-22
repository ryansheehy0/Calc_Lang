# Calc Lang
A very simple calculator programming language used to learn how compilers work.
- You can only create variables and print results.

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
	- Printing multiple lines of 1 or more digit literals


- Creating variables
- Simple calculation with 1 digit literals
- Multi digit literals
- Multiple outputs
- Using variables
- Using parenthesis

## Future features
- Single line comments with `//`s
- Implicit multiplication. `xy`
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
- Predefined variables
	- e, pi
	- Maybe not. How many decimals do you guarantee?
		- Users can redefine them
- imports
	- import filepath
	- Just copies and pastes the file at that location