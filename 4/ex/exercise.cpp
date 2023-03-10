#include <iostream>

using namespace std;

int findGCD(int a, int b);

class Fraction{
    friend bool operator<(Fraction &f1, Fraction &f2);
    friend bool operator==(Fraction &f1, Fraction &f2);
    friend Fraction operator*(Fraction &f1, Fraction &f2);
    friend Fraction operator/(Fraction &f1, Fraction &f2);
    friend ostream& operator<<(ostream& out, Fraction f);
    friend istream& operator>>(istream& in, Fraction f);
    friend Fraction operator+(Fraction &f1, Fraction &f2);
    friend Fraction operator-(Fraction &f1, Fraction &f2);
    
    private:
        int nom;
        int den;
        void reduce(void){
            for (int i = this->den; i > 0;i--){
                if(!(this->den % i || this->nom % i)){
                    cout << "i: " << i << endl;
                    this->den = this->den / i;
                    this->nom = this->nom / i;
                }  
            }
        }
    public:
        Fraction(int n, int d) : nom(n), den(d) {}
        Fraction(int n) : nom(n), den(1) {}
        Fraction& operator*=(Fraction multiplier){
            this->nom *= multiplier.nom;
            this->den *= multiplier.den;
            reduce();
            return *this;
        }
        Fraction& operator+=(Fraction sum){
            
            this->nom = this->nom * sum.den + sum.nom * this->den;
            this->den *= sum.den;
            reduce();
            return *this;
        }
        Fraction& operator-=(Fraction sub){
            
            this->nom = this->nom * sub.den - sub.nom * this->den;
            this->den *= sub.den;
            reduce();
            return *this;
        }
        Fraction& operator-(void){
            nom = -nom;
            reduce();
            return *this;
        }
        inline Fraction& operator++(void){
            ++nom;
            reduce();
            return *this;
        }
        inline Fraction& operator--(void){
            --nom;
            reduce();
            return *this;
        }
        inline Fraction operator++(int){
            auto copy{*this};
            ++(*this);
            reduce();
            return copy;
        }
        inline Fraction operator--(int){
            auto copy{*this};
            --(*this);
            reduce();
            return copy;
        }
        operator double() {
            return nom / double(den);
        }
};

ostream& operator<<(ostream& out, Fraction f){
    cout << "("<< f.nom << "/" << f.den << ")" << endl; 
    return out;
}

istream& operator>>(istream& in, Fraction f){
    cin >> f.nom;
    cin >> f.den; 

    return in;
}

bool operator==(Fraction &f1, Fraction &f2){
    return f1.nom == f2.nom && f1.den == f2.den;
}

bool operator<(Fraction &f1, Fraction &f2){
    int first = f1.nom * f2.den;
    int second = f1.den * f2.nom;
    return first < second;
}

Fraction operator+(Fraction &f1, Fraction &f2){
    return Fraction((f1.nom * f2.den) + (f2.nom * f1.den), f1.den * f2.den);
}

Fraction operator-(Fraction &f1, Fraction &f2){
    return Fraction((f1.nom * f2.den) - (f2.nom * f1.den), f1.den * f2.den);
}

Fraction operator*(Fraction &f1, Fraction &f2){
    return Fraction(f1.nom * f2.nom, f1.den * f2.den);
}

Fraction operator/(Fraction &f1, Fraction &f2){
    return Fraction(f1.nom * f2.den, f1.den * f2.nom);
}




int main(){
    Fraction frac1(2,3);
    Fraction frac2(1,5);
    Fraction newFrac(1,2);
    //cin >> newFrac;
    cout << "The newly created frac is " << newFrac << endl;
    cout << frac1;
    cout << frac2;

    cout << boolalpha << (frac1 < frac2) << endl;
    frac1 -= frac2;
    cout << "-= " << frac1 << endl;
    Fraction mul{frac1 * frac2};
    cout << mul;
    Fraction div{frac1 / frac2};
    cout << div;
    cout << endl;
    cout << frac1;
    cout << frac2;
    Fraction sum{frac1 - frac2};
    cout << sum;
    cout << mul.operator-();
    double fracDouble = frac1;
    cout << fracDouble <<endl;
    return 0;
}
