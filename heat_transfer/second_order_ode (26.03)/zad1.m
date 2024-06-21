func = @(x, y) [y(2); (-5 * y(1)) - 0.25];
boundaries = @(y1, y2) [y1(1) - 20; y2(1) + 10];
finit = @(x) [x x.^2];

x = linspace(0, 1, 20);
solinit = bvpinit(x,finit);
result = bvp4c(func, boundaries, solinit);
y = deval(result, x);

plot(x, y)