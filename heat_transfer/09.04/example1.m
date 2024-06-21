% wykres funkcji f(x,t)=t*sin(2*pi*x), x:[0;0.5], t:[0:10]
xmin=0;
xmax=0.5;
nx=21; % liczba wezlow polozeniowych
x=linspace(xmin,xmax,nx); % siatka polozeniowa - wezly
tmin=0;
tmax=10;
nt=51; % liczba wezlow czasowych
t=linspace(tmin,tmax,nt); % siatka czasowa – chwile
% teraz stablicujemy funkcje dla zdefiniowanych wyzej
% czasow i polozen
for i=1:nx
    for j=1:nt
        z(j,i)=sin(x(i)*2*pi)*t(j); % wiersz – czas, kolumna – położenie
    end
end
surf(x, t, z);
shading flat;
colorbar
xlabel('x [m]');
ylabel('t [s]');
colormap jet;