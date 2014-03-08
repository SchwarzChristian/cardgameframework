#!/usr/bin/ruby
# -*- coding: utf-8 -*-

teststring = `#{ARGV * " "}`

puts "profile:"
s = `gprof #{(ARGV * " ").split(/\s/)[0]}`
unit = s.match(/(?<unit>\S*)\/call\s*name/)[:unit]
s.scan(/(?:\d{1,3}\.\d\d\s+)(\d{1,3}\.\d\d)\s+\d{1,3}\.\d\d\s+(\d+)\s+\d{1,3}\.\d\d\s+(\d{1,3}\.\d\d)\s+([^\s_][^\n]*)/m).each do
  |data|
  puts " >" + data[3] + " executed " + data[0] + "s, " + data[1] + " x " + data[2] + unit if not /void out</.match data[3]
end

puts "test:"
teststring.scan(/([^\n]*)\n([^§]*)§§§\n([^§]*)§§§\n/m).each do |data|
  File.write "test/expected", data[1]
  File.write "test/got", data[2]
  print data[0] + ": "
  s = `git diff --no-index test/got test/expected`.gsub "\n", "\n >"
  if (s.length > 0) then
    puts "fail\n >" + s.gsub(/.*---/m, "---").gsub(/[ab]\/test\//, "")
  else
    puts "ok"
  end
end
