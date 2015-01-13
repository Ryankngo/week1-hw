#include <iostream>
#include <string>
using namespace std;
//ryan
class fraction
{
    public:
    fraction(int inNumerator =0, int inDenominator=1);
    friend ostream& operator<<(ostream& out,
                               const fraction& right);
    friend bool operator<(const fraction& left,
                          const fraction& right);
    friend bool operator<=(const fraction& left,
                          const fraction& right);
    friend bool operator>(const fraction& left,
                           const fraction& right);
    friend bool operator>=(const fraction& left,
                           const fraction& right);
    friend bool operator==(const fraction& left,
                           const fraction& right);
    friend bool operator!=(const fraction& left,
                           const fraction& right);
    friend fraction operator+(const fraction& left,
                                const fraction& right);
    friend fraction operator-(const fraction& left,
                              const fraction& right);
    friend fraction operator*(const fraction& left,
                              const fraction& right);
    friend fraction operator/(const fraction& left,
                              const fraction& right);
    fraction operator+=(const fraction& right);
    fraction operator-=(const fraction& right);
    fraction operator*=(const fraction& right);
    fraction operator/=(const fraction& right);
    fraction operator++();
    fraction operator++(int);
    fraction operator--();
    fraction operator--(int);


    
    
    
    private:
        int numerator;
        int denominator;
    
};

fraction :: fraction (int inNumerator, int inDenominator)
{
    numerator = inNumerator;
    denominator =inDenominator;
}

bool operator<(const fraction& left, const fraction& right)
{
    if ((left.numerator *right.denominator) < (right.numerator * left.denominator)){
        return true;
    }
    
    if ((left.numerator *right.denominator) > (right.numerator * left.denominator)){
        return false;
    }
    
    
    return false;
}

bool operator<=(const fraction& left, const fraction& right)
{
    if ((left.numerator *right.denominator) < (right.numerator * left.denominator)){
        return true;
    }
    
    if ((left.numerator *right.denominator) > (right.numerator * left.denominator)){
        return false;
    }
    
    if ((left.numerator *right.denominator) == (right.numerator * left.denominator)){
        return true;
    }
    
    
    return false;
}

bool operator>(const fraction& left, const fraction& right)
{
    if ((left.numerator *right.denominator) > (right.numerator * left.denominator)){
        return true;
    }
    
    if ((left.numerator *right.denominator) < (right.numerator * left.denominator)){
        return false;
    }
    
    
    return false;
}

bool operator>=(const fraction& left, const fraction& right)
{
    if ((left.numerator *right.denominator) > (right.numerator * left.denominator)){
        return true;
    }
    
    if ((left.numerator *right.denominator) < (right.numerator * left.denominator)){
        return false;
    }
    
    if ((left.numerator *right.denominator) == (right.numerator * left.denominator)){
        return true;
    }
    
    
    return false;
}

bool operator==(const fraction& left, const fraction& right)
{
    if ((left.numerator *right.denominator) == (right.numerator * left.denominator)){
        return true;
    }
    
    return false;
}

bool operator!=(const fraction& left, const fraction& right)
{
    if ((left.numerator *right.denominator) != (right.numerator * left.denominator)){
        return true;
    }
    
    return false;
}

fraction operator+(const fraction& left,
                     const fraction& right)
{
    fraction answer;
    
    answer.numerator = (left.numerator * right.denominator) + (right.numerator* left.denominator);
    answer.denominator = left.denominator * right.denominator;
    
    
    return answer;
    
    
}

fraction operator-(const fraction& left,
                   const fraction& right)
{
    fraction answer;
    
    answer.numerator = (left.numerator * right.denominator) - (right.numerator* left.denominator);
    answer.denominator = left.denominator * right.denominator;
    
    
    return answer;
    
    
}

fraction operator*(const fraction& left,
                   const fraction& right)
{
    fraction answer;
    
    answer.numerator = (left.numerator * right.numerator);
    answer.denominator = left.denominator * right.denominator;
    
    
    return answer;
    
    
}

fraction operator/(const fraction& left,
                   const fraction& right)
{
    fraction answer;
    
    answer.numerator = (left.numerator * right.denominator);
    answer.denominator = left.denominator * right.numerator;
    
    
    return answer;
    
    
}

fraction fraction::operator+=(const fraction& right)
{

    
    numerator = (numerator * right.denominator) + (right.numerator* denominator);
    denominator = denominator * right.denominator;
    
    return *this;
}



fraction fraction::operator-=(const fraction& right)
{
    
    
    numerator = (numerator * right.denominator) - (right.numerator* denominator);
    denominator = denominator * right.denominator;
    
    return *this;
}

fraction fraction::operator*=(const fraction& right)
{
    
    numerator = (numerator * right.numerator);
    denominator = denominator * right.denominator;
    
    
    return *this;
}

fraction fraction::operator/=(const fraction& right)
{
    numerator = (numerator * right.denominator);
    denominator = denominator * right.numerator;
 
    return *this;
}

fraction fraction::operator++()
{
    numerator += denominator;
    return *this;
}

fraction fraction::operator++(int)
{
    fraction temp(numerator, denominator);
    numerator += denominator;
    return temp;
}

fraction fraction::operator--()
{
    numerator -= denominator;
    return *this;
}

fraction fraction::operator--(int)
{
    fraction temp(numerator, denominator);
    numerator -= denominator;
    return temp;
}




ostream& operator<<(ostream& out, const fraction& right)
{
    out << right.numerator << "/" << right.denominator;
    return out;
}

void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
string boolString(bool convertMe);

int main()
{
    BasicTest();
    RelationTest();
    BinaryMathTest();
    MathAssignTest();
}





void BasicTest()
{
    cout << "\n----- Testing basic fraction creation & printing\n";
    cout << "(fractions should be in reduced form, and as mixed numbers.)\n";
    
    const fraction fr[] = {fraction(4, 8), fraction(-15,21),
        fraction(10), fraction(12, -3),
        fraction(), fraction(28, 6), fraction(0, 12)};
    
    for (int i = 0; i < 7; i++){
        cout << "fraction [" << i <<"] = " << fr[i] << endl;
    }
    
    
    
}





string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    } else {
        return "false";
    }
}


void RelationTest()
{
    cout << "\n----- Testing relational operators between fractions\n";
    
    const fraction fr[] =  {fraction(3, 6), fraction(1,2), fraction(-15,30),
        fraction(1,10), fraction(0,1), fraction(0,2)};
    
    for (int i = 0; i < 5; i++) {
        cout << "Comparing " << fr[i] << " to " << fr[i+1] << endl;
        cout << "\tIs left < right? " << boolString(fr[i] < fr[i+1]) << endl;
        cout << "\tIs left <= right? " << boolString(fr[i] <= fr[i+1]) << endl;
        cout << "\tIs left > right? " << boolString(fr[i] > fr[i+1]) << endl;
        cout << "\tIs left >= right? " << boolString(fr[i] >= fr[i+1]) << endl;
        cout << "\tDoes left == right? " << boolString(fr[i] == fr[i+1]) << endl;
        cout << "\tDoes left != right ? " << boolString(fr[i] != fr[i+1]) << endl;
    }
    
    cout << "\n----- Testing relations between fractions and integers\n";
    fraction f(-3,6);
    int num = 2;
    cout << "Comparing " << f << " to " << num << endl;
    cout << "\tIs left < right? " << boolString(f < num) << endl;
    cout << "\tIs left <= right? " << boolString(f <= num) << endl;
    cout << "\tIs left > right? " << boolString(f > num) << endl;
    cout << "\tIs left >= right? " << boolString(f >= num) << endl;
    cout << "\tDoes left == right? " << boolString(f == num) << endl;
    cout << "\tDoes left != right ? " << boolString(f != num) << endl;
    
    fraction g(1,4);
    num = -3;
    cout << "Comparing " << num << " to " << g << endl;
    cout << "\tIs left < right? " << boolString(num < g) << endl;
    cout << "\tIs left <= right? " << boolString(num <= g) << endl;
    cout << "\tIs left > right? " << boolString(num > g) << endl;
    cout << "\tIs left >= right? " << boolString(num >= g) << endl;
    cout << "\tDoes left == right? " << boolString(num == g) << endl;
    cout << "\tDoes left != right ? " << boolString(num != g) << endl;
}





void BinaryMathTest()
{
    cout << "\n----- Testing binary arithmetic between fractions\n";
    
    const fraction fr[] = {fraction(1, 6), fraction(1,3),
        fraction(-2,3), fraction(5), fraction(-4,3)};
    
    for (int i = 0; i < 4; i++) {
        cout << fr[i] << " + " << fr[i+1] << " = " << fr[i] + fr[i+1] << endl;
        cout << fr[i] << " - " << fr[i+1] << " = " << fr[i] - fr[i+1] << endl;
        cout << fr[i] << " * " << fr[i+1] << " = " << fr[i] * fr[i+1] << endl;
        cout << fr[i] << " / " << fr[i+1] << " = " << fr[i] / fr[i+1] << endl;
    }
    
    cout << "\n----- Testing arithmetic between fractions and integers\n";
    fraction f(-1, 2);
    int num = 4;
    cout << f << " + " << num << " = " << f + num << endl;
    cout << f << " - " << num << " = " << f - num << endl;
    cout << f << " * " << num << " = " << f * num << endl;
    cout << f << " / " << num << " = " << f / num << endl;
    
    fraction g(-1, 2);
    num = 3;
    cout << num << " + " << g << " = " << num + g << endl;
    cout << num << " - " << g << " = " << num - g << endl;
    cout << num << " * " << g << " = " << num * g << endl;
    cout << num << " / " << g << " = " << num / g << endl;
}






void MathAssignTest()
{
    cout << "\n----- Testing shorthand arithmetic assignment on fractions\n";
    
    fraction fr[] = {fraction(1, 6), fraction(4),
        fraction(-1,2), fraction(5)};
    
    for (int i = 0; i < 3; i++) {
        cout << fr[i] << " += " << fr[i+1] << " = ";
        cout << (fr[i] += fr[i+1]) << endl;
        cout << fr[i] << " -= " << fr[i+1] << " = ";
        cout << (fr[i] -= fr[i+1]) << endl;
        cout << fr[i] << " *= " << fr[i+1] << " = ";
        cout << (fr[i] *= fr[i+1]) << endl;
        cout << fr[i] << " /= " << fr[i+1] << " = ";
        cout << (fr[i] /= fr[i+1]) << endl;
    }
    
    cout << "\n----- Testing shorthand arithmetic assignment using integers\n";
    fraction f(-1, 3);
    int num = 3;
    cout << f << " += " << num << " = ";
    cout << (f += num) << endl;
    cout << f << " -= " << num << " = ";
    cout << (f -= num) << endl;
    cout << f << " *= " << num << " = ";
    cout << (f *= num) << endl;
    cout << f << " /= " << num << " = ";
    cout << (f /= num) << endl;
    
    cout << "\n----- Testing increment/decrement prefix and postfix\n";
    fraction g(-1, 3);
    cout << "Now g = " << g << endl;
    cout << "g++ = " << g++ << endl;
    cout << "Now g = " << g << endl;
    cout << "++g = " << ++g << endl;
    cout << "Now g = " << g << endl;
    cout << "g-- = " << g-- << endl;
    cout << "Now g = " << g << endl;
    cout << "--g = " << --g << endl;
    cout << "Now g = " << g << endl;
}

/*
 ----- Testing basic fraction creation & printing
 (fractions should be in reduced form, and as mixed numbers.)
 fraction [0] = 4/8
 fraction [1] = -15/21
 fraction [2] = 10/1
 fraction [3] = 12/-3
 fraction [4] = 0/1
 fraction [5] = 28/6
 fraction [6] = 0/12
 
 ----- Testing relational operators between fractions
 Comparing 3/6 to 1/2
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false
 Comparing 1/2 to -15/30
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
 Comparing -15/30 to 1/10
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing 1/10 to 0/1
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
 Comparing 0/1 to 0/2
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false
 
 ----- Testing relations between fractions and integers
 Comparing -3/6 to 2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing -3 to 1/4
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 
 ----- Testing binary arithmetic between fractions
 1/6 + 1/3 = 9/18
 1/6 - 1/3 = -3/18
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 3/6
 1/3 + -2/3 = -3/9
 1/3 - -2/3 = 9/9
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = 3/-6
 -2/3 + 5/1 = 13/3
 -2/3 - 5/1 = -17/3
 -2/3 * 5/1 = -10/3
 -2/3 / 5/1 = -2/15
 5/1 + -4/3 = 11/3
 5/1 - -4/3 = 19/3
 5/1 * -4/3 = -20/3
 5/1 / -4/3 = 15/-4
 
 ----- Testing arithmetic between fractions and integers
 -1/2 + 4 = 7/2
 -1/2 - 4 = -9/2
 -1/2 * 4 = -4/2
 -1/2 / 4 = -1/8
 3 + -1/2 = 5/2
 3 - -1/2 = 7/2
 3 * -1/2 = -3/2
 3 / -1/2 = 6/-1
 
 ----- Testing shorthand arithmetic assignment on fractions
 1/6 += 4/1 = 25/6
 25/6 -= 4/1 = 1/6
 1/6 *= 4/1 = 4/6
 4/6 /= 4/1 = 4/24
 4/1 += -1/2 = 7/2
 7/2 -= -1/2 = 16/4
 16/4 *= -1/2 = -16/8
 -16/8 /= -1/2 = -32/-8
 -1/2 += 5/1 = 9/2
 9/2 -= 5/1 = -1/2
 -1/2 *= 5/1 = -5/2
 -5/2 /= 5/1 = -5/10
 
 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 8/3
 8/3 -= 3 = -1/3
 -1/3 *= 3 = -3/3
 -3/3 /= 3 = -3/9
 
 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 5/3
 Now g = 5/3
 g-- = 5/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3
 Program ended with exit code: 0 */
