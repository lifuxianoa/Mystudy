#! /usr/bin/perl

$advicefile = "UserAdvice.txt";
$advice_keyfile= "advice.key";
$counter = "counter.dat";
$counter_keyfile = "counter.key";

$method = $ENV{'REQUEST_METHOD'};


if ($method eq 'POST')
{
	read(STDIN, $input, $ENV{'CONTENT_LENGTH'});
}

if ($method eq 'PUT')
{
	$input = $ENV{'QUERY_STRING'};
}

if ($input eq "")
{
	&print_from;
	exit;
}

@form_inputs = split(/&/, $input);
foreach $pair(@form_inputs)
{
	($html_name, $html_value) = split(/=/, $pair);
	$html_value =~ tr/+//;
	$html_value =~ s/%([a-fA-F0-9][a-fA-F0-9])/pack("C".hex($1))/eg;
	$form_data{$html_name} = $html_value;
}

$yourname = $form_data{'yourname'};
$youremail = $form_data{'youremail'};
$youradvice = $form_data{'youradvice'};
$youradvice =~ tr/\n\r/\n/;
$youradvice =~ tr/\r/\n/;

#检查yourname和youradvice的值是否为空。
if ($yourname eq "" || $youradvice eq "")
{
	&html_header("用户意见薄－－响应", "输入错误");
	print "<H2>必须输入你的名字并发表意见！</H2>\n";
	&html_foot;
	exit;
}

#将用户信息存入用户意见文件
&print_file($yourname, $youremail, $youradvice);
&html_header("用户意见薄－－响应", "输入正确");
print "<H2>非常感谢您的感谢意见！</H2>\n";
&display_counter;
&html_foot;

#输出对用户信息的响应结果的头部分。
sub html_header
{
	local($headtitle, $bodytitle) = @_;
	print "Content-type:text/html\r\n\r\n";
	print "<HTML>\n";
	print "<HEAD>\n";
	print "<TITLE> $headtitle </TITLE>\n";
	print "</HEAD>\n";
	print "<BODY> <CENTER>\n";
	print "<H1> $bodytitle </H1>\n";
	print "</CENTER> <BR>\n";
}

#输出对用户信息的响应结果的结尾部分
sub html_foot
{
	print "</BODY>\n";
	print "</HTML>\n";
}

#将用户输入的表单变量存入用户意见簿
sub print_file
{
	local($name, $email, $advice) = @_;
	while (-e $advice_keyfile)
	{
		sleep 1;
	}

	open(LOCK, ">$advice_keyfile");
	close(LOCK);

	unless(open(FILE, ">>$advicefile"))
	{
		&html_header("用户意见薄－－响应", "文件错误");
		print "<H2> 不能打开$advicefile文件，请重试。<H2>\n";
		&html_foot;
		exit;
	}

	print FILE "所输入的名字：$name\n";
	print FILE "所输入的E-mail: $email\n";
	print FILE "所输入的意见：\n";
	print FILE "$advice\n";
	print FILE "*****************************************************\n";
	close FILE;
	unlink($advice_keyfile);
}

#如果没有用户输入数据，则输出HTML表单。
sub print_from
{
	&html_header("用户意见薄", "CGI程序实例：用户意见簿");
	print "<FORM METHOD=POST ACTION=/cgi-bin/userAdvice.pl>\n";
	print "<B>您的名字：</B> <INPUT SIZE=50 NAME=\"yourname\" > <BR> \n";
	print "<B>您的E-mail：</B> <INPUT SIZE=50 NAME=\"youremail\" > <BR> \n";
	print "<B>请发表意见：</B> \n";
	print "<TEXTAREA ROWS=5 COLS=50 NAME=\"youradvice\" >\n";
	print "</TEXTAREA>\n";
	print "<BR> <BR> <CENTER> \n";
	print "<INPUT TYPE=\"SUBMIT\" VALUE=\"发送\" NAME=\"Submit\"> \n";
	print "</CENTER> </FORM> \n";
	&html_foot;
}

#实现计数功能
sub display_counter
{
	#从计数文件中读数
	while (-e $counter_keyfile)
	{
		sleep 1;
	}

	open(LOCK, ">$counter_keyfile");
	close(LOCK);


	unless(open(COUNTER, "$counter"))
	{
		&html_header("用户意见簿－－响应", "文件错误");
		print "<H2> 不能打开$counter文件，请重试</H2>\n";
		&html_foot;
		exit;
	}

	$count = <COUNTER>;
	close(COUNTER);

	$count++;

	#显示计数
	print "<BR> <BR> <BR> <B> <CENTER> \n";
	print "您是给我们提宝贵意见的$count位用户.\n";
	print "</B> </CENTER> \n";

	#将新数存入计数文件中
	open(COUNTER, ">$counter");
	print COUNTER "$count\n";
	close COUNTER;
	unlink($counter_keyfile);
}

