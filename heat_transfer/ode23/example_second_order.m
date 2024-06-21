%{

Functions encoded the same way as with bvp4c.
For initial conditions:
y0 = [a, b] which is identical to defining:
y(0) = a, y'(0) = b.

%}

func = @(x, y) [y(2); (-2*y(1)) - (3*y(2))];
func_0 = [0; 5];

x = linspace(0, 3, 100);
sol = ode23(func, x, func_0);
y = deval(sol, x);
plot(x, y(1, :));