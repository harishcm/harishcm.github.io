#!/usr/bin/gnuplot -persist
set term epslatex color solid
set output 'qa-qt-v.tex'
set format '$%g$'
set xlabel '$Q_T$, (cm$^3$/s)'
set ylabel '$Q_A$, (cm$^3$/s)'
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
     'results-table.dat' u 3:2 notitle w p ls 1, \
     1.014*x-12.76 t '$y=1.014x-12.76 \quad R^2=0.9996$' w l ls 2
