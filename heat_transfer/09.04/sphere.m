function z = sphere(r, t)
%SPHERE Summary of this function goes here
%   Detailed explanation goes here

T_0 = 20;
R = 10;
a = 1;
z = 0;
sum_limit = 50;

for n = 1:sum_limit
    element = 1/n * sin((n * pi * r)/R) * exp(-(n^2 * pi^2 * a * t)/(R^2));
    if(mod(n, 2) == 0)
        element = -element;
    end
    z = z + element;
end
z = z * (2 * R * T_0)/(pi * r);

end

