#include<iostream>
#include<stdio.h>
using namespace std;

// bu programda kullanacağımız değişkenleri tanımlıyoruz.
#define INFINITY 9999
#define max 11

// disjktra isimli fonksiyon tanımlıyoruz.
void dijkstra(int G[max][max],int n,int startnode);

int main() {
                   // şehirlerimizin komşuluklarına göre matris oluşturuyoruz.
                   //Is,Sa,Ank,Bu,İz,Kü,Ko,An,Ad,Di
   int G[max][max]={{0,0,450,154,0,0,0,0,0,0},
                    {0,0,403,0,0,0,0,0,0,0,0},
                    {450,403,0,388,0,319,262,0,487,1001},
                    {154,0,388,0,345,183,0,0,0,0},
                    {0,0,0,345,0,335,0,460,0,0},
                    {0,0,319,183,335,0,326,0,0,0},
                    {0,0,262,0,0,326,0,0,345,0},
                    {0,0,0,0,460,0,0,0,609,0},
                    {0,0,487,0,0,0,284,609,0,523},
                    {0,0,1001,0,0,0,0,0,523,0}};

   int n=10;    // node sayımızı belirtiyoruz.
   int u=0;

   // yukarıda tanımladığımız fonksiyonu çağırarak programı çalıştıyoruz.
   dijkstra(G,n,u);
   return 0;

}

// yukarda tanımladığımız ve main fonksiyonunun içinde çağırdığımız
// asıl işlemin yapıldığı fonksiyonun içeriğini yazıyoruz.
void dijkstra(int G[max][max],int n,int startnode) {

   // herbir node'un mesafesini bulmak için değişkenler tanımlıyoruz.
   int cost[max][max],distance[max],pred[max];
   // node'ları tekrar etmemek için değikenler tanımlıyoruz.
   int visited[max],count,mindistance,nextnode,i,j;

  // 2li matris tanımladığımız için,
  // iç içe 2 for yaparak bütün node'ları kontrol ediyoruz.
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
      // eğer 2 node arası 0 ise kendisidir, bu yüzden değeri yoktur.
   if(G[i][j]==0)
      cost[i][j]=INFINITY;
   else
      cost[i][j]=G[i][j];
   for(i=0;i<n;i++) {
       // node'lar arttıkça,
       // başlangıç node'umuza göre mesafesini buluyoruz her node'un.
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
   }
   distance[startnode]=0;
   visited[startnode]=1;
   count=1;

    // başlangıç node'u olmadığı sürece,
    // yani diğer node'ları kontrol ediyoruz.
   while(count<n-1) {
      mindistance=INFINITY;
      for(i=0;i<n;i++)
         // eğer olan mesafe, min mesafeden küçükse
         // ve ziyaret edilmemişse
         if(distance[i]<mindistance&&!visited[i]) {
             // min mesafe artık, olan mesafedir.
         mindistance=distance[i];
         nextnode=i;
      }
      // ziyaret edilen node'ların değerini atıyoruz.
      visited[nextnode]=1;

      for(i=0;i<n;i++)
            // eğer ziyaret edilmemişse
         if(!visited[i])
      // bir sonraki node'la olan uzaklığı ve min mesafe,
      // olan mesafeden küçükse
      if(mindistance+cost[nextnode][i]<distance[i]) {
          // olan mesafe, artık bir sonraki node + min mesafedir.
         distance[i]=mindistance+cost[nextnode][i];
         // bir önceki node'la bir sonraki node'u eşitleyerek de ilerliyoruz.
         pred[i]=nextnode;
      }
      count++;
   }

   for(i=0;i<n;i++)
      // çıktı kısmı
   if(i!=startnode) {
      cout<<"\nMesafe node"<<i<<"="<<distance[i];
      cout<<"\nYol="<<i;
      j=i;
      do {
         j=pred[j];
         cout<<"<-"<<j;
      }while(j!=startnode);
   }
}
