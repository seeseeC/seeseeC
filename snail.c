#include<stdio.h>
//#include<stdlib.h>

int InputNumber();
void SetContourLine(int snailArr[][19], int nbyn);
void SetInwardShape(int snailArr[][19], int nbyn);
int (*CreateSnail(int snailArr[][19], int nbyn))[19];
void ShowSnail(int (*pSnailArr)[19], int nbyn);

int main(void)
{ 
 int (*pSnailArr)[19];
 int snailArr[19][19];
 int nbyn;

 nbyn = InputNumber();
 pSnailArr = CreateSnail(snailArr, nbyn);
 ShowSnail(pSnailArr, nbyn); 

 return 0; 
} 

int InputNumber()
{
 //if input data is out of range(4~18), input again
 int nbyn;

 while(1)
 {
  printf("Input pos_number (range :1~16)");
  scanf("%d", &nbyn);
  if(nbyn>16 || nbyn<1)
   printf("1 <= nbyn <= 16\n");
  else
   return nbyn;
 }
}

void SetContourLine(int snailArr[][19], int nbyn)
{
 int x = 0;
 int y = 0;
  //input -1, in spaces of outer-most contour line of snailArray (for knowing last spaces of array[x][y])
 while(x < nbyn)
  snailArr[x++][nbyn]=-1;
 while(y < nbyn)
  snailArr[nbyn][y++]=-1;
}

void SetInwardShape(int snailArr[][19], int nbyn)
{
 int x = 0;
 int y = 0;
 int pos_num = 1;
 int dir_x[4] = {1, 0, -1, 0}, dir_y[] = {0, 1, 0, -1};
 int dir_index = 0;
 int direction_x = 0;
 int direction_y = 0;

 while(!snailArr[x][y])
 {
  if(pos_num <= nbyn*nbyn)
   snailArr[x][y] = pos_num++;
  else
   break;

  direction_x = x + dir_x[dir_index];
  direction_y = y + dir_y[dir_index];

  //change direction 
  if( (snailArr[direction_x][direction_y] !=0) || (direction_x < 0) || (direction_y < 0))        
   dir_index = (dir_index + 1) % 4;

  x += dir_x[dir_index];         
  y += dir_y[dir_index];
 }
}

int (*CreateSnail(int snailArr[][19],int nbyn))[19]
{
// int snailArr[19][19]={0,};
 int pos_num = 1;    

 SetContourLine(snailArr, nbyn);
 SetInwardShape(snailArr, nbyn);

 return snailArr;
}

void ShowSnail(int (*pSnailArr)[19], int nbyn)
{
 int x = 0;
 int y = 0;

 for(y = 0; y < nbyn; y++) 
 {       
 for(x = 0; x < nbyn; x++)       
  {
    if(nbyn < 10)
     printf("%2d ", pSnailArr[x][y]);
    else
     printf("%3d ", pSnailArr[x][y]);
  }       
  printf("\n");    
 }  

}

