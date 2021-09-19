//
// https://www.aceptaelreto.com/problem/statement.php?id=101
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int countDigits(int n)
{
    string tmp;
    tmp = to_string(n);
    return int(tmp.size());
}
bool checkMagic(vector<vector<int>> vector,int n){
    int numH=0;
    int numV=0;
    int numX=0;
    for(int x=0;x<n;x++){

        numH=numH+vector[0][x];

    }
    for(int x=0;x<n;x++){
        numV=numV+vector[x][0];
    }
    if(numH!=numV){
        return false;
    }
    for(int x=0;x<n;x++){
        numX=numX+vector[x][x];
    }
    return numH==numX;

}
bool checkEsoterico(vector<vector<int>> vector,int n){
    int digitos = 0;
    int cm=0;
    int cm2;
    int center= int((ceil(n/2))-1) ;
    int sumaesquinas = vector[0][0]+vector[n-1][0]+vector[0][n-1]+vector[n-1][n-1];

    for(int x=0;x<n;x++){
        if (countDigits(vector[0][x]) > digitos) {
            digitos = countDigits(vector[0][x]);
        }
        cm = cm+vector[0][x];
    }
    cm2=floor( (cm*4)/n);
    if (digitos!=countDigits(n*n) or sumaesquinas!=cm2){
        return false;
    }
    if (int(n)%2!=0){
        int sumacentro=vector[center][0]+vector[0][center]+vector[center][n-1]+vector[n-1][center];
        if (sumacentro!=cm2 or vector[center][center]*4!=cm2){
            return false;
        }

    }else{
        int sumacentro=vector[center][0]+vector[0][center]+vector[center][n-1]+vector[n-1][center]+ vector[center+1][0]+vector[0][center+1]+vector[center+1][n-1]+vector[n-1][center+1];
        int sumacentrocentro= vector[center][center]+vector[center+1][center]+vector[center][center+1]+vector[center+1][center+1];
        if (sumacentro!=2*(cm2) and sumacentrocentro!=cm2){
            return false;
        }
    }
    return true;

}
int mainX(){
    while(true){
    int n=1;
    cin>>n;
    if (n==0){break;}
    vector<vector<int>> v;
    for (int x=0;x<n;x++){
        vector<int> vx;
        for(int y=0;y<n;y++){
            int num=0;
            cin>>num;
            vx.push_back(num);
        }
        v.push_back(vx);
    }


    if ( checkEsoterico(v,n) and checkMagic(v,n)){
        cout<<"ESOTERICO"<<endl;
    }else if(checkMagic(v,n)){
        cout<<"DIABOLICO"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    }
    return 0;

}
