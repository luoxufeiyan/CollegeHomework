clear all;
close all;
syms t w;
ifourier((4*sin(w)/w)*cos(2*w));
ans

(2*pi*heaviside(x - 1) - 2*pi*heaviside(x + 1) - 2*pi*heaviside(x - 3) + 2*pi*heaviside(x + 3))/(2*pi)

clear all;
close all;
syms t w;
ifourier(3/(-(w^2)+j*w-2));
ans

-(2*pi*heaviside(-x)*exp(x) + 2*pi*exp(-2*x)*heaviside(x))/(2*pi)

clear all;
close all;
syms t w;
ifourier((sin(w/4)/(w/4))^2);
ans

-(8*fourier(cos(w/2)/w^2, w, -x) + 8*pi*x*(2*heaviside(x) - 1))/(2*pi)