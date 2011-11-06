#! /usr/bin/perl

#initialize list to empty
$header = "";

while ($line = <>)
{
	#remove leading and trailing spaces
	$line =~ s/^\s+|\s+$//g;
	@words = split(/\s+/, $line);
	foreach $word (@words)
	{
		#remove closing punctuation. if any.
		$word =~ s/[.,;:-]$//;
		#convert all words to lower case
		$word =~ tr/A-Z/a-z/;
		&add_word_to_list($word);
	}
}

&print_list;

sub add_word_to_list
{
	local($word) = @_;
	local($pointer);

	#if item is empty, add first item.
	if ($header eq "")
	{
		$header = $word;
		$wordlist{$word} = "";
		return;
	}

	#if word identical to first element in list. Do noting.
	return if ($header eq $word);

	#see whether word should be the new first word in the list.
	if ($header gt $word)
	{
		$wordlist{$word} = $header;
		$header = $word;
		return;
	}

	#find place where word belongs.
	$pointer = $header;
	while ($wordlist{$pointer} ne ""
		&& $wordlist{$pointer} lt $word)
	{
		$pointer = $wordlist{$pointer};
	}

	#if word already seen, do nothing.
	return if ($word eq $wordlist{$pointer});

	$wordlist{$word} = $wordlist{$pointer};
	$wordlist{$pointer} = $word;
}

sub print_list
{
	local ($pointer);

	print ("Worlds in the file:\n");

	$pointer = $header;
	while ($pointer ne "")
	{
		print ("$pointer\n");
		$pointer = $wordlist{$pointer};
	}
}

