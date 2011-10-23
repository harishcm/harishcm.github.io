#!/usr/bin/gnuplot -persist
#set term x11
set term epslatex solid
set output 'H_T.tex'
set logscale x
set xlabel '$T$ (hr)'
set xrange [0.01:1.0]
#set xtics add (0.5,1.5,2.0)
#set xtics add ("" 1.1 1,"" 1.2 1,"" 1.3 1,"" 1.4 1,"" 1.5 1,"" 1.6 1,"" 1.7 1,"" 1.8 1,"" 1.9 1)
set logscale y
set ylabel offset 2,0 'H (m)'
set yrange [0.05:1.1]
set ytics add (0.05,0.2,0.5)
set style line 1 lt 1 pt 1 ps 1 lw 2
set style line 2 lt 2 pt 2 ps 1 lw 2
set style line 3 lt 3 pt 3 ps 1 lw 2
set style line 4 lt 4 pt 4 ps 1 lw 2
set style line 5 lt 5 pt 5 ps 1 lw 2
set style line 6 lt 7 pt 7 ps 1 lw 2
set style line 7 lt 8 pt 8 ps 1 lw 2
set style line 8 lt 9 pt 9 ps 1 lw 2
set style line 9 lt 10 pt 10 ps 1 lw 2
set style line 10 lt 11 pt 11 ps 1 lw 2
plot \
     'H_T.dat' u 1:2 notitle w lp ls 1, \
     1/0 t 'Filter 1 (Fine): Unable to suggest relation' w lp ls 1, \
     'H_T.dat' u 3:4 notitle w p ls 2, \
     0.109*x**0.087 notitle w l ls 2, \
     1/0 t 'Filter 2 (Coarse): $H=0.109T^{0.087}$, R$^2$=0.74' w lp ls 2, \
     'H_T.dat' u 3:5 notitle w lp ls 3, \
     1/0 t 'Filter 3 (Mixed): Unable to suggest relation' w lp ls 3
