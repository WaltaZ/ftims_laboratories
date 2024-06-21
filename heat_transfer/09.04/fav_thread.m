function z = fav_thread(x,t)
%FAV_THREAD Summary of this function goes here
%   Detailed explanation goes here
T_0 = 20;
L = 10;
a = 1;
z = 0;
sum_limit = 5;
for k = 0:sum_limit
    z = z + (1/(2*k + 1)) * sin(((2 * k + 1) * pi * x)/L) * exp(-((2 * k + 1)^2 * pi^2 * a * t)/(L^2));
end
z = z * (4 * T_0)/(pi);

