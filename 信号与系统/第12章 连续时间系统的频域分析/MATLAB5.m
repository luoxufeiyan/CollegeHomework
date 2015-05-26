clear all;
close all;
syms t f;
f=fourier(sin(2*t)^2);
f

-1/2*pi*dirac(w-4)+pi*dirac(w)-1/2*pi*dirac(w+4)

clear all;
close all;
syms t f;
f=fourier(cos(pi*t)+cos(2*pi*t));
f

pi*(dirac(pi + w) + dirac(w - pi)) + pi*(dirac(w - 2*pi) + dirac(2*pi + w))

clear all;
close all;
syms t f;
f=fourier(cos(2*t)*sin(3*t));
f

- (pi*(dirac(w - 1) - dirac(w + 1))*i)/2 - (pi*(dirac(w - 5) - dirac(w + 5))*i)/2