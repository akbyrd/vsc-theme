// -------------------------------------------------------------------------------------------------
// Control Flow

#pragma once

#ifndef ONCE
#define ONCE
#include "test.cpp"

#include <vector>
#include <typeinfo>
#include <xmmintrin.h>
#pragma comment(lib, "foolib")

#define FUNCTION_MACRO(x, ...) __VA_ARGS__ ## x #x
#define DEFINE \
	__FUNCTION__ __LINE__ \
	"line"

void
BarControlFlow()
{
	if (0) {} else {}
	switch (0) { case 0: default: break; }

	for (;;) { break; }
	while (0) { continue; }
	do { } while (0);

	try {} catch (...) {} throw 0;

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
struct alignas(8) FooStruct final : private FooBase // TODO
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
	void Bar5() throw(int) {} // TODO

	explicit operator int() { return 0; }

public:
private:
protected:
};

[[nodiscard]] [[noreturn]] [[deprecated]]
[[using gnu: unused, fakeattribute]]
void BarAttribute() {}

int Global;
template <typename> void BarTemplate() {}

static union {};
enum {};
enum struct A {};
enum class B {};
namespace N {}
struct C final : public FooBase {};
typedef int D;
using E = int;

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

	static_cast<int*>(0);
	reinterpret_cast<int*>(0);
	const_cast<int*>(0);
	dynamic_cast<int*>(0);
}

// -------------------------------------------------------------------------------------------------
// Types

void BarTypes()
{
	int;
	std::size_t;
	__m128;

	// TODO
	struct Foo {};
	new Foo;
	new Foo();
	new Foo{};
}

// -------------------------------------------------------------------------------------------------
// Functions

struct FooFunctions
{
	FooFunctions() = default;
	FooFunctions(int) {}

	// TODO: operator keyword color
	void* operator new(size_t) { return 0; }
	void* operator new[](size_t) { return 0; }
	void operator delete(void*) {}
	void operator delete[](void*) {}

	void operator[](int) {}
	void operator&() {}
	void operator*() {}
	C* operator->() { return 0; }
	void operator->*(int) {}
	operator int() { return 0; }

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

void operator +(A, A) {};

char operator""_z(char) { return 0; }
char g = 's'_z; // TODO: user defined literal color

void
BarFunctionCalls()
{
	&BarFunctionCalls;

	new int;
	new int[1];
	delete (int*) nullptr;
	delete[] (int*) nullptr;

	new FooFunctions;
	new FooFunctions[1];
	delete (FooFunctions*) nullptr;
	delete[] (FooFunctions*) nullptr;

	FooFunctions f;
	(int) f; // TODO: overloaded cast color
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
/// <summary> Doxygen comment </summary> // TODO
/** <summary> Doxygen comment </summary> */ // TODO

// -------------------------------------------------------------------------------------------------

template<auto& ReleaseFn> struct TemplateParam {}; // TODO
template<typename T = int> struct TemplateDefault {}; // TODO

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
	x = x < x || x <= x || x > x || x >= x;
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
