cd 'C:\Users\User\source\repos\jelek21\Exercise1SortingCpp'
set title 'Results of performance testing'  
set xlabel 'Length of the vector'
set ylabel 'Time spent to sort (sec)'
set grid
set pointsize 1.5
plot "Results.dat" u 1:2 t 'Quicksort' w linespoint