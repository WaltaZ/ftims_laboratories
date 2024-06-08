function sol = an_tfunc(r, t, precision)
    global R a q_0 lambda;

    sol = 0;

    for m = 1:precision
        c_m = m * pi / R;
        sol = sol + an_c_constant(c_m)*(sin(c_m * r)/r)*exp(-c_m^2 * a * t);
    end

    sol = sol + (q_0/(R * lambda)) * (r^3/12 - (R*r^2)/6) + ((R^2*q_0)/(12*lambda));
end