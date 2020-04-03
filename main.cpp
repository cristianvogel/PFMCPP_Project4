
#include <iostream>
/*
Project 4: Part 5 / 9
 video: Chapter 5 Part 2
 Operator Overloading.

Do not delete your previous main. 

 Create a branch named Part5

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 1) replace the add/subtract/multiply/etc functions with overloaded math operators 
        e.g. add() would become operator+=() because it modifies the internal heap-allocated object.
 
 2) Your overloaded operators should only take primitives, passed by value.
 
 3) don't delete your conversion functions.
         if you removed them in Chapter 4 Part 7, put them back in.
         uncomment them if you commented them in Chapter 4 Part 7
 
 4) your main() function should be the same as Chapter 4 Part 7.  
     
 5) if your Chapter4 Part7 task didn't use any [+ - * or /], 
         add some in and fix the build errors that might result via the techniques you have learned in the previous weeks (hint: casting)
         i.e.
 */


 /*
 6) compile/link/run to make sure you don't have any errors
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
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

Point& Point::multiply( const FloatType& m) 
{
    x *= m;
    y *= m;
    return *this;
}

Point& Point::multiply( const DoubleType& m)
{
    x *= static_cast<float>(m);
    y *= static_cast<float>(m);
    return *this;
}

Point& Point::multiply( const IntType& m) 
{
    x *= static_cast<float>(m);
    y *= static_cast<float>(m);
    return *this;
}

#include <iostream>
#include <memory>

int main()
{   
    std::string div = "\n \x1B[35m ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \x1B[0m \n";
    //assign heap primitives
    FloatType ftErrorTest ( 2.0f );
    FloatType ft( 2.0f );

    DoubleType dt ( 0.5 );
    DoubleType dtErrorTest ( 0.5 );

    IntType it ( 2 );
    IntType itErrorTest ( 2 );
    
    Point p1 (2.0f, 20.0f);
    Point p2 (25.0f, 50.0f);
    
    ftErrorTest /= 0.0f;
    std::cout << "FloatType divide by zero test =" << ftErrorTest << div << std::endl;
    std::cout << "FloatType pow ( 2.0f ) = " << ft.pow( 2.0f ) << std::endl; 
    std::cout << "FloatType pow ( 2 ) = " << ft.pow( 2 ) << std::endl; 
    std::cout << "FloatType pow ( 0.5 ) = " << ft.pow( 0.5 ) << std::endl; 
    std::cout << "FloatType pow ( DoubleType with value of " << dt << " ) = " << ft.pow( dt ) << std::endl; 
    std::cout << "FloatType pow (IntType with value of " << it << " ) = " << ft.pow ( it ) << std::endl;
    std::cout << "FloatType pow ( FloatType with value of " << ft << " ) = " << ft.pow( ft ) << std::endl; 

    ft+=2.0f;
    std::cout << "FloatType add result=" << ft << std::endl;
    ft-=2.0f;
    std::cout << "FloatType subtract result=" << ft  << std::endl;
    ft*=2.0f;
    std::cout << "FloatType multiply result=" << ft << std::endl;
    ft/=8.0f;
    std::cout << "FloatType divide result =" <<  ft << div << std::endl;

    dtErrorTest /= 0;
    std::cout << "DoubleType divide by zero test =" << dtErrorTest << div << std::endl;
    std::cout << "DoubleType pow ( 2.5 ) = " << dt.pow( 2.5 ) << std::endl; 
    std::cout << "DoubleType pow ( 2 ) = " << dt.pow( 2 ) << std::endl; 
    std::cout << "DoubleType pow ( 0.5f ) = " << dt.pow(0.5 ) << std::endl; 
    ft /=1000;
    std::cout << "DoubleType pow ( FloatType with value of " << ft << ") /1000 = " << dt.pow( ft ) << std::endl; 
    std::cout << "DoubleType pow (IntType with value of " << it << " ) = " << dt.pow ( it ) << std::endl;
    std::cout << "DoubleType pow ( DoubleType with value of " << dt << " ) = " << dt.pow( dt ) << std::endl; 
    dt+=2;
    std::cout << "DoubleType add result=" << dt << std::endl;
    dt-=2;
    std::cout << "DoubleType subtract result=" << dt << std::endl;
    dt*=2.5;
    std::cout << "DoubleType multiply result=" << dt << std::endl;
    
    std::cout << "DoubleType divide result=" << dt << div << std::endl;

    itErrorTest /= 0;
    std::cout << "IntType divide by zero test =" <<  itErrorTest << div << std::endl;
    std::cout << "IntType pow ( 2.5 ) = " << it.pow( 2.5 ) << std::endl; 
    std::cout << "IntType pow ( 2 ) = " << it.pow(2) << std::endl; 
    std::cout << "IntType pow ( 4.0f ) = " << it.pow( 2.0f ) << std::endl; 
    std::cout << "IntType pow ( FloatType with value of " << ft << ") = " << it.pow( ft ) << std::endl; 
    std::cout << "IntType pow (DoubleType with value of " << dt << " ) = " << it.pow ( dt ) << std::endl;
    std::cout << "IntType pow ( IntType with value of " << it << " ) = " << it.pow( it ) << std::endl; 
    it+=8;
    std::cout << "IntType add result=" << it << std::endl;
    it-=2;
    std::cout << "IntType subtract result=" << it << std::endl;
    it*=2;
    std::cout << "IntType multiply result=" << it << std::endl;
    it/=4;
    std::cout << "IntType divide result=" << it << std::endl << std::endl;

    //my example of a rounding loss causing an int divide by zero in the chain
    it *= 1000;
    it /= 2;
    it -= 10;
    it += 100;
    std::cout << "\x1B[32m Chain calculation = " << it.pow(2) << div << std::endl;

    // some Point calculations
    std::cout << "\x1B[36m Point " << p1.toString() << " multiplication with FloatType > Point \x1B[0m" << (p1.multiply( ft )).toString() << std::endl;
    std::cout << "\x1B[36m Point " << p2.toString() << " multiplication with DoubleType > Point \x1B[0m" << (p2.multiply( dt )).toString() << std::endl;
    std::cout << "\x1B[36m Point " << p1.toString() << " multiplication with IntType > Point \x1B[0m" << (p1.multiply( it )).toString() << std::endl;
    
    
    std::cout << "good to go!" << std::endl;
}
