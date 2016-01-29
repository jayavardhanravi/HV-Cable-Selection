#include<stdio.h>
#include<conio.h>
#include<math.h>
Void main ()
{
Int n,q,c,ci,yes,i,var,ii;
float pf,r,area,e,vdper,pvdip,df,t,xd,df1,dfci,mina,ifull,is,reqr,kv,rce,xce;
float l,w,vdip,vd,ist,k,k1,k2,k3;
char p,m[2];
clrscr();
printf("\n\n\n\t\t SIZING CALCULATIONS FOR HV CABLES \n");
printf("-------------------------------------------------------------------------------------------------------  --------------------------------------------------------\n\n\n\n");
printf("ENTER THE POWER FACTOR OF THE SYSTEM [range is 0<pf<1]   = ");
scanf("%f",&pf);
printf("\n\nENTER THE RATING OF THE EQUIPMENT IN KVA    = ");
scanf("%f",&r);
reqr=(r)/(pf);
printf("\n\nREQUIRED RATING OF THE EQUIPMENT IS %f KVA\n",reqr);
printf("\n\nENTER THE VOLTAGE RATING IN KV   =");
scanf("%f",&kv);
ifull=(reqr)/(kv*1.723);
printf("\nTHE FULL LOAD CURRENT IS %f A\n",ifull);
printf("\nDO YOU KNOW THE SHORT CIRCUIT CURRENT ? \n\n 1. YES\n\n 2. NO\t\t ENTER 1 OR 2 \n");
scanf("%d",&ii);
if(ii==1)
{
printf("\nENTER THE VALUE OF SHORT CIRCUIT CURRENT IN A  =");
scanf("%f",&is);
}
else
{
printf("\n\nENTER THE VALUE OF SUB-TRANSIENT REACTANCE IN Ohm/ph/km   = ");
scanf("%f",&xd);
printf("\n\nENTER THE VALUE OF VOLTAGE REGULATION FOR TRANSFORMER AND EFFICIENCY FOR MOTOR  =");
scanf("%f",&df1);
is=(reqr)/(xd*1.723*kv*df1);
}
printf("\n\nTHE SHORT CIRCUIT CURRENT IS %f A\n",is);
printf("\n\nENTER THE VALUE OF SQUARE ROOT OF SC TIME(t) IN SECONDS\n\n\t 1.0 FOR INCOMER\n\n\t 0.7746 FOR TRANSFORMER \n\n\t 0.44722 FOR MOTOR\n");
scanf("%f",&t);
printf("\n\nENTER THE MATERIAL TO BE USED \n\n\t 1. FOR COPPER\n\n\t 2. FOR ALUMINIUM\n");
scanf("%d",&q);
if(q==1)
{
e=0.143;
printf("\n\n THE MATERIAL USED IS COPPER\n");
}
else
{
e=0.094;
printf("\n\n THE MATERIAL USED IS ALUMINIUM\n");
}
mina=(is*t)/(e*1000);
printf("\n\nMINIMUM CROSS SECTION AREA IS %f sq.mm\n",mina);
printf("\n\nCHOOSE THE SUITABLE CABLE \n");
printf("\n\nENTER \t1. FOR SINGLE CORE \n\n\t3. FOR MULTI CORE\n\n");
scanf("%d",&c);
for(i=0;i<10;i++)
{
printf("\n\nENTER THE CROSS SECTION AREA IN sq.mm   =");
scanf("%f",&area);
if(area<mina)
{
i=1;
}
else
{
i=11;
}

}
printf("\n\n\n--------------------------------------------------------------------------------\n");
printf("\nTHE CABLE YOU CHOOSE IS %dCx%fsq.mm\n",c,area);
printf("--------------------------------------------------------------------------------\n");

printf("\n\nENTER THE CURRENT CARRYING CAPACITY OF THE CABLE AT THE REQUIRED TEMPERATURE IN A  =");
scanf("%d",&ci);
printf("\n\n\nCALCULATING DERATING FACTOR\n");
printf("\nENTER THE FOLLOWING DETAILS........\n");
printf(" \n\n        1. TEMPERATURE CORRECTION FACTOR (K1)   = ");
scanf("%f",&k1);
printf(" \n\n        2. RATING FACTOR FOR DEPTH OF LAYING (K2)  =");
scanf("%f",&k2);
printf(" \n\n        3. GROUP DERATING FACTOR (K3)  =");
scanf("%f",&k3);
df=k1*k2*k3;
printf("\n\n  THE OVERALL DERATING FACTOR IS %f \n",df);
dfci=ci*df;
printf("\n\n  THE CURRENT CARRYING CAPACITY OF THE CABLE AFTER CONSIDERING THE OVERALL DERATING FACTOR IS %f A\n",dfci);
n=(ifull/dfci)+1;
printf("\n-----------------------------------------------------------------------------");
printf("\n\nTHE NUMBER OF RUNS REQUIRED IS %d\n",n);
printf("\-----------------------------------------------------------------------------------");
printf("\n\nCALCULATING THE VOLTAGE DROP..........\n");
printf("\n\nENTER THE ALLOWABLE PERCENTAGE VOLTAGE DROP  =\n");
scanf("%f",&vdper);
printf("\n\nENTER THE CABLE ROUTE LENGTH IN METERS   =");
printf("\n");
scanf("%f",&l);
printf("\n\nENTER THE VALUE OF RESISTANCE IN ohm/ph/km  =\n");
scanf("%f",&rce);
printf("\n\nENTER THE VALUE OF REACTANCE IN ohm/ph/km  =\n");
scanf("%f",&xce);
w=cosl(pf);
vd=(1.732*ifull*(rce*cos(w)+xce*sin(w))*l)/(kv*10000*n);
printf("\n\nTHE PERCENTAGE VOLTAGE DROP OBTAINED IS %f \n",vd);
if(vd<=vdper)
{
printf("\n\nTHE CABLE YOU CHOOSE IS THE SUITABLE  ONE \n");
}
else
{
printf("\n\nTHE CABLE YOU CHOSE IS NOT THE SUITABLE ONE\n\n");
}
printf("\n\n IS THE EQUIPMENT YOU CHOOSE A MOTOR ? \n\tENTER \n\n1. YES\n\n2. NO\n\n");
scanf("%d",&var);
if(var==1)
{
printf("\n\nNEED TO CALCULATE THE VOLTAGE DIP........\n");
printf("\n\nENTER THE ALLOWABLE PERCENTAGE VOILTAGE DIP  =");
scanf("%f",&pvdip);
printf("\n\n THE STARTING CURRENT FOR A MOTOR IS 6 TIMES THE FULL LOAD CURRENT \n");
ist=6*ifull;
vdip=(1.732*ist*(rce*cos(w)+xce*sin(w))*l)/(kv*10000*n);
printf("\n\nTHUS THE PERCENTAGE VOLTAGE DIP OBTAINED IS %f \n",vdip);
if(vdip>pvdip)
{
printf("\n\n VOLTAGE DIP MORE THAN REQUIRED\n");
printf("\n\n CABLE YOU CHOOSE IS NOT SUITABLE \n");
}
else
printf("\n\n THE CABLE YOU CHOOSE IS THE SUITABLE ONE\n");

printf("\n\n\n\t\t\t------------------------------------------\n");
printf("\t\t\t\t\tOUTPUT\n");
printf("\n\n\t\t\t------------------------------------------\n");
if(vd<vdper&&vdip<pvdip)
{
printf("\n\n THE CABLE TO BE USED IS %f KV, %dC x %f sq.mm,ARMOURED CABLE\n",kv,c,area);
if(q==1)
printf("\n\n MATERIAL USED IS COPPER\n");
else
printf("\n\n MATERIAL USED IS ALUMINIUM\n");
}
else
{
printf("\n\n THE CABLE YOU CHOOSE IS NOT SUITABLE ONE\n");
printf("\n\n START THE PROGRAM AGAIN.............\n");
}
}
else
{
if(vd>vdper)
{
printf("\n\n THE CABLE YOU CHOOSE IS NOT THE SUITABLE ONE \n");
printf("\n\n START THE PROGRAM AGAIN.............\n");
}
else
{
printf("\n\n\n\t\t\t------------------------------------------\n");
printf("\t\t\t\t\tOUTPUT\n");
printf("\n\n\t\t\t------------------------------------------\n");
printf("\n\n THE CABLE TO BE USED IS %f KV, %dC x %f sq.mm,ARMOURED CABLE\n",kv,c,area);
if(q==1)
printf("\n\n MATERIAL USED IS COPPER\n");
else
printf("\n\n MATERIAL USED IS ALUMINIUM\n");
}
}
getch();
}
