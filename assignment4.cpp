// PHYS 30762 Programming in C++
// Assignment 4: a class to store and do arithmetic operations with complex numbers 
//Afonso Sequeira ID:10139091

#include<iostream>
#include<cmath>
#include<string>

//class for handling complex numbers of the form a + ib or a + bi
class complex
{
private:
  double re,im;
public:
    //Member functions
    // Constructors (default and parametrized) & destructor
    complex(){re=im=0;}
    complex(double real_part, double im_part){re=real_part; im=im_part;}
    ~complex(){}

    // Return real component
    double get_real () const {
        return re;
    }
    // Return imaginary component
    double get_imaginary () const {
        return im;
    }
    // Return modulus
    double modulus () const {
        double mod;
        mod = sqrt(pow(re, 2) + pow(im, 2));
        return mod;
    }
    // Return argument (in rads)
    double argument () const {
        double arg;
        arg = atan(im/re);
        if ((im * re > 0 && re < 0) || (im * re < 0 && re < 0)) {
            arg += atan(1)*4 ;
        }
        return arg;
    }
    // Return complex conjugate (as a complex class object)
    complex comp_conjugate () const {
        complex temp(re, -im);
        return temp;
    }
    // Overload + operator for addition 
    complex operator+(const complex &num) const  {
        complex temp(re + num.re , im + num.im);
        return temp;
    }
    // Overload - operator for subtraction
    complex operator-(const complex &num) const  {
        complex temp(re - num.re , im - num.im);
        return temp;
    }
    // Overload * operator for multiplication, z1*z2
    complex operator*(const complex &num) const  {
        complex temp(re * num.re - im * num.im , re * num.im + im * num.re);
        return temp;
    }
    // Overload / operator for division, z1/z2
    complex operator/(const complex &num) const  {
        complex conj{num.comp_conjugate()};
        complex temp{ (*this * conj).get_real() / pow(num.modulus(),2),
                     (*this * conj).get_imaginary() / pow(num.modulus(), 2)};
        return temp;
    }
    // Make functions to overload operator<< and operator>> friends of this class
    friend std::ostream & operator<<(std::ostream &os, const complex &z);
    friend std::istream& operator>>(std::istream &is, complex &z);
};

//Overload operator<< to handle complex numbers and output in the form a + ib.
//Change format out output a - ib or a + ib depending on sign of imaginary part
std::ostream& operator<<(std::ostream &os, const complex &z) {
    if (z.im > 0){
        os << z.re << " + i" << z.im;
    }
    else if (z.im == 0) {
        os << z.re;
    }
    else {
        os << z.re << " - i" << - z.im;
    }
    return os;
}

//Overload operator>> to be able to extract a complex number from the input stream. 
//The function handles input separated by whitespace or in tight format, and can handle both forms
//a + ib and a + bi
std::istream& operator>>(std::istream &is, complex &z) {
    char sign;
    std::string rest_of_input;
    is >> z.re >> std::ws >> sign >> std::ws >> rest_of_input;
    //check if the second part of the input start with i (a +- ib)
    if (rest_of_input[0] == 'i') {
        //delete first element (i) and convert the rest to a double
        rest_of_input.erase(0,1); 
        z.im = std::stod(rest_of_input);
    }
    //if in format a +- bi
    else {
        //delete last element (i)
        rest_of_input.pop_back(); 
        z.im = std::stod(rest_of_input);
    }
    if (sign == '-') {
        z.im = - z.im;
    }
    return is;
}

//main function
int main () {
    //create objects a,b,c
    complex a(3,4);
    complex b(1,-2);
    complex c;
    std::cout << "Please input a complex number in the form a +/- ib or a +/- bi."
                   << "(Whitespace is optional) " << std::endl;

    //use overloaded operator >> to create number c
    std::cin >> c;

    //Use overloaded operator << to print out numbers
    std::cout << " a = " << a << std::endl;
    std::cout << " b = " << b << std::endl;
    std::cout << " c = " << c << std::endl;

    //Demonstrate use of memeber functions on objects a, b and c
    std::cout << "For a: \n - Real part: " << a.get_real() 
                << "\n - Imaginary part: " << a.get_imaginary()
                << "\n - Argument (rad): " << a.argument()
                << "\n - Modulus: " << a.modulus()
                << "\n - And it's complex conjugate is: " << a.comp_conjugate() << std::endl;

    std::cout << "For b: \n - Real part: " << b.get_real() 
                << "\n - Imaginary part: " << b.get_imaginary()
                << "\n - Argument (rad): " << b.argument()
                << "\n - Modulus: " << b.modulus()
                << "\n - And it's complex conjugate is: " << b.comp_conjugate() << std::endl;
    
    std::cout << "For c: \n - Real part: " << c.get_real() 
                << "\n - Imaginary part: " << c.get_imaginary()
                << "\n - Argument (rad): " << c.argument()
                << "\n - Modulus: " << c.modulus()
                << "\n - And it's complex conjugate is: " << c.comp_conjugate() << std::endl;
    
    //show use of overloaded operators +-*/ on a and b
    std::cout << " a + b = " << a+b 
                <<"\n a - b = " << a-b
                <<"\n a * b = " << a*b
                <<"\n a / b = " << a/b << std::endl;
    return 0;
}