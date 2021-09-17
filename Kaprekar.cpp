#include <iostream>
#include <string>
#include <vector>

using namespace std;

int * integerToArray(int x)
{
    int array[4];
    for (int i = 3; i >= 0; i--) {
        array[i] = x % 10;
        x /= 10;
    }
    return array;
}

int concat(int a, int b,int c, int d)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    string s3 = to_string(c);
    string s4 = to_string(d);
    string s = s1 + s2 + s3 + s4;
    int cr = stoi(s);
    return cr;
}
int SortedNumber(int a,int b,int c,int d){
    int tempnum[4]={a,b,c,d};
    int sorted[4] = {0,0,0,0};
    for (int y=0;y<sizeof(sorted)/sizeof(sorted[0]);y++){

        int indx=0;
        for (int x=0;x<sizeof(tempnum)/sizeof(tempnum[0]);x++){
            if (tempnum[x]>sorted[y]){
                sorted[y]=tempnum[x];
                indx=x;
            }

        }
        tempnum[indx]=0;
    }
    return (concat(sorted[0],sorted[1],sorted[2],sorted[3]) - concat(sorted[3],sorted[2],sorted[1],sorted[0]) );
}

int main(){
    int resultado = 3524;
    do{
        resultado = SortedNumber(integerToArray(resultado)[0],integerToArray(resultado)[1],integerToArray(resultado)[2],integerToArray(resultado)[3]);
        cout<<resultado<<endl;
    }while(resultado!=6174);
}
