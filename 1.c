#include<stdio.h>
#include<stdlib.h>
struct day
{
 char* dayname;
 int date;
 char* activity;
};

struct day* createday()
{
  struct day* newday=(struct day*)malloc(sizeof(struct day));
  newday->dayname=(char*)malloc(sizeof(char));
  newday->activity=(char*)malloc(sizeof(char));
  printf("Enter day:");
  scanf("%s",newday->dayname);
  printf("Enter date:");
  scanf("%d",&(newday->date));
  printf("Enter activity:");
  scanf(" %[^\n]",newday->activity);
  return newday;
}
  
void read(struct day* calendar[],int size)
{
  for(int i=0;i<size;i++)
  {
    printf("Enter details for day %d:\n",i+1);
    calendar[i]=createday();
  }
}

void display(struct day* calendar[],int size)
{
  printf("\nWeek's activity details:\n");
  for(int i=0;i<size;i++)
  {
    printf("Day %d:\n",i+1);
    printf("Day name:%s\n",calendar[i]->dayname);
    printf("Date:%d\n",calendar[i]->date);
    printf("Activity: %s\n",calendar[i]->activity);
    printf("\n");
  }
}

void freememory(struct day* calendar[],int size)
{
  for(int i=0;i<size;i++)
  {
    free(calendar[i]->dayname);
    free(calendar[i]->activity);
    free(calendar[i]);
  }
}
      
int main()
{
  struct day* week[7];
  read(week,7);
  display(week,7);
  freememory(week,7);
  return 0;
}
