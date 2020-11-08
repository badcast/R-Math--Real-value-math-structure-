#ifndef __RMATH_H
#define __RMATH_H

#include <stdint.h>
#include <limits>
#include <list>

namespace rmath
{
	constexpr double INFINITY = std::numeric_limits<double>::infinity(); // infinity by value the are 1/0 = ~8 
	struct real_t; // is real value: How to exist?

	inline const double to_double(real_t val);
	inline const real_t to_prime(real_t v);
	inline const real_t mix(real_t value);
	
	struct real_t
	{
		int m;		// целое 
		int p;		// числитель
		int q;		// знаменатель

		real_t() = default;

		real_t(const int& m, const int& p, const int& q) {
			this->m = m;
			this->p = p;
			this->q = q;
		}

		explicit real_t(const double& rhs);
		explicit real_t(const int32_t& rhs) : real_t(static_cast<int64_t>(rhs)) {}
		explicit real_t(const uint32_t& rhs) : real_t(static_cast<uint64_t>(rhs)) {}

		explicit real_t(const int64_t& rhs) {
			this->m = 0;
			this->p = rhs;
			this->q = 1;
		}
		explicit real_t(const uint64_t& rhs) {
			this->m = 0;
			this->p = rhs;
			this->q = 1;
		}

		operator const double() {
			return to_double(*this);
		}
	};

	//const value 
	const  real_t minusOne{ 0, -1, 1 };
	const  real_t zero{ 0, 0, 1 };
	const  real_t one{ 0, 1, 1 };
	const  real_t two{ 0, 2, 1 };
	const  real_t NaN{ 0, 0, 0 };
	const  real_t positiveInfinity{ 0, 1, 0 };
	const  real_t negativeInfinity{ 0, -1, 0 };

	real_t::real_t(const double& rhs) {
		if (rhs == INFINITY)
		{
			*this = positiveInfinity;
		}
		else if (rhs == -INFINITY)
		{
			*this = negativeInfinity;
		}
		else {
			m = 0;
			p = int(rhs * 1000) - int(rhs * 100);
			q = 900;
			*this = to_prime(*this);
		}
	}

	inline const real_t create(int p, int q, int c = 0)
	{
		return { c, p, q };
	}
	inline const real_t create(double rhs)
	{
		real_t v;
		if (rhs == INFINITY)
		{
			v = positiveInfinity;
		}
		else if (rhs == -INFINITY)
		{
			v = negativeInfinity;
		}
		else {
			v.m = 0;
			v.p = int(rhs * 1000) - int(rhs * 100);
			v.q = 900;
			v = to_prime(v);
		}
		return v;
	}

	inline const bool is_negative(const real_t& v)
	{
		return v.m < 0 || v.p < 0 || v.q < 0;
	}

	inline const bool is_inf(const real_t& v)
	{
		return !v.m && v.p && !v.q;
	}

	inline const bool is_nan(const real_t& v)
	{
		return !v.m && !v.p && !v.q;
	}

	inline const bool is_int(const real_t& v, int value)
	{
		return !v.m && v.p == value && v.q == 1;
	}

	inline const bool is_zero(const real_t& v)
	{
		return is_int(v, 0);
	}

	inline const bool is_one(const real_t& v)
	{
		return is_int(v, 1);
	}

	inline const bool right(const real_t& v)
	{
		return v.m == 0 && v.p < v.q;
	}

	inline const bool is_normalize(const real_t& v)
	{
		return !v.m;
	}

	std::list<uint16_t> get_multipliers(long value)
{
    if(!value) 
        return std::list<uint16_t>();

    std::list<uint16_t> lst;
    ldiv_t delta;
    long divide = 2;
	
    delta.quot = value;
    while (delta.quot != 1)
    {
        do
        {
            delta = ldiv((long)value, (long)divide);
            if (delta.rem)
            {
                divide+=delta.rem;
            }
            else
            {
                value = delta.quot;
                break;
            }
        } while (true);
        lst.emplace_back(divide);
    }
    return lst;
}

const size_t NOD(long lhs, long rhs) throw()
{
	if(lhs==rhs)
	return lhs;
	
    //todo: Оптимизировать O(n2) нужен O(n)
    size_t result = 1;
    auto lstLhs = get_multipliers(lhs);
    auto lstRhs = get_multipliers(rhs);

    for (auto i = lstLhs.begin(); i != lstLhs.end(); ++i)
        for (auto j = lstRhs.begin(); j != lstRhs.end(); ++j)
            if (*i == *j)
            {
                result *= *i;
                lstRhs.erase(j);
                break;
            }
    return result;
}

const size_t NOK(long lhs, long rhs) throw()
{
	if(lhs==rhs)
	return lhs;
    
    //todo: Оптимизировать O(n2) нужен O(n)
    size_t result = lhs;
    auto lstLhs = get_multipliers(lhs);
    auto lstRhs = get_multipliers(rhs);

    for (auto i = lstLhs.begin(); i != lstLhs.end(); ++i)
        for (auto j = lstRhs.begin(); j != lstRhs.end(); ++j)
            if (*i != *j)
            {
                result *= *j;
                lstRhs.erase(j);
                break;
            }
    return result;
}


	inline const real_t to_prime(real_t v)
	{
		auto nod = NOD(abs(v.p), abs(v.q));
		if (nod > 1)
		{
			v.p = v.p / static_cast<int>(nod);
			v.q = v.q / static_cast<int>(nod);
		}
		return v;
	}

	//To normalize value
	inline const real_t normalize(real_t v)
	{
		if (!is_normalize(v)) // break do normalize value
		{
			v.p = v.m * v.q + v.p;
			v.m = 0;
		}
		return to_prime(v);
	}

	inline const bool eq_lowest(const real_t& lhs, const real_t& rhs)
	{
		return to_double(lhs) < to_double(rhs);
	}

	//Operation addition
	inline const real_t add(real_t lhs, real_t rhs)
	{
		if (!lhs.q || !rhs.q)
			return lhs;

		lhs = normalize(lhs);
		rhs = normalize(rhs);

		auto nok = NOK(lhs.q, rhs.q); // nok
		lhs.p = lhs.p * (nok / lhs.q);
		lhs.q = nok;
		rhs.p = rhs.p * (nok / rhs.q);
		lhs.p += rhs.p; // add
		return lhs;
	}

	// оператор вычитания 
	inline const real_t sub(real_t lhs, real_t rhs)
	{
		decltype(NOK(0, 0)) nok; // get the type (is optimal variant) c++ 14
		lhs = normalize(lhs);
		rhs = normalize(rhs);
		nok = NOK(lhs.q, rhs.q); // nok
		lhs.p = lhs.p * (nok / lhs.q);
		lhs.q = nok;
		rhs.p = rhs.p * (nok / rhs.q);
		lhs.p -= rhs.p; // sub
		return lhs;
	}

	// оператор умножения
	inline const real_t mul(real_t lhs, real_t rhs, bool toPrime = true)
	{
		lhs = normalize(lhs);
		rhs = normalize(rhs);

		lhs.p *= rhs.p;
		lhs.q *= rhs.q;

		if (toPrime)
			lhs = to_prime(lhs);

		return lhs;
	}

	// оператор деления
	inline const real_t div(real_t lhs, real_t rhs, bool toPrime = true)
	{
		lhs = normalize(lhs);
		rhs = normalize(rhs);

		std::swap(rhs.p, rhs.q); // операция перевернуть

		lhs.p *= rhs.p;
		lhs.q *= rhs.q;

		if (toPrime)
			lhs = to_prime(lhs);

		return lhs;
	}

	inline const real_t mix(real_t value){
		value = normalize(value);
		if(!right(value))
		{
			value.m = value.p / value.q;
			value.q = value.p % value.q;
		}
		return value; 
	}

	inline const double to_double(real_t val)
	{
		val = normalize(val);

		return static_cast<double>(val.p) / val.q;
	}

	const real_t operator +(const real_t& lhs, const real_t& rhs) {
		return add(lhs, rhs);
	}

	const real_t operator -(const real_t& lhs, const real_t& rhs) {
		return sub(lhs, rhs);
	}

	const real_t operator /(const real_t& lhs, const real_t& rhs) {
		return div(lhs, rhs);
	}

	const real_t operator *(const real_t& lhs, const real_t& rhs) {
		return mul(lhs, rhs, true);
	}

	const real_t operator +(const real_t& lhs, const double& rhs) {
		real_t num = lhs + real_t(rhs);
		return num;
	}
	const real_t operator -(const real_t& lhs, const double& rhs) {
		real_t num = lhs - real_t(rhs);
		return num;
	}
	const real_t operator *(const real_t& lhs, const double& rhs) {
		real_t num = lhs * real_t(rhs);
		return num;
	}
	const real_t operator /(const real_t& lhs, const double& rhs) {
		real_t num = lhs / real_t(rhs);
		return num;
	}

	const real_t operator +(const double& lhs, const real_t& rhs) { return rhs + lhs; }
	const real_t operator -(const double& lhs, const real_t& rhs) { return rhs - lhs; }
	const real_t operator *(const double& lhs, const real_t& rhs) { return rhs * lhs; }
	const real_t operator /(const double& lhs, const real_t& rhs) { return rhs / lhs; }

	const bool operator ==(const real_t& lhs, const real_t& rhs) {
		double num = to_double(lhs);
		double num2 = to_double(rhs);
		return num == num2;
	}

	const bool operator >(real_t lhs, real_t rhs) {
		lhs = normalize(lhs);
		rhs = normalize(rhs);

		if (lhs.q == rhs.q)
			return lhs.p > rhs.p;
		else if (lhs.p == rhs.p)
			return lhs.q < rhs.q;

		return to_double(lhs) > to_double(rhs);
	}

	const bool operator <(real_t lhs, real_t rhs) {
		lhs = normalize(lhs);
		rhs = normalize(rhs);

		if (lhs.q == rhs.q)
			return lhs.p < rhs.p;
		else if (lhs.p == rhs.p)
			return lhs.q > rhs.q;

		return to_double(lhs) < to_double(rhs);
	}

	const bool operator ==(const real_t& lhs, const double& rhs)
	{
		return to_double(lhs) == rhs;
	}

	const bool operator ==(const double& lhs, const real_t& rhs) { return rhs == lhs; }

}
#endif
