```toml
markup.goldmark.renderer.hardWraps = true
[markup]
	anchorLineNos = true
```

- ```toml
	markup.goldmark.renderer.hardWraps = true
	[markup]
		anchorLineNos = true
	```

- ```toml
	markup.goldmark.renderer.hardWraps = true
	[[markup]]
		anchorLineNos = true
	```

- ```toml
	#: preprocessor

	# Comment

	foo1 = 0
	foo2 = +0
	foo3 = 1_0

	foo4 = 0.0
	foo5 = +0.0
	foo6 = 1_0e6
	foo7 = 1_0e+6
	foo8 = 1_0.0e6
	foo9 = 1_0.0e+6
	foo10 = 1_0E6
	foo11 = 1_0E+6
	foo12 = 1_0.0E6
	foo13 = 1_0.0E+6
	foo14 = 1_0e06 # TODO
	foo15 = 1_0.0e06 # TODO
	foo16 = 1_0E06 # TODO
	foo17 = 1_0.0E06 # TODO
	foo18 = inf
	foo19 = +inf
	foo20 = nan
	foo21 = +nan

	foo22 = 0x0
	foo23 = 0x0_0
	foo24 = 0o0
	foo25 = 0o0_0
	foo26 = 0b0
	foo27 = 0b0_0

	foo28 = true

	foo29 = 2024-01-01T00:00:00Z
	foo30 = 2024-01-01T00:00:00-00:00
	foo31 = 2024-01-01T00:00:00.000000-00:00
	foo32 = 2024-01-01 00:00:00Z
	foo33 = 2024-01-01 00:00:00-00:00
	foo34 = 2024-01-01 00:00:00.000000-00:00

	foo35 = 2024-01-01T00:00:00
	foo36 = 2024-01-01T00:00:00.000000
	foo37 = 2024-01-01 00:00:00
	foo38 = 2024-01-01 00:00:00.000000

	foo39 = 2024-01-01
	foo40 = 00:00:00
	foo41 = 00:00:00.000000

	foo42 = "bar"
	foo43 = "\b\t\n\f\r\"\\\u0000\U00000000"
	foo44 = " 'bar' "
	foo45 = """ "bar" """
	foo46 = """\
	bar"""

	foo47 = 'bar'
	foo48 = '\b\t\n\f\r\\\u0000\U00000000'
	foo49 = ' "bar" '
	foo50 = ''' 'bar' '''
	foo51 = '''\
	bar'''

	"foo52" = 0 # TODO: Don't color quotes
	'foo53' = 0
	foo54.bar = 0 # TODO: Table and array keys are not consistently labelled
	foo55 . bar = 0
	foo56."bar" = 0
	"foo57".bar = 0
	"foo58.bar" = 0 # TODO: Don't color dot
	foo60.'bar' = 0
	'foo61'.bar = 0
	'foo62.bar' = 0

	foo63 = [ 0, 1, ]
	foo64 = [ [ 0, 0, ], [ 1, 1, ], ]
	foo65 = { bar = 0 }
	foo66 = { bar.baz = 0 }
	foo67 = { "bar" = 0 }
	foo68 = { "bar".baz = 0 }
	foo69 = { bar."baz" = 0 }
	foo70 = { "bar.baz" = 0 }

	[foo71]
	bar = 0

	[foo72.bar]
	baz = 0

	["foo73".bar]
	baz = 0

	[foo74."bar"]
	baz = 0

	["foo75.bar"]
	baz = 0

	[[foo76.bar]]
	baz = 0

	[["foo76".bar]]
	baz = 0

	[[foo76."bar"]]
	baz = 0

	[["foo76.bar"]]
	baz = 0

	[[foo77]]
	bar = 0

	[[foo77.bar]]
	baz = 0

	[["foo77".bar]]
	baz = 0 # BUG

	[[foo77."bar"]]
	baz = 0 # BUG

	[["foo77.bar"]]
	baz = 0

	[[foo78]]

	[foo78.bar]
	baz = 0

	["foo78".bar]
	baz = 0

	[foo78."bar"]
	baz = 0

	["foo78.bar"]
	baz = 0
	```
