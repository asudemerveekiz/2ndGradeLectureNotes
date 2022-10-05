clc;

clear all;
close all;

a = input(" Hazir ses icin 1'e kendi kaydettigim ses icin 2'ye basiniz:");
if a==1
[tel,fs]=audioread('tel.wav');
n=7;
else
[tel,fs]=audioread('mynumber.wav');
n=11;
end

sound(tel);

figure(1)
subplot(2,1,1);
plot(tel);
subplot(2,1,2);
stem(tel);

d = floor(length(tel)/n);
 figure(2)
for i = 0:n-1;
 
 tels=tel(i*d+1:(i+1)*d);
  
 temp = fft(tels); 
 P2 = abs(temp/d);
 P1 = P2(1:d/2+1);

 
 P1(2:end-1) = 2*P1(2:end-1);
 f = fs*(0:(d/2))/d;

 subplot(4,3,i+1);
 plot(f,P1);
 
title('Single-Sided Amplitude Spectrum of tel(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')

j=1;
max=j;

%enyuksek1 i bulma kismi 
    while(f(j)<1000 ) 
        if(P1(j)>P1(max))
            max=j;
        end  
        j=j+1;
    end
    enyuksek1=floor(f(max));
    
 %enyuksek2 yi bulma   
    max=j;
    while(f(j)<1500)
        if(P1(j)>P1(max))
            max=j;
            
        end  
        %fprintf("%f\n",f(i));
    
        j=j+1;
    end

    enyuksek2=floor(f(max));
  
  %%hangi tus oldugunu bulma
  noise=20; 
  %%gurultu degerler icin deger 20 olarak belirlendi
  
  if enyuksek1<=(697+noise)
    if enyuksek2<=(1209+noise)
        c='1';
   
    
    elseif enyuksek2<=(1336+noise)
        c='2';
    
    
    else 
        c='3';
    
     end

  elseif enyuksek1<=(770+noise)
    if enyuksek2<=(1209+noise)
        c='4';
    
    
    elseif enyuksek2<=(1336+noise)
        c='5';
    
    
    else 
        c='6';
    
    end 
  
  
  elseif enyuksek1<=(852+noise)
    if enyuksek2<=(1209+noise)
        c='7';
    
    
    elseif enyuksek2<=(1336+noise)
        c='8';
    
    
    else 
        c='9';
    end
     



  elseif enyuksek1<=(941+noise)
    if enyuksek2<=(1209+noise)
        c='*';
    
    
    elseif enyuksek2<=(1336+noise)
        c='0';
    
    
    else 
        c='#';
    end
     
end

fprintf("%c ",c);



end
