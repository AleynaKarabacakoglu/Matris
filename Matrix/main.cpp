#include <iostream>
#include <stdlib.h>    //ALEYNA KARABACAKOGLU 330090
#include <time.h>      //NESNE YONELİMLİ PROGRAMLAMA DONEM ODEVİ
#include <fstream>     //aleynakarabacakoglu26@gmail.com
#include <iomanip>     //05445038639
#include <math.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>


using namespace std;
template <class T>

class Matris
{
  protected:
    int satir;
    int sutun;
    T **m;
    T deger;

  public:
  //prototipleri tanımladım;
  Matris(int _satir=10,int _sutun=10,T _deger=0 );
  virtual ~Matris();
  void setSatirSutun(T,T,T);
  void getSatirSutun(T &,T &,T);
  virtual void print();
  void print(string);
  void reSize(int ,int);
  Matris operator+(const Matris&);
  Matris operator+=(const Matris& );
  virtual Matris operator+=(int );
  Matris operator-=(const Matris&);
  Matris operator-=(int);
  Matris operator*(const Matris&);
  Matris operator*=(int);
  Matris operator/=(float);
  Matris operator%(int);
  Matris operator^(int);
  void Transpoz();
  void emul(const Matris&);
  void inv();
  //int determ(Matris);

};
//constructure
template <class T>
Matris <T>::Matris(int _satir,int _sutun,T _deger )
{
    satir = _satir;
    sutun = _sutun;
    deger=_deger;
    srand(time(NULL));//her seferinde farkli deger cekmek icin
    int i,j;
    int sayac=1;
    m = new T*[satir];

    for(i=0;i<satir;i++)
      {
        m[i] = new T[sutun];
      }
    if(deger=='e') //birim matris modu
      {
       if(satir==sutun)
         {for(i=0 ; i<satir ; i++)
            {for(j=0 ; j<sutun ; j++)
                {
                  if(i==j)
                    {
                      m[i][j]=1;
                    }
                  else
                    {
                      m[i][j]=0;
                    }
                }
            }
          }
       else
       {
         cout<<"Birim Matrisi Yanlis Tanimladiniz."
         <<endl<<"Lutfen Satir Sutun degerlerinizi kontrol ediniz!"<<endl<<endl;

       }
      }
	else if(deger=='l') //lineer matris modu
      {

         {for(i=0 ; i<satir ; i++)
            {for(j=0 ; j<sutun ; j++)
                {
                  m[i][j]=sayac;
			sayac++;
                }
            }
          }

      }
    else if(deger=='r')//random mod
         {
          for(i=0 ; i<satir ; i++)
            {
              for( j=0 ; j<sutun ; j++)
                 {
                   m[i][j]=rand()%256;
                 }
            }
          }

    else
    {
      for(i=0;i<satir;i++)
         {
           for(j=0;j<sutun;j++)
              {
                m[i][j]=deger;
              }
         }
    }
}
//yikici method
template <class T>
Matris <T>::~Matris()
{/*
 int i=0;
 for(i=0;i<satir;i++)
    {
     delete m[i];
    }
     delete m;
     m=NULL;*/
}
//tek seferde get set methodu
template <class T>
void Matris<T>::getSatirSutun(T &_satir, T &_sutun,T _deger)
    { _satir=satir;
      _sutun=sutun;
    }
template <class T>
void Matris<T>::setSatirSutun(T _satir,T _sutun,T _deger)
    {satir=_satir;
             sutun=_sutun;
    }

template <class T>
 void Matris<T>::print()
{
  int i,j;
  cout<<endl;
      for(i=0 ; i<satir ; i++)
         { cout<<"\t";
          for(j=0 ; j<sutun ; j++)
             {
                cout<<m[i][j]<<"\t";
             }
                cout<<endl;
         }      cout<<endl;
}

template <class T>
void Matris<T>::print(string _dosya)
{
    int i=0,j=0;
    ofstream dosya;
    dosya.open(_dosya);

    for(i=0 ; i<satir ; i++)
        { dosya<<"\t";
         for(j=0 ; j<sutun ; j++)
            {
                dosya<<m[i][j]<<"\t";
            }
                dosya<<endl;
                dosya<<endl;
            }
                dosya.close();
        }

template <class T>
void Matris<T>::reSize(int _satir,int _sutun)
{
    T* *m_yeni;
    int i,j;
    m_yeni= new T*[_satir];

           for(i=0 ; i<_satir ; i++)
           {
             m_yeni[i] = new T[_sutun];

           }
           for(i=0 ; i<_satir ; i++)
              {
               for(j=0;j<_sutun;j++)
                  {
                    m_yeni[i][j]=0;
                  }
              }


        if (satir>=_satir&&sutun<=_sutun)
        {
            int j,i;
            for(i=0;i<_satir;i++)
            { cout<<"\t";
              for(j=0;j<sutun;j++)
                 {
                    m_yeni[i][j]=m[i][j];
                    cout<<m_yeni[i][j]<<"\t";
                 }
              for(j=sutun;j<_sutun;j++)
                 {
                    m_yeni[i][j]=0;
                    cout<<m_yeni[i][j]<<"\t";
                 }
                    cout<<endl;
             }      cout<<endl;
        }
       else if (sutun>=_sutun&&satir>=_satir)
        {
          int i=0,j=0;

          for(i=0 ; i<_satir ; i++)
             {cout<<"\t";
               for(j=0 ; j<_sutun ; j++)
                  {
                     //m[i][j]=deger;
                    cout<<m[i][j]<<"\t";
                  }
                    cout<<endl;
             }      cout<<endl;
         }


        else
            {
            for(i=0; i<satir ;i++)
               {
                 for(j=0; j<sutun ;j++)
                    {
                      m_yeni[i][j]=m[i][j];
                    }
               }
            for(i=satir; i<_satir ;i++)
              {
                for(j=sutun; j<_sutun ;j++)
                    {
                      m_yeni[i][j]=0;
                    }
              }
            for(i=0; i<_satir ;i++)
               {cout<<"\t";
                 for(j=0; j<_sutun ;j++)
                    {
                      cout<<m_yeni[i][j]<<"\t";
                    }
                     cout<<endl;
               }
             }
                     cout<<endl;
}

//İki matrisin toplanmasi
template <class T>
Matris <T> Matris<T>::operator+(const Matris<T>& m1)
{

   if (satir != m1.satir || sutun != m1.sutun)
    {
      cout<<"Toplama islemi basarisiz.."<<endl;
      cout << "Matris boyutlari esit degil!!"<<endl<<endl;

    }
    else
    {
        Matris mtrs_yeni(satir,sutun,0);
        for(int i=0; i<satir; i++)
            {
                for(int j=0; j<sutun; j++)
                    {
                        mtrs_yeni.m[i][j] = m[i][j] + m1.m[i][j];
                    }
            }
                        return mtrs_yeni;

    }

}
//Diğer matrisin kendisiyle toplanmasi
template <class T>
Matris<T> Matris<T>:: operator+=(const Matris<T>& m1)
{

	if(sutun != m1.sutun || satir != m1.satir)
      {
        cout<<"Toplama islemi basarisiz.."<<endl;
        cout << "Matris boyutlari esit degil!!"<<endl<<endl;

      }
     else
     {
         Matris mtrs_yeni(satir,sutun,0);
	for (int i=0; i<satir; i++){
		for (int j=0; j<sutun; j++){
			m[i][j] += m1.m[i][j];
		}
	}
	return mtrs_yeni;

     }

}
//Diger matrisin kendisinden cikarilmasi
template <class T>
Matris<T> Matris<T>::operator-=(const Matris<T>& m1)
{

	if (satir != m1.satir || sutun != m1.sutun){
		cout << "Cikarma islemi yapilamaz."<<endl;

	}
	else
    {
        Matris mtrs_yeni(satir,sutun,0);
        cout<<"Cikarma sonucu:"<<endl;
        for(int i=0; i<satir; i++)
           {
             for(int j=0; j<sutun; j++)
                {
			      m[i][j] -= m1.m[i][j];
                }
	       }
	             return mtrs_yeni;
    }
}
//Matrisin bir sayiyla toplanmasi
template <class T>
Matris<T> Matris<T>::operator+=(int _deger)
{
	Matris mtrs_yeni(satir,sutun,0);
	cout<<"Matrisin degerle toplanmasi sonucu:"<<endl;
	 for(int i=0; i<satir; i++)
        {
            for(int j=0; j<sutun; j++)
               {
			     m[i][j] += _deger;
		       }
	    }
	          return mtrs_yeni;
}
//Matristen bir sayi cikarilmasi
template <class T>
Matris<T> Matris<T>::operator-=(int _deger)
{
    cout<<"Matristen bir deger cikarilmasi sonucu:"<<endl;
	Matris mtrs_yeni(satir,sutun,0);
	for (int i=0; i<satir; i++)
        {
            for (int j=0; j<sutun; j++)
                {
                    m[i][j] -= _deger;
                }
        }
	return mtrs_yeni;
}
//İki matrisi carpma
template <class T>
Matris<T> Matris <T>:: operator*(const Matris<T>& m1)
{
  int i=0,j=0,k=0;
Matris mtrs_yeni(satir,m1.sutun,0);

	if(sutun !=m1.satir)
       {
		cout << "Carpma islemi yapamazsiniz!!"<<endl
		<<"Lütfen satir sutun degerlerinizi kontrol edin."<<endl;
		return mtrs_yeni;

	}
	else
    {

        cout<<"Iki matrisin carpilmasi sonucu:"<<endl;
        for (i=0; i<satir; i++)
            {
            for (j=0; j<m1.sutun; j++)
                {
                for (k = 0; k <sutun; ++k)
                    {
                        mtrs_yeni.m[i][j] += m[i][k]*m1.m[k][j];
                    }
                }
            }
	return mtrs_yeni;

    }
}
//Matrisin bir degerle carpilmasi
template <class T>
Matris<T> Matris<T> :: operator*=(int _deger)
{
	Matris mtrs_yeni(satir,sutun,0);
	cout<<"Matrisin degerle carpilmasi sonucu:"<<endl;
	for (int i=0; i<satir; i++)
        {
		  for(int j=0; j<sutun; j++)
		    {
			  m[i][j] *= _deger;
		    }
        }
            return mtrs_yeni;
}
//Matrisin degere bolunmesi
template <class T>
Matris<T> Matris<T>:: operator/=(float _deger)
{
    cout<<"Matrisin degere bolunmesi sonucu:"<<endl;
	Matris mtrs_yeni(satir,sutun,0);
	for (int i=0; i<satir; i++){
		for (int j=0; j<sutun; j++){
			m[i][j] /= _deger;
		}
	}
            return mtrs_yeni;
}
//Matris mod alma islemi
template <class T>
Matris<T> Matris<T>:: operator%(int _deger)
{
    cout<<"Matrisin degere gore mod sonucu:"<<endl;
	Matris mtrs_yeni(satir,sutun,0);
	for (int i=0; i<satir; i++)
        {
            for (int j=0; j<sutun; j++)
            {
                mtrs_yeni.m[i][j]=m[i][j]% _deger;
            }
	}
                return mtrs_yeni;
}
//Matrisin ussu
template <class T>
Matris<T> Matris<T>:: operator^(int _deger)
{
    cout<<"Matrisin ussu sonucu:"<<endl;

	Matris mtrs_yeni(satir,sutun,0);

	for (int i=0; i<satir; i++)
        {
		for (int j=0; j<sutun; j++)
            {
                mtrs_yeni.m[i][j]=	pow(m[i][j],_deger)+1; //kodda bi hata var o yüzden +1
            }
	    }
                return mtrs_yeni;
}
template <class T>
void Matris<T>::Transpoz()
{
    cout<<"Matrisin transpozu:"<<endl;
    Matris t(sutun,satir,deger);
    int i=0,j=0;

    for(i=0; i<sutun ;i++)
       {cout<<"\t";
        for(j=0; j<satir ;j++)
           {
             t.m[i][j]=m[j][i];
             cout<<t.m[i][j]<<"\t";
           }
             cout<<endl;
       }     cout<<endl;

}
template <class T>
void Matris<T>::emul(const Matris<T>& m1)
{
  int i,j;
  Matris mtrs_yeni(satir,sutun,0);

  if(satir != m1.satir || sutun != m1.sutun)
    {
        cout << "Matris boyutlari esit degil!!"<<endl;

  	}
    else
    {
        cout<<"Matrisin eleman duzeyi carpma sonucu:"<<endl;
	    for(i=0; i<satir; i++)
           {cout<<"\t";
            for(j=0; j<sutun; j++)
               {
			      mtrs_yeni.m[i][j] = m[i][j]*m1.m[i][j];
                  cout<<mtrs_yeni.m[i][j];
                  cout<<"\t";
               }
                  cout<<endl<<endl;
	       }
    }

}

//Matris determinant
/*template <class T>
Matris<T>::determ(Matris<T> a)
{
  Matris temp(satir,sutun,0);
  int det=0,p,h,k,i,j;
  if(satir==1)
  {
      return a.m[0][0];
  }
  else if(satir==2)
  {
      det=(a.m[0][0]*a.m[1][1]-a.m[0][1]*a.m[1][0]);
      return det;
  }
  else
  {
    for(p=0;p<satir;p++)
    {
       h = 0;
       k = 0;
       for(i=1;i<satir;i++)
       {
         for( j=0;j<satir;j++)
         {
            if(j==p)
                {
                    continue;
                }
                temp.m[h][k] = a.m[i][j];
            k++;
                if(k==satir-1)
                {
                      h++;
                      k = 0;
            }
             }
       }
       det=det+a.m[0][p]*pow(-1,p)*determ(temp);
    }
    return det;
  }
}

template<typename T>
void Matris<T>::inv()
{
    Matris tempMatrix1(this->satir,this->sutun,'e');
    float d,k;
    for(int i=0;i<this->satir;i++){
        d=this->m[i][i];
        for(int j=0;j<this->sutun;j++){
            this->m[i][j]=this->m[i][j]/d;
            tempMatrix1.m[i][j]=tempMatrix1.m[i][j]/d;
        }
        for(int x=0;x<this->satir;x++){
            if(x!=i){
                k=this->m[x][i];
                for(int j=0;j<this->sutun;j++){
                    this->m[x][j]=this->m[x][j]-(this->m[i][j]*k);
                    tempMatrix1.m[x][j]=tempMatrix1.m[x][j]-(tempMatrix1.m[i][j]*k);
                }
            }
        }
    }

    for(int i=0;i<this->satir;i++){
        for(int j=0;j<this->sutun;j++){
            this->m[i][j]=tempMatrix1.m[i][j];
        }
    }
}
*/

//Tablo sınıfı
template <class T>
class Tablo :protected Matris<T>
{
  private:

  string *tr;
  string *tc;

  public:

  Tablo(int,int,T);

  void disp();
  void itemAt(string );
  void itemAt(int,int );
  void itemAt(string,string );
  void setRowNames(string *s ,T );
  void setColNames(string *s,int );
  virtual void print();

};

template <class T>
Tablo<T>::Tablo(int _satir,int _sutun,T _deger):Matris<T>(_satir,_sutun,_deger)
{
    Matris<T>::satir;
    int i,j;
    char sayac='A';
    tc = new string[Matris<T>::sutun];
    tr = new string[Matris<T>::satir];

    for(i=1;i<Matris<T>::satir;i++)
    {
     tr[i]=i;
    }
}

template <class T>
  void Tablo<T>::disp()
{

    int i,j;
    Tablo t(Matris<T>::satir,Matris<T>::sutun, Matris<T>::deger);
    char sayac='A';

    for(i=0;i<Matris<T>::sutun;i++)
       {
           if(i == 0)
           cout<<"\t";

         tc[i]=sayac++;
        cout<<tc[i]<<"\t";
       }cout<<endl;
    for(i=0;i<Matris<T>::satir;i++)
       {cout<<i<<"\t";
        for( j=0;j<Matris<T>::sutun;j++)
           {
             cout<<t.m[i][j]<<"\t";
           }
            cout<<endl;
        }
  }
template <class T>
void Tablo<T>::itemAt(int r,int c)
{
    Tablo table(Matris<T>::satir,Matris<T>::sutun,Matris<T>::deger);


    cout<<r<<".satir "<<c<<".sutun="<<table.m[r][c]<<endl<<endl;
}
template <class T>
void Tablo<T>::itemAt(string s)
{
    int i;
    Tablo t1(Matris<T>::satir,Matris<T>::sutun,Matris<T>::deger);
    int c1= 0;
    int c2 = 0;
    int c3 = 0;
    char sayac1 = '0';
    char sayac2 = 'A';
    char sayac3 = '0';

    if(s[2]!='\0')
      {
        for(i=0;i<Matris<T>::satir;i++)
            {
               if(sayac1 == s[1])         //2 basamaklı satir sayisa göre yani 2.basamak
                 {
                   break;                  //bos degilse bu ifin icine girer.
                 }
                 sayac1++;
                 c1++;
             }

        for(i=0;i<Matris<T>::satir;i++)
            {
               if(sayac3 == s[2])
                 {
                    break;
                 }
                    sayac3++;
                    c3++;
            }

                   c1=c1*10+c3;
     }
     else
     {
        for(i=0;i<Matris<T>::sutun;i++)       //satir sayisi tek basamakliysa
        {
          if( sayac1 == s[1] )
            {
               break;
            }
             sayac1++;
             c1++;
        }
     }

//Sutundaki ABC..lerin kaçinci sutunda oldugunu dondurur.
    for(i=0;i<Matris<T>::satir;i++)
    {
      if(sayac2 == s[0])
        {
        break;
        }
      c2++;
      sayac2++;
    }


     cout<<endl<<s<<"="<<t1.m[c1][c2]<<endl<<endl;

}
template <class T>
void Tablo<T>::itemAt(string s,string s1)
{
    int i;
    Tablo t1(Matris<T>::satir,Matris<T>::satir,Matris<T>::satir);
    int c1= 0;
    int c2 = 0;
    int c3 = 0;
    char sayac1 = '0';
    char sayac2 = 'A';
    char sayac3 = '0';

    if(s1[1]!='\0')
      {
        for(i=0;i<Matris<T>::satir;i++)
            {
               if(sayac1 == s1[0])         //2 basamaklı satir sayisa göre yani 2.basamak
                 {
                   break;                  //bos degilse bu ifin icine girer.
                 }
                 sayac1++;
                 c1++;
             }

        for(i=0;i<Matris<T>::satir;i++)
            {
               if(sayac3 == s1[1])
                 {
                    break;
                 }
                    sayac3++;
                    c3++;
            }

                   c1=c1*10+c3;
     }
     else
     {
        for(i=0;i<Matris<T>::sutun;i++)       //satir sayisi tek basamakliysa
        {
          if( sayac1 == s1[0] )
            {
               break;
            }
             sayac1++;
             c1++;
        }
     }

//Sutundaki ABC..lerin kaçinci sutunda oldugunu dondurur.
    for(i=0;i<Matris<T>::sutun;i++)
    {
      if(sayac2 == s[0])
        {
        break;
        }
      c2++;
      sayac2++;
    }


     cout<<endl<<s<<s1<<"="<<t1.m[c1][c2]<<endl<<endl;

}
template <class T>
void Tablo<T>::setRowNames(string s[],T n)
{
  Tablo table(Matris<T>::satir,Matris<T>::sutun,Matris<T>::deger);
  char sayac='A';
  int i,j,k=0;
  cout<<endl;
  cout<<"\t\t";
  for(i=0; i<Matris<T>::sutun ;i++)
     {

       tc[i]=sayac++;
       cout<<tc[i]<<"\t";
     } cout<<endl;
  for(i=0; i<Matris<T>::satir ;i++)
     {
      if(k<n)
        {
          cout<<s[i]<<"\t";
        }
      else
      {
          cout<<i<<"\t\t";
      }
      k++;
        for( j=0;j<Matris<T>::sutun;j++)
        {
           cout<<table.m[i][j]<<"\t";
        }
      cout<<endl<<endl;
    }

}
template <class T>
void Tablo<T>::setColNames(string s[],int n)
{
   Tablo table(Matris<T>::satir,Matris<T>::sutun,Matris<T>::deger);
   char sayac='A';
   int i,j,k=0,counter1=0;
   cout<<"\t";
   for(i=0;i<Matris<T>::satir;i++)
      {
         tc[i]=sayac++;
         if(counter1<n)
         cout<<s[counter1]<<"\t";
         else
         cout<<tc[i]<<"\t\t";
     counter1++;
     }
     cout<<endl;
    for(i=0;i<Matris<T>::satir;i++)
       {cout<<i<<"\t";
        for( j=0;j<Matris<T>::sutun;j++)
           {
             cout<<table.m[i][j]<<"\t\t";
             k++;
           }
             k=0;
            cout<<endl;
        }

}
template <class T>
void Tablo<T>::print()
{
      Tablo table(Matris<T>::satir,Matris<T>::sutun,Matris<T>::deger);
      char sayac='A';
      int i,j;

      string s[] = {"0. satir","1. satir","2. satir","3. satir","4. satir","5. satir",
      "6. satir","7. satir","8. satir","9. satir","10. satir","11. satir"};
      string s1[] = {"0sutun","1sutun","2sutun","3sutun","4sutun","5sutun","6sutun",
      "7sutun","8sutun","9sutun","10sutun","11sutun","12sutun","13sutun"};

    cout<<"\t\t\t";
    for(i=0;i<Matris<T>::sutun;i++)
        {
              tc[i]=sayac++;
        //Asagida sutun isimlerinin ilk 4 hanesini aldim.
        cout<<s1[i][0]<<s1[i][1]<<s1[i][2]<<s1[i][3]<<"\t\t";
        }cout<<endl;

    for(i=0;i<Matris<T>::satir;i++)
      {  //Asagida satir isimlerinin ilk 8 hanesini aldim.
         cout<<s[i][0]<<s[i][1]<<s[i][2]<<s[i][3]<<s[i][4]<<s[i][5]<<s[i][6]<<s[i][7]<<"\t\t";
         for( j=0;j<Matris<T>::satir;j++)
            {
                cout<<table.m[i][j]<<"\t\t";
            }
      cout<<endl;
    }

}

struct RGB
{
  unsigned char R;
  unsigned char G;
  unsigned char B;

};
class Image:public Matris<RGB>
{
protected:
    bool isBinary;

public:
    Image(int,int,int);



};
/*Image::Image(int width,int height,int piksel):Matris<RGB>(width,height,piksel)
{

}*/


int main()
{
  //Matris<int> *m1 = new Matris<int>(2,2,5);
  //Matris<int> *m2 = new Matris<int>(5,5,2);
   //Matris<int> *m3 = new Matris<int>(5,4,5);
  // Matris<int> *m4 = new Matris<int>(5,4,'r');
  //Matris<int> *m6 = new Matris<int>(2,2,'r');
  // Matris<int> *m5 = new Matris<int>(5,4,'e');
//   Matris<float> *m4 = new Matris<float>(5,5,2);
   //Tablo *t3 = new Tablo(5,5,'r');
   //m2->reSize(2,2);
   //t3->disp();
   //t3->itemAt("B2");
  // t3->itemAt("C","7");
  // t3->itemAt(2,2);
   //t3->itemAt("B","3");
   //string s[] = {"0. satir","1. satir","2. satir","3. satir","4. satir","5. satir"};
   //t3->setColNames(s,5);
  //t3->setRowNames(s,5);
   //*t3+=5;
   //t3->print();

  //  Tablo<int>(2,2,3);


   //toplama işlemi
   /*
   *m1=*m1+*m2;
    m1->print();
   *m3+=*m2;
    m3->print();
    */

    //cikarma işlemi
    /* *m1-=*m2;
    m1->print();
    */

    //sayiyla toplama
    /*
    *m1+=10;
    m1->print();
    */

    //Sayi cikarma
    /*
    *m1-=10;
    m1->print();
    */

    //İki matrisi carpma
    /*
    *m1=*m1**m2;
    m1->print();
    */

    //Matrisin degerle carpilmasi
    /*
    *m1*=4;
    m1->print();
    */


    //Matrisin degere bolunmesi
    /*
    *m1/=4.5;
    m1->print();
    */

    //mod islemi
    /*
    *m1=*m1%6;
    m1->print();
    */

    //us islemi
    /*
    *m1=*m1^-2;
    m1->print();
    */

    //Matris transpozu
    /*
    m4->print();
    m4->Transpoz();
    */

    //eleman duzeyi carpma
    //m1->emul(*m2);

    //determinant
   // m1->determ(*m1);
  //m1->inv();
   //Tablo *t3 = new Tablo(5,5,'r');
//t3->print();
   Tablo<double> t1(4,4,1.7);
      t1.print(); // satır ve sütun etiketleri de yazılmalı
      string s[] = {"Sat1","Sat2"};
      t1.setRowNames(s,2);



}
