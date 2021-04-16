clear all;close all;clc;

T = readtable('D:\Visone\Documents\IngegneriInformaticaLaureaMagistraleM63\I-ANNO\I-SEMESTRE\ASD\Preparazione_Esame\merge_sort\measurements.csv');
T3 = readtable('D:\Visone\Documents\IngegneriInformaticaLaureaMagistraleM63\I-ANNO\I-SEMESTRE\ASD\Preparazione_Esame\merge_sort\measurements_counting_sort_best_case.csv');
T4 = readtable('D:\Visone\Documents\IngegneriInformaticaLaureaMagistraleM63\I-ANNO\I-SEMESTRE\ASD\Preparazione_Esame\merge_sort\measurements_counting_sort_worst_case.csv');

x = [1:1:9999];
y = table2array(T)';
y_count_sort = table2array(T3)';
y_count_sort_w_case = table2array(T4)';

myfun = @(a,x)a(1).*(x.*(log2(x)));

y2 = 0.23.*x.*log2(x);
y3 = 0.05.*x.*log2(x);

ahat = lsqcurvefit(myfun,[1,1],x,y);
y = movmean(y,10);
y_count_sort = movmean(y_count_sort,10);
y_count_sort_w_case = movmean(y_count_sort_w_case,20);

figure(1);
plot(x,myfun(ahat,x),'b-',x,y,'m-',x,y2,'r-',x,y3,'g-');
title('Merge Sort time complexity');xlabel('length of the input vector') 
ylabel('Time execution in us');legend({'Merge Sort execution time approximation','Merge Sort real execution time','c1*n*log2(n)','c2*n*log2(n)'},'Location','northwest') 

figure(2);title('Merge Sort vs Counting Sort');
plot(x,y,'b-',x,y_count_sort,'r-');
xlabel('length of the input vector') 
ylabel('Time execution in us');legend({'Merge Sort real execution time','Counting Sort real execution time'},'Location','northwest') 

figure(3);title('Counting Sort Best Case vs Worst Case');
plot(x,y_count_sort,'b-',x,y_count_sort_w_case,'r-');
xlabel('length of the input vector') 
ylabel('Time execution in us');legend({'Counting sort best-case','Counting Sort worst case'},'Location','northwest') 

figure(4);title('Counting Sort Worst Case vs MergeSort');
plot(x,y_count_sort_w_case,'b-',x,y,'r-');
xlabel('length of the input vector');
ylabel('Time execution in us');legend({'Counting sort worst-case','Merge Sort'},'Location','northwest') 
