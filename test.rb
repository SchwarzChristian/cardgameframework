#!/usr/bin/ruby
# -*- coding: utf-8 -*-

puts "test:"
`#{ARGV * " "}`.scan(/([^\n]*)\n([^§]*)§§§\n([^§]*)§§§\n/m).each do |data|
  print data[0] + ": "
  f = File.open("test/expected", "w")
  f.write(data[1])
  f.close
  f = File.open("test/got", "w")
  f.write(data[2])
  f.close
  s = `git diff test/got test/expected`.gsub "\n", "\n >"
  if (s.length > 0) then
    puts "fail\n >" + s.gsub(/.*---/m, "---").gsub(/[ab]\/test\//, "")
  else
    puts "ok"
  end
end

puts "profile:"
s = `gprof #{(ARGV * " ").split(/\s/)[0]}`
unit = s.match(/(?<unit>\S*)\/call\s*name/)[:unit]
s.scan(/(?:\d{1,3}\.\d\d\s+)(\d{1,3}\.\d\d)\s+\d{1,3}\.\d\d\s+(\d+)\s+\d{1,3}\.\d\d\s+(\d{1,3}\.\d\d)\s+([^\s_][^\n]*)/m).each do |data|
  puts " >" + data[3] + " executed " + data[0] + "s, " + data[1] + " x " + data[2] + unit
end
