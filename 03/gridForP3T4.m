%Grid for project 3 in SF2568 C++
clc; close all; clear

File_xValues = fopen("xValues.bin");
File_yValues = fopen("yValues.bin");

X = fread(File_xValues, inf, 'double');
Y = fread(File_yValues, inf, 'double');

%plot(X,Y, '-x')

hold on
scatter(X,Y,'.')
%line(X,Y)
axis([-11 6 -1 4]);

fclose(File_xValues);
fclose(File_yValues);                   