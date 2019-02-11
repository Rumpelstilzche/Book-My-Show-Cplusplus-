/*				    COMPUTER PROJECT 2015-16 

        				 "BOOK MY SHOW" 

Program to book movie shows scheduled for the next day and maintain purchase-history records. 

*/

#include <fstream.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <process.h>   
#include <string.h>  
#include <time.h> 
#include <stddef.h> 

fstream finout;                       //fstream class object for both input & output 

void login();                         //to log in 
void movie_select();                  //to select movies 

void waiting() 
{ 
 for (int i=0;i<3;i++)
  {
    sleep(1);
    cout<<".";
  }
} 

// Some Global initializations 
char* showtime[] = {  "10.05a","11.00a","12.50p","01.45p","03.35p","04.30p","05.40p","06.20p","10.00p", 
   "10.00a","11.50a","12.55p","03.50p","04.30p","05.15p","06.45p","09.40p","10.30p", 
   "09.30a","12.30p","02.50p","04.15p","05.30p","07.45p","08.30p","09.15p","11.20p", 
   "10.00a","12.40p","03.20p","06.00p","07.40p","08.40p","09.20p","10.20p","11.30p", 
   "09.45a","11.00a","12.45p","02.00p","03.45p","05.00p","06.45p","08.00p","09.00p",
   "09.50a","11.00a","12.35p","03.20p","06.05p","07.15p","08.50p","10.00p","11.35p",
   "10.20a","01.00p","03.40p","06.20p","07.00p","08.40p","09.30p","10.35p","11.05p",
   "09.45a","12.05p","02.50p","03.55p","05.30p","06.35p","08.10p","09.15p","10.45p",
   "09.00a","10.20a","11.00a","12.00n","03.00p","06.15p","09.30p","10.55p","11.50p",
   "09.30a","10.15a","12.30p","03.30p","06.30p","08.30p","09.20p","10.40p","11.40p"};
char str_plat[][4] = {"P1","P2","P3","P4","P5","P6","P7","P8","P9","P10","P11",
    "P12","P13","P14","P15","P16","P17","P18","P19","P20","P21","P22"};
char str_gold[][4] = {"G1","G2","G3","G4","G5","G6","G7","G8","G9","G10","G11",
    "G12","G13","G14","G15","G16","G17","G18","G19","G20","G21","G22",
    "G23","G24","G25","G26","G27","G28","G29","G30","G31","G32","G33"};
char str_sil[][4] = {"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11", "S12","S13","S14","S15","S16","S17","S18","S19","S20","S21","P22"};
char *mall[] = {"PVR , EDM mall","SM World","World Square Mall","PVR Saket","BIG cinemas Waves"};
char *mbolly[] = {"Kis Kis ko Pyaar karu","Calender Girls","Singh is Bliing","Talvar","Jazba"};
char *mholly[] = {"Macbeth","The Martian","The Final Girls","Knock Knock","Steve Jobs"};

float amount = 0;
int len1 = 0,len2 = 0;

class movie
 {

 int no_s;
 char *venue,*time,*ur_movie;

 public:

 void show_time(int);                 //to get showtime for a specific movie
 void book_show(int);                 //to book the show scheduled for the next day
 void seat_arrgmnt();                 //to select seats
 void payment();                      //to make payment through various options
 void purchase_his();                 //to maintain purchase history

};

movie *obj = new movie;                 //dynamic object

void movie::show_time(int r)
 {
  int p,n;

  for(int i=0;i<10;i++)
   {
    if(r == (i + 1))
       {p = i*9; n = p+9;}
   }

  for(p;p<n;++p)
   {
    cout<<"  ";
    cout.write(showtime[p],6);
   }
 }

void login()
 {

 char ch,login_ID[50],password[30];

 textbackground(WHITE);
 clrscr();
 cout<<"\n\n\n\n\n\n\t\t\t";
 textcolor(RED);
 cprintf("               /^^^^/");

 textcolor(RED);
 cout<<"\n\t\t\t\t";
 cprintf("  book//");

 textcolor(YELLOW);
 cprintf("my");

 textcolor(RED);
 cprintf("//show");
 cout<<"\n\t\t\t";
 cprintf("             /^^^^/");
 cout<<"\n\n\n\n\n\n\t\t       ";

 textbackground(BLUE);
 textcolor(WHITE);
 cprintf(" f  | LOGIN WITH FACEBOOK(press 'f')");

 textbackground(RED);
 textcolor(WHITE);
 cout<<"\n\n\t\t       ";
 cprintf(" g+ | LOGIN WITH GOOGLE+(press 'g')");

 textbackground(WHITE);
 textcolor(BLACK);
 cout<<"\n\n\t\t       ";
 cprintf(" e  | LOGIN WITH EMAIL(press 'e') ");

 getch();

 cout<<"\n\n\t\t\t               ";

 cprintf(".");
 sleep(1);
 cprintf(".");
 sleep(0.5);
 cprintf(".");
 sleep(1);

 textcolor(BLACK);

 clrscr();

 cout<<"\n\n\n\n\n\n\t\t\t Enter your ID: ";
 gets(login_ID);
 cout<<"\n\t\t\t Password: ";
 gets(password);

 clrscr();

 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t   ";
 cout<<"    Please Wait.";

 waiting();

 }


void movie::book_show(int r)
 {

 textcolor(WHITE);

 char *tim = NULL, book_it;
 int ven;
 *venue = *ur_movie = *time=NULL;

 for(int g=0;g<=10;++g)
 {
  int p,n;

  for(int i=0;i<10;i++)
  {
  if(r == (i + 1))
   { p = i*9; n = p+9;

     if(r > 5)
       ur_movie = mholly[r-6];

     else
       ur_movie = mbolly[i];
   }

  }

 len1 = strlen(ur_movie);

 if(g == r - 1)
  {
   textbackground(BLUE);

   clrscr();

   textcolor(YELLOW);
   cout<<"\n\n";
   cprintf(" Pick a venue. ");
   cout<<"\n\n";

   for(int k=0;k<5;k++)
    {
     cout<<" "<<k + 1<<". ";
     puts(mall[k]);
    }

   cout<<"\n\n The timings for this movie are: \n\n  ";
   show_time(g+1);

   cout<<"\n\n\n\n\t Select venue: ";
   cin>>ven;

   for(k=0;k<5;k++)
    {
      if(ven == (k + 1))
	venue = mall[k];
    }

   len2 = strlen(venue);

   cout<<"\n\t Enter timing (hh:mm): ";
   gets(tim);

   for(p;p<n;++p)
    {
     if(strcmp(tim,showtime[p]) == 0)
       {time = showtime[p];
	break;}
     else continue;

    }

   cout<<"\n\n    Now select your seating arrangement in the next screen (press any key).";
   getch();

   seat_arrgmnt();

   cout<<"\n\n\n\n\t\t\t Press any key to continue.";
   getch();

   obj->payment();

   textbackground(LIGHTCYAN);
   textcolor(YELLOW);

   clrscr();

   cout<<"\n\n All done.";
   cout<<"\n\n\n Your ticket";
   cout<<"\n Booking ID: FNLN0001864721";
   cout<<"\n Transaction ID: 600250980";
   cout<<"\n T-PIN/KIOSK No: 3532";
   cout<<"\n Ticket type: E-ticket";
   cout<<"\n\n\t ______________________________________________________________";
   cout<<"\n\t >                                            |               |";
   cout<<"\n\t >  ";
   cout.write(ur_movie,len1);

   if(len1 != 21)
    {for(int i=0;i<(21-len1);++i)
     cout<<" ";}

   cout<<"                     | SAT           |";
   cout<<"\n\t >   (U/A)                                    | 10 Oct. 2015  |";
   cout<<"\n\t >                                            |               |";
   cout<<"\n\t >                                            |               |";
   cout<<"\n\t >                                            |               |";
   cout<<"\n\t >   ADMITS                  ";
   cout.write(venue,len2);

   if(len2 != 17)
    {for(int i=0;i<(17-len2);++i)
       cout<<" ";}

   cout<<"|               |";
   cout<<"\n\t >    "<<no_s<<"                      Region(NCR)      | Time          |";
   cout<<"\n\t >                                            | ";
   cout.write(time,6);
   cout<<"        |";
   cout<<"\n\t >____________________________________________|_______________|";

   getch();

   finout.open("Bms.txt",ios::out);
   finout.write(ur_movie,len1);         finout<<"\n";
   finout.write(time,7);                finout<<"\n";
   finout.write(venue,len2);            finout<<"\n";
   finout<<no_s;
   finout<<"\n";
   finout.close();

   clrscr();

   cout<<"\n\n\n\n\n\n\n\t\t Want to book more(press 'y'),  ";
   cout<<"\n\t\t or press 'v' to view purchase history. ";
   cin>>book_it;

   if(book_it == 'y'||book_it == 'Y')
      movie_select();

   if(book_it == 'v'||book_it == 'V')
      purchase_his();

   else exit(0);

   break;
   }

 else continue;
  }

 }

void movie::seat_arrgmnt()
{

 textbackground(BLACK);
 textcolor(WHITE);

 clrscr();

 amount = 0;
 char ch, line[3];
 unsigned int seedval;
 time_t t;
 seedval = (unsigned)time_t(&t);
 char sts[10][5];
 int k, j, m, d[2];

 textcolor(YELLOW);

 cout<<"\n";
 cprintf(" PLATINUM (Rs.300.00)");
 srand(seedval);

 for(int i=0;i<(rand()%4)+2;++i)
 {
 d[i] = (rand() % 21) + 0;
 strcpy(str_plat[d[i]], "Bkd");
 }

 for(i=0;i<2;i++)
 {cout<<"\n";

  if(i == 0)
  {j = 1; k = 1; m = 11;}

  if(i == 1)
  {j = 12; k = 12; m = 22;}

  for(j;j<=m;j++)
  { cout<<" ____";
    cout<<"  ";
  }

  cout<<"\n";

  for(k;k<=m;k++)
  {if(k < 10)
   {cout<<"| ";

    if(strcmp(str_plat[k-1], "Bkd") == 0)
      {textcolor(GREEN);    cprintf("Bkd");
       cout<<"| ";}

    else {cout.write(str_plat[k-1],2);
   cout<<" | ";}
   }

   else
   {cout<<"| ";

    if(strcmp(str_plat[k-1], "Bkd") == 0)
     {textcolor(GREEN);    cprintf("Bkd");}

    else cout.write(str_plat[k-1], 3);
    cout<<"| ";
   }
  }
 }

 textcolor(YELLOW); 

 cout<<"\n"; 
 cprintf(" GOLD (Rs.280.00)"); 

 srand(seedval); 

 for(i=0;i<(rand()%4)+2;++i) 
 { 
 d[i] = (rand() % 32) + 0; 
 strcpy(str_gold[d[i]], "Bkd"); 
 } 

 for(i=0;i<3;i++) 
 {cout<<"\n"; 

  if(i == 0) 
  {j = 1; k = 1; m = 11;} 

  if(i == 1) 
  {j = 12; k = 12; m = 22;} 

  if(i == 2) 
  {j = 23; k = 23; m = 33;} 

  for(j;j<=m;j++) 
  { cout<<" ____"; 
    cout<<"  "; 
  } 

  cout<<"\n"; 

  for(k;k<=m;k++) 
  {if(k<10) 
   {cout<<"| "; 

    if(strcmp(str_gold[k-1], "Bkd")==0) 
      {textcolor(GREEN);    cprintf("Bkd"); 
       cout<<"| ";} 

    else {cout.write(str_gold[k-1], 2); 
    cout<<" | ";} 
  } 

   else 
   {cout<<"| "; 

    if(strcmp(str_gold[k-1], "Bkd")==0) 
     {textcolor(GREEN);    cprintf("Bkd");} 

    else cout.write(str_gold[k-1], 3); 
    cout<<"| "; 
   } 
  } 
 } 

 textcolor(YELLOW); 
 cout<<"\n"; 

 cprintf(" SILVER (Rs.260.00)"); 
 srand(seedval); 

 for(i=0;i<(rand()%4)+2;++i)  
 { 
 d[i] = (rand() % 21) + 0; 
 strcpy(str_sil[d[i]], "Bkd"); 
 } 

 for(i=0;i<2;i++) 
 {cout<<"\n"; 
 
  if(i == 0) 
   {j = 1; k = 1; m = 11;} 

  if(i == 1) 
   {j = 12; k = 12; m = 22;} 

  for(j;j<=m;j++) 
  { cout<<" ____"; 
    cout<<"  "; 
  } 

  cout<<"\n"; 

  for(k;k<=m;k++) 
  {if(k < 10) 
    {cout<<"| "; 

     if(strcmp(str_sil[k-1], "Bkd")==0) 
      {textcolor(GREEN);    cprintf("Bkd"); 
       cout<<"| ";} 

     else {cout.write(str_sil[k-1], 2); 
           cout<<" | ";} 
  } 
   else 
   {cout<<"| "; 

   if(strcmp(str_sil[k-1], "Bkd")==0) 
    {textcolor(GREEN);    cprintf("Bkd");} 

   else cout.write(str_sil[k-1], 3); 

   cout<<"| "; 
   } 
  } 
 } 

 textcolor(RED); 

 cout<<"\n\n"; 
 cprintf("==============================================================================="); 
 cprintf("                                     SCREEN"); 
 cout<<"\n\n\t  Keep what you selected in your mind and press any key."; 
 getch(); 

 textcolor(WHITE); 

 clrscr(); 

 cout<<"\n\n Enter No. of seats(max. 10): "; 
 cin>>no_s; 

 cout<<"\n Enter what you have selected. \n"; 

 for(int l=0;l<no_s;++l) 
  {cout<<"\n\t Enter name of seat "<<l+1<<" : "; 
   gets(sts[l]); 

   for(int i=0;i<22;i++) 
   {if(strcmp(str_plat[i], sts[l]) == 0) 
     {amount += 300; 
      break;} 
   } 

   for(int j=0;j<33;j++) 
   {if(strcmp(str_gold[j], sts[l]) == 0) 
     {amount += 280; 
      break;} 
   } 

   for(int k=0;k<22;k++) 
   {if(strcmp(str_sil[k], sts[l]) == 0) 
     {amount += 260; 
      break;} 
   } 
  } 
} 

void movie::payment() 
{ 

 clrscr(); 

 int pay; 

 textbackground(RED); 
 textcolor(YELLOW); 

 cout<<"\n"; 
 cprintf("                                 AMOUNT SUBTOTAL                           "); 
 cprintf("                                         "); 
 cout<<"Rs. "<<amount<<".00"; 
 cprintf("                                  "); 
 cout<<"\n\n Payment Options."; 
 cout<<"\n\n\n\t    1. Debit / Credit card"; 
 cout<<"\n\n\t    2. Net banking"; 
 cout<<"\n\n\t    3. Paytm"; 
 cout<<"\n\n\n Enter your choice: "; 
 cin>>pay; 

 textbackground(BLACK); 
 textcolor(WHITE); 

 clrscr(); 

 switch(pay) 
 { 

  case 1:long c_no, sec_cod; 
	 char *exp_d; 

	 cout<<"\n\n\n\n\n\n\t\t\t Card Number: "; 
	 cin>>c_no; 

	 cout<<"\n\n\t\t\t Expiration date: "; 
	 gets(exp_d); 

	 cout<<"\n\n\t\t\t CVV: "; 
	 cin>>sec_cod; 

	 clrscr(); 

	 cout<<"\n\n\n\n\n\n\n\n\n\t\t\t           Processing"; 
	 waiting(); 

	 break; 

   case 2:char t_pmnt, *pw; 

	  cout<<"\n\n Select bank."; 
	  cout<<"\n\n\n\t   1. ICICI bank"; 
	  cout<<"\n\t   2. YES bank"; 
	  cout<<"\n\t   3. HDFC bank"; 
	  cout<<"\n\t   4. citi bank"; 
	  cout<<"\n\t   5. State bank of India"; 
	  cout<<"\n\t   6. Axis bank"; 
	  cout<<"\n\t   7. Standard Chartered"; 
	  cout<<"\n\t   8. Kodak Mahindra bank"; 
	  cout<<"\n\t   9. IDBI bank \n\n\t\t\t"; 

	  getch(); 

 	  clrscr(); 
  
	  cout<<"\n\n\n\n\n\n\n\n\t\t\t Password: "; 
	  gets(pw); 
	  cout<<"\n\n\t\t\t Type of Payment."; 
	  cout<<"\n\t\t\t ('c' for Current,'a' for Advanced): "; 
	  cin>>t_pmnt; 

	  clrscr(); 

	  cout<<"\n\n\n\n\n\n\n\n\n\t\t\t   Processing"; 
	  waiting(); 

	  break; 

  case 3:int pytm_num; 

	 cout<<"\n\n\n\n\n\n\n\n\n\t\t\t    Enter your Paytm number: "; 
	 cin>>pytm_num; 

	 clrscr(); 

	 cout<<"\n\n\n\n\n\n\n\n\n\t\t\t   Processing"; 
	 waiting(); 
	 break; 
 } 
} 

void movie::purchase_his() 

{ 

 clrscr(); 

 textbackground(WHITE); 
 textcolor(BLACK); 

 clrscr(); 

 textbackground(RED); 

 char chr, line[22]; 

 for(int i=0;line[i]!='\0';i++) 
  line[i] = ' '; 

 cout<<"\n"; 
 cprintf("                               PURCHASE HISTORY                                 "); 
 finout.open("Bms.txt",ios::in); 

 if(!finout) 
   cout<<"\n\n\n\n\n\n\n\n\n\t\t\t      No Recent Purchases"; 

 else 
  {finout.seekg(0); 
   cout<<"\n"; 

   while(finout) 
   { 
   if(finout.eof()) 
     break; 

   cout<<"_______________________________________________________________________________\n"; 

   finout.getline(line, 22); 
   cout.write(line, strlen(line)).write("\n",1); 

   finout.getline(line, 22); 
   cout.write(line, strlen(line)).write("\n",1); 

   finout.getline(line, 22); 

   if((finout.eof()) - 1) 
    {cout.write(line, strlen(line)).write("\nADMITS:", 8);} 

   finout.getline(line, 22); 
   cout.write(line, strlen(line)).write("\n", 1); 

   } 
  } 

 cout<<"\t\t\t         Press any key."; 
 getch(); 

 finout.close(); 
 movie_select(); 
} 

void movie_select() 
 { 

 select: 

 textbackground(BLACK); 
 textcolor(WHITE); 

 clrscr();

 textbackground(RED);

 char wood, book;

 cout<<"\n\n";
 cprintf("                                   DISCOVER                                     ");

 textbackground(BLACK);

 cout<<"\n\n\n\n\t Select.";
 cout<<"\n\n\t\t 1. Hindi Movies";
 cout<<"\n\t\t 2. English Movies";
 cout<<"\n\n\t 3. View purchase history. ";

 cout<<"\n\n\n\t Enter your choice (or press '0' to exit): ";
 cin>>wood;

 switch(wood)
 {
  case '1':film:

	 textbackground(BLUE);
	 textcolor(WHITE);

	 clrscr();

	 textbackground(RED);

	 char boll;

	 cout<<"\n";
	 cprintf("                                   BOLLYWOOD                                    ");
	 cout<<"\n\n Here are some latest running and upcoming movies.";

	 textbackground(BLUE);
	 textcolor(RED);

	 cout<<"\n\n\t\t\t    ";
	 cprintf("   RUNNING MOVIES ");
	 cout<<"\n\n\t";

	 for(int r=0;r<5;r++)

	 {
	  cout<<" "<<r + 1<<". ";
	  puts(mbolly[r]);
	  cout<<"\t";
	 }

	 cout<<"\n\n\t\t\t      ";
	 cprintf(" UPCOMING MOVIES");
	 cout<<"\n\n\t 6. Chinar Daastan-E-Ishq";
	 cout<<"\n\t 7. Shaandar";
	 cout<<"\n\t 8. Ghayal Once Again";

	 cout<<"\n\n\n\t Enter Your choice: ";
	 cin>>boll;

	 textcolor(WHITE);

	 switch(boll)
	 {
	 case '1':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" KIS KIS KO PYAAR KARU");
		cout<<"\n";
		cprintf(" _____________________");
		cout<<"\n\n Release Date: 25 sept 2015";
		cout<<"\n\n Genre: Comedy/Romance";
		cout<<"\n\n Kis Kis ko Pyaar Karu is an upcoming 2015 Indian romantic comedy";
		cout<<"\n film directed by director Abbas Mustan. Indian stand-up comedian Kapil";
		cout<<"\n Sharma will make his Bollywood debut with this movie. Other casts include";
		cout<<"\n Arbaaz Khan, Manjari Phadnis, Amrita Puri, Simran Kaur Mundi,Elli Avram, Sai";
		cout<<"\n Lokur, Varun Sharma, Supriya Pathak,Sharat Saxena,Manoj Joshi,                Sharad Sankla";
		cout<<"\n (charlie),and Johnny Lever's daughter Jamie Lever.";
		cout<<"\n\n The film was also promoted at Kapil Sharma's own comedy show,Comedy Nights ";
		cout<<"\n with Kapil.Most of the shooting of this movie is done in Jodhpur India,";
		cout<<"\n most of the songs were choreographed by Ahmed Khan.";

		cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0).";
		cin>>book;

		if(book == 'b' || book == 'B')
		   obj->book_show(1);

		else goto film;

		break;

	 case '2':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" CALENDER GIRLS");
		cout<<"\n";
		cprintf(" ______________");
		cout<<"\n\n Release Date: 25 sept 2015";
		cout<<"\n\n Genre: Drama";
		cout<<"\n\n Calendar Girls is an upcoming 2015 Indian drama film directed by Madhur ";
		cout<<"\n Bhandarkar and co-produced by Sangeeta Ahir and Bhandarkar Entertainment.";
		cout<<"\n According to director Madhur Bhandarkar, the story of Calendar Girls is 75%";
		cout<<"\n reality and 25% fiction.";
		cout<<"\n\n The film focuses on five girls who hail from different regions of India, and";
		cout<<"\n who have been selected to pose for the country's most prestigious annual";
		cout<<"\n calendar which is a joint effort between business tycoon Rishabh Kukreja";
		cout<<"\n and his photographer friend Timmy Sen. Five new actressess are making their";
		cout<<"\n debut in Hindi film industry with Calendar Girls.";

		cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0).";
		cin>>book;

		if(book == 'b' || book == 'B')
		   obj->book_show(2);

		else goto film;

		break;

	 case '3':clrscr();
		textcolor(YELLOW);
		cout<<"\n\n";
		cprintf(" SINGH IS BLIING");
		cout<<"\n";
		cprintf(" _______________");
		cout<<"\n\n Release Date: 2 oct 2015";
		cout<<"\n\n Genre: Action/Comedy";
		cout<<"\n\n Singh Is Bliing is an upcoming Bollywood action/comedy film directed";
		cout<<"\n by Prabhu Deva and produced by Ashvini Yardi and Jayantilal Gada under";
		cout<<"\n the banners Grazing Goat Pictures and Pen India Pvt. Ltd. The film features";
		cout<<"\n Akshay Kumar,Amy Jackson, Lara Dutta and Deedag Ali in lead roles.";
		cout<<"\n\n Shri Akal Takht Jathedar, Giani Gurbachan Singh objected some scenes";
		cout<<"\n in Trailer and said that equating Holy Golden Temple with whisky and ";
		cout<<"\n chicken is highly objectionable and also film posters which has Kada with";
		cout<<"\n inscribed Gurbani shown with semi-clad women.";

		cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0).";
		cin>>book;

		if(book == 'b' || book == 'B')
		   obj->book_show(3);

		else goto film;

		break;

	 case '4':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" TALVAR");
		cout<<"\n";
		cprintf(" ______");
		cout<<"\n\n Release Date: 2 oct 2015";
		cout<<"\n\n Genre: Murder Mystery";
		cout<<"\n\n Talvar is a 2015 Bollywood murder mystery thriller film directed by ";
		cout<<"\n Meghna Gulzar. The film is based on the 2008 Noida double murdercase, in";
		cout<<"\n which a teenage girl and her family servant were found murdered, and her ";
		cout<<"\n parents were convicted for the murders.";
		cout<<"\n\n The film stars Irrfan Khan,Konkona Sen Sharma,Neeraj Kabi and Sohum Shah";
		cout<<"\n in leading roles and Tabu in a guestappearance.";
		cout<<"\n\n The film is based on a 2008 murder case in Noida, in which 14-year old ";
		cout<<"\n Aarushi Talwar was found murdered at her home.";

		cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0).";
		cin>>book;

		if(book == 'b' || book == 'B')
		   obj->book_show(4);
		else goto film;

		break;

	 case '5':clrscr();
		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" JAZBA");
		cout<<"\n";
		cprintf(" _____");
		cout<<"\n\n Release Date: 9 oct 2015";
		cout<<"\n\n Genre: Action/Drama";
		cout<<"\n\n Jazbaa is an upcoming Indian action-drama film directed by Sanjay ";
		cout<<"\n Gupta. It stars Aishwarya Rai Bachchan in the lead role, with Irrfan Khan";
		cout<<"\n and Shabana Azmi in supporting roles.";
		cout<<"\n\n Filming began in January 2015, and the film has been shot in and around";
		cout<<"\n Mumbai. It is a remake of the 2007 South Korean film 'Seven Days'. The ";
		cout<<"\n trailer of the film released on August 25, 2015.";

		 cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0).";
		 cin>>book;

		 if(book == 'b' || book == 'B')
		    obj->book_show(5);

		 else goto film;

		 break;

	 case '6':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" CHINAR DAASTAAN-E-ISHQ");
		cout<<"\n";
		cprintf(" ______________________");
		cout<<"\n\n Release Date: 16 oct 2015";
		cout<<"\n\n Chinar Daastaan-E-Ishq is Bollywood movie produced by Rajesh R Jain";
		cout<<"\n & Directed By Sharique Minhaj. Aamir Khan's brother Faisal Khan has made";
		cout<<"\n come back in Bollywood after 9 Years. Inayat Sharma is lead actress opposite";
		cout<<"\n to Faisal Khan. Dalip Tahil, Pramod Mautho & Shahbaj Khan are in parallel lead";
		cout<<"\n in Chinar Daastaan-E-Ishq.";
		cout<<"\n\n This film has been shot in the beautiful locations of Kashmir & Mumbai. Main";
		cout<<"\n plot of film belongs to Kashmir.";

		cout<<"\n\n\n\t        Press '0' to jump back or '1' to exit.";
		cin>>book;

		if(book == '0')
		   goto film;

		else exit(0);

		break;

	 case '7':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" SHAANDAR");
		cout<<"\n";
		cprintf(" ________");
		cout<<"\n\n Release Date: 22 oct 2015";
		cout<<"\n\n Genre: Romantic/comedy";
		cout<<"\n\n Shaandaar is an upcoming Indian romantic comedy film, directed by Vikas";
		cout<<"\n Bahl and produced by Anurag Kashyap and Vikramaditya Motwane.It stars Alia";
		cout<<"\n Bhatt and Shahid Kapoor in lead roles,with Pankaj Kapur and Sanjay Kapoor in";
		cout<<"\n supporting roles.";
		cout<<"\n\n The first look of the movie released on 5 August 2015 with a teaser poster ";
		cout<<"\n where the leads are sitting on a bench. The trailer of the film was released";
		cout<<"\n on 11 Aug,2015 by Dharma Productions featuring Shahid Kapoor and Alia Bhatt.";

		cout<<"\n\n\n\t        Press '0' to jump back or '1' to exit.";
		cin>>book;

		if(book == '0')
		   goto film;

		else exit(0);

		break;

	 case '8':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" GHAYAL ONCE AGAIN");
		cout<<"\n";
		cprintf(" _________________");
		cout<<"\n\n Release Date: Probably in Jan 2016";
		cout<<"\n\n Genre: Action/Drama";
		cout<<"\n\n Ghayal Once Again is an upcoming Indian action/drama film directed by Sunny";
		cout<<"\n Deol and produced by Dharmendra.It is the sequel to 1990 super-hit film Ghayal.";
		cout<<"\n\n The film was initially scheduled to release on 13 November 2015 but it got ";
		cout<<"\n delayed as the shooting could not meet it's deadline due to VFX works that are";
		cout<<"\n going on in full swing. Sunny Deol hired Hollywood Action Co-ordinator Dan Bradley";
		cout<<"\n for designing action sequences.";
		cout<<"\n The film will take-off from where the first version lef to.";

		cout<<"\n\n\n\t        Press '0' to jump back or '1' to exit.";
		cin>>book;

		if(book == '0')
		   goto film;

		else exit(0);

		break;

	default:clrscr();
		goto film;
	}
	break;

  case '2':h_film:

	 textbackground(BLUE);
	 textcolor(WHITE);

	 clrscr();
	 textbackground(RED);

	 char holl;

	 cout<<"\n";
	 cprintf("                                   HOLLYWOOD                                    ");
	 cout<<"\n\n Here are some latest running and upcoming movies.";

	 textbackground(BLUE);
	 textcolor(RED);

	 cout<<"\n\n\t\t\t    ";
	 cprintf("   RUNNING MOVIES ");
	 cout<<"\n\n\t";

	 for(r=0;r<5;r++)
	 {
	  cout<<" "<<r+1<<". ";
	  puts(mholly[r]);
	  cout<<"\t";
	 }

	 cout<<"\n\n\t\t\t      ";
	 cprintf(" UPCOMING MOVIES");
	 cout<<"\n\n\t 6. Goosebumps";
	 cout<<"\n\t 7. Paranormal activity:The Ghost Dimension";
	 cout<<"\n\t 8. Brooklyn";
	 cout<<"\n\n\n\t Enter Your choice: ";
	 cin>>holl;

	 textcolor(WHITE);

	 switch(holl)
	 {
	 case '1':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" MACBETH");
		cout<<"\n";
		cprintf(" _______");
		cout<<"\n\n Release Date: 2 oct 2015";
		cout<<"\n\n Genre: Comedy/Romance";
		cout<<"\n\n Macbeth is a 2015 British drama film directed by Justin Kurzel and written by";
		cout<<"\n Jacob Koskoff, Todd Louiso and Michael Lesslie, based on William Shakespeare's";
		cout<<"\n play The Tragedy of Macbeth. The film stars Michael Fassbender in the title ";
		cout<<"\n role and Marion Cotillard as Lady Macbeth.";
		cout<<"\n\n On Rotten Tomatoes, the film has an approval rating of 93% based on 15 ";
		cout<<"\n reviews, with an average rating of 7.5/10.";
		cout<<"\n\n Filming took place over seven weeks in England and Scotland. Other locations";
		cout<<"\n used include Quiraing in Skye, and Ely Cathedral in Ely, Cambridgeshire.";

		cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0).";
		cin>>book;

		if(book == 'b' || book == 'B')
		   obj->book_show(6);

		else goto h_film;

		break;

	 case '2':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" THE MARTIAN");
		cout<<"\n";
		cprintf(" ___________");
		cout<<"\n\n Release Date: 2 oct 2015";
		cout<<"\n\n Genre: Science Fiction";
		cout<<"\n\n The Martian is a 2015 American science fiction film directed by Ridley Scott";
		cout<<"\n and starring Matt Damon. The film is based on Andy Weir's 2011 novel The ";
		cout<<"\n Martian, which was adapted into a screenplay by Drew Goddard. Damon stars as";
		cout<<"\n an astronaut who is presumed dead and left behind on the planet Mars,and he";
		cout<<"\n fights to survive the situation. ";
		cout<<"\n\n On Rotten Tomatoes the film has a rating of 97%, based on 39 reviews, with an";
		cout<<"\n average rating of 7.4/10. The site's critical consensus reads,''Smart,";
		cout<<"\n thrilling,and surprisingly funny, The Martian offers a faithful adaptation of";
		cout<<"\n the best selling book that brings out the best in leading man Matt Damon and";
		cout<<"\n director Ridley Scott''";

		cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0).";
		cin>>book;

		if(book == 'b' || book == 'B')
		   obj->book_show(7);

		else goto h_film;

		break;

	 case '3':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" THE FINAL GIRLS");
		cout<<"\n";
		cprintf(" _______________");
		cout<<"\n\n Release Date: 9 oct 2015";
		cout<<"\n\n Genre: Horror/comedy";
		cout<<"\n\n The Final Girls is a 2015 American horror comedy film, directed by Todd";
		cout<<"\n Strauss-Schulson and written by M.A. Fortin and Joshua John Miller. The film";
		cout<<"\n stars Taissa Farmiga and Malin Akerman in the two leading roles,with ";
		cout<<"\n supporting performances from Adam DeVine, Thomas Middleditch, Alia Shawkat,";
		cout<<"\n Alexander Ludwig, Nina Dobrev,Chloe Bridges,and Angela Trimbur.";
		cout<<"\n\n The Final Girls received acclaim from film critics. The film holds a 70% ";
		cout<<"\n 'Fresh' rating on review aggregator website Rotten Tomatoes.";
		cout<<"\n The film had its world premiere on March 13, 2015 at South by Southwest.It ";
		cout<<"\n then screened at the Stanley Film Festival on May2,2015,where it won the ";
		cout<<"\n Audience Award for Feature Film.";

		cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0)...";
		cin>>book;

		if(book == 'b'||book == 'B')
		   obj->book_show(8);

		else goto h_film;

		break;

	 case '4':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" KNOCK KNOCK ");
		cout<<"\n";
		cprintf(" ___________");
		cout<<"\n\n Release Date: 9 oct 2015";
		cout<<"\n\n Genre: Erotic Horror";
		cout<<"\n\n Knock Knock is a 2015 Chilean-American erotic horror film directed by Eli";
		cout<<"\n Roth, who also co-wrote the script with Guillermo Amoedo and Nicolas Lopez.";
		cout<<"\n The film stars Keanu Reeves, Lorenza Izzo, and Ana de Armas.";
		cout<<"\n\n Knock Knock has a score of 69% on Metacritic. Dread Central awarded it a ";
		cout<<"\n score of 4 out of 5, saying 'what we do have is a home invasion film for the ";
		cout<<"\n social media generation.";
		cout<<"\n\n Knock Knock was released in the Republic of Ireland in June 2015 and in the ";
		cout<<"\n UK in June where it grossed approximately 500,000 pounds.";

		cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0).";
		cin>>book;

		if(book == 'b' || book == 'B')
		   obj->book_show(9);

		else goto h_film;

		break;

	 case '5':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" STEVE JOBS ");
		cout<<"\n";
		cprintf(" __________");
		cout<<"\n\n Release Date: 9 oct 2015";
		cout<<"\n\n Genre: Biographical Drama";
		cout<<"\n\n Steve Jobs is an upcoming 2015 American biographical drama film based on ";
		cout<<"\n the life of Apple Inc. co-founder Steve Jobs,starring Michael Fassbender in ";
		cout<<"\n the title role. The film is directed by Danny Boyle,produced by Scott Rudin, ";
		cout<<"\n and written by Aaron Sorkin (with a screenplay adapted both from Walter ";
		cout<<"\n Isaacson's biography Steve Jobs as well as from interviews conducted by ";
		cout<<"\n Sorkin).";
		cout<<"\n\n According to the film's offcial website: 'Set backstage at three iconic ";
		cout<<"\n product launches and ending in 1998 with the unveiling of the iMac,Steve Jobs";
		cout<<"\n takes us behind the scenes of the digital revolution to paint an intimate ";
		cout<<"\n portrait of the brilliant man at it's epicenter.";

		cout<<"\n\n\n\t       Press 'b' to book or jump back(press 0).";
		cin>>book;

		if(book == 'b' || book == 'B')
		   obj->book_show(10);

		else goto h_film;

		break;

	 case '6':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" GOOSEBUMPS ");
		cout<<"\n";
		cprintf(" __________");
		cout<<"\n\n Release Date: 16 oct 2015";
		cout<<"\n\n Genre: 3D Live action-computer animated";
		cout<<"\n\n Goosebumps is an upcoming 2015 American 3D live action/computer-animated";
		cout<<"\n film directed by Rob Letterman and written by Scott Alexander,Larry ";
		cout<<"\n Karaszewski, and Darren Lemke. It is based on the children's book series of";
		cout<<"\n the same name by R. L. Stine and stars Jack Black, Dylan Minnette, Odeya";
		cout<<"\n Rush, Amy Ryan, Ryan Lee,and Jillian Bell.";
		cout<<"\n\n In mid-April 2014, a crew of six spent three days gathering visual data ";
		cout<<"\n for the film in downtown Madison, Georgia. The crew used a theodolite to ";
		cout<<"\n collect points in three-dimensional space to complete a detailed survey of";
		cout<<"\n the city.";

		cout<<"\n\n\n\t        Press '0' to jump back or '1' to exit.";
		cin>>book;

		if(book == '0')
		   goto h_film;

		else exit(0);

		break;

	 case '7':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" PARANORNMAL ACTIVITY: THE GHOST DIMENSION ");
		cout<<"\n";
		cprintf(" _________________________________________");
		cout<<"\n\n Release Date: 23 oct 2015";
		cout<<"\n\n Genre: 3D sound footage-supernatural horror";
		cout<<"\n\n Paranormal Activity: The Ghost Dimension (also known as Paranormal ";
		cout<<"\n Activity 6) is an upcoming American 3D found footage supernatural horror";
		cout<<"\n film directed by Gregory Plotkin in his directorial debut and written by";
		cout<<"\n Jason Pagan and Andrew Stark. Plotkin served as the editor for the past ";
		cout<<"\n four Paranormal Activity films.It is the second spin-off/sequel of the ";
		cout<<"\n Paranormal Activity film series and the sixth and final installment of ";
		cout<<"\n thefranchise.";
		cout<<"\n\n The film will follow supernatural occurrences that take place in a newly";
		cout<<"\n moved family's home in Palo Alto,California.";

		cout<<"\n\n\n\t        Press '0' to jump back or '1' to exit.";
		cin>>book;

		if(book == '0')
		   goto h_film;

		else exit(0);

		break;

	 case '8':clrscr();

		textcolor(YELLOW);

		cout<<"\n\n";
		cprintf(" BROOKLYN ");
		cout<<"\n";
		cprintf(" ________");
		cout<<"\n\n Release Date: 6 nov 2015";
		cout<<"\n\n Genre: Historical Period Drama";
		cout<<"\n\n Brooklyn is a 2015 historical period drama film directed by John Crowley and";
		cout<<"\n written by Nick Hornby, base don Colm Toibin's novel of the samename. The film";
		cout<<"\n ,starring Saoirse Ronan, Emory Cohen, Domhnall Gleeson, Jim Broadbent and";
		cout<<"\n Julie Walters.";
		cout<<"\n\n The film is an international co-production between companies in Ireland,the ";
		cout<<"\n United Kingdom,and Canada.";
		cout<<"\n\n It has been selected to be shown in the Special Presentations section of the";
		cout<<"\n 2015 Toronto International Film Festival.";

		cout<<"\n\n\n\t        Press '0' to jump back or '1' to exit.";
		cin>>book;

		if(book == '0')
		   goto h_film;

		else exit(0);

		break;

	default:clrscr();
		goto h_film;
	 }
	 break;

  case '3':obj->purchase_his();
	 break;

  case '0':exit(0);

  default:clrscr();
	  goto select;
  }

 }

void main()
{

 textbackground(RED);

 clrscr();

 textcolor(WHITE);

 cout<<"\n\n\n\n\n\n\n\n\n\t\t\t";
 cprintf("               /^^^^/");
 cout<<"\n\t\t\t\t";
 cprintf("  book//");

 textcolor(YELLOW);

 cprintf("my");

 textcolor(WHITE);

 cprintf("//show");
 cout<<"\n\t\t\t";
 cprintf("             /^^^^/");
 cout<<"\n\n\t\t    ";
 cprintf("(MINI version: to book next day shows only)");
 sleep(3);

 login();
 movie_select();

 delete obj;

 getch();
}