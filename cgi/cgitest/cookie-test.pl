#! /usr/bin/perl -w

use strict;
use CGI qw(:all);
use CGI::Carp qw(fatalsToBrowser);

my($requested_color, $old_color, $color_cookie) = ("", "");

$old_color = "blue"; #Default value

#Is there a new color requested?
if (defined param('color'))
{
    $requested_color = param('color');
}

#What was the old color, if any?
if (defined cookie('bgcolor'))
{
    $old_color = cookie('bgcolor');
}

if ($requested_color and ($old_color ne $requested_color))
{
    #Set the cookie in the browser
    $color_cookie = cookie(-name => 'bgcolor',
            -value => $requested_color,
            -expires => '+5s');
    print header(-cookie => $color_cookie);
}
else
{
    #Nothing's changed, no need to set the cookie.
    $requested_color = $old_color;
    print header;
}

print <<END_OF_HTML
<HTML>
<HEAD>
<TITLE>Set your background color</TITLE>
</HEAD>
<BODY BGCOLOR="$requested_color">
<FORM>
<SELECT NAME="color">
    <OPTION value="red">Red
    <OPTION value="blue">Blue
    <OPTION value="yellow">Yellow
    <OPTION value="white">White
</SELECT>
<INPUT TYPE=SUBMIT VALUE="Set the color">
</FROM>
</BODY>
</HTML>
END_OF_HTML
