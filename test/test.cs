#define Foo2
#undef Foo2

//extern alias Foo;

using System;
using System.Collections;
using System.Runtime;
using System.Runtime.InteropServices;
using Debug = System.Diagnostics.Debug; // TODO

#if false
#elif false
#else
#endif

#region Foo
#endregion

//#warning warning
//#error error
#line (1, 1) - (2, 2) "filename"
#line hidden
#line default
#nullable enable // TODO
#pragma warning disable 1
#pragma warning restore 1
#pragma checksum "test.cs" "{406EA660-64CF-4C82-B6F0-42D48172A799}" "ab007f1d23d9"

[assembly: ComVisible(false)]
var A = args;

global::System.Int32 xg = new global::System.Int32(); // TODO
string x = nameof(global::System.Int32); // TODO
namespace N1 {}
[global::System.Diagnostics.Conditional("DEBUG")]
interface I {}

file record R { int x; }
public abstract partial class C1
{
	extern static int F();
	static C1() {}

	protected C1() {}
	~C1() {}

	delegate void D();
	event D? E1;
	event D E2 { add { E1 += value; } remove { E2 -= value; } }

	public int F1 { get { return x2; } set { x2 = value; } }
	public int F2 { get; init; } = new int();
	public int F3 { internal get; set; }
	public int F4 { protected get; set; }
	public int F5 { private get; set; }
	public static C1 operator +(C1 a) => a;
	public static explicit operator int(C1 a) => a.x1;
	public static implicit operator char(C1 a) => (char) a.x1;

	public virtual void M() {}
	ref int M2(ref int x) { return ref x; }
	int this[int i] { get { return 0; } set { x2 = value; } }

	public required int x1 = 0;
	volatile int x2 = 0;
	readonly int x3 = 0;
	const int x4 = 0;

	readonly struct S {}
}
sealed class C2 : C1
{
	C2() : base() {}
	public override void M() {}
}
class C3<T> where T : I {}
class C4<T> where T : I? {}
class C5<T> where T : class {}
class C6<T> where T : class? {}
class C7<T> where T : struct {}
class C9<T> where T : notnull {} // TODO
class C10<T> where T : unmanaged {} // TODO
class C11<T> where T : new() {}

public abstract class B
{
	public void M<T>(T? item) where T : struct { }
	public abstract void M<T>(T? item);
}
public class D : B
{
	public override void M<T>(T? item) where T : default { } // TODO
}

enum E { Null = 0 };

class C3
{
	void types()
	{
		long    x1;
		ulong   x2;
		short   x3;
		ushort  x4;
		int     x5;
		uint    x6;
		nint    x7;
		nuint   x8;
		float   x9;
		double  x10;
		char    x11;
		string  x12;
		bool    x13;
		byte    x14;
		sbyte   x15;
		decimal x16;
		object  x17;
		dynamic x18;
		var     x19 = 0;
		int?    x20; // TODO

		System.Int128 x20;
	}

	void literals()
	{
		var x1 = 1;
		var x2 = 1.0;
		var x3 = 1.0f;
		var x4 = 1.0d;
		var x5 = 1e-6; // TODO
		var x6 = true;
		var x7 = false;
		var x8 = "string \r\n";
		var x9 = $"string {x8}";
		var x10 = string.Format("string {0}", 0); // TODO
		var x11 = "string"u8; // TODO
		var x12 = 'c';
		var x13 = null as object;
		var x14 = E.Null; // TODO
		int[] x15 = { 0 };
		var x16 = x15[0];

		var x17 = +0 + 0 - -0 * 0 / 1;
		var x18 = !true && true || true;
		var x19 = ~0 & 0 | 0 ^ 0;
		var x20 = ++x1 + x1--;
		var x21 = (0 < 0) == (0 <= 0) != (0 > 0) && (0 >= 0);
		var x22 = false ? 0 : 0;
	}

	void keywords(in int p1, out int p2, ref int p3, params int[] p4)
	{
		p2 = 0;

		var x1 = null as object;
		var x2 = null is object;
		scoped ref int x3 = ref p3; // TODO
		var x4 = default(int);
		var x5 = this;
		var x6 = nameof(x1);
		var x7 = typeof(global::B);
		var x8 = sizeof(int); // TODO
		var x9 = new R() with {}; // TODO
		int[] x10 = {};
		var x11 =
			from x in x10
			let xl = x
			join xj in x10 on x equals xj
			where true
			orderby x ascending
			orderby x descending
			group x by x into x
			select x;

		unsafe
		{
			var b1 = stackalloc int[1];
			var b2 = new int[1];
			fixed (int* b3 = &b2[^1]) {}
			int U1<T>(delegate* managed<T> p) => 0;
			int U2<T>(delegate* unmanaged[Cdecl]<T> p) => 0; // TODO
			int U3<T>(delegate* unmanaged[Stdcall]<T> p) => 0; // TODO
			int U4<T>(delegate* unmanaged[Fastcall]<T> p) => 0; // TODO
			int U5<T>(delegate* unmanaged[Thiscall]<T> p) => 0; // TODO
		}
		checked {}
		unchecked {}
		lock (null) {}
		using (null) {}
		new object();
	}

	int keywords2(object x) => x switch
	{
		var (y) when x is (int or char) => 0,
			>= 1 and < 2 or not null => 0,
	};

	void control1()
	{
		int[] x = { 0 };

		if (true) {} else {}
		switch (1)
		{
			case (> 0) when true: break;
			default: break;
		}

		for (;;) { break; } // TODO
		for (int x;;) { break; }
		foreach (int _ in x) { continue; }
		while (false) {}
		do {} while (false);

		try { throw new Exception(); } catch when (true) {} finally {}
		0 ? 0 : 1;
		0 ? false : true; // BUG
		0 ?? 1;
		x ??= null; // TODO
		null!;
		null?.GetType()
		null!.GetType()

		goto Label2;
		goto Label;
		Label:
		return;
	}

	IEnumerator control2()
	{
		if (Random.Shared.Next() < 0) // TODO
			yield break;
		else
			yield return 0;
	}

	async void control3()
	{
		await new Task(() => {});
	}

	void parameters(int p = 0)
	{
		var x = p; // TODO
	}

	/// <summary>foo</summary>
	/// <param name="foo">foo</param> // TODO
	/// <returns>foo</returns>
	void comments()
	{
		// single line comment
		/* Block Comment */

		/// single line doc comment
		/** block doc comment */
	}
}
