#! /usr/bin/perl -w

use strict;
use CGI qw(:all);

print header();

foreach my $cookie (cookie())
{
    print "Cookie name: $cookie <BR>";
    print qq{Cookie value: "}, cookie($cookie), qq{"<P><HR>};
}
