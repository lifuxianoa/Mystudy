#! /usr/bin/perl

use Sys::Hostname;

#获取系统主机名
my $hostname = hostname();
print "hostname:$hostname\n";

unless (open(FILE, "/etc/hostname"))
{
    die("cannot open input file /etc/hostname\n");
}
my $hostname = <FILE>;
#去掉字符串结尾换行符
chomp($hostname);
print "hostname:$hostname\n";
close (FILE);


#获取本机IP地址
unless (open(FILE, "/sbin/ifconfig|"))
{
    die("cannot open input file ifconfig\n");
}

while (<FILE>)
{
    if (/\s*inet addr:([\d\.]*)\s*Bcast:([\d\.]*)\s*Mask:([\d\.]*)/)
    {
        $host_ip = $1;
        $bcast = $2;
        $mask = $3;
        print "host_ip:$host_ip\n";
        print "bcast:$bcast\n";
        print "mask:$mask\n";
    }
}
close (FILE);


