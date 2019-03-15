#include <iostream>
using namespace std;

class Fraction
{
   public:
      Fraction(int n, int d); // construct fraction n/d
      Fraction();             // construct fraction 0/1
      void display();         // display fraction
      void restore(Fraction frac); // restore numer and denom
      void add(Fraction frac);  // calling obj = calling obj + frac
      void sub(Fraction frac);  // calling obj = calling obj - frac
      void mul(Fraction frac);  // calling obj = calling obj * frac
      void div(Fraction frac);  // calling obj = calling obj / frac
   private:
      void reduce();       // reduce the fraction to simplest form
      int numer, denom;
};

Fraction::Fraction(int n, int d)
{
/*
Initialize numer to n, and denom to d,
and use reduce() to simplest the numer and denom.
*/
    numer = n;
    denom = d;
    reduce();
}

Fraction::Fraction()
{
/*
Initialize numer to 0, and denom to 1
*/
    numer = 0;
    denom = 1;
}

void Fraction::display()
{
/*
Show the result.
If denom=1, show numer, otherwise show numer and denom.
*/
    if(denom == 1)
    {
        cout << numer << endl;
    }
    else
    {
        cout << numer << "/" << denom << endl;
    }
    return;
}

void Fraction::reduce()
{
/* Simplest the fraction number */
    int abs_n, abs_d;
    if(numer < 0)
    {
        abs_n = -numer;
    }
    else
    {
        abs_n = numer;
    }
    if(denom < 0)
    {
        abs_d = -denom;
    }
    else
    {
        abs_d = denom;
    }
    for(int i = 2; i <= abs_d; i++)
    {
        while(abs_n % i == 0 && abs_d % i == 0)
        {
            abs_n /= i;
            abs_d /= i;
        }
    }
    if(numer < 0 && denom < 0)
    {
        numer = abs_n;
        denom = abs_d;
    }
    else if(numer < 0 || denom < 0)
    {
        numer = -abs_n;
        denom = abs_d;
    }
    else
    {
        numer = abs_n;
        denom = abs_d;
    }
    return;
}

void Fraction::restore(Fraction frac)
{
/* Restore numer to frac.numer and denom to frac.denom */
    numer = frac.numer;
    denom = frac.denom;
    return;
}

void Fraction::add(Fraction frac)
{
/* Add two fractions number */
    numer = numer * frac.denom + frac.numer * denom;
    denom *= frac.denom;
    reduce();
    return;
}


void Fraction::sub(Fraction frac)
{
/* Subtract two fractions number */
    numer = numer * frac.denom - frac.numer * denom;
    denom *= frac.denom;
    reduce();
    return;
}

void Fraction::mul(Fraction frac)
{
/* Multiply two fractions number */
    numer *= frac.numer;
    denom *= frac.denom;
    reduce();
    return;
}

void Fraction::div(Fraction frac)
{
/* Divide two fractions number */
    numer *= frac.denom;
    denom *= frac.numer;
    reduce();
    return;
}

int main(){
   int a1,b1,a2,b2;
   cin >> a1 >> b1;
   cin >> a2 >> b2;
   Fraction frac1(a1,b1);
   Fraction frac2(a2,b2);
   Fraction frac3(a1,b1);

   frac1.add(frac2);
   cout << a1 << "/" << b1 << " + "<< a2 << "/" << b2 << " = ";
   frac1.display();
   frac1.restore(frac3);

   frac1.sub(frac2);
   cout << a1 << "/" << b1 << " - "<< a2 << "/" << b2 << " = ";
   frac1.display();
   frac1.restore(frac3);

   frac1.mul(frac2);
   cout << a1 << "/" << b1 << " * "<< a2 << "/" << b2 << " = ";
   frac1.display();
   frac1.restore(frac3);

   frac1.div(frac2);
   cout << a1 << "/" << b1 << " / "<< a2 << "/" << b2 << " = ";
   frac1.display();
   frac1.restore(frac3);

}
