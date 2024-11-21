#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
struct node
{
 int coef;
 int pow_x;
 int pow_y;
 int pow_z;
 struct node*next;
};
typedef struct node*POLYPTR;
POLYPTR InsertTerm(POLYPTR poly,int coef,int pow_x,int pow_y,int pow_z)
{
 POLYPTR cur;
 POLYPTR newNode=(POLYPTR)malloc(sizeof(struct node));
 newNode->coef=coef;
 newNode->pow_x=pow_x; 
 newNode->pow_y=pow_y; 
 newNode->pow_z=pow_z; 
 newNode->next=NULL;
 cur=poly;
 while(cur->next!=poly)
 {
  cur=cur->next;
 }
 cur->next=newNode;
 newNode->next=poly;
 return poly;
}
void Display(POLYPTR poly)   
{
 if(poly->next==poly)
  {
   printf("Polynomial is empty\n");
   return;
  }
  POLYPTR cur=poly->next;
  do
  {
   printf("%dx^%dy^%dz^%d",cur->coef,cur->pow_x,cur->pow_y,cur->pow_z);
   cur=cur->next;
   if(cur!=poly)
   {
    printf("+");
   }
  }while(cur!=poly);
}
int Evaluate(POLYPTR poly,int x,int y,int z)
{
 int result=0;
 if(poly->next==poly)
 {
  return result;
 }
 POLYPTR cur=poly->next;
 do
 {
  int Val=cur->coef*pow(x,cur->pow_x)*pow(y,cur->pow_y)*pow(z,cur->pow_z);
  result=result+Val;
  cur=cur->next;
 }while(cur!=poly);
 return result;
}
bool MatchTerm(POLYPTR p1,POLYPTR p2)
{
 bool bMatches=true;
 if(p1->pow_x!=p2->pow_x)
 bMatches=false;  
 if(p1->pow_y!=p2->pow_y)
 bMatches=false;   
 if(p1->pow_z!=p2->pow_z)
 bMatches=false;
 return bMatches;
}
POLYPTR AddPoly(POLYPTR poly1,POLYPTR poly2,POLYPTR polySum)
{
 POLYPTR cur1=poly1->next;  
 POLYPTR cur2=poly2->next;    
 do 
 {
  polySum=InsertTerm(polySum,cur1->coef,cur1->pow_x,cur1->pow_y,cur1->pow_z);
  cur1=cur1->next;
 }while(cur1!=poly1);
 do
 {
  cur1=polySum->next;
  bool MatchFound=false;
  do
  {
   if(MatchTerm(cur1,cur2))
   {
    cur1->coef+=cur2->coef;
    MatchFound=true;
    break;
   }
   cur1=cur1->next;
  }while(cur1!=polySum);
  if(!MatchFound)
  {
   polySum=InsertTerm(polySum,cur2->coef,cur2->pow_x,cur2->pow_y,cur2->pow_z);
  }
  cur2=cur2->next;
 }while(cur2!=poly2);
 return polySum;
}
int main()
{
 POLYPTR poly1=(POLYPTR)malloc(sizeof(struct node));
 poly1->next=poly1;
 POLYPTR poly2=(POLYPTR)malloc(sizeof(struct node));
 poly2->next=poly2;
 POLYPTR polySum=(POLYPTR)malloc(sizeof(struct node));
 polySum->next=polySum;
 poly1=InsertTerm(poly1,6,2,2,1);
 poly1=InsertTerm(poly1,-4,0,1,5);
 poly1=InsertTerm(poly1,3,3,1,1);
 poly1=InsertTerm(poly1,2,1,5,1);
 poly1=InsertTerm(poly1,-2,1,1,3);
 printf("POLY(x,y,z)=");
 Display(poly1);
 poly2=InsertTerm(poly2,1,1,1,1);
 poly2=InsertTerm(poly2,4,3,1,1);
 printf("\nPOLY2(x,y,z)=");
 Display(poly2);
 polySum=AddPoly(poly1,poly2,polySum);
 printf("\nPOLYSUM(x,y,z)=");
 Display(polySum);
 int x=1,y=1,z=1;
 int iRes=Evaluate(polySum,x,y,z);
 printf("\nResult of POLYSUM=%d\n",iRes);
 return 0;
} 

