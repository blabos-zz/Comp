#!/usr/bin/env perl

use strict;
use warnings;
use FindBin qw($Bin);
use Carp qw(croak);

my $exit_code = main();
exit $exit_code;

sub main {
    chdir $Bin;

    test_string();
    test_reserved_words();

    cleanup();

    return 0;
}

sub test_string {
    my @compile = qw{ gcc -Wall -c ../string.c -o string.o };
    croak if system @compile;

    while (<0*.c>) {
        croak
          if system "gcc -Wall -o $_.bin $_ string.o"
          or system "./$_.bin";
    }
}

sub test_reserved_words {
    my @compile = qw{ gcc -Wall -c ../reserved_words.c -o reserved_words.o };
    croak if system @compile;

    while (<1*.c>) {
        croak
          if system "gcc -Wall -o $_.bin $_ string.o reserved_words.o"
          or system "./$_.bin";
    }
}

sub cleanup {
    print "$/Cleaning up$/";

    qx{ rm *.o *.bin };
}
