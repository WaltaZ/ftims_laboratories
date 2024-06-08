function [c, f, s] = num_heateq(r, t, u, dudx)
    global a q_0;
    
    c = 1/a;
    f = dudx;
    s = q_0 - (10/q_0)*r;
end