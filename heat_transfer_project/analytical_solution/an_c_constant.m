function c_const = an_c_constant(c_m)
    global R q_0 lambda;

    I_1 = (1/c_m^2) * sin(c_m*R) - (R/c_m)*cos(c_m*R);
    I_2 = ((3*R^2/c_m^2) - (6/c_m^4))*sin(c_m*R) + ((6*R/c_m^3) - (R^3/c_m))*cos(c_m*R);
    I_3 = ((4*R^3/c_m^2) - (24*R/c_m^4))*sin(c_m*R) + ((12*R^2/c_m^3) - (24/c_m^5) - (R^4/c_m))*cos(c_m*R) + (24/c_m^5);

    c_const = -(((q_0*R)/(6*lambda))*I_1) + ((q_0/(3 * lambda * R))*I_2) - ((q_0/(6 * lambda * R^2))*I_3);
end