// -------------------------------------------------------------------------------------------------
// Control Flow

#pragma once

#ifndef ONCE
#define ONCE
#include "test.cpp"

#include <vector>
#include <typeinfo>
#pragma comment(lib, "foolib")

#define FUNCTION_MACRO(x, ...) __VA_ARGS__ ## x #x
#define DEFINE \
	"line"

void
BarControlFlow()
{
	if (0) {}
	else {}

	for (;;) {}
	while (0) {}
	do { continue; } while (0);

	switch (0)
	{
		case 0: break;
	}

	try {}
	catch (...) {}
	throw false;

	goto ExitLabel;
	ExitLabel:
	return;
}

// -------------------------------------------------------------------------------------------------
// Keywords

struct FooBase
{
	virtual void Bar() = 0;
};

template <typename, class... Us>
struct alignas(4) FooStruct final : private FooBase
{
	FooStruct() = default;
	FooStruct(FooStruct&&) = delete;

	using FooBase::FooBase;
	using FooBase::Bar;

	int x;
	mutable int y;
	volatile int* z;
	const int w = 0;
	static int a;
	static inline int b;
	constexpr static int c = 0;

	void Bar() override final {}
	void Bar2() const {}
	static void Bar3() {}
	void Bar4() noexcept(0) {}
	void Bar5() throw(int) {}

	explicit operator int() { return 0; }

public:
private:
protected:
};

static union {};
enum {};
enum struct A {};
enum class B {};
namespace {}
struct C final : public FooBase {};
typedef int D;
using E = int;

void BarThrow() throw(int) {};

template <typename, class... Us>
constexpr inline static int
BarKeywords(const volatile int* parameter)
noexcept(0)
{
	static_assert(true);
	alignof(int);
	decltype(int);
	typeid(int);
	sizeof(int);

	int* ptr;
	new int;
	delete ptr;
	new int[1];
	delete[] ptr;

	static_cast<int*>(ptr);
	reinterpret_cast<int*>(ptr);
	const_cast<int*>(ptr);
	dynamic_cast<int*>(ptr);
}

// -------------------------------------------------------------------------------------------------
// Functions

struct FooFunctions
{
	FooFunctions() = default;
	FooFunctions(int) {}

	void* operator new(size_t) { return 0; }
	void* operator new[](size_t) { return 0; }
	void operator delete(void*) {}
	void operator delete[](void*) {}

	void operator[](int) {}
	void operator&() {}
	void operator*() {}
	C* operator->() { return 0; }
	void operator->*(int) {}

	void operator++() {}
	void operator++(int) {}
	void operator--() {}
	void operator--(int) {}
	void operator+() {}
	void operator-() {}

	void operator+(int) {}
	void operator-(int) {}
	void operator*(int) {}
	void operator/(int) {}
	void operator%(int) {}
	void operator+=(int) {}
	void operator-=(int) {}
	void operator*=(int) {}
	void operator/=(int) {}
	void operator%=(int) {}

	void operator~() {}
	void operator^(int) {}
	void operator&(int) {}
	void operator|(int) {}
	void operator^=(int) {}
	void operator&=(int) {}
	void operator|=(int) {}

	void operator=(int) {}
	void operator,(int) {}

	void operator&&(int) {}
	void operator||(int) {}
	void operator<(int) {}
	void operator>(int) {}
	void operator==(int) {}
	void operator<=(int) {}
	void operator>=(int) {}
	void operator!=(int) {}

	void operator<<(int) {}
	void operator>>(int) {}
	void operator<<=(int) {}
	void operator>>=(int) {}

	void Bar() {};
};

void operator""_z(char) {}

void
BarFunctionCalls()
{
	new int;
	new int();

	new FooFunctions;
	new FooFunctions();
	new FooFunctions(0);
	new FooFunctions{};
	new FooFunctions{0};

	&BarFunctionCalls;

	FooFunctions* pf = nullptr;

	delete pf;
	delete[] pf;

	FooFunctions f;
	f[0];
	*f;
	f->Bar();
	f->*(0);

	f++;
	++f;
	f--;
	--f;
	+f;
	-f;

	f + 0;
	f - 0;
	f * 0;
	f / 0;
	f % 0;
	f += 0;
	f -= 0;
	f *= 0;
	f /= 0;
	f %= 0;

	~f;
	f ^ 0;
	f & 0;
	f | 0;
	f ^= 0;
	f &= 0;
	f |= 0;

	f = 0;
	f , 0;

	f && 0;
	f || 0;
	f < 0;
	f > 0;
	f == 0;
	f <= 0;
	f >= 0;
	f != 0;

	f << 0;
	f >> 0;
	f <<= 0;
	f >>= 0;
}

// -------------------------------------------------------------------------------------------------
// Function Parameters

void BarParameter(int parameter) { int variable = parameter; }

// -------------------------------------------------------------------------------------------------
// Comments

// Comment
/* Block comment */
/// Doxygen comment

// -------------------------------------------------------------------------------------------------

void
BarVariables()
{
	int x = 0;
	x = 0ull;
	x = 0xff;
	x = 0b0011'0000;
	x = (-1) + (+1);
	x = 0 ? 0 : 0;

	float y = 0.0f;
	y = (-1e-6) + (+1e+6);

	char* z = "string" "\n\t" "%u %.2f";
	char w = '0' + '\0';

	int* px = &x;
	int& rx = x;

	auto a = nullptr;
	size_t b = 0;

	x = x | x ^ x & x;
	x = !x + ~x;

	x = x || x && x;
	x = x <= x || x >= x;
	x |= 1;
	x &= 1;
	x ^= 1;

	x = x + x - x * x / x % x;
	x += 1;
	x -= 1;
	x *= 1;
	x /= 1;
	x %= 1;

	x = x << 1 >> 1;
	x <<= 1;
	x >>= 1;

	x = x, x;

	FooFunctions* ptr = nullptr;
	(FooFunctions*) ptr;
}

void
BarStructMember()
{
	FooStruct<int> f = {};
	f.x = f.x + (&f)->x;
}

namespace Space { int member; }
using namespace Space;
enum FooEnum { Value };

void
BarMisc()
{
	BarStructMember();
	ExitLabel:
	int x = Space::member;
	x = FooEnum::Value;
}

void
BarStd()
{
	std::vector<int> x;
}

int main() {}

#endif
