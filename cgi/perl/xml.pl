#! /usr/bin/perl

use strict;
use warnings;

my $filename = 'library.xml';

use XML::LibXML qw(:all);
use XML::LibXML;

my $parse   = XML::LibXML->new();
my $doc     = $parse->parse_file($filename);

foreach my $book ($doc->findnodes('/library/book/title'))
{
#    my ($title) = $book->findnodes('./title');
#    print $title->to_literal, "\n";
    print $book->to_literal, "\n";
}

sub read_xml
{
    my $node = @_;
    my $type = $node->nodetype;
    print $type;
}

#read_xml($doc->findnodes('/library'));
my $node = $doc->findnodes('/library');
#my $type = $node->nodetype;
my $name = $node->nodename;
print $name;
