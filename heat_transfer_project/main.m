addpath 'D:\Polibuda XD\ftims_laboratories\heat_transfer_project\numerical_solution'
addpath 'D:\Polibuda XD\ftims_laboratories\heat_transfer_project\analytical_solution'

global a lambda q_0 beta R;

a = 1e-03; % Thermal diffusivity
lambda = 8; % Thermal conductivity
q_0 = 1e02; % Heat efficiency in the point of r = 0
beta = 0.5; % Empirical coefficient of heat efficiency diminishing
R = 10; % Radius of the sphere

t_end = 5400;
delta = 100;

r = linspace(0.01, R, delta);
t = linspace(0, t_end, delta);

num_sol = num_heatsol(r, t);
an_sol = an_heatsol(r, t(4), 100);
plot(an_sol, r);
hold on;
plot(num_sol(4, :));

%surf(r, t, sol);

%{
figure(1)
for i = 1:delta
    plot(r, sol(i, :));
    pause(0.1);
    drawnow;
end
%}