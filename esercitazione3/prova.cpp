#include <iostream>
#include "rational.hpp"

int main (){
	
	rational<int> a(1, 2);
    rational<int> b(1, 4);
    rational<int> zero(0, 1);
    rational<int> infinito(1, 0);
    rational<int> nan(0, 0);

   rational<int> c;
	
	c=a+b;

    std::cout << a << " +" << b << " = " << c << "\n";
	c=a-b;
    std::cout << a << " - " << b << " = " <<c << "\n";
	c=a*b;
    std::cout << a << " * " << b << " = " <<c << "\n";
	c=a/b;
    std::cout << a << " / " << b << " = " <<c << "\n";

    std::cout << a << " + " << infinito << " = " << (a + infinito) << "\n";
    std::cout << a << " + " << nan << " = " << (a + nan) << "\n";
    std::cout << infinito << " + " << infinito << " = " << (infinito + infinito) << "\n";

    std::cout << a << " - " << infinito << " = " << (a - infinito) << "\n";
    std::cout << infinito << " - " << infinito << " = " << (infinito- infinito) << "\n";

    std::cout << a << " * " << zero << " = " << (a * zero) << "\n";
    std::cout << a << " * " << infinito << " = " << (a * infinito) << "\n";
    std::cout << zero << " * " << infinito << " = " << (zero * infinito) << "\n";

    std::cout << a << " / " << zero << " = " << (a / zero) << "\n";
    std::cout << a << " / " << infinito << " = " << (a / infinito) << "\n";
    std::cout << infinito << " / " << zero << " = " << (infinito / zero) << "\n";
    std::cout << infinito << " / " << infinito << " = " << (infinito / infinito) << "\n";

    rational<int> f(1, 2);
    f+= b;
    std::cout << "operazione += : " <<f<< "\n";
    
    f-= b;
    std::cout << "operazione -= : " << f<< "\n";
    
    f *= a;
    std::cout << "operazione *= : " << f << "\n";
    
    f /= a;
    std::cout << "operazione /= : " << f << "\n";
	
	
	
	
	
	
}
