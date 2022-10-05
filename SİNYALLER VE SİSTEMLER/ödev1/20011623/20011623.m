clc;
clear all;
close all;

x=input('Enter the first signal:');
x0=input('Enter the x0:'); 
n=length(x);
y=input('Enter the second signal:');
y0=input('Enter the y0:');
m=length(y);
axis = -(x0*y0- 1):1:n + m- 1 - x0*y0 ;
Z1=myconv(x,n,y,m);%% kendi fonksiyonumla
Z2=conv(x,y);%% hazır conv fonksiyonuyla


figure;
subplot(4,1,1);stem(x, '-b^');xlabel('n');
ylabel('x[n]'); grid on;
subplot(4,1,2); stem(y, '-ms');
xlabel('m'); ylabel('y[m]'); grid on;
subplot(4,1,3); stem(axis,Z1, '-ro');
ylabel('z1[k]'); xlabel('----->k'); grid on;
title('convolution of two signals with myconv')
subplot(4,1,4); stem(axis,Z2, '-ro');
ylabel('z2[k]'); xlabel('----->k'); grid on;
title('convolution of two signals with conv')

fprintf('vector illustration\n');
x
y
Z1
Z2

recObj = audiorecorder; %% kayıt başlatma nesnesi
disp('Start speaking.') %% ekrana mesaj
recordblocking(recObj, 5); %% kayıt işlemi
disp('End of Recording.'); %% ekrana mesaj
x1 = getaudiodata(recObj); %% kaydedilen sesi x değişkenine saklama

recObj = audiorecorder; 
disp('Start speaking.') 
recordblocking(recObj, 10); 
disp('End of Recording.');
x2 = getaudiodata(recObj); 

sound(x1); %% 5 saniyelik ses
sound(x2); %% 10 saniyelik ses  

l=40000;
h=zeros(1,l);
h(1)=1;
h(401)=0.4;
h(801)=0.4;

%% h sinyalinin hazır conv ile konvolüsyonu
Y1=conv(x1,h);
sound(Y1);
Y2=conv(x2,h);
sound(Y2);

%% h sinyalinin myconv ile konvolüsyonu
My_Y1=myconv(x1,length(x1),h,length(h));
sound(My_Y1);
My_Y2=myconv(x2,length(x2),h,length(h));
sound(My_Y2);



%%myconv fonksiyonu:
function[F]=myconv(x,n,y,m)
X=[x,zeros(1,n)];
Y=[y,zeros(1,m)];
for i=1:n+m-1
    F(i)=0;
    for j=1:m
        if(i-j+1>0)
            F(i)=F(i)+X(j)*Y(i-j+1);
        else
        end
     end
end
end









