#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <random>

using namespace std;


vector<string> removeduplicate(vector<string> str, int n)
{
   int idx=0;
   for (int i=0;i<n;i++)
   {
        int j;
        for(j=0;j<i;j++)
        {
            if(str[i]==str[j])
            {
               break;
            }
        }
        if(j==i)
        {
            str[idx++]=str[i];
        }
   }
   return str;
}

double kabataku(int ops, double n1, double n2){
    if(ops == 0){
        return n1*n2;
    }
    else if(ops == 1){
        return n1/n2;
    }
    else if(ops == 2){
        return n1+n2;
    }
    else if(ops == 3){
        return n1-n2;
    }
    else{
        return 9999.0;
    }
}

char ops(int oper){
    if(oper == 0){
        return '*';
    }
    else if(oper == 1){
        return '/';
    }
    else if(oper == 2){
        return '+';
    }
    else if(oper == 3){
        return '-';
    }
}

string ubahInt(double i){
    if(i == 1.0){
        return "1";
    }
    else if(i == 2.0){
        return "2";
    }
    else if(i == 3.0){
        return "3";
    }
    else if(i == 4.0){
        return "4";
    }
    else if(i == 5.0){
        return "5";
    }
    else if(i == 6.0){
        return "6";
    }
    else if(i == 7.0){
        return "7";
    }
    else if(i == 8.0){
        return "8";
    }
    else if(i == 9.0){
        return "9";
    }
    else if(i == 10.0){
        return "10";
    }
    else if(i == 11.0){
        return "11";
    }
    else if(i == 12.0){
        return "12";
    }
    else if(i == 13.0){
        return "13";
    }
}


double evalKartu(string card){
    if(card=="A"){
        return 1.0;
    }
    else if(card=="2"){
        return 2.0;
    }
    else if(card=="3"){
        return 3.0;
    }
    else if(card=="4"){
        return 4.0;
    }
    else if(card=="5"){
        return 5.0;
    }
    else if(card=="6"){
        return 6.0;
    }
    else if(card=="7"){
        return 7.0;
    }
    else if(card=="8"){
        return 8.0;
    }
    else if(card=="9"){
        return 9.0;
    }
    else if(card=="10"){
        return 10.0;
    }
    else if(card=="J"){
        return 11.0;
    }
    else if(card=="K"){
        return 13.0;
    }
    else if(card=="Q"){
        return 12.0;
    }
    else{
        return 9999.0;
    }
}

int randint(int Min, int Max) {
    return (rand() % (Max + 1 - Min)) + Min;
}

int main(){
    string x1,x2,x3,x4;
    double n1,n2,n3,n4;
    int cho;
    cout << "Selamat datang pada solver permainan 24." << endl;
    cout << "Apakah anda ingin memasukkan kartu sendiri? \n(1/Ya, 2/Masukkan kartu secara random)" << endl;
    do{
        cin >> cho;
        if(cho != 1 && cho != 2){
            cout << "Mohon masukkan input yang sesuai." << endl;
        }
    }while(cho != 1 && cho != 2);

    if(cho == 1){
        do{
            printf("Masukkan 4 buah kartu yang ingin digunakan\n");
            cin >> x1;
            n1 = evalKartu(x1);
            cin >> x2;
            n2 = evalKartu(x2);
            cin >> x3;
            n3 = evalKartu(x3);
            cin >> x4;
            n4 = evalKartu(x4);
            if(n1 == 9999 || n2 == 9999 || n3 == 9999 || n4 == 9999){
                printf("Terdapat kesalahan input pada kartu yang dimasukkan.\n");
            }
            printf("Kartu anda adalah: \n");
            printf("%f %f %f %f\n",n1,n2,n3,n4);
        }while(n1 == 9999 || n2 == 9999 || n3 == 9999 || n4 == 9999);
    }
    else if(cho == 2){
        n1 = randint(1,13);
        n2 = randint(1,13);
        n3 = randint(1,13);
        n4 = randint(1,13);
        printf("Kartu anda adalah: \n");
        printf("%f %f %f %f\n",n1,n2,n3,n4);
    }

    string sol = "";
    vector<string> sols;
    int counter = 0;
    auto init = chrono::steady_clock::now();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                // i/j/k merupakan ops
                // 1
                if(kabataku(k,kabataku(j,kabataku(i,n1,n2),n3),n4) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n1) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n3) + ")" + ops(k) + ubahInt(n4);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n1,n2),kabataku(j,n3,n4)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n1) + ops(i) + ubahInt(n2) + ")" + ops(k) + "(" + ubahInt(n3) + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n1,kabataku(i,n2,n3))) == 24.0){    
                    sol = "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n3) + "))" + ops(k) + ubahInt(n4);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n2,kabataku(i,n3,n4))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n4) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n4,kabataku(i,n2,n3))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "((" + ubahInt(n2) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n1,n2),n4),n3) == 24.0){
                    sol = "((" + ubahInt(n1) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n4) + ")" + ops(k) + ubahInt(n3);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n1,n2),kabataku(j,n4,n3)) == 24.0){
                    sol = "(" + ubahInt(n1) + ops(i) + ubahInt(n2) + ")" + ops(k) + "(" + ubahInt(n4) + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n1,kabataku(i,n2,n4))) == 24.0){    
                    sol = "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n4) + "))" + ops(k) + ubahInt(n3);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n2,kabataku(i,n4,n3))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n3) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n3,kabataku(i,n2,n4))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "((" + ubahInt(n2) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n1,n3),n2),n4) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n1) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n2) + ")" + ops(k) + ubahInt(n4);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n1,n3),kabataku(j,n2,n4)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n1) + ops(i) + ubahInt(n3) + ")" + ops(k) + "(" + ubahInt(n2) + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n1,kabataku(i,n3,n2))) == 24.0){    
                    sol = "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n2) + "))" + ops(k) + ubahInt(n4);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n3,kabataku(i,n2,n4))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n4) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n4,kabataku(i,n3,n2))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "((" + ubahInt(n3) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n1,n3),n4),n2) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n1) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n4) + ")" + ops(k) + ubahInt(n2);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n1,n3),kabataku(j,n4,n2)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n1) + ops(i) + ubahInt(n3) + ")" + ops(k) + "(" + ubahInt(n4) + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n1,kabataku(i,n3,n4))) == 24.0){    
                    sol = "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n4) + "))" + ops(k) + ubahInt(n2);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n3,kabataku(i,n4,n2))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n2) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n2,kabataku(i,n3,n4))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "((" + ubahInt(n3) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                
                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n1,n4),n2),n3) == 24.0){
                    sol = "((" + ubahInt(n1) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n2) + ")" + ops(k) + ubahInt(n3);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n1,n4),kabataku(j,n2,n3)) == 24.0){
                    sol = "(" + ubahInt(n1) + ops(i) + ubahInt(n4) + ")" + ops(k) + "(" + ubahInt(n2) + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n1,kabataku(i,n4,n2))) == 24.0){    
                    sol = "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n2) + "))" + ops(k) + ubahInt(n3);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n4,kabataku(i,n2,n3))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n3) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n3,kabataku(i,n4,n2))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "((" + ubahInt(n4) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n1,n4),n3),n2) == 24.0){
                    sol = "((" + ubahInt(n1) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n3) + ")" + ops(k) + ubahInt(n2);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n1,n4),kabataku(j,n3,n2)) == 24.0){
                    sol = "(" + ubahInt(n1) + ops(i) + ubahInt(n4) + ")" + ops(k) + "(" + ubahInt(n3) + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n1,kabataku(i,n4,n3))) == 24.0){    
                    sol = "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n3) + "))" + ops(k) + ubahInt(n2);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n4,kabataku(i,n3,n2))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n2) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n2,kabataku(i,n4,n3))) == 24.0){
                    sol = ubahInt(n1) + ops(k) + "((" + ubahInt(n4) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n2,n1),n3),n4) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n2) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n3) + ")" + ops(k) + ubahInt(n4);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n2,n1),kabataku(j,n3,n4)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n2) + ops(i) + ubahInt(n1) + ")" + ops(k) + "(" + ubahInt(n3) + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n2,kabataku(i,n1,n3))) == 24.0){    
                    sol = "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n3) + "))" + ops(k) + ubahInt(n4);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n1,kabataku(i,n3,n4))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n4) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n4,kabataku(i,n1,n3))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "((" + ubahInt(n1) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n2,n1),n4),n3) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n2) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n4) + ")" + ops(k) + ubahInt(n3);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n2,n1),kabataku(j,n4,n3)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n2) + ops(i) + ubahInt(n1) + ")" + ops(k) + "(" + ubahInt(n4) + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n2,kabataku(i,n1,n4))) == 24.0){    
                    sol = "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n4) + "))" + ops(k) + ubahInt(n3);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n1,kabataku(i,n4,n3))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n3) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n3,kabataku(i,n1,n4))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "((" + ubahInt(n1) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n2,n3),n1),n4) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n2) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n1) + ")" + ops(k) + ubahInt(n4);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n2,n3),kabataku(j,n1,n4)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n2) + ops(i) + ubahInt(n3) + ")" + ops(k) + "(" + ubahInt(n1) + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n2,kabataku(i,n3,n1))) == 24.0){    
                    sol = "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n1) + "))" + ops(k) + ubahInt(n4);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n3,kabataku(i,n1,n4))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n4) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n4,kabataku(i,n3,n1))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "((" + ubahInt(n3) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n2,n3),n4),n1) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n2) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n4) + ")" + ops(k) + ubahInt(n1);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n2,n3),kabataku(j,n4,n1)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n2) + ops(i) + ubahInt(n3) + ")" + ops(k) + "(" + ubahInt(n4) + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n2,kabataku(i,n3,n4))) == 24.0){    
                    sol = "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n4) + "))" + ops(k) + ubahInt(n1);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n3,kabataku(i,n4,n1))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n1) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n1,kabataku(i,n3,n4))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "((" + ubahInt(n3) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n2,n4),n1),n3) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n2) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n1) + ")" + ops(k) + ubahInt(n3);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n2,n4),kabataku(j,n1,n3)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n2) + ops(i) + ubahInt(n4) + ")" + ops(k) + "(" + ubahInt(n1) + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n2,kabataku(i,n4,n1))) == 24.0){    
                    sol = "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n1) + "))" + ops(k) + ubahInt(n3);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n4,kabataku(i,n1,n3))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n3) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n3,kabataku(i,n4,n1))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "((" + ubahInt(n4) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n2,n4),n3),n1) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n2) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n3) + ")" + ops(k) + ubahInt(n1);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n2,n4),kabataku(j,n3,n1)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n2) + ops(i) + ubahInt(n4) + ")" + ops(k) + "(" + ubahInt(n3) + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n2,kabataku(i,n4,n3))) == 24.0){    
                    sol = "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n3) + "))" + ops(k) + ubahInt(n1);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n4,kabataku(i,n3,n1))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n1) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n1,kabataku(i,n4,n3))) == 24.0){
                    sol = ubahInt(n2) + ops(k) + "((" + ubahInt(n4) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n3,n1),n2),n4) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n3) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n2) + ")" + ops(k) + ubahInt(n4);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n3,n1),kabataku(j,n2,n4)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n3) + ops(i) + ubahInt(n1) + ")" + ops(k) + "(" + ubahInt(n2) + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n3,kabataku(i,n1,n2))) == 24.0){    
                    sol = "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n2) + "))" + ops(k) + ubahInt(n4);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n1,kabataku(i,n2,n4))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n4) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n4,kabataku(i,n1,n2))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "((" + ubahInt(n1) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n3,n1),n4),n2) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n3) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n4) + ")" + ops(k) + ubahInt(n2);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n3,n1),kabataku(j,n4,n2)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n3) + ops(i) + ubahInt(n1) + ")" + ops(k) + "(" + ubahInt(n4) + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n3,kabataku(i,n1,n4))) == 24.0){    
                    sol = "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n4) + "))" + ops(k) + ubahInt(n2);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n1,kabataku(i,n4,n2))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n2) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n2,kabataku(i,n1,n4))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "((" + ubahInt(n1) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n3,n2),n1),n4) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n3) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n1) + ")" + ops(k) + ubahInt(n4);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n3,n2),kabataku(j,n1,n4)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n3) + ops(i) + ubahInt(n2) + ")" + ops(k) + "(" + ubahInt(n1) + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n3,kabataku(i,n2,n1))) == 24.0){    
                    sol = "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n1) + "))" + ops(k) + ubahInt(n4);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n2,kabataku(i,n1,n4))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n4) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n4,kabataku(i,n2,n1))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "((" + ubahInt(n2) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n4) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n3,n2),n4),n1) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n3) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n4) + ")" + ops(k) + ubahInt(n1);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n3,n2),kabataku(j,n4,n1)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n3) + ops(i) + ubahInt(n2) + ")" + ops(k) + "(" + ubahInt(n4) + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n3,kabataku(i,n2,n4))) == 24.0){    
                    sol = "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n4) + "))" + ops(k) + ubahInt(n1);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n2,kabataku(i,n4,n1))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n1) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n1,kabataku(i,n2,n4))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "((" + ubahInt(n2) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n3,n4),n1),n2) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n3) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n1) + ")" + ops(k) + ubahInt(n2);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n3,n4),kabataku(j,n1,n2)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n3) + ops(i) + ubahInt(n4) + ")" + ops(k) + "(" + ubahInt(n1) + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n3,kabataku(i,n4,n1))) == 24.0){   
                    sol = "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n1) + "))" + ops(k) + ubahInt(n2);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n4,kabataku(i,n1,n2))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n2) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n2,kabataku(i,n4,n1))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "((" + ubahInt(n4) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n3,n4),n2),n1) == 24.0){
                // ((n1 i n2) j n3) k n4
                    sol = "((" + ubahInt(n3) + ops(i) + ubahInt(n4) + ")" + ops(j) + ubahInt(n2) + ")" + ops(k) + ubahInt(n1);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n3,n4),kabataku(j,n2,n1)) == 24.0){
                // (n1 i n2) k (n3 j n4)
                    sol = "(" + ubahInt(n3) + ops(i) + ubahInt(n4) + ")" + ops(k) + "(" + ubahInt(n2) + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n3,kabataku(i,n4,n2))) == 24.0){    
                    sol = "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n4) + ops(i) + ubahInt(n2) + "))" + ops(k) + ubahInt(n1);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n4,kabataku(i,n2,n1))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n1) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n1,kabataku(i,n4,n2))) == 24.0){
                    sol = ubahInt(n3) + ops(k) + "((" + ubahInt(n4) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                
                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n4,n1),n2),n3) == 24.0){
                    sol = "((" + ubahInt(n4) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n2) + ")" + ops(k) + ubahInt(n3);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n4,n1),kabataku(j,n2,n3)) == 24.0){
                    sol = "(" + ubahInt(n4) + ops(i) + ubahInt(n1) + ")" + ops(k) + "(" + ubahInt(n2) + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n4,kabataku(i,n1,n2))) == 24.0){    
                    sol = "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n2) + "))" + ops(k) + ubahInt(n3);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n1,kabataku(i,n2,n3))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n3) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n3,kabataku(i,n1,n2))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "((" + ubahInt(n1) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                
                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n4,n1),n3),n2) == 24.0){
                    sol = "((" + ubahInt(n4) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n3) + ")" + ops(k) + ubahInt(n2);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n4,n1),kabataku(j,n3,n2)) == 24.0){
                    sol = "(" + ubahInt(n4) + ops(i) + ubahInt(n1) + ")" + ops(k) + "(" + ubahInt(n3) + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n4,kabataku(i,n1,n3))) == 24.0){    
                    sol = "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n3) + "))" + ops(k) + ubahInt(n2);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n1,kabataku(i,n3,n2))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "(" + ubahInt(n1) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n2) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n2,kabataku(i,n1,n3))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "((" + ubahInt(n1) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n4,n2),n1),n3) == 24.0){
                    sol = "((" + ubahInt(n4) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n1) + ")" + ops(k) + ubahInt(n3);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n4,n2),kabataku(j,n1,n3)) == 24.0){
                    sol = "(" + ubahInt(n4) + ops(i) + ubahInt(n2) + ")" + ops(k) + "(" + ubahInt(n1) + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n3,kabataku(j,n4,kabataku(i,n2,n1))) == 24.0){    
                    sol = "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n1) + "))" + ops(k) + ubahInt(n3);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n2,kabataku(i,n1,n3))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n3) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n3,kabataku(i,n2,n1))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "((" + ubahInt(n2) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n3) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n4,n2),n3),n1) == 24.0){
                    sol = "((" + ubahInt(n4) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n3) + ")" + ops(k) + ubahInt(n1);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n4,n2),kabataku(j,n3,n1)) == 24.0){
                    sol = "(" + ubahInt(n4) + ops(i) + ubahInt(n2) + ")" + ops(k) + "(" + ubahInt(n3) + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n4,kabataku(i,n2,n3))) == 24.0){    
                    sol = "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n3) + "))" + ops(k) + ubahInt(n1);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n2,kabataku(i,n3,n1))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "(" + ubahInt(n2) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n1) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n1,kabataku(i,n2,n3))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "((" + ubahInt(n2) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n4,n3),n1),n2) == 24.0){
                    sol = "((" + ubahInt(n4) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n1) + ")" + ops(k) + ubahInt(n2);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n4,n3),kabataku(j,n1,n2)) == 24.0){
                    sol = "(" + ubahInt(n4) + ops(i) + ubahInt(n3) + ")" + ops(k) + "(" + ubahInt(n1) + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n2,kabataku(j,n4,kabataku(i,n3,n1))) == 24.0){    
                    sol = "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n1) + "))" + ops(k) + ubahInt(n2);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n3,kabataku(i,n1,n2))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n1) + ops(i) + ubahInt(n2) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n2,kabataku(i,n3,n1))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "((" + ubahInt(n3) + ops(i) + ubahInt(n1) + ")" + ops(j) + ubahInt(n2) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }

                // -------------------------------------------------------------------------
                if(kabataku(k,kabataku(j,kabataku(i,n4,n3),n2),n1) == 24.0){
                    sol = "((" + ubahInt(n4) + ops(i) + ubahInt(n3) + ")" + ops(j) + ubahInt(n2) + ")" + ops(k) + ubahInt(n1);
                    counter++;
                    sols.push_back(sol);
                }
                if(kabataku(k,kabataku(i,n4,n3),kabataku(j,n2,n1)) == 24.0){
                    sol = "(" + ubahInt(n4) + ops(i) + ubahInt(n3) + ")" + ops(k) + "(" + ubahInt(n2) + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n1,kabataku(j,n4,kabataku(i,n3,n2))) == 24.0){ 
                    sol = "(" + ubahInt(n4) + ops(j) + "(" + ubahInt(n3) + ops(i) + ubahInt(n2) + "))" + ops(k) + ubahInt(n1);
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n3,kabataku(i,n2,n1))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "(" + ubahInt(n3) + ops(j) + "(" + ubahInt(n2) + ops(i) + ubahInt(n1) + "))";
                    counter++;   
                    sols.push_back(sol); 
                }
                if(kabataku(k,n4,kabataku(j,n1,kabataku(i,n3,n2))) == 24.0){
                    sol = ubahInt(n4) + ops(k) + "((" + ubahInt(n3) + ops(i) + ubahInt(n2) + ")" + ops(j) + ubahInt(n1) + ")";
                    counter++;   
                    sols.push_back(sol); 
                }
                
            }
        }
    }
    auto end = chrono::steady_clock::now();
    double waktu = chrono::duration_cast<chrono::microseconds>(end - init).count() * 0.001;

    if(counter != 0){
        cout << counter << " solusi ditemukan." << endl;
        /*auto it = std::unique(sols.begin(), sols.end());
        sols.erase(it, sols.end());
        std::sort(sols.begin(), sols.end());
        it = std::unique(sols.begin(), sols.end()); */
        
        vector<string> nsols = removeduplicate(sols, sols.size());
        for(int ok=0;ok<counter;ok++){
            cout << nsols[ok] << endl;
        }
    }
    else{
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }
    cout << "Program berhasil dijalankan dengan waktu " << waktu << " ms." << endl;

    cout << "Ingin menyimpan jawaban dalam bentuk file? (1 (Ya), 0 (Tidak))" << endl;
    int pil;
    do{
        cin >> pil;
        if(pil != 1 && pil != 0){
            cout << "Mohon masukkan input yang sesuai." << endl;
        }
    }while(pil != 1 && pil != 0);
    
    if(pil == 1){
        ofstream ansFile;
        string file = "../test/answer.txt";
        ansFile.open(file.c_str());
        ansFile << "Untuk kartu " + x1 + ", " + x2 + ", " + x3 + " dan " + x4 + ","<< endl;
        if(counter != 0){
            ansFile << "Terdapat " << counter  << " solusi ditemukan." << endl;
            vector<string> nsols = removeduplicate(sols, sols.size());
            for(int ok=0;ok<counter;ok++){
                ansFile << nsols[ok] << endl;
            }
        }
        else{
            ansFile << "Tidak ada solusi yang ditemukan.";
        }
        cout << "File telah berhasil tersimpan pada test/answer.txt" << endl;
    }
    else{
        cout << "Jawaban tidak disimpan dalam bentuk file." << endl;
    }
    cout << "Terima kasih telah menggunakan solver ini." << endl;

    return 0;
   

}