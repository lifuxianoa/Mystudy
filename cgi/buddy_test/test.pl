#! /usr/bin/perl -w

use strict;
use CGI qw(:all);

print header;
my $method = param("method");
print `$method`;

my @cookie_list = cookie();
foreach my $cookie (@cookie_list)
{
    my $cookie_value = cookie($cookie);
    print "$cookie: $cookie_value\n";
}
