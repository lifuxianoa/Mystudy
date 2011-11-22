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
    if (/^\s*inet addr:([\d\.]*)\s*Bcast:([\d\.]*)\s*Mask:([\d\.]*)/)
    {
        $host_ip = $1;
        $bcast = $2;
        $mask = $3;
        print "host_ip:$host_ip\n";
        print "bcast:$bcast\n";
        print "mask:$mask\n";
        last;
    }
}
close (FILE);


#获取CPU型号
unless (open(FILE, "/proc/cpuinfo"))
{
    die("cannot open input file /etc/cpuinfo\n");
}

while (<FILE>)
{
    if (/model name\s*: (.*)$/)
    {
        $cpu_type = $1;
        print "cpu Type:$cpu_type\n";
        last;
    }
}

#计算CPU利用率
sub get_cpu_stat
{
    my @stats;
    
    #Linux 系统，从/proc/stat来获取CPU信息
    open (FILE, "/proc/stat") or die "$!";

    while (<FILE>)
    {
        if (/^cpu .*/)
        {
            @stats = split;
        }
    }
    close($FILE);

    print "$stats[1] $stats[2] $stats[3] $stats[4]\n";
    my $total = $stats[1] + $stats[2] + $stats[3] + $stats[4];
    my $idle = $stats[4];
    return ($total, $idle);
}

my ($t1, $i1) = get_cpu_stat();
#sleep(1);
select(undef, undef, undef, 0.1);
my ($t2, $i2) = get_cpu_stat();

my $total = $t2 -$t1;
my $idle = $i2 -$i1;

my $per = 100 * ($total - $idle) / $total;

print "Per: $per\n";

