clear;

tmin = 0;
tmax = 1;
nt = 100;

t = linspace(tmin, tmax, nt);

xmin = 0;
xmax = 10;
nx = 100;

x = linspace(xmin, xmax, nx);

for i = 1:nx
    for j = 1:nt
        z(j, i) = sphere(x(i), t(j));
    end
end

surf(x, t, z);
shading flat;
colormap jet;