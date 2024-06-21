func = @(x, y) [y(2); - (y(2)./x) - (6000 * (1 + (0.001 * (y(1) - 500))))];
boundaries = @(y1, y2) [y1(1) - 0.001; y2(1) - 500];
finit = @(x) [x -x.^2];

x = linspace(0.001, 1, 20);
solinit = bvpinit(x,finit);
result = bvp4c(func, boundaries, solinit);
y = deval(result, x);

plot(x, y)