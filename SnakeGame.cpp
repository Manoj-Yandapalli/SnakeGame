#include <bits/stdc++.h>
using namespace std;
int score=0;
void printInstructions(){
    cout<<"                                                                 "<<"Welcome To SNAKE.IO"<<endl;
    cout<<"                                                                 "<<"Press W to move forward"<<endl;
    cout<<"                                                                 "<<"Press S to move backward"<<endl;
    cout<<"                                                                 "<<"Press A to move left"<<endl;
    cout<<"                                                                 "<<"Press D to move right"<<endl;
    cout<<"                                                                 "<<"O is your snake and X is food"<<endl;
    
}
void printPlayArea(char arr[4][14]){
    
cout<<"                                                                     "<<"################"<<endl;
cout<<"                                                                     "<<"#"<<arr[0][0]<<arr[0][1]<<arr[0][2]<<arr[0][3]<<arr[0][4]<<arr[0][5]<<arr[0][6]<<arr[0][7]<<arr[0][8]<<arr[0][9]<<arr[0][10]<<arr[0][11]<<arr[0][12]<<arr[0][13]<<"#"<<endl;
cout<<"                                                                     "<<"#"<<arr[1][0]<<arr[1][1]<<arr[1][2]<<arr[1][3]<<arr[1][4]<<arr[1][5]<<arr[1][6]<<arr[1][7]<<arr[1][8]<<arr[1][9]<<arr[1][10]<<arr[1][11]<<arr[1][12]<<arr[1][13]<<"#"<<endl;
cout<<"                                                                     "<<"#"<<arr[2][0]<<arr[2][1]<<arr[2][2]<<arr[2][3]<<arr[2][4]<<arr[2][5]<<arr[2][6]<<arr[2][7]<<arr[2][8]<<arr[2][9]<<arr[2][10]<<arr[2][11]<<arr[2][12]<<arr[2][13]<<"#"<<endl;
cout<<"                                                                     "<<"#"<<arr[3][0]<<arr[3][1]<<arr[3][2]<<arr[3][3]<<arr[3][4]<<arr[3][5]<<arr[3][6]<<arr[3][7]<<arr[3][8]<<arr[3][9]<<arr[3][10]<<arr[3][11]<<arr[3][12]<<arr[3][13]<<"#"<<endl;
cout<<"                                                                     "<<"################"<<endl;
cout<<endl;
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}
void gameStart(char arr[4][14],int &num1,int &num2,int &num3,int &num4){ 
int i=num1;
int j=num2;
int k=num3;
int l=num4;
arr[i][k]='O';
arr[j][l]='X';      
}
void kill(char arr[4][14],int &i,int &k,int &j,int &l){
    do{
j=rand()%4;
l=rand()%14;
}while(i==j && k==l); // find a spot where not equal to O  // i==j==k==l wrong wont work as expected in c++
arr[j][l]='X';    
}
void gamePlay(char arr[4][14],int &i,int &j,int &k,int &l,bool &gameEnd){
char operation;
cin>>operation;
switch (operation){
    
    case 'w': {arr[i][k]=' ';
    arr[i-1][k]='O';
      i=i-1;           
    break;
    }

   case 's':{ arr[i][k]=' ';
    arr[i+1][k]='O';
      i=i+1;           
    break;
   }

    case 'a':{ arr[i][k]=' ';
    arr[i][k-1]='O';
     k=k-1;
    break;
    }

    case 'd':{ arr[i][k]=' ';
    arr[i][k+1]='O';
    k=k+1;
    break;
    }
    default: cout<<"                                                            "<<"        Select correct key"<<endl;
    break; 
}
    if(i<0 || i>3 ||k<0 ||k>13){
        cout<<"                                                                 "<<"!!Game Over!!";
        gameEnd=true;
    }
    if(i==j&&k==l){ // if row and column of O and X are same 
        score++;
        arr[j][l]='O';
        cout<<"                                                                         Score: "<<score<<endl;
        kill(arr,i,k,j,l);
        // we are not printing again since main fn prints already
    }

}

int main(){

char arr[4][14];
for(int i=0;i<4;i++){
    for(int j=0;j<14;j++){ // to create 54 empty spaces correctly
        arr[i][j]=' ';
    }
} 
srand(time(0));
int num1=rand()%4;
int num2=rand()%4;
int num3=rand()%14;
int num4=rand()%14;
while((num1==num2 && num2==num3 && num3==num4)){
num1=rand()%4;
num2=rand()%4;
num3=rand()%14;
num4=rand()%14;
}
bool gameEnd=false;
printInstructions();
gameStart(arr,num1,num2,num3,num4);
while(!gameEnd){
printPlayArea(arr);
gamePlay(arr,num1,num2,num3,num4,gameEnd);
}
cout<<endl;
char sym;
cout<<"Enter Any key to Exit: ";
cin>>sym;



    return 0;
}