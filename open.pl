#!/usr/bin/perl -w

use strict;
use warnings;

my $cmd = "vim -p";
foreach my $fn (@ARGV) {
  (my $hdr_path = $fn) =~ s/\.[^.]+$//;
  $hdr_path = "./include/$hdr_path.h";

  my $src_path = "./src/$fn.cpp";
  if($fn =~ m/src/) { $src_path = $fn; }

  $cmd = "$cmd $src_path $hdr_path";
}

system("$cmd");
