clear all
clear

M=102 %yi qun gui mo
A=[0;0]
B=[10;10]
rand('state',1)
G=rand(2,100)*10
U=[A G B]
C=U'  % jiedian jvzheng
K=100;% die dai ci shu
Alpha=1;%xinxi qifa yin zi
Beta=5;% neng jian du xiang dui quan zhi
Rho=0.5;%xin xi su hui fa xi shu
Q=100;% xin xi qiang du
N=size(C,1) % jie dian gui mo
D=ones(N,N) % jie dian lu jin jv li
Length_best=ones(K,1)
    Routh_best=cell(K,1)
    Best_path=cell(K,1)
    Best_length=ones(K,1)
    Length_average=ones(K,1)
for i=1:N
    for j=1:N
        if i < j
           D(i,j)=sqrt((C(i,1)-C(j,1))^2+(C(i,2)-C(j,2))^2);
        end
    D(j,i)=D(i,j);
    end
end

Eta=ones(N,N); % neng jian du jvzheng

D_average=mean(mean(D));
R_max=D_average;
for i=1:N
    for j=1:N
        
Eta(i,j)=1/(D(i,j)+D(j,N));
    end
end
rand('state',5)
E=2*ones(N,1); % dian lu zong neng liang
E1=zeros(N,1); % mei ge jie dian zuo wei fa she jie dian suo xiao hao de zong neng liang 
E2=zeros(N,1);% mei ge jie dian zuo wei jie shou jie shou jie dian xiao hao de zong neng liang
E3=2*ones(N,1);% mei ge jie dian sheng yu neng liang
kd=2000;  % fa song kd ge bit
Eelec=50*10.^-9;
Eamp=100*10.^-12;
Tau = ones(N,N);
Routes=cell(K,M);
PL=zeros(K,M);
for k=1:K
    disp(k);
    
    for m=1:M
        W=1;
       
        Path=1;
        PLkm=0;
        Tabukm=ones(1,N); % jin ji biao
        Tabukm(1)=0;
        DD=D;% jie dian lu jin jv li
        
       while W~=N  
        for j=1:N
            if Tabukm(j)==0
                DD(W,j)=inf;% jie dian bu ke fang wen
            end
        end
      
        LJD=find(DD(W,:)<R_max);% cha zhao lu jin xiao yu ping jv lu jin de jie dian, zuo wei dai fang wen jie dian
        Len_LJD=length(LJD);
        if Len_LJD>=1
            PP=zeros(1,Len_LJD);
            for i=1:Len_LJD
                
                PP(i)=(Tau(W,LJD(i))^Alpha)*(Eta(W,LJD(i))^Beta)*E3(LJD(i));% zhuan yi gai lv
             
            end
           
            PP=PP/(sum(PP));
            Pcum=cumsum(PP); %yuan su lei jia ji qiu he
           
            Select=find(Pcum>=rand);%ruo ji suan de gai lv da yu yuan lai de jiu xuan ze zhe tiao lu xian
            
            to_visit=LJD(Select(1));
            Path =[Path ,to_visit];
            PLkm=PLkm+DD(W,to_visit);% yuan jv li jia shang fang wen de cheng shi jv li 
            E1(W)=E1(W)+Eelec*kd+Eamp*kd*(DD(W,to_visit)/10)^2;% fa she neng liang xiao hao jian p36
            E2(to_visit)=E2(to_visit)+Eelec*kd;%jie shou neng liang xiao hao 
            
           
            E3=E-E1-E2;% sheng yu neng liang
            Tau(W,to_visit)=(1-Rho)*Tau(W,to_visit)+Q/D(W,to_visit);%kao lv xin xi su hui fa ,geng xin hou de xin xi su
            W=to_visit;
            Tabukm(W)=0;
           
        else
            break ;
        end
            
      end
        
        Routes{k,m}=Path;%ji lu m ma yi lu jin
        if Path(end)==N
            PL(k,m)=PLkm;
        else
            PL(k,m)=0;
        end
    end% ma yi m pa yi ci jie dian N
    
    Delta_Tau=zeros(N,N);
    for m=1:M
        if PL(k,m)
            Rout=Routes{k,m};%di k ci die dai,m ma yi de lu jin
            TS=length(Rout)-1;
            PL_km=PL(k,m);
            
        end
    end
    if k>1
        PL(k,1)=Length_best(k-1);
    end
    Length_best(k)=min(PL(k,:));% xuan chu di k ci die dai zui jia lu jin 
    e=zeros(m,1);
    e_average=zeros(m,1);
    
    for m=1:M
        e(m)=0;
        g=Routes{k,m};%ji lu m ma yi lu jin
        f=length(g);
        for j=1:f
            e(m)=e(m)+E3(g(j));
        end
        e_average(m)=e(m)/f;
       L=zeros(M,1);
       f=zeros(M,1);
       L(m)=PL(k,m);
       f(m)=e_average(m)/L(m);
    end
       B=find(f==max(f));
       Best_path{k}=Routes{k,B(1)};
       Best_length(k)=PL(k,B(1));
       for i=1:length(B)
           q=B(i);
           Route=Routes{k,q};
           for j=2:length(Route)
                Delta_Tau(Route(j),Route(j-1)) = Q/Best_length(k);
           end
       end
    Position=find(PL(k,:)==Length_best(k));
    Routh_best{k}=Routes{k,Position(1)};
    Length_average(k)=mean(PL(k,:));
    for i=1:length(Position)
                p=Position(i);
                Route=Routes{k,p};
                for j=2:length(Route)
                    Delta_Tau(Route(j),Route(j-1))=Q/Length_best(k);
                end
    end
    
    Tau=Tau+Delta_Tau;
end
figure(1)
set(gcf,'Name','Figure of Length_best','Color','r')
plot(Length_best ,'r');
hold on

position=find(Best_length==min(Best_length));
shortest_path=Best_path{position(1)};
shortest_length=Best_length(position(1));
figure(3)
set(gcf,'Name','Figure of shortest_path','Color','r')
A=length(shortest_path);
scatter(C(:,1),C(:,2),10,'filled')

hold on

for i=2:A
    plot([C(shortest_path(i-1),1),C(shortest_path(i),1)],[C(shortest_path(i-1),2),C(shortest_path(i),2)],'r');
    hold on
end

figure(4)
set(gcf,'Name','Figure of remainder energy','Color','r')
plot(E3);
hold on
figure(5)
set(gcf,'Name','Figure of energy cost','Color','r')
plot(E1+E2);
hold on
Eaverage=mean(mean(E1+E2))
