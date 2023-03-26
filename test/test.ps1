# Control Flow
#Requires -RunAsAdministrator
foreach ($font in $fonts)
exit

# Keywords
$local:foo
$global:foo
function foo {}
class foo {}

# Types
function foo {}
class foo {}
[String] $foo

# Functions
function foo {}
("ls") | Invoke-Expression

# Function Parameters
function foo([String] $foo) {}

# Variables
$foo
$Profile.CurrentUserAllHosts

# Literals
"foo"
'foo'
$true
1e6

# Escape Sequences
"\n \t"

# Format Specifiers
"{} {0}"

# Comments
# foo
