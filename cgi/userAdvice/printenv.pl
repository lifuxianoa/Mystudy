#! /usr/bin/perl

$advicefile = "/cgi-bin/UserAdvice.txt";

$method = $ENV{'REQUEST_METHOD'};

print "Content-type:text/html\r\n\r\n";

while (($key, $value) = each(%ENV))
{
	print "$key:$value\n<br>";
}


