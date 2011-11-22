#! /usr/bin/perl

print "Content-type:text/html\r\n\r\n";

while (($key, $value) = each(%ENV))
{
	print "$key:$value\n<br>";
}


