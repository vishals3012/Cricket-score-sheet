#include<termios.h>
#include<unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<time.h>
 
void toss();
void gotoxy(int x,int y);
void bowling();
void batting();
void bowling_zero();
void new_batsman(int d);
int play();
void basic_display();
void basic_display1();
struct bowler_details
  {
   char name[50];
   int bowler_number;
   float overs;
   int runs;
   int madien;
  int toss; 
  int wickets;
  };
struct batsmen_details
 {
  char batsman_name[50];
  int i_score;
  int i_balls;
  float sr_rate;
  int status;

 };
void main()
 {
  struct bowler_details bd[11];
  
   gotoxy(12,6);
   printf("WELCOME TO CRICKET MATCH BETWEEN INDIA AND PAKISTAN");

  toss();
  bowling_zero();
    bowling();
 }
void toss()
 {
  basic_display();
  char c;
  gotoxy(86,5);
  printf("ENTER TO TOSS A COIN");
  
  scanf("^[\n]");

srand(time(0));

  int random=rand()%2;
    int random1=rand()%2;
    gotoxy(12,12);
        
    if(random==1)
    {
      if (random1==1)
      {
      printf("INDIA WON THE TOSS AND CHOOSE TO BAT");
      //toss=1;
      gotoxy(12,13);}  
      else
       {
        printf("INDIA WON THE TOSS AND CHOOSE TO BOWL\n");
    //    toss=0;
        }
        }
  else

    {
      if (random1==1)
        {
      printf("PAKISTAN WON THE TOSS AND CHOOSE TO BAT\n");
//      toss=0; 
      }
     else
        {
      printf("PAKISTAN WON THE TOSS AND CHOOSE TO BOWL\n");
  //   toss=1;
    }
    }
  gotoxy(12,13);
 }
void bowling_zero()
 {
 struct bowler_details bd[11];
 struct batsmen_details bc[11];

  for(int b=0;b<=11;b++)
   {
  bd[b].name[50]=0;
  bd[b].overs=0;
  bd[b].runs=0;
  bd[b].madien=0;
  bd[b].wickets=0;
  bc[b].i_score=0;
  bc[b].i_balls=0;
  bc[b].sr_rate=0; 
  }

 }
void bowling()
 {
 struct bowler_details bd[11];
 struct batsmen_details bc[11];
  int c=0;
 float t_overs=0;
 int t_score=0;
 int t_wickets=0;
   int x=2;
 int w=1;
  gotoxy(86,8);
 printf("ENTER THE OPENING BATSMEN NAME");
   gotoxy(86,9);
 scanf("%s%s",bc[1].batsman_name,bc[2].batsman_name);
  int wi=w+1; 
  while(w<=11 && wi<=11 && t_overs<=50)
 {
  
  int temp;
  int i;
  int r;
  gotoxy(86,10);
  printf("ENTER THE BOWLER NUMBER");
   gotoxy(86,11);
   scanf("%d",&i);
  if(bd[i].overs==0)
  {
   gotoxy(86,12);
       printf("ENTER THE BOWLER NAME\n");
      gotoxy(86,13); 
   scanf("%s",bd[i].name);
  basic_display1();
  }
  for(int balls=0;balls<6;)
  {
   r=play();
  if(r>=0 && r<=6)
  {
  
   bd[i].overs+=0.1;
  bd[i].runs+=r;
  balls++;
 t_score+=r;
 t_overs+=0.1; 
 bc[w].i_score+=r;
 bc[w].i_balls++;
 float r1=bc[w].i_score;
 float b=bc[w].i_balls;
 bc[w].sr_rate=(r1/b)*100;
  if(r%2==1)
  {
   temp=wi;
   wi=w;
   w=temp;
  }
 }
 
  else if(r==7)
  {
  bc[w].status=1;

   if(w==11 || wi==11)
  {
   
  gotoxy(60,15);
   printf("TOTAL SCORE=%d/%d",t_score,t_wickets);
   gotoxy(80,30);
   exit(0);
   }
   if(w<wi)
  {
  w=wi+1;
  }
 else
 w=w+1;
    r++;
    bd[i].overs+=.1;
    bd[i].wickets=+1;
    balls+=1;
   t_overs+=0.1;
   t_wickets+=1;
  gotoxy(86,8);
  printf("ENTER %d BATSMEN NAME",++x);
    gotoxy(86,9);
  scanf("%s",bc[x].batsman_name);
  }
   else 
 {
 bd[i].runs++;
 t_score+=1;
  }
    if(1)
    {
   
   basic_display1();
    gotoxy(86,30);
     printf("%d %d",w,wi);   
for(int t=1;t<x;t++)
{   
  gotoxy(23,6+t);
    if(bc[t].status==1)
    printf("OUT");
    else
    printf("NOT OUT");
gotoxy(23,6+t+1);
    if(bc[t+1].status==1)
    printf("OUT");
    else
    printf("NOT OUT");
     
    gotoxy(5,6+t);
    printf("%s",bc[t].batsman_name);
    gotoxy(5,6+t+1);
    printf("%s",bc[t+1].batsman_name);
        gotoxy(37,6+t);
    printf("%d",bc[t].i_score);
        gotoxy(47,6+t);
    printf("%d",bc[t].i_balls);
    gotoxy(37,6+t+1);
    printf("%d",bc[t+1].i_score);
        gotoxy(47,6+t+1);
    printf("%d",bc[t+1].i_balls);
    
    gotoxy(60,6+t);
    printf("%3f",bc[t].sr_rate);
     gotoxy(60,6+t+1);
    printf("%3f",bc[t+1].sr_rate);
    gotoxy(31,6+w);
    printf("*");    
   gotoxy(60,29); 
     printf("%s:",bd[i].name);
    gotoxy(68,29);
    printf("%f",bd[i].overs);
    gotoxy(71,29);
    printf("-%d-%d-%d\n",bd[i].madien,bd[i].runs,bd[i].wickets);
    gotoxy(10,29);
    printf("SCORE:%d/%d",t_score,t_wickets);
    gotoxy(30,29);
    printf("OVERS:%f",t_overs);
    gotoxy(39,29);
    printf("     ");
    }
   }  
}
  bd[i].overs+=0.4;
  t_overs+=0.4;
 }
 }
int play()
 {
  int result;
  gotoxy(86,5);
  printf("ENTER THE RUNS SCORED");
  gotoxy(86,6);
  printf("7-WICKET");
  gotoxy(86,7);
  printf("8-NO BALL");
  gotoxy(86,8);
  printf("9-WIDE");
   gotoxy(86,9);
  scanf("%d",&result);
  return result;
  }
void gotoxy(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);

 }
void basic_display()
 {
  
     
     system("clear"); 

     for(int o=0;o<120;o++)  
    {
     gotoxy(o,0);
     printf("##");
     gotoxy(o,33);

     printf("##");
     }
     for(int o=0;o<33;o++)
     {
     gotoxy(85,o);
     printf("|");
     gotoxy(0,o);
     printf("##");
     gotoxy(120,o);
     printf("##");
     }
     gotoxy(10,2);
     printf("INDIA VERSUS PAKISTAN,MATCH-5,ICC WORLD CUP 2018");
     gotoxy(65,2);
     time_t T=time(NULL);
     struct tm tm =*localtime(&T);
     printf("DATE:-%02d/%02d/%02d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);

  }
void basic_display1()
 {
  
     
     system("clear"); 

     for(int o=0;o<120;o++)  
    {
     gotoxy(o,0);
     printf("##");
     gotoxy(o,33);

     printf("##");
     }
     for(int o=0;o<33;o++)
     {
     gotoxy(85,o);
     printf("|");
     gotoxy(0,o);
     printf("##");
     gotoxy(120,o);
     printf("##");
     }
     gotoxy(10,2);
     printf("INDIA VERSUS PAKISTAN,MATCH-5,ICC WORLD CUP 2019");
     gotoxy(65,2);
     time_t T=time(NULL);
     struct tm tm =*localtime(&T);
     printf("DATE:-%02d/%02d/%02d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
     gotoxy(4,6);
     printf("BATSMAN NAME");
     gotoxy(21,6);
     printf("OUT/NOT OUT");
     gotoxy(35,6);
     printf("RUNS");
     gotoxy(45,6);
     printf("BALLS FACED");
     gotoxy(58,6);
     printf("STRIKE RATE");
  }
