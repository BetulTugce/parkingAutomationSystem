#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include  <cmath>
using namespace std;
#define MAX 100

class Vehicle{
	public:
		string plate,name,surname,tel;
		time_t entry;
}car[MAX];

class Parking{
	public:
		string attendant_id,attendant_password;
		int i, income;
		Parking(string id,string p){
			attendant_id=id;
			attendant_password=p;
			i=-1;
			income=0;	
		}
		void menu(){
			int selection;
			cout<<"OTOPARK PROGRAMI"<<endl;
			cout<<"-----------------------"<<endl;
			cout<<"1.Yeni Arac"<<endl;
			cout<<"2.Arac Cikisi"<<endl;
			cout<<"3.Arac Listele"<<endl;
			cout<<"4.Rapor"<<endl;
			cout<<"5.Cikis"<<endl;
			selection=getch();
			switch(selection){
				case '1':newV();
				break;
				case '2':takeOut();
				break;
				case '3':list();
				break;
				case '4':report();
				break;
				case '5':exit(0);
				default:cout<<"Error!!"<<endl;
				system("pause");
				system("CLS");
				menu();
				break;
			}
		}
		void newV(){
			system("CLS");
			i++;
			cout<<"Arac sahibinin bilgilerini girin."<<endl;
			cout<<"Ad: ";
			cin>>car[i].name;
			cout<<"Soyad: ";
			cin>>car[i].surname;
			cout<<"Telefon: ";
			cin>>car[i].tel;
			cout<<"Plaka: ";
			cin>>car[i].plate;
			cout<<"Arac girisi yapilmistir."<<endl;
			time(&car[i].entry);
			system("pause");
			system("CLS");
			menu();
		}
		void takeOut(){
			system("CLS");
			int j=0,k,hour;
			bool found=false;
			double timee;
			time_t exit;
			string t_plate;
			time(&exit);
			cout<<"Plaka: ";
			cin>>t_plate;
			while(j<=i){
				if(car[j].plate==t_plate){
					timee=difftime(exit,car[j].entry);
					for(k=j;k<=i;k++){
						car[k]=car[k+1];
					}
					found=true;
					i--;
					break;
				}
				j++;
			}
			if(found==true){
				cout<<"Arac cikisi yapildi!"<<endl;
				timee=timee/3600;
				hour=ceil(timee);
				cout<<"Ucret="<<hour*10<<" TL"<<endl;
				income+=hour*10;	
				system("pause");
				system("CLS");
				menu();
			}
			else{
				cout<<"Arac bulunamadi!"<<endl;
				system("pause");
				system("CLS");
				menu();
			}
		}
		void list(){
			system("CLS");
			for(int j=0;j<=i;j++){
				cout<<car[j].plate<<endl;
			}
			system("pause");
			system("CLS");
			menu();
		}
		void report(){
			system("CLS");
			cout<<"Gelir: "<<income<<" TL"<<endl;
			system("pause");
			system("CLS");
			menu();
		}
};

int main(int argc, char** argv) {
	Parking attendant("Egemen","egemen123");
	string username,password;
	int i=0;
	cout<<"OTOPARK PROGRAMI"<<endl;
	cout<<"-----------------------"<<endl;
	while(1){
		cout<<"Kullanici Adi: ";
		cin>>username;
		cout<<"Sifre: ";
		cin>>password;
		if(attendant.attendant_id==username){
			if(attendant.attendant_password==password){
				system("CLS");
				attendant.menu();
			}
			cout<<"Kullanici adi veya sifre hatali! Tekrar deneyin."<<endl;
			system("pause");
			system("CLS");
		}
	}
	system("pause");
	return 0;
}
