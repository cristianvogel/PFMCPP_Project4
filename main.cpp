/*
Project 4: Part 4 / 9
 Chapter 4 Part 7
 Function/Constructor Overloading

 Create a branch named Part4
 
 Do not delete your previous main. you will be adding to it.

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 1) add pow() functions, and a powInternal() function to each of your UDTs
     a) your pow() functions should call powInternal()
     b) add a pow() whose argument type is the primitive your UDT owns.  the argument should be passed by copy.
     c) for each UDT in the file, your class should have pow() overloads that take that UDT as the function argument.
         the argument should be passed as const ref
         i.e. if you had UDTs named IntType, FloatType, DoubleType
             in your IntType class, you'd have:
                 pow(const IntType&),
                 pow(const FloatType&),
                 pow(const DoubleType&),
                 and pow(int)
     d) be sure to remember the rules about what member functions can be called on const objects.
             (const objects can only call their const member functions)
 
 2) your powInternal() function should do something like this in its body:    *val = std::pow( *val, arg );
         where 'arg' is the passed-in type, converted to whatever type your object is holding.
             if your UDT owns an int, then arg would be an int.
             if your UDT owns a float, then arg would be a float.
         std::pow's documentation is found here: https://en.cppreference.com/w/cpp/numeric/math/pow so be sure to include
             the proper header file listed there.
 
 3) modify the Point class below to have Constructors that accept your UDTs.
     a) make the Constructor's UDT arguments initialize the Point class's two member variables.
     b) overload the multiply() function so it can accept each of your UDTs.  I've added an implementation you can mimick for this function.
     c) add a toString() function to the Point class that prints out the x and y members via std::cout.
 
 4) Add to main()
     a) use your new pow() function in main for all of your types and print out the results.
     b) use the Point class in main and multiply some Point instances with your UDTs
     c) use the Point::toString() function to print out the results.
 
 
 5) make sure it compiles without errors.
 
 You will need to use Forward Declaration and out-of-class definitions to complete this.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */
 
#include <cmath> 
#include <iostream> 
#include <string>
#include <vector>

struct IntType;
struct DoubleType;
struct FloatType;

struct Point
{
    Point( float x_, float y_ ) : x{ x_ }, y{ y_ } {}
 
    Point( const FloatType& );
    Point( const DoubleType& );
    Point( const IntType& );

    Point& multiply(float);
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
    const FloatType& powInternal( float );

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
   
    FloatType& add ( float );
    FloatType& subtract ( float );
    FloatType& multiply ( float );
    FloatType& divide ( float );

    const FloatType& pow ( float );
    const FloatType& pow ( double d_ ) { return pow(static_cast<float>(d_)); }
    const FloatType& pow ( int i_ ) { return pow(static_cast<float>(i_)); }
    const FloatType& pow (  FloatType& );
    const FloatType& pow (  DoubleType& );
    const FloatType& pow (  IntType& );

    operator float() const { return *pointerToFloatValue; } 

};


FloatType& FloatType::add ( float x )
{
    *pointerToFloatValue += x;
    return *this;
}

FloatType& FloatType::subtract ( const float y ) 
{ 
    *pointerToFloatValue -= y;
    return *this; 
}

FloatType& FloatType::multiply ( const float y) 
{ 
    *pointerToFloatValue *= y;
    return *this; 
}

FloatType& FloatType::divide ( const float y ) 
{ 
    *pointerToFloatValue /= y;
    if ( !(std::abs(y) > 0) ) 
    {
        std::cout <<    "\x1B[31m Divide-by-zero warning! \x1B[0m" << std::endl; 
    }   
    return *this;      
}

struct DoubleType
{
private:
    double* pointerToDoubleValue = nullptr;
    const DoubleType& powInternal( double );

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

    DoubleType& add ( double );
    DoubleType& subtract ( double );
    DoubleType& multiply ( double );
    DoubleType& divide ( double );

    const DoubleType& pow ( double );
    const DoubleType& pow ( float f_ ) { return pow(static_cast<double>(f_)); }
    const DoubleType& pow ( int i_ ) { return pow(static_cast<double>(i_)); }
    const DoubleType& pow ( FloatType& );
    const DoubleType& pow ( DoubleType& );
    const DoubleType& pow ( IntType& );

    operator double() const { return *pointerToDoubleValue; } 

};
DoubleType& DoubleType::add ( const double y)
{
    *pointerToDoubleValue += y;
    return *this;
}

DoubleType& DoubleType::subtract ( const double y) 
{ 
    *pointerToDoubleValue -= y;
    return *this; 
}

DoubleType& DoubleType::multiply ( const double y) 
{ 
    *pointerToDoubleValue *= y;
    return *this; 
}

DoubleType& DoubleType::divide ( const double y) 
{ 
    *pointerToDoubleValue /= y; 
    if (!(std::abs(y) > 0)) 
    { 
        std::cout <<    "\x1B[31m Divide-by-zero warning! \x1B[0m" << std::endl;
    } 
    return *this;      
}

struct IntType
{
private:
    int* pointerToIntValue = nullptr;
    const IntType& powInternal( int );

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

    IntType& add ( int );
    IntType& subtract ( int );
    IntType& multiply ( int );
    IntType& divide ( int );

    const IntType& pow ( int );
    const IntType& pow ( float f_ )  { return pow(static_cast<int>(f_)); }
    const IntType& pow ( double d_ ) { return pow(static_cast<int>(d_)); }
    const IntType& pow (  FloatType& );
    const IntType& pow (  DoubleType& );
    const IntType& pow (  IntType& );

    operator int() const { return *pointerToIntValue; } 
};


IntType& IntType::add ( const int y )
{
    *pointerToIntValue += y;
    return *this;
}

IntType& IntType::subtract ( const int y ) 
{ 
    *pointerToIntValue -= y;
    return *this;
}

IntType& IntType::multiply ( const int y ) 
{ 
    *pointerToIntValue *= y;
    return *this; 
}

IntType& IntType::divide ( const int y ) 
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

// Pow Implementations


const FloatType& FloatType::pow ( float x )
{
    powInternal( x );
    return *this;
}

const FloatType& FloatType::pow ( FloatType& ft ) 
{
    powInternal( static_cast<float>(ft) );
    return *this;
}

const FloatType& FloatType::pow ( IntType& it ) 
{
    powInternal( static_cast<float>(it) );
    return *this;
}

const FloatType& FloatType::pow ( DoubleType& dt ) 
{
    powInternal( static_cast<float>(dt) );
    return *this;
}

const DoubleType& DoubleType::pow ( double x )
{
    powInternal( x );
    return *this;
}

const DoubleType& DoubleType::pow ( DoubleType& dt )
{
    powInternal( static_cast<double>(dt) );
    return *this;
}

const DoubleType& DoubleType::pow ( FloatType& ft )
{
    powInternal( static_cast<double>(ft) );
    return *this;
}

const DoubleType& DoubleType::pow ( IntType& it )
{
    powInternal( static_cast<double>(it) );
    return *this;
}

const IntType& IntType::pow ( int x )
{
    powInternal( x );
    return *this;
}

const IntType& IntType::pow ( IntType& it ) 
{
    powInternal( static_cast<int>(it) );
    return *this;
}

const IntType& IntType::pow ( FloatType& ft ) 
{
    powInternal( static_cast<int>(ft) );
    return *this;
}

const IntType& IntType::pow ( DoubleType& dt ) 
{
    powInternal( static_cast<int>(dt) );
    return *this;
}

const FloatType& FloatType::powInternal( float y )
{ 
    if (pointerToFloatValue != nullptr)
    {
        *pointerToFloatValue = std::pow( *pointerToFloatValue , y ); 
    }
    return *this; 
}

const IntType& IntType::powInternal( int y )
{ 
    if (pointerToIntValue != nullptr)
    {
        *pointerToIntValue = static_cast<int>( std::pow( *pointerToIntValue , y ));
    }
    return *this; 
}

const DoubleType& DoubleType::powInternal( double y ) 
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

Point& Point::multiply(float m)
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

int main()
{   
    std::string div = "\n \x1B[35m ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \x1B[0m \n";
    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 0.5 );
    IntType it ( 2 );
    
    Point p1 (2.0f, 20.0f);
    Point p2 (25.0f, 50.0f);
    
    std::cout << "FloatType pow ( 2.0f ) = " << ft.pow( 2.0f ) << std::endl; 
    std::cout << "FloatType pow ( 2 ) = " << ft.pow( 2 ) << std::endl; 
    std::cout << "FloatType pow ( 0.5 ) = " << ft.pow( 0.5 ) << std::endl; 
    std::cout << "FloatType pow ( DoubleType with value of " << dt << " ) = " << ft.pow( dt ) << std::endl; 
    std::cout << "FloatType pow (IntType with value of " << it << " ) = " << ft.pow ( it ) << std::endl;
    std::cout << "FloatType pow ( FloatType with value of " << ft << " ) = " << ft.pow( ft ) << std::endl; 

    std::cout << "FloatType add result=" <<  ft.add( 2 )  << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f )  << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ) << std::endl;
    std::cout << "FloatType divide result=" <<  ft.divide( 16.0f) << div << std::endl;

    std::cout << "DoubleType pow ( 2.5 ) = " << dt.pow( 2.5 ) << std::endl; 
    std::cout << "DoubleType pow ( 2 ) = " << dt.pow( 2 ) << std::endl; 
    std::cout << "DoubleType pow ( 0.5f ) = " << dt.pow(0.5 ) << std::endl; 
    std::cout << "DoubleType pow ( FloatType with value of " << ft << ") /1000 = " << dt.pow( ft.divide(1000) ) << std::endl; 
    std::cout << "DoubleType pow (IntType with value of " << it << " ) = " << dt.pow ( it ) << std::endl;
    std::cout << "DoubleType pow ( DoubleType with value of " << dt << " ) = " << dt.pow( dt ) << std::endl; 

    std::cout << "DoubleType add result=" << dt.add(2.0) << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0) << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.5) << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(1.5) << div << std::endl;

    std::cout << "IntType pow ( 2.5 ) = " << it.pow( 2.5 ) << std::endl; 
    std::cout << "IntType pow ( 2 ) = " << it.pow(2) << std::endl; 
    std::cout << "IntType pow ( 4.0f ) = " << it.pow( 2.0f ) << std::endl; 
    std::cout << "IntType pow ( FloatType with value of " << ft << ") = " << it.pow( ft ) << std::endl; 
    std::cout << "IntType pow (DoubleType with value of " << dt << " ) = " << it.pow ( dt ) << std::endl;
    std::cout << "IntType pow ( IntType with value of " << it << " ) = " << it.pow( it ) << std::endl; 
    std::cout << "IntType add result=" << it.add(8) << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2) << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2) << std::endl;
    std::cout << "IntType divide result=" << it.divide(0) << std::endl << std::endl;

    //my example of a rounding loss causing an int divide by zero in the chain
    std::cout << "\x1B[32m Chain calculation = " << ( it.multiply(1000).divide(static_cast<int>(0.125f)).subtract(10).add(100) ) << div << std::endl;

    // some Point calculations
    std::cout << "\x1B[36m Point " << p1.toString() << " multiplication with FloatType > Point \x1B[0m" << (p1.multiply( ft )).toString() << std::endl;
    std::cout << "\x1B[36m Point " << p2.toString() << " multiplication with DoubleType > Point \x1B[0m" << (p2.multiply( dt )).toString() << std::endl;
    std::cout << "\x1B[36m Point " << p1.toString() << " multiplication with IntType > Point \x1B[0m" << (p1.multiply( it )).toString() << std::endl;
    
    
    std::cout << "good to go!" << std::endl;
}
