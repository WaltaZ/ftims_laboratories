function [c, f, s] = heateq(r, t, u, dudx)
    a = 1e-05; % Thermal diffusivity
    lambda = 8; % Thermal conductivity
    q_0 = 1e05; % Heat efficiency in the point of r = 0
    beta = 0.5; % Empirical coefficient of heat efficiency diminishing

    c = 1/a;
    f = dudx;
    s = (q_0/lambda) * exp(-beta * r);

end