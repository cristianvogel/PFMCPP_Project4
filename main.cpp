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
    Point( float _x, float _y ) : x{_x}, y{_y} 
    {      
    }

    Point( const FloatType& );
    Point( const DoubleType& );
    Point( const IntType& );

    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }

    Point& multiply(FloatType& m);
    Point& multiply(DoubleType& m);
    Point& multiply(IntType& m);

    std::string toString() 
    { 
        std::string result = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
        return result;
    }

private:
    float x{1}, y{1};
};

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

    operator float() { return getValue(); }
    
    const FloatType& powInternal( float ) const;
    float getValue() const { return *pointerToFloatValue; }
};


Point::Point( const FloatType& ft) : 
    x{ ft.getValue() } , 
    y{ ft.getValue() } 
{    
}

Point& Point::multiply( FloatType& m) 
{
    x *= m.getValue();
    y *= m.getValue();
    return *this;
}

FloatType& FloatType::pow ( float x )
{
    FloatType::powInternal( x );

    std::cout << "\x1B[33m.. Call to pow ( float ) \x1B[0m result: ";
    return *this;
}

const FloatType& FloatType::powInternal( float y ) const
{ 
    *pointerToFloatValue = static_cast<float>( std::pow( this->getValue() , y ));

    std::cout << "\n \x1B[36m... call powInternal ( float ) > \x1B[0m .. \n";

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
    DoubleType& pow ( double );

    operator double() { return getValue(); }

    const DoubleType& powInternal( double ) const;
    double getValue() const { return *pointerToDoubleValue;} 
};

Point::Point( const DoubleType& dt) : 
    x{ static_cast<float>(dt.getValue()) } , 
    y{ static_cast<float>(dt.getValue()) } 
{      
}

Point& Point::multiply( DoubleType& m) 
{
    x *= m.getValue();
    y *= m.getValue();
    return *this;
}

DoubleType& DoubleType::pow ( double x )
{
    DoubleType::powInternal( x );

    std::cout << "\x1B[33m.. Call to pow ( double ) \x1B[0m result: ";
    return *this;
}

const DoubleType& DoubleType::powInternal( double y ) const
{ 
    *pointerToDoubleValue = static_cast<double>( std::pow( this->getValue() , y ));

    std::cout << "\n \x1B[36m... call powInternal ( double ) > \x1B[0m .. \n";

    return *this; 
}

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
    IntType& pow ( int );

    operator int() { return getValue(); }

    const IntType& powInternal( int ) const;
    int getValue() const { return *pointerToIntValue;} 
};

Point::Point( const IntType& it) : 
    x{ static_cast<float>(it.getValue()) } , 
    y{ static_cast<float>(it.getValue()) } 
{      
}

Point& Point::multiply( IntType& m) 
{
    x *= m.getValue();
    y *= m.getValue();
    return *this;
}

IntType& IntType::pow ( int x )
{
    IntType::powInternal( x );

    std::cout << "\x1B[33m.. Call to pow ( int )  \x1B[0m result: ";
    return *this;
}

const IntType& IntType::powInternal( int y ) const
{ 
    *pointerToIntValue = static_cast<int>( std::pow( this->getValue() , y ));

    std::cout << "\n \x1B[36m... call powInternal (" << this->getValue() <<" , int " << y << " ) >  \x1B[0m .. \n";

    return *this; 
}

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
#include <typeinfo> // for typeid()

int main()
{   
    std::string div = "\n \x1B[35m ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \x1B[0m \n";
    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 0.5 );
    IntType it ( 2 ) ;

    std::vector<Point*> somePoints;

    for (float x=1 ; x<5.0f; x+=0.5f) 
    { 
        somePoints.push_back( new Point( x, x * 1.618f ));
    }

    std::cout << "FloatType pow ( 2.0f ) = " << ft.pow( 2.0f ) << std::endl; 
    std::cout << "FloatType pow ( 2 ) = " << ft.pow( static_cast<int>(2) ) << std::endl; 
    std::cout << "FloatType pow ( 0.5 ) = " << ft.pow( static_cast<double>(0.5) ) << std::endl; 
    std::cout << "FloatType pow ( DoubleType with value of " << it.getValue() << " ) = " << ft.pow( dt ) << std::endl; 
    std::cout << "FloatType pow (IntType with value of " << it.getValue() << " ) = " << ft.pow ( it ) << std::endl;
    std::cout << "FloatType pow ( FloatType with value of " << ft.getValue() << " ) = " << ft.pow( ft ) << std::endl; 
    std::cout << "FloatType pow ( IntType with value of " << it.getValue() << " ) = " << ft.pow( it ) << std::endl; 

    std::cout << "FloatType add result=" <<  ft.add( 2 )  << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f )  << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ) << std::endl;
    std::cout << "FloatType divide result=" <<  ft.divide( 16.0f) << div << std::endl;

    std::cout << "DoubleType pow ( 2.5 ) = " << dt.pow( 2.5 ) << std::endl; 
    std::cout << "DoubleType pow ( 2 ) = " << dt.pow( static_cast<int>(2) ) << std::endl; 
    std::cout << "DoubleType pow ( 0.5f ) = " << dt.pow( 0.5f ) << std::endl; 
    std::cout << "DoubleType pow ( FloatType with value of " << ft.getValue() << ") /1000 = " << dt.pow( ft.divide(1000) ) << std::endl; 
    std::cout << "DoubleType pow (IntType with value of " << it.getValue() << " ) = " << dt.pow ( it ) << std::endl;
    std::cout << "DoubleType pow ( DoubleType with value of " << dt.getValue() << " ) = " << dt.pow( dt ) << std::endl; 

    std::cout << "DoubleType add result=" << dt.add(2.0) << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0) << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(static_cast<double>(2.5f)) << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(0.5) << div << std::endl;

    std::cout << "IntType pow ( 2.5 ) = " << it.pow( 2.5 ) << std::endl; 
    std::cout << "IntType pow ( 2 ) = " << it.pow( static_cast<int>(2) ) << std::endl; 
    std::cout << "IntType pow ( 4.0f ) = " << it.pow( 2.0f ) << std::endl; 
    std::cout << "IntType pow ( FloatType with value of " << ft.getValue() << ") = " << it.pow( ft ) << std::endl; 
    std::cout << "IntType pow (DoubleType with value of " << dt.getValue() << " ) = " << it.pow ( dt ) << std::endl;
    std::cout << "IntType pow ( IntType with value of " << it.getValue() << " ) = " << it.pow( it ) << std::endl; 
    std::cout << "IntType add result=" << it.add( static_cast<int>(2.25f)) << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2) << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2) << std::endl;
    std::cout << "IntType divide result=" << it.divide(0) << std::endl << std::endl;

    //my example of a rounding loss causing an int divide by zero in the chain
    std::cout << "\x1B[32m Chain calculation = " << ( it.multiply(1000).divide(static_cast<int>(0.125f)).subtract(10).add(100) ) << div << std::endl;

    // some Point calculations
    for (Point* p : somePoints ) 
    { 
        std::cout << "\x1B[36m Point " << p->toString() << " multiplication with FloatType > Point \x1B[0m" << (p->multiply( ft )).toString() << std::endl;
        std::cout << "\x1B[36m Point " << p->toString() << " multiplication with DoubleType > Point \x1B[0m" << (p->multiply( dt )).toString() << std::endl;
        std::cout << "\x1B[36m Point " << p->toString() << " multiplication with IntType > Point \x1B[0m" << (p->multiply( it )).toString() << std::endl;
    }

    std::cout << "good to go!" << std::endl;
}
