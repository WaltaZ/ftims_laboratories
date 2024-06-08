function sol = an_heatsol(r, t, precision)
    for i = 1:length(r)
        sol(i) = an_tfunc(r(i), t, precision);
    end
end