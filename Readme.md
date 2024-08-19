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
	- Creating variables
	- Simple calculation with 1 digit literals
- Test2
	- Multi digit literals
	- Multiple outputs
- Test3
	- Using variables
- Test4
	- Using parenthesis

## Future features
- Single line comments with `//`s
- Implicit multiplication
	- | `xy`       | Implicit multiplication     |
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