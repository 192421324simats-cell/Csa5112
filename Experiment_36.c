/* Experiment 36: Affine Cipher
Aim: Affine cipher validation and encryption.
Educational CNS lab program.
*/
#include <stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}int main(){char s[300];int a,b;printf("Text: ");fgets(s,sizeof s,stdin);printf("a b: ");scanf("%d%d",&a,&b);if(gcd(a,26)!=1){puts("a must be coprime to 26");return 1;}for(int i=0;s[i];i++)if(s[i]>='a'&&s[i]<='z')s[i]=(a*(s[i]-'a')+b)%26+'a';else if(s[i]>='A'&&s[i]<='Z')s[i]=(a*(s[i]-'A')+b)%26+'A';printf("Encrypted: %s",s);}
