#!/usr/bin/gnuplot -persist
set term epslatex color solid
set output 'head-losses-qa.tex'
set format '$%g$'
set xlabel '$Q_A$, (cm$^3$/s)'
set ylabel '$H$, (cm)'
set yrange [:30]
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
     'results-table.dat' u 2:5 t 'Venturimeter' w lp ls 1, \
     '' u 2:6 t 'Orifice plate meter' w lp ls 2, \
     '' u 2:7 t 'Rotameter' w lp ls 3, \
     '' u 2:8 t 'Wide-angled diffuser' w lp ls 5, \
     '' u 2:9 t 'Right-angled bend' w lp ls 6
