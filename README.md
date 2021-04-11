# complex-numbers-class

Write a C++ class to store complex numbers, z=x+iy ( as part of Assignment 4 OOP in C++)
The data for each object should contain two doubles to represent the real and imaginary part of z.

Your class should demonstrate usage of operator overloading for arithmetic operations (on complex numbers) and overload the insertion operator to insert complex numbers into an ostream, and an extraction operator to read a complex number from an istream.
The last two functions should be friends of the class.
The main program should demonstrate use of the class through declaring and using objects (or reading them from input!); for simplicity, please use a=3+4i and b=1−2i in all your tests.
You should modify function parameters with const wherever appropriate.

Guidelines:
  - Four member functions, each returning real part, imaginary part, modulus and argument
  - Member function to return complex conjugate 
  - Functions that overload the + and - operators to perform addition and subtraction of 2 complex numbers 
  - Functions that overload the * and / operators to perform multiplication and division of 2 complex numbers 
  - Consistent use of const modifier in function declarations for two purposes: 1 - prevent parameters being modified; 2 - prevent member data being modified 
  - A non-member function to allow insertion of complex objects into an ostream (must be a friend of the class and output should be appropriately formatted to handle complex numbers with negative imaginary parts)
  - A non-member function to allow extraction of complex objects from an istream (must be a friend of the class and should be able to handle complex numbers of the form a+ib and a−ib . Assume a and b to be specified even if zero.)
