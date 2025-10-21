func = @(x, y) [y(2); (x^2*y(1))+(3*y(2))];
bc = @(ya, yb) [ya(1) - 10, yb(1) - 20];

x = linspace(0, 10, 100);
init = bvpinit(x, @(x) [x, x.^(2)]);

sol = bvp4c(func, bc, init);
y = deval(sol, x);

plot(x, y(1, :), 'LineWidth', 2);