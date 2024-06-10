function [c, f, s] = num_heateq(r, t, u, dudx)
    global a q_0 R lambda;
    
    c = 1/a;
    f = dudx;
    s = (q_0/lambda)*(1 - r/R);
end