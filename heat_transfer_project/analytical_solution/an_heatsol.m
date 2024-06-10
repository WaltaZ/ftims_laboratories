function sol = an_heatsol(r, t, precision)
    for i = 1:length(t)
        for j = 1:length(r)
            sol(j, i) = an_tfunc(r(i), t(j), precision);
        end
    end
    
end