func = @(x, y) x^2*y^2;

res = 100;

x = linspace(-2, 2, res);
y = linspace(-2, 2, res);
z = zeros(res, res);

for i = 1:length(x)
    for j = 1:length(y)
        z(i, j) = func(x(i), y(j));
    end
end

pcolor(x, y, z);
colormap('jet')
cb = colorbar;
xlabel('x');
ylabel('y');
shading flat;