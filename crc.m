clear all;
clc
close all;
 
Ns     = 128; 
RES    = 12;  
OFFSET = 0;    
T = 0:((2*pi/(Ns-1))):(2*pi);

 Y = sin(T);             % Sine wave

Y = Y + 1;    
Y = Y*((2^RES-1)-2*OFFSET)/(2+OFFSET);
Y = round(Y) ;                 

figure(1)
plot(T,Y)

crcGen = comm.CRCGenerator(...
    'Polynomial','X^16 + X^12 + X^5 + 1',...
    'InitialConditions',1,...
    'DirectMethod',true,...
    'FinalXOR',1);

bin = de2bi( Y );%here we are coverting deciaml data into binary data
bin=reshape(bin,[128*12,1]);
crcSeq = crcGen(bin);  %we are generating the crc sequence into the system

res=reshape(crcSeq(1:1536),[128,12]);
B = bi2de( res );
figure(2) % the binary converted sin wave
plot(T,B)

% with error

for i=1:size(crcSeq,1)
if(rand()<0.5)
    crcSeq(i)= xor(crcSeq(i),1);
end
end
res=reshape(crcSeq(1:1536),[128,12]);
bin = bi2de( res );
figure(3)% error introduced into the code.
plot(T,bin)