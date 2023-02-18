import * as assert from "assert";
//import A = require("assert");
declare module "module" {}
namespace Namespace {}
export default class Class {};
//package

function keywords()
{
	const x1 = 0;
	let x2: any;
	var x3: any;

	let x4: any;
	let x5 = new Promise(() => {});
	delete x5[0];
	debugger;

	0 as number;
	(x: any): x is any => x;
	typeof(x1);
	type T1 = keyof Math;
	type T2<T> = T extends (infer T) ? T : any;
	x4 instanceof x4;
	class Base {}
	class Foo extends Base
	{
		constructor() { super(); }
		public Bar1(): this { return this };
		protected Bar2() {}
		private Bar3() {}
		static get Bar() { return 0; }
		static set Bar(x) {}
	};
}

void function types()
{
	let x1: undefined = undefined;
	let x2: null = null;
	let x3: unknown | never | any | boolean | string | void;
	let x4: number[] = [];
	let x5: Array<number> = new Array<number>();

	class Class implements Class {};

	interface Interface {};
	interface ExtendInterface extends Interface {};

	enum Enum { Value = 0, };

	type Type = {};
	type IntersectionType = Type & {};
	type UnionType = Class | ExtendInterface | Enum | IntersectionType;
}

function literals()
{
	let x1 = undefined;
	let x2 = null;
	let x3 = 0 && true && false;
	let x4 = "string %d %i \n\t";
	let x5 = [];
}

function functions()
{
	let x1 = () => {};
	Math.max(0, 0);
}

export async function controlFlow()
{
	for (let i in []) { i = i; }
	for (let x of []) { x = x; }
	for (let i = 0; i < 0; i++) {}
	while (true) { break; }
	do { continue; } while (false);
	try { throw false; } catch {} finally {}
	if (false) {} else {}
	switch (0) { case 0: break; default: break; }
	function* G() { yield null; };
	return;
}
