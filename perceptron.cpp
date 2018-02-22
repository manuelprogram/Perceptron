#include<bits/stdc++.h>

using namespace std;

double Rand(){
    double i = rand()%10;
    double f = rand()%10;
    if(i>f){
        swap(i,f);
    }
   return 1.0*i/f;
}

bool tabla[4][3]={{1,1,1},{1,0,0},{0,1,0},{0,0,0}};
double pesos[]={Rand(),Rand(),Rand()};


bool f(int pos){
  return (tabla[pos][0] * pesos[0] + tabla[pos][1] * pesos[1] + pesos[2])>0;
}

void moverpesos(){
    pesos[0] = Rand() - Rand();
    pesos[1] = Rand() - Rand();
    pesos[2] = Rand() - Rand();
}

int main(){
   srand(time(NULL));
   bool entreno,rta;
   int it=0;
   do{
        entreno=0;
        ++it;
        for (int i = 0; i < 4 ; i++){
            rta=f(i);
            if (rta!=tabla[i][2]){
                moverpesos();
                entreno=1;
                break;
            }
        }
   }while(entreno);

   printf("e1 e2 = s  PERCP\n");
   for(int i=0; i < 4; i++){
        printf("%d & %d = %d  %d\n",tabla[i][0],tabla[i][1],tabla[i][2],f(i));
   }
   printf("\nIteracion: %d\n\n",it);
   printf("w1 = %lf\n",pesos[0]);
   printf("w2 = %lf\n",pesos[1]);
   printf("b  = %lf\n",pesos[2]);
return 0;
}
