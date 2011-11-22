#! /usr/bin/perl

use strict;
use warnings;

my $filename = 'library.xml';

use XML::LibXML;

my $parse   = XML::LibXML->new();
my $doc     = $parse->parse_file($filename);

foreach my $book ($doc->findnodes('/library/book/title'))
{
#    my ($title) = $book->findnodes('./title');
#    print $title->to_literal, "\n";
    print $book->to_literal, "\n";
}

