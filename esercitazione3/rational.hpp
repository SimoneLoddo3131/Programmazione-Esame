#include <iostream>
#include <concepts>
#include <cmath>
#include <numeric>



template<typename I> requires std::integral<I>

class rational
{
I num_;
I den_;


void simplify(){
	I MCD= std::gcd(num_, den_);
	if (MCD!=0){
	num_=num_/MCD;
	den_=den_/MCD;
	}
	
	
	
	
}

public:
rational()
: num_(I{0}), den_(I{1})


	{}
	
	rational(const I& n, const I& d) 
	: num_(n), den_(d)
	
	{ if (!is_nan() && !is_inf()) {
            simplify();
        }}
	
	I den() const {return den_;}
	I num() const {return num_;}
	
	bool is_nan() const{
		return(den_==0 && num_==0);
	}
	bool is_inf() const{
		return(den_==0 && num_!=0);
	}
	
	
	rational& operator+=(const rational &other){
		
		
		if (this->is_nan() ||  other.is_nan()){  //se entrambi sono nan restituisce nan
			num_=0;
			den_=0;
			return *this;

		}
		if (this->is_inf() ||  other.is_inf()){  //se entrambi sono infiniti restituisce infinito
			num_=1;
			den_=0;
			return *this;
			
			
		}
		
	
			
		
		
		
		
		
		
		num_ = (num_ * other.den_) + (other.num_ * den_);
        den_ = den_ * other.den_;
		simplify();
        
        return *this;
 		
	
}
rational operator+(const rational& other) const {
        rational r = *this;
        r += other;
        return r;
    }
	
	






	rational& operator-=(const rational &other){
		
		
		if (this->is_nan() ||  other.is_nan()){  //se entrambi sono nan restituisce nan
			num_=0;
			den_=0;
			return *this;

		}
		if (this->is_inf() ||  other.is_inf()){  //se entrambi sono infiniti restituisce infinito
			num_=0;
			den_=0;
			return *this;}
			
		num_ = (num_ * other.den_) - (other.num_ * den_);
        den_ = den_ * other.den_;
		simplify();
        
        return *this;
 		
	
}
rational operator-(const rational& other) const {
        rational r = *this;
        r -= other;
        return r;
    }
	rational& operator*=(const rational &other){
		
		
		if (this->is_nan() ||  other.is_nan()){  //se entrambi sono nan restituisce nan
			num_=0;
			den_=0;
			return *this;

		}
		if (this->is_inf() ||  other.is_inf()){  //se entrambi sono infiniti restituisce infinito
			num_=1;
			den_=0;
			return *this;}
			
		num_ = num_*other.num_;
        den_ = den_ * other.den_;
		simplify();
        
        return *this;
 		
	
}
rational operator*(const rational& other) const {
        rational r = *this;
        r *= other;
        return r;
    }
	
	

		
		
		rational& operator/=(const rational &other) {
    
     if (this->is_nan() || other.is_nan()) {
        num_ = 0; den_ = 0;
        return *this;
    }

    
     if (this->is_inf() && other.is_inf()) {
        num_ = 0; den_ = 0;
        return *this;
    }

     
    if (other.is_inf()) {
         num_ = 0; den_ = 1;
        return *this;
    }

    
    if (other.num_ == 0) {
        num_ = 1; den_ = 0;
        return *this;
    }
 
    
    num_ = num_ * other.den_;
    den_ = den_ * other.num_;
    
    simplify(); // [cite: 281]
    return *this;
}
	

rational operator/(const rational& other) const {
        rational r = *this;
        r /= other;
        return r;
    }
	
	
	




};

template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.is_nan()) os << "NaN";
    else if (r.is_inf()) os << "Inf";
    else os << r.num() << "/" << r.den();
    return os;
}
