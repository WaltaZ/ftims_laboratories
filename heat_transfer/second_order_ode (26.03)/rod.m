%{
    === ENCODING THE DIFFERENTIAL EQUATION ===  
    We do the substitution when solving second order differential eqs
    y_1' = y_2
    y_1'' = y_2'
    dydx = [everything that is a derivative, everything that this derivative
    is equal to], so:
    dydx = [y(2), y(1) {blah blah blah} y(2)] where:
    y(2) in first row is y_1''
    y(2) in second row is y_1'
    y(1) in second row is y_1

    === BOUNDARY CONDITIONS === 
    if y(a) = c_1 and y(b) = c_2 we can transform them into:
    ya(1) - c_1 = 0
    yb(1) - c_2 = 0

    The index of bc function indicates the order of the derivative + 1
    Thus the boundary conditions have been encoded
    boundary_func = [first eq, second eq]
%}

q_v = 1.7e6;
lambda = 58;
rod_function = @(r, y) [y(2) (-(1/r)*y(2))-(q_v/lambda)];
rod_bc = @(ya, yb) [ya(2), yb(1) - 20];

r = linspace(0.00001, 0.001, 100);
rod_init = bvpinit(r, @(x) [x, x.^(2)]);

sol = bvp4c(rod_function, rod_bc, rod_init);
y = deval(sol, r);

plot(r, y(1, :));