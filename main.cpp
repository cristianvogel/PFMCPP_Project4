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

struct Point
{
    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }
private:
    float x{0}, y{0};
};

#include <cmath> 
#include <iostream> // to print a divide-by-zero console message

struct IntType;
struct DoubleType;

struct FloatType
{
private:
    float* pointerToFloatValue = nullptr;

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

    FloatType& pow ( float );
    FloatType& pow ( const FloatType& );
    FloatType& pow ( const IntType& );
    FloatType& pow ( const DoubleType& );

    const FloatType& powInternal( float ) const;
    const FloatType& powInternal( const FloatType& ) const;
    const FloatType& powInternal( const DoubleType& ) const { return *this; }
    const FloatType& powInternal( const IntType& ) const { return *this; }

    operator float() { return *pointerToFloatValue; }
};

FloatType& FloatType::pow ( float x )
{
    FloatType::powInternal( x );

    std::cout << ".. Call to pow ( float ) result: " << *(this->pointerToFloatValue )<< "\n";
    return *this;
}

FloatType& FloatType::pow ( const FloatType& y ) 
{
    FloatType::powInternal( y );
    return *this; 
}

FloatType& FloatType::pow ( const DoubleType& y ) 
{
    FloatType::powInternal( y );
    return *this; 
}

FloatType& FloatType::pow ( const IntType& y ) 
{
    FloatType::powInternal( y );
    return *this; 
}

const FloatType& FloatType::powInternal( float y ) const
{ 
    *pointerToFloatValue = static_cast<float>( std::pow( *pointerToFloatValue, y ));

    std::cout << "\n.. call powInternal ( float ) " << *(this->pointerToFloatValue )<< "\n";

    return *this; 
}


const FloatType& FloatType::powInternal( const FloatType& y ) const
{ 
    *pointerToFloatValue = static_cast<float>( std::pow( *pointerToFloatValue, *y.pointerToFloatValue ));

    std::cout << "\n.. call powInternal ( FloatType& ) " << *(this->pointerToFloatValue )<< "\n";

    return *this; 
}

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
    if (std::abs(y) > 0) 
    {
       *pointerToFloatValue /= y;
    } 
    else 
    { 
        std::cout <<    "\x1B[31m Divide-by-zero warning! \x1B[0m" << std::endl; 
    }
    
    return *this;      
}


struct DoubleType
{
private:
    double* pointerToDoubleValue = nullptr;

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

    operator double() { return *pointerToDoubleValue; }
    //operator const FloatType& () { return (static_cast<float> (*pointerToDoubleValue)) ; }
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
    if (std::abs(y) > 0) 
    { 
        *pointerToDoubleValue /= y; 
    } 
    else 
    {
        std::cout <<    "\x1B[31m Divide-by-zero warning! \x1B[0m" << std::endl;
        *pointerToDoubleValue /= y; 
    }   
    return *this;      
}

struct IntType
{
private:
    int* pointerToIntValue = nullptr;
   
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
    
    operator int() { return *pointerToIntValue; }
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

#include <iostream>

int main()
{   

    //assign heap primitives
    FloatType ft ( 10 );
    DoubleType dt ( 10 );
    IntType it ( 10 ) ;

    std::cout << " power =" << ft.pow( 3.0f ) << std::endl; 

    std::cout << "FloatType add result=" <<  ft.add( 2 )  << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f )  << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ) << std::endl;
    std::cout << "FloatType divide result=" <<  ft.divide( 16.0f) << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0) << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0) << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(static_cast<double>(2.5f)) << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(0) << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(static_cast<int>(2.25f)) << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2) << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2) << std::endl;
    std::cout << "IntType divide result=" << it.divide(0) << std::endl << std::endl;

    //my example of a rounding loss causing an int divide by zero in the chain
    std::cout << "\x1B[32m Chain calculation = " << ( it.multiply(1000).divide(static_cast<int>(0.125f)).subtract(10).add(100) ) << std::endl;

    std::cout << "good to go!" << std::endl;
}
