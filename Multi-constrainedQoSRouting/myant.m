clear all
clear
load('delay.mat')
x=[43 153 154 116 88 18 34 8 100 25 64 92 120 156 134 3 40 73 108 138 42 4 91 73 118 152 87 66 113 66 123 37 57 19 10 10 45 61 141 128 100 147 154]
y=[142 140 113 112 112 128 109 98 71 66 80 78 74 73 94 49 49 49 50 48 25 4 27 2 13 6 136 139 140 125 138 88 119 89 80 32 7 20 60 32 7 26 52]
first = [24 8 33 31 14 36]
second = [3 1 35 37 41 38]
third = [6 28 2 32 22 26]
fourth = [32 40 29 43 35 2]
all = [first',second',third',fourth']
all = all'
M=102
K=100;% die dai ci shu
Alpha=1;%xinxi qifa yin zi
Beta=5;% neng jian du xiang dui quan zhi
Rho=0.5;%xin xi su hui fa xi shu
Q=100;% xin xi qiang du
N = size(delay,1)
D = delay
length_best = ones(K,1)
Routh_best = cell(K,1)
Best_path = cell(K,1)
Best_length = ones(K,1)
length_average = ones(K,1)

eta = ones(N,N);

D_average = mean(mean(D));
R_max = D_average;

for i = 1 : N
	for j = 1 : N
	eta(i,j) = 1/D(i,j);
	end
end

Eelec = 50*10.^-9;
Eamp = 100*10.^-12;
Tau = ones(N,N);
Routes = cell(K,M);
PL = zeros(K,M);
for k = 1 : K
	W = all(1,1);

	disp(k);
	for m = 1 : M
	path = all(1,1);
	plkm = 0;
	tabukm = ones(1,N);
	tabukm(all(1,1)) = 0;
	DD = D;
	while(ismember(0,ismember(all(1,:),Path)))
		for j = 1 : N
			if tabukm(j) == 0
				DD(W,j) = inf;
			end
		end
		LJD = find(DD(W,:)<R_max);
		Len_LJD = length(LJD);
		if Len_LJD >= 1
			PP = zeros(1,Len_LJD);
			for i = 1 ：Len_LJD
					PP(i)=(Tau(W,LJD(i))^Alpha)*(Eta(W,LJD(i))^Beta)*E3(LJD(i));% zhuan yi gai lv
			end
		PP=PP/(sum(PP));
		Pcum=cumsum(PP); %yuan su lei jia ji qiu he
		
		Select=find(Pcum>=rand);%ruo ji suan de gai lv da yu yuan lai de jiu xuan ze zhe tiao lu xian
		
		to_visit=LJD(Select(1));
		
    Path =[Path ,to_visit];
    PLkm=PLkm+DD(W,to_visit);% yuan jv li jia shang fang wen de cheng shi jv li 
 
    Tau(W,to_visit)=(1-Rho)*Tau(W,to_visit)+Q/D(W,to_visit);%kao lv xin xi su hui fa ,geng xin hou de xin xi su
    W=to_visit;
    Tabukm(W)=0;
    else
    	break
    end
   end
   Routes{k,m}=Path;
   if ismember(0,ismember(all(1,:),Path)) == 0
   	PL(k,m) = PLKm;
   else
   	PL(k,m) = 0;
   end %m只蚂蚁结束
   
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
   

    Position=find(PL(k,:)==Length_best(k));%找到最短路径的位置
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
	
	
	end
	end
