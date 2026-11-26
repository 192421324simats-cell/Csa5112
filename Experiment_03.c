/* Experiment 3: Playfair Cipher
Aim: Playfair encryption with I/J combined.
Educational CNS lab program.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void make(char*k,char m[5][5]){int used[26]={0},n=0;used['j'-'a']=1;for(int z=0;z<2;z++){char *p=z?k:"abcdefghijklmnopqrstuvwxyz";for(int i=0;p[i];i++){int x=tolower(p[i])-'a';if(x>=0&&x<26&&!used[x]){used[x]=1;m[n/5][n%5]=x+'a';n++;}}}}int pos(char m[5][5],char c,int*r,int*co){if(c=='j')c='i';for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(m[i][j]==c){*r=i;*co=j;return 1;}return 0;}int main(){char key[100],s[500],out[500];char m[5][5];printf("Keyword: ");scanf("%99s",key);make(key,m);printf("Plaintext: ");getchar();fgets(s,sizeof s,stdin);int n=0;for(int i=0;s[i];i++)if(isalpha(s[i])){char a=tolower(s[i]);if(a=='j')a='i';char b='x';int j=i+1;while(s[j]&&!isalpha(s[j]))j++;if(s[j]){b=tolower(s[j]);if(b=='j')b='i';}if(a==b)b='x';out[n++]=a;out[n++]=b;if(s[j]&&a!=b)i=j;}if(n%2)n++;for(int i=0;i<n;i+=2){int r1,c1,r2,c2;pos(m,out[i],&r1,&c1);pos(m,out[i+1],&r2,&c2);if(r1==r2){out[i]=m[r1][(c1+1)%5];out[i+1]=m[r2][(c2+1)%5];}else if(c1==c2){out[i]=m[(r1+1)%5][c1];out[i+1]=m[(r2+1)%5][c2];}else{out[i]=m[r1][c2];out[i+1]=m[r2][c1];}}out[n]=0;printf("Cipher pairs: %s\n",out);}
