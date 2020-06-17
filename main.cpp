/*
Project 4 - Part 6 / 9
Video: Chapter 5 Part 3
 
Create a branch named Part6
 
 Lambdas
 
    Do not delete your previous main. you will be adding to it.

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 1) add two member functions named "apply()" to each of your Heap-Allocated Numeric Type wrappers.
         both apply() functions should work with chaining
 
 2) One of the apply() functions should takes a std::function<> object as the function argument.
    the std::function<> object should return *this;
 
 3) the other apply() function should take a function pointer. 
    the function pointer should return void.
 
 4) Make both of the member functions's Callable Function Parameter use your owned object as it's single parameter.
         e.g. if you manage your owned object via std::unique_ptr<T>, you'd use this for your std::function argument:
             std::function< OwnedT&(std::unique_ptr<T>&)>
             
         if you managed your owned object via a raw pointer, you'd use this for your std::function argument:
             std::function<OwnedT&(T&)>    
 
 5) call that Callable Function Parameter in the apply() member function.
         be sure to practice safe std::function usage (make sure it's not a nullptr function being called)
 
 6) copy the part6() function below and paste it after part4()
 7) call part6() after part4() is called at the end of main().

 8) fill in the missing arguments in part6 such that you produce the expected output.

 9) Make your lambda & free function update the value of your held object
 
 
build/run to make sure you don't have any errors
 
 If you need to see an example, look at https://bitbucket.org/MatkatMusic/pfmcpptasks/src/master/Projects/Project4/Part6Example.cpp
 */

void part6()
{
    FloatType ft3(3.0f);
    DoubleType dt3(4.0);
    IntType it3(5);
    
    std::cout << "Calling FloatType::apply() using a lambda (adds 7.0f) and FloatType as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;
    ft3.apply( [](){} );
    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "Calling FloatType::apply() using a free function (adds 7.0f) and void as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;
    ft3.apply(myFloatFreeFunct);
    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling DoubleType::apply() using a lambda (adds 6.0) and DoubleType as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;
    dt3.apply( [](){} );
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "Calling DoubleType::apply() using a free function (adds 6.0) and void as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;
    dt3.apply(myDoubleFreeFunct);
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling IntType::apply() using a lambda (adds 5) and IntType as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;
    it3.apply( [](){} );
    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "Calling IntType::apply() using a free function (adds 5) and void as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;
    it3.apply(myIntFreeFunct);
    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "---------------------\n" << std::endl;    
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.



FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^4 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
Power tests with FloatType 
pow(ft1, floatExp) = 2^2 = 4
pow(ft1, itExp) = 4^2 = 16
pow(ft1, ftExp) = 16^2 = 256
pow(ft1, dtExp) = 256^2 = 65536
---------------------

Power tests with DoubleType 
pow(dt1, doubleExp) = 2^2 = 4
pow(dt1, itExp) = 4^2 = 16
pow(dt1, ftExp) = 16^2 = 256
pow(dt1, dtExp) = 256^2 = 65536
---------------------

Power tests with IntType 
pow(it1, intExp) = 2^2 = 4
pow(it1, itExp) = 4^2 = 16
pow(it1, ftExp) = 16^2 = 256
pow(it1, dtExp) = 256^2 = 65536
===============================

Point tests with float argument:
Point { x: 3, y: 6 }
Multiplication factor: 6
Point { x: 18, y: 36 }
---------------------

Point tests with FloatType argument:
Point { x: 3, y: 3 }
Multiplication factor: 3
Point { x: 9, y: 9 }
---------------------

Point tests with FloatType argument:
Point { x: 3, y: 4 }
Multiplication factor: 4
Point { x: 12, y: 16 }
---------------------

Point tests with IntType argument:
Point { x: 3, y: 4 }
Multiplication factor: 5
Point { x: 15, y: 20 }
---------------------

Calling FloatType::apply() using a lambda (adds 7.0f) and FloatType as return type:
ft3 before: 3
ft3 after: 10
Calling FloatType::apply() using a free function (adds 7.0f) and void as return type:
ft3 before: 10
ft3 after: 17
---------------------

Calling DoubleType::apply() using a lambda (adds 6.0) and DoubleType as return type:
dt3 before: 4
dt3 after: 10
Calling DoubleType::apply() using a free function (adds 6.0) and void as return type:
dt3 before: 10
dt3 after: 16
---------------------

Calling IntType::apply() using a lambda (adds 5) and IntType as return type:
it3 before: 5
it3 after: 10
Calling IntType::apply() using a free function (adds 5) and void as return type:
it3 before: 10
it3 after: 15
---------------------

good to go!

Use a service like https://www.diffchecker.com/diff to compare your output. 
*/



#include <cmath> 
#include <iostream> 
#include <string>

struct IntType;
struct DoubleType;
struct FloatType;

struct Point
{
    Point( float x_, float y_ ) : x{ x_ }, y{ y_ } {}
 
    Point( const FloatType& );
    Point( const DoubleType& );
    Point( const IntType& );

    Point& multiply( float );
    Point& multiply(const FloatType& m);
    Point& multiply(const DoubleType& m);
    Point& multiply(const IntType& m);

    std::string toString() 
    { 
        std::string result = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
        return result;
    }

private:
    float x{0}, y{0};
};

struct FloatType
{
private:
    float* pointerToFloatValue = nullptr;
    FloatType& powInternal( float );

public:
    FloatType(float floatIn )
    {
        pointerToFloatValue = new float( floatIn );
    }
    
    ~FloatType()
    {
        delete pointerToFloatValue;
        pointerToFloatValue = nullptr;
    }
   
    FloatType& operator+= ( const float x )
    {
        *pointerToFloatValue += x;
        return  *this;
    }

    FloatType& operator-= ( const float x )
    {
        *pointerToFloatValue -= x;
        return  *this;
    }

    FloatType& operator*= ( const float x )
    {
        *pointerToFloatValue -= x;
        return  *this;
    }

    FloatType& operator/= ( const float x )
    {
        *pointerToFloatValue /= x;
        if (std::abs(x) <= 1e-32f ) //smallest 32-bit non-zero number
        {
            std::cout <<    "\x1B[31m Divide-by-zero warning! \x1B[0m" << std::endl; 
        }   
        return *this;      
    }

    FloatType& pow ( const float );
    FloatType& pow ( const double d_ ) { return pow(static_cast<float>(d_)); }
    FloatType& pow ( const int i_ ) { return pow(static_cast<float>(i_)); }
    FloatType& pow ( const FloatType& ft_ );
    FloatType& pow ( const DoubleType& dt_ );
    FloatType& pow ( const IntType& ); 

    operator float() const { return *pointerToFloatValue; }
};

struct IntType
{
private:
    int* pointerToIntValue = nullptr;
    IntType& powInternal( int );

public:
    IntType( int intIn )
    {
        pointerToIntValue = new int ( intIn );
    }
    ~IntType()
    {
        delete pointerToIntValue;
        pointerToIntValue = nullptr;
    }

    IntType& operator+= ( const int y )
    {
        *pointerToIntValue += y;
        return *this;
    }

    IntType& operator-= ( const int y ) 
    { 
        *pointerToIntValue -= y;
        return *this;
    }

    IntType& operator*= ( const int y ) 
    { 
        *pointerToIntValue *= y;
        return *this; 
    }

    IntType& operator/= ( const int y ) 
    { 
        if (y != 0 ) 
        {
            *pointerToIntValue /=y; 
        } 
        else 
        {
            std::cout << "\x1B[31m Cannot divide Int by Zero! \x1B[0m" << std::endl;
        }
        return *this;
    }

    IntType& pow ( const int );
    IntType& pow ( const float f_ )  { return pow(static_cast<int>(f_)); }
    IntType& pow ( const double d_ ) { return pow(static_cast<int>(d_)); }
    IntType& pow ( const FloatType& );
    IntType& pow ( const DoubleType& );
    IntType& pow ( const IntType& );

    operator int() const { return *pointerToIntValue; } 
};

struct DoubleType
{
private:
    double* pointerToDoubleValue = nullptr;
    DoubleType& powInternal( double );

public:
    DoubleType(double doubleIn )
    {
        pointerToDoubleValue = new double( doubleIn );
    }
    
    ~DoubleType()
    {
        delete pointerToDoubleValue;
        pointerToDoubleValue = nullptr;
    }

    DoubleType& operator+= ( const double y)
    {
        *pointerToDoubleValue += y;
        return *this;
    }

    DoubleType& operator-= ( const double y) 
    { 
        *pointerToDoubleValue -= y;
        return *this; 
    }

    DoubleType& operator*= ( const double y) 
    { 
        *pointerToDoubleValue *= y;
        return *this; 
    }

    DoubleType& operator/= ( const double y) 
    { 
        *pointerToDoubleValue /= y; 
        if (std::abs(y) <= 1e-32) //smallest 32-bit non-zero number
        { 
            std::cout <<    "\x1B[31m Divide-by-zero warning! \x1B[0m" << std::endl;
        } 
        return *this;      
    }

    DoubleType& pow ( const double );
    DoubleType& pow ( const float f_ ) { return pow(static_cast<double>(f_)); }
    DoubleType& pow ( const int i_ ) { return pow(static_cast<double>(i_)); }
    DoubleType& pow ( const FloatType& );
    DoubleType& pow ( const DoubleType& );
    DoubleType& pow ( const IntType& );

    operator double() const { return *pointerToDoubleValue; } 

};

// Pow Implementations
FloatType& FloatType::pow ( float x )
{
    return powInternal( x );
}

FloatType& FloatType::pow ( const FloatType& ft ) 
{  
    return powInternal( static_cast<float>(ft) );
}

FloatType& FloatType::pow ( const DoubleType& dt ) 
{
    return powInternal( static_cast<float>(dt) );
}

FloatType& FloatType::pow ( const IntType& it ) 
{
    return powInternal( static_cast<float>(it) );
}

DoubleType& DoubleType::pow ( const double x )
{
    return powInternal( x );
}

DoubleType& DoubleType::pow ( const DoubleType& dt )
{
    return powInternal( static_cast<double>(dt) );
}

DoubleType& DoubleType::pow ( const FloatType& ft )
{
    return powInternal( static_cast<double>(ft) );
}

DoubleType& DoubleType::pow ( const IntType& it )
{
    return  powInternal( static_cast<double>(it) );
}

IntType& IntType::pow ( const int x )
{
    return powInternal( x );
}

IntType& IntType::pow ( const IntType& it ) 
{
    return powInternal( static_cast<int>(it) );
}

IntType& IntType::pow (const FloatType& ft ) 
{
    return powInternal( static_cast<int>(ft) );
}

IntType& IntType::pow (const DoubleType& dt ) 
{   
    return powInternal( static_cast<int>(dt) );
}

FloatType& FloatType::powInternal( float y )
{ 
    if (pointerToFloatValue != nullptr)
    {
        *pointerToFloatValue = std::pow( *pointerToFloatValue , y ); 
    }
    return *this;
}

IntType& IntType::powInternal( int y )
{ 
    if (pointerToIntValue != nullptr)
    {
        *pointerToIntValue = static_cast<int>( std::pow( *pointerToIntValue , y ));
    }
    return *this;
}

DoubleType& DoubleType::powInternal( double y ) 
{ 
    if (pointerToDoubleValue != nullptr)
    {
        *pointerToDoubleValue = static_cast<double>( std::pow( *pointerToDoubleValue , y ));
    }
    return *this;
}

// Point UDT forwarding constructors
Point::Point( const FloatType& ft) : Point(ft, ft)
{    
}

Point::Point( const DoubleType& dt) : Point(static_cast<float>(dt), static_cast<float>(dt) )
{       
}

Point::Point( const IntType& it) : Point(static_cast<float>(it), static_cast<float>(it))
{      
}

// Point Implementations 
Point& Point::multiply( float m )
{
    x *= m;
    y *= m;
    return *this;
}

Point& Point::multiply( const FloatType& m) 
{
    return multiply(static_cast<float>(m));
}

Point& Point::multiply( const DoubleType& m)
{
    return multiply(static_cast<float>(m));
}

Point& Point::multiply( const IntType& m) 
{
    return multiply(static_cast<float>(m));
}

#include <iostream>
#include <memory>

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^3 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( it ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( pi ).multiply( dt ).subtract( ft ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( ft ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( dt ).add( ft ).multiply( 24 ) << std::endl;
}

void part4()
{
    // ------------------------------------------------------------
    //                          Power tests
    // ------------------------------------------------------------
    FloatType ft1(2);
    DoubleType dt1(2);
    IntType it1(2);    
    int floatExp = 2.0f;
    int doubleExp = 2.0;
    int intExp = 2;
    IntType itExp(2);
    FloatType ftExp(2.0f);
    DoubleType dtExp(2.0);
    
    // Power tests with FloatType
    std::cout << "Power tests with FloatType " << std::endl;
    std::cout << "pow(ft1, floatExp) = " << ft1 << "^" << floatExp << " = " << ft1.pow(floatExp)  << std::endl;
    std::cout << "pow(ft1, itExp) = " << ft1 << "^" << itExp << " = " << ft1.pow(itExp)  << std::endl;
    std::cout << "pow(ft1, ftExp) = " << ft1 << "^" << ftExp << " = " << ft1.pow(ftExp)  << std::endl;    
    std::cout << "pow(ft1, dtExp) = " << ft1 << "^" << dtExp << " = " << ft1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;  

    // Power tests with DoubleType
    std::cout << "Power tests with DoubleType " << std::endl;
    std::cout << "pow(dt1, doubleExp) = " << dt1 << "^" << doubleExp << " = " << dt1.pow(intExp)  << std::endl;
    std::cout << "pow(dt1, itExp) = " << dt1 << "^" << itExp << " = " << dt1.pow(itExp)  << std::endl;
    std::cout << "pow(dt1, ftExp) = " << dt1 << "^" << ftExp << " = " << dt1.pow(ftExp)  << std::endl;    
    std::cout << "pow(dt1, dtExp) = " << dt1 << "^" << dtExp << " = " << dt1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;    

    // Power tests with IntType
    std::cout << "Power tests with IntType " << std::endl;
    std::cout << "pow(it1, intExp) = " << it1 << "^" << intExp << " = " << it1.pow(intExp)  << std::endl;
    std::cout << "pow(it1, itExp) = " << it1 << "^" << itExp << " = " << it1.pow(itExp)  << std::endl;
    std::cout << "pow(it1, ftExp) = " << it1 << "^" << ftExp << " = " << it1.pow(ftExp)  << std::endl;    
    std::cout << "pow(it1, dtExp) = " << it1 << "^" << dtExp << " = " << it1.pow(dtExp)  << std::endl;    
    std::cout << "===============================\n" << std::endl; 

    // ------------------------------------------------------------
    //                          Point tests
    // ------------------------------------------------------------
    FloatType ft2(3.0f);
    DoubleType dt2(4.0);
    IntType it2(5);
    float floatMul = 6.0f;

    // Point tests with float
    std::cout << "Point tests with float argument:" << std::endl;
    Point p0(ft2, floatMul);
    p0.toString();   
    std::cout << "Multiplication factor: " << floatMul << std::endl;
    p0.multiply(floatMul); 
    p0.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with FloatType
    std::cout << "Point tests with FloatType argument:" << std::endl;
    Point p1(ft2, ft2);
    p1.toString();   
    std::cout << "Multiplication factor: " << ft2 << std::endl;
    p1.multiply(ft2); 
    p1.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with DoubleType
    std::cout << "Point tests with FloatType argument:" << std::endl;
    Point p2(ft2, static_cast<float>(dt2));
    p2.toString();   
    std::cout << "Multiplication factor: " << dt2 << std::endl;
    p2.multiply(dt2); 
    p2.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with IntType
    std::cout << "Point tests with IntType argument:" << std::endl;
    Point p3(ft2, static_cast<float>(dt2));
    p3.toString();   
    std::cout << "Multiplication factor: " << it2 << std::endl;
    p3.multiply(it2); 
    p3.toString();   
    std::cout << "---------------------\n" << std::endl;
}

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt.value << std::endl;
    std::cout << "Initial value of it: " << it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    part3();
    part4();

    std::cout << "good to go!\n";

    return 0;
}
