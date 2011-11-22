#! /usr/bin/perl

$x=123456;

if (1234 + 34 == 5432)
{
	print "aaaaaaaaaaaaa";
}
else
{
	print "bbbbbbbbbbbbbbbbbb";
}
print "$x\n";

$x=0x34;
print "x=$x\n";

$value = 9.01e+21 + 0.01 - 9.01e+21;
$value = 9.01e+21 - 9.01e+21 + 0.01;
print "value=$value";

$number = 123;
$text = "This text contains the number $number";
print "$text\n";

@var = (1, 2, 3);
print (@var, "var\n");

$var[5]=32;
@var=(1..10);
print "@var\n";

$count=@var;
print "length=$count\n";

@array = reverse(@var);
print "array=@array\n";
@array1 = sort(@array);
print "array1=@array1\n";

$string = join(":", "this", "is", "a", "string");
print "string=$string\n";

@array2 = split(":", $string);
print (@array2, "\n");

open(outfile, ">>outfile");
print outfile ("Here is an output line.\n");

open(infile, "outfile");
#$line = <infile>;
#print "read a line: $line";

@allline = <infile>;
print "read all: @allline\n";

print "@ARGV\n";

$~ = "MYFORMAT";

write;

format MYFORMAT=
============================================================
Here is the text I want to display.
============================================================
.

my $value = 10;
my $pointer = \$value;
print "\n Pointer Address $pointer of $value \n";
print "\n What Pointer *($pointer) points to $$pointer\n";
