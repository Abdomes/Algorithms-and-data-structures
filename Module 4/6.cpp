#include<iostream>
#include<vector>
#include<string>

using namespace std;

int c = 10;

class BigInteger
{
public:
    BigInteger() {};
    BigInteger(string str);
    BigInteger(int x);
    explicit operator bool() { return *this != 0; }

    string toString() const;
    void shift_right();
    void remove_zeros();

    BigInteger& operator=(const BigInteger& second);

    friend BigInteger operator+(const BigInteger& first, const BigInteger& second);
    friend BigInteger operator-(const BigInteger& first, const BigInteger& second);
    friend BigInteger operator*(const BigInteger& first, const BigInteger& second);
    friend BigInteger operator/(const BigInteger& first, const BigInteger& second);
    friend BigInteger operator%(const BigInteger& first, const BigInteger& second);

    BigInteger& operator+=(const BigInteger& second);
    BigInteger& operator-=(const BigInteger& second);
    BigInteger& operator*=(const BigInteger& second);
    BigInteger& operator/=(const BigInteger& second);
    BigInteger& operator%=(const BigInteger& second);

    bool operator==(const BigInteger& second);
    bool operator!=(const BigInteger& second);
    bool operator<(const BigInteger& second);
    bool operator>(const BigInteger& second);
    bool operator<=(const BigInteger& second);
    bool operator>=(const BigInteger& second);

    BigInteger operator-();
    BigInteger operator++(int);
    BigInteger& operator++();
    BigInteger operator--(int);
    BigInteger& operator--();

private:
    vector<int>digits;
    bool sign = false;
    friend istream& operator>>(istream& stream, BigInteger& bigint);
};

BigInteger::BigInteger(string str)
{
    if (str[0] == '-') {
        sign = true;
        str.erase(0, 1);
    }
    for (int i = (int)str.size(); i > 0; --i) {
        this->digits.push_back(atoi(str.substr(i - 1, 1).c_str()));
    }
}

BigInteger::BigInteger(int x)
{
    if (x < 0)
    {
        x = -x;
        sign = true;
    }
    else if (x == 0)
    {
        this->digits.push_back(0);
        sign = false;
    }
    while (x)
    {
        this->digits.push_back(x % c);
        x /= c;
    }
}

string BigInteger::toString() const
{
    string str;
    if (this->digits.size() == 1 && this->digits[0] == 0) {
        return "0";
    }
    if (sign == 1) {
        str.push_back('-');
    }
    for (int i = this->digits.size() - 1; i >= 0; --i) {
        str += to_string(this->digits[i]);
    }
    if (str.empty() || (str[0] == '-' && str.length() == 1)) {
        str = '0';
    }
    return str;
}

void BigInteger::shift_right()
{
    if (this->digits.size() == 0) {
        this->digits.push_back(0);
        return;
    }
    this->digits.push_back(this->digits[this->digits.size() - 1]);
    for (size_t i = this->digits.size() - 2; i > 0; --i)
    {
        this->digits[i] = this->digits[i - 1];
    }
    this->digits[0] = 0;
}

void BigInteger::remove_zeros()
{
    while (this->digits.size() > 1 && this->digits.back() == 0)
    {
        this->digits.pop_back();
    }
}

BigInteger& BigInteger::operator=(const BigInteger& second)
{
    this->sign = second.sign;
    this->digits.resize(second.digits.size());
    for (size_t i = 0; i < this->digits.size(); ++i)
    {
        this->digits[i] = second.digits[i];
    }
    return *this;
}

BigInteger operator+(const BigInteger& first, const BigInteger& second)
{
    BigInteger bigint;
    BigInteger firstt = first;
    if (firstt.sign == second.sign)
    {
        bigint.sign = second.sign;
        int overflow = 0;
        for (size_t i = 0; i < max(firstt.digits.size(), second.digits.size()) || overflow; ++i)
        {
            long long sum = 0;
            if (i == firstt.digits.size()) { firstt.digits.push_back(0); }
            if (i < second.digits.size())
            {
                sum += (overflow + second.digits[i] + firstt.digits[i]);
            }
            else
            {
                sum += (overflow + firstt.digits[i]);
            }
            overflow = (sum >= c);
            if (overflow)
            {
                sum -= c;
            }
            bigint.digits.push_back(sum);
        }
    }
    else if (firstt.sign)
    {
        BigInteger tmp = second;
        if (-firstt <= second)
        {
            bigint = (tmp - (-firstt));
            bigint.sign = 0;
        }
        else
        {
            bigint = ((-firstt) - second);
            bigint.sign = 1;
        }
    }
    else
    {
        BigInteger tmp = second;
        if (firstt < (-tmp))
        {
            bigint = ((-tmp) - (firstt));
            bigint.sign = 1;
        }
        else
        {
            bigint = ((firstt)-(-tmp));
            bigint.sign = 0;
        }
    }
    return bigint;
}

BigInteger operator-(const BigInteger& first, const BigInteger& second)
{
    BigInteger bigint;
    BigInteger tmp = second;
    BigInteger firstt = first;
    if (firstt == second)
    {
        bigint.sign = 0;
        bigint.digits.push_back(0);
        return bigint;
    }
    if (firstt.sign == second.sign && ((!firstt.sign && firstt > second) || (firstt.sign && -firstt > -tmp)))
    {
        int overflow = 0;
        for (size_t i = 0; i < firstt.digits.size() || overflow != 0; ++i)
        {
            long long sub = 0;
            if (i < second.digits.size())
            {
                sub = firstt.digits[i] - second.digits[i] - overflow;
            }
            else
            {
                sub = firstt.digits[i] - overflow;
            }
            overflow = (sub < 0);
            if (overflow)
            {
                sub += c;
            }
            bigint.digits.push_back(sub);
        }
        bigint.remove_zeros();
        bigint.sign = firstt.sign;
    }
    else if (firstt.sign == second.sign && ((!firstt.sign && firstt < second)))
    {
        bigint = (tmp - firstt);
        bigint.sign = 1;
    }
    else if (firstt.sign == second.sign && ((firstt.sign && -firstt < -tmp)))
    {
        bigint = (tmp - firstt);
        bigint.sign = 0;
    }
    else if (firstt.sign && !second.sign)
    {
        bigint = ((-firstt) + second);
        bigint.sign = 1;
    }
    else if (!firstt.sign && second.sign)
    {
        bigint = (firstt + (-tmp));
        bigint.sign = 0;
    }
    return bigint;
}

BigInteger operator*(const BigInteger& first, const BigInteger& second)
{
    BigInteger bigint;
    bigint.digits.resize(first.digits.size() + second.digits.size());
    for (size_t i = 0; i < first.digits.size(); ++i)
    {
        int overflow = 0;
        for (size_t j = 0; j < second.digits.size() || overflow != 0; ++j)
        {
            long long sub = 0;
            if (j < second.digits.size())
            {
                sub = overflow + bigint.digits[i + j] + (long long)first.digits[i] * second.digits[j];
            }
            else
            {
                sub = bigint.digits[i + j] + overflow;
            }
            bigint.digits[i + j] = static_cast<int>(sub % c);
            overflow = static_cast<int>(sub / c);
        }
    }
    bigint.remove_zeros();
    bigint.sign = !(first.sign == second.sign);
    if (bigint.digits.size() == 1 && bigint.digits[0] == 0) bigint.sign = false;
    return bigint;
}

BigInteger operator/(const BigInteger& first, const BigInteger& second)
{
    BigInteger bigint = second, res, cur;
    bigint.sign = 0;
    res.digits.resize(first.digits.size());
    for (int i = first.digits.size() - 1; i >= 0; --i)
    {
        cur.shift_right();
        cur.digits[0] = first.digits[i];
        cur.remove_zeros();
        int l = 0, r = c, t = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            BigInteger tmp = bigint * mid;
            if (tmp <= cur)
            {
                t = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        res.digits[i] = t;
        cur = cur - bigint * t;
    }
    res.remove_zeros();
    (first.sign == second.sign) ? res.sign = false : res.sign = 1;
    if (res.digits.size() == 1 && res.digits[0] == 0) res.sign = false;
    return res;
}

BigInteger operator%(const BigInteger& first, const BigInteger& second)
{
    BigInteger bigint, firstt = first, secondd = second;
    firstt.sign = 0;
    secondd.sign = 0;
    bigint = firstt - (firstt / secondd) * secondd;
    if ((first.sign == second.sign && first.sign == false) || (first.sign == 0 && second.sign == 1))
    {
        bigint.sign = 0;
    }
    else
    {
        bigint.sign = 1;
    }
    return bigint;
}

BigInteger& BigInteger::operator+=(const BigInteger& second)
{
    return *this = *this + second;
}

BigInteger& BigInteger::operator-=(const BigInteger& second)
{
    return *this = *this - second;
}

BigInteger& BigInteger::operator*=(const BigInteger& second)
{
    return *this = *this * second;
}

BigInteger& BigInteger::operator/=(const BigInteger& second)
{
    return *this = *this / second;
}

BigInteger& BigInteger::operator%=(const BigInteger& second)
{
    return *this = *this % second;
}

istream& operator>>(istream& stream, BigInteger& bigint)
{
    string str;
    stream >> str;
    bigint = BigInteger(str);
    return stream;
}

ostream& operator<<(ostream& stream, const BigInteger& bigint)
{
    return stream << bigint.toString();
}

bool BigInteger::operator==(const BigInteger& second)
{
    if (this->sign != second.sign)
    {
        return false;
    }
    if (this->digits.size() != second.digits.size())
    {
        return false;
    }
    if (this->digits.empty())
    {
        return (second.digits.empty() || (second.digits.size() == 1 && second.digits[0] == 0)) ? true : false;
    }
    if (second.digits.empty())
    {
        return (this->digits.size() == 1 && this->digits[0] == 0) ? true : false;
    }
    for (size_t i = 0; i < this->digits.size(); ++i)
    {
        if (this->digits[i] != second.digits[i])
        {
            return false;
        }
    }
    return true;
}

bool BigInteger::operator!=(const BigInteger& second)
{
    return !(*this == second);
}

bool BigInteger::operator<(const BigInteger& second)
{
    if ((this->digits.empty() || (this->digits.size() == 1 && this->digits[0] == 0))
        && (second.digits.empty() || (second.digits.size() == 1 && second.digits[0] == 0)))
    {
        return false;
    }
    if (this->digits.empty() || (this->digits.size() == 1 && this->digits[0] == 0))
    {
        return (!second.sign) ? true : false;
    }
    else if (second.digits.empty() || (second.digits.size() == 1 && second.digits[0] == 0))
    {
        return (!this->sign) ? false : true;
    }
    if (this->sign && !second.sign)
    {
        return true;
    }
    else if (!this->sign && second.sign)
    {
        return false;
    }
    if ((this->digits.size() < second.digits.size()) && (this->sign == 0) && (this->sign == second.sign))
    {
        return true;
    }
    else if ((this->digits.size() < second.digits.size()) && (this->sign == second.sign))
    {
        return false;
    }
    if ((this->digits.size() > second.digits.size()) && (this->sign == 0) && (this->sign == second.sign))
    {
        return false;
    }
    else if ((this->digits.size() > second.digits.size()) && (this->sign == second.sign))
    {
        return true;
    }
    if (this->sign == second.sign)
    {
        if (!this->sign)
        {
            for (int i = this->digits.size() - 1; i >= 0; --i)
            {
                if (this->digits[i] < second.digits[i])
                {
                    return true;
                }
                else if (this->digits[i] > second.digits[i])
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = this->digits.size() - 1; i >= 0; --i)
            {
                if (this->digits[i] < second.digits[i])
                {
                    return false;
                }
                else if (this->digits[i] > second.digits[i])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool BigInteger::operator>(const BigInteger& second)
{
    return !(*this <= second);
}

bool BigInteger::operator<=(const BigInteger& second)
{
    return (*this < second || *this == second);
}

bool BigInteger::operator>=(const BigInteger& second)
{
    return !(*this < second);
}

BigInteger BigInteger::operator-()
{
    BigInteger copy = *this;
    if (this->digits.empty() || (this->digits.size() == 1 && this->digits[0] == 0))
    {
        return copy;
    }
    copy.sign = !copy.sign;
    return copy;
}

BigInteger BigInteger::operator++(int)
{
    BigInteger copy = *this;
    ++(*this);
    return copy;
}

BigInteger& BigInteger::operator++()
{
    *this = *this + 1;
    return *this;
}

BigInteger BigInteger::operator--(int)
{
    BigInteger copy = *this;
    --(*this);
    return copy;
}

BigInteger& BigInteger::operator--()
{
    *this = *this - 1;
    return *this;
}

