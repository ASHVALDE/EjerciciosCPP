//[[
// El matemático indio Dattaraya Ramchandra Kaprekar descubrió en 1949 una curiosa característica del número 6174. Hoy, se conoce a dicho número como constante de Kaprekar en honor a él.
//El número es notable por la siguiente propiedad:
//Elige un número de cuatro dígitos que tenga al menos dos diferentes (es válido colocar el dígito 0 al principio, por lo que el número 0009 es válido).
//Coloca sus dígitos en orden ascendente y en orden descendente para formar dos nuevos números. Puedes añadir los dígitos 0 que necesites al principio.
//Resta el menor al mayor.
//Vuelve al paso 2.
//A este proceso se le conoce como la rutina de Kaprekar, y siempre llegará al número 6174 en, como mucho, 7 iteraciones. Una vez en él, el proceso no avanzará, dado que 7641 − 1467 = 6174.
//
//Por ejemplo, el número 3524 alcanzará la constante de Kaprekar en 3 iteraciones:
//
//5432 − 2345 = 3087
//8730 − 0378 = 8352
//8532 − 2358 = 6174
// ]]


#include <iostream>
#include <string>

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
    int iteraciones =0;
    cout<<"Ingrese un numero de 4 cifras: ";
    cin>>resultado;
    cout<<endl;
    do{
        resultado = SortedNumber(integerToArray(resultado)[0],integerToArray(resultado)[1],integerToArray(resultado)[2],integerToArray(resultado)[3]);
        cout<<resultado<<endl;
        iteraciones++;
    }while(resultado!=6174);

    cout<<endl<<"Este numero tiene "<<iteraciones<<" iteraciones";
}
