x = linspace(0, 100, 2000);

oscillator_func = @(x, y) [y(2); -y(1) - 0.1 * y(2)];
result = ode23(oscillator_func, x, [0; 1]);
y = deval(result, x);

plot(x, y);