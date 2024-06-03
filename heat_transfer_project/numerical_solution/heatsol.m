R = 10;
t_end = 5400;
delta = 100;

r = linspace(0, R, delta);
t = linspace(0, t_end, delta);

sol = pdepe(2, @heateq, @heatic, @heatbc, r, t);

surf(r, t, sol);
%{
figure(1)
for i = 1:delta
    plot(r, sol(i, :));
    pause(0.1);
    drawnow;
end
%}