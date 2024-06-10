addpath 'D:\Polibuda XD\ftims_laboratories\heat_transfer_project\numerical_solution'
addpath 'D:\Polibuda XD\ftims_laboratories\heat_transfer_project\analytical_solution'

global a lambda q_0 beta R;

a = 1e-05; % Thermal diffusivity
lambda = 8; % Thermal conductivity
q_0 = 1e05; % Heat efficiency in the point of r = 0
R = 0.5; % Radius of the sphere

t_end = 5400;
delta = 100;

r = linspace(0, R, delta);
t = linspace(0, t_end, delta);
timeindex = 90;

num_sol = num_heatsol(r, t);
an_sol = an_heatsol(r, t, 10);

%{
pcolor(r, t, num_sol);
colormap('jet')
cb = colorbar;
shading flat;
%}

plot(r, an_sol(length(t), :));
xlim([0 0.5]);
ylim([0 250]);
xlabel('Promień R [m]');
ylabel('Temperatura T');