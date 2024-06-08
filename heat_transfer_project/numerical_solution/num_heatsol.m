function sol = num_heatsol(r, t)
    sol = pdepe(2, @num_heateq, @num_heatic, @num_heatbc, r, t);
end