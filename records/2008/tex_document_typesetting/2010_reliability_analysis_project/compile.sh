#!/bin/bash
./vary_n.gnuplot
./vary_m.gnuplot
./vary_q.gnuplot
./vary_s.gnuplot
./verification_s.gnuplot
./verification_m.gnuplot
epstopdf vary_n.eps
epstopdf vary_m.eps
epstopdf vary_q.eps
epstopdf vary_s.eps
epstopdf verification_s.eps
epstopdf verification_m.eps
pdflatex report.tex
