set term png
set xra [0:63]
set yra [0:63]
set view map
set size square
unset key

set cbrange[0:0.4]
do for[i=0:99:1]{
  input = sprintf("data/%03d.dat",i)
  output = sprintf("data/%03d.png",i)
  print output
  set out output
  sp input w pm3d
}

