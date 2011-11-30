#! /usr/bin/perl -w

use strict;
use CGI qw(:all);

#print header;
#my $method = param("method");
#print `$method`;

#my @cookie_list = cookie();
#foreach my $cookie (@cookie_list)
#{
#    my $cookie_value = cookie($cookie);
#    print "$cookie: $cookie_value\n";
#}
print "Content-type: text/html\n\n";
print qw(<?xml version="1.0" encoding="UTF-8"?>
<systeminfo>
	<deviceinfo>
		<hostname>hostname</hostname>
		<deviceid>deviceid</deviceid>
		<firmwareversion>firmwareversion</firmwareversion>
		<ipaddress>ip</ipaddress>
		<cputype>CPU-Type</cputype>
		<cpuoccupation>%CPU</cpuoccupation>
		<memory>
			<total>memorytotal</total>
			<used>memoryused</used>
			<free>memoryfree</free>
		</memory>
		<downloadspeed>downloadspeed</downloadspeed>
		<uploadspeed>uploadspeed</uploadspeed>
	</deviceinfo>
	<diskinfo>
		<disktype>disktype</disktype>
		<diskid>diskid</diskid>
		<uptime>uptime</uptime>
		<capacity>
			<total>capacity-total</total>
			<used>capacity-used</used>
			<free>capacity-free</free>
		</capacity>
		<partitions>
			<partition>
				<number>partition-number</number>
				<capacity>
					<total>partition-capacity-total</total>
					<used>partition-capactity-used</used>
					<free>partition-capactity-free</free>
				</capacity>
				<filesystem>filesystem</filesystem>
			</partition>
		</partitions>
	</diskinfo>
</systeminfo>);
