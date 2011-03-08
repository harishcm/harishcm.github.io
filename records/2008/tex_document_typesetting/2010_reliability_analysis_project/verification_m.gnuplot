#!/usr/bin/gnuplot -persist
set term epslatex color solid
set output 'verification_m.tex'
#set term x11
set format '$%g$'
set xlabel '$\bar{m}/\bar{m_b}$'
set ylabel '$\beta$' 2,0
set yrange [2:3]
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
     'vary_m.dat' u 1:5 t 'Section D FORM' w lp ls 1, \
     'vary_m_monte_carlo.dat' u 1:5 t 'Section D Monte Carlo' w lp ls 2
