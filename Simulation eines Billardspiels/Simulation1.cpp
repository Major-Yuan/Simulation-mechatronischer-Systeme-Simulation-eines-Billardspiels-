//====================================================================
// Simulation dynamischer Systeme mit PLAN
//====================================================================
// Projektbeschreibung: Eine Simulation Vom Billardspiel
//
//====================================================================
#include <vcl.h>
#pragma hdrstop
#include "Plan.h"

class TUser : public TPlan {
   int N,cb,cw,P1,P2,a1,a2;
   double xtoK,ytoK,xx,yy,xc,yc,xp,yp,dx,dy;
   bool klick,los,ZeigerAktiv,f1,f2;
   public:
   void Init();
   void DGL();
   void Run();
   void Reset();
   void Draw();
   void Blatt();
   void BildMouseDown(int x, int y);
   void BildMouseUp(int x, int y);
   void BildMouseMove(int x, int y, int leftdown);
   void Klick();
   void RunTaste0();
   void RunTaste1();
   void RunTaste2();
   void  Punkte(int i);
   };


void TUser::Init(){
   N = 11;                                                 //die Anzahl der Billarde definieren
   Scale(0.0,20.0,0.0);
   GesamtOrdnung = 4*(N+1);
   Intervall(0.0,1000.0);
   Toleranz = 1e-8;
   cb=20000;
   cw=20000;
   Blatt();
   Reset();
   klick=false;
   los=false;
   InsertTaste(0,"Spieler 1","");
   InsertTaste(1,"Spieler 2","");
   InsertTaste(2,"Reset Weiss","");
   }


void TUser::Run(){
   int i;
   if(f1==true)
   {                                                                                                                                                                 //##ins Loch fuer den Spieler 1##
   for(i=0;i<N;i++){
   if(X2O(i)<1.5+0.5&&X2O(i+N)<1.5+0.5)
    if(X2O(i)>-1.0) {X2O(i)=-1.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}       //  ins unterlinks   Loch
   if(X2O(i)>18.5-0.5&&X2O(i+N)<1.5+0.5)
    if(X2O(i)>-1.0) {X2O(i)=-1.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}       //  ins oberlinks    Loch
   if(X2O(i)<1.5+0.5&&X2O(i+N)>10.5-0.5)
    if(X2O(i)>-1.0) {X2O(i)=-1.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}       //  ins untermittels Loch
   if(X2O(i)>18.5-0.5&&X2O(i+N)>10.5-0.5)
    if(X2O(i)>-1.0) {X2O(i)=-1.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}       //  ins obermittels  Loch
   if(X2O(i)>10-0.25&&X2O(i)<10+0.25&&X2O(i+N)<1.5+0.25)
    if(X2O(i)>-1.0) {X2O(i)=-1.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}       //  ins unterrechts  Loch
   if(X2O(i)>10-0.25&&X2O(i)<10+0.25&&X2O(i+N)>10.5-0.25)
    if(X2O(i)>-1.0) {X2O(i)=-1.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}       //  ins oberrechts   Loch
                   }
   }

   else if(f2==true)                                                                                                                                                 //##ins Loch fuer den Spieler 2##
   {
   for(i=0;i<N;i++){
   if(X2O(i)<1.5+0.5&&X2O(i+N)<1.5+0.5)
    if(X2O(i)>-1.0) {X2O(i)=-2.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}
   if(X2O(i)>18.5-0.5&&X2O(i+N)<1.5+0.5)
    if(X2O(i)>-1.0) {X2O(i)=-2.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}
   if(X2O(i)<1.5+0.5&&X2O(i+N)>10.5-0.5)
    if(X2O(i)>-1.0) {X2O(i)=-2.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}
   if(X2O(i)>18.5-0.5&&X2O(i+N)>10.5-0.5)
    if(X2O(i)>-1.0) {X2O(i)=-2.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}
   if(X2O(i)>10-0.25&&X2O(i)<10+0.25&&X2O(i+N)<1.5+0.25)
    if(X2O(i)>-1.0) {X2O(i)=-2.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}
   if(X2O(i)>10-0.25&&X2O(i)<10+0.25&&X2O(i+N)>10.5-0.25)
    if(X2O(i)>-1.0) {X2O(i)=-2.5;X2O(i+N)=-1.5;X2OP(i)=0;X2OP(i+N)=0;X2OPP(i)=0;X2OPP(i+N)=0;Punkte(i);}
   }
                   }

   CallRun = Integrationsschritt(0.01);
   if(los){ X2OP(0)=-xp;X2OP(N)=-yp;
   los=!los;}

   Draw();

}


void TUser::Punkte(int i)                                                                                                                                             //##Punkte von verschiedenen Kugeln definieren und speichern##
{                                      //##Punkte von verschiedenen Kugeln definieren und speichern##
if(f1==true)                           //Fuer Spieler 1                                                                                                                               // Fuer Spieler 1
{switch(i){case 0:a1=a1-9;  break;     //Punkte fuer Kugeln mit verschiedener Nummern z.B Nummer 0 ist fuer weisse Kugel
           case 1:a1=a1+1;  break;
           case 2:a1=a1+2;  break;
           case 3:a1=a1+3;  break;
           case 4:a1=a1+4;  break;
           case 5:a1=a1+5;  break;
           case 6:a1=a1+6;  break;
           case 7:a1=a1+7;  break;
           case 8:a1=a1+8;  break;
           case 9:a1=a1+9;  break;
           case 10:a1=a1+10;break;
           default:a1=a1+11;};
}

else if(f2==true)                      //Fuer Spieler 1                                                                                                                               // Fuer Spieler 2
{switch(i){case 0:a2=a2-9;  break;
           case 1:a2=a2+1;  break;
           case 2:a2=a2+2;  break;
           case 3:a2=a2+3;  break;
           case 4:a2=a2+4;  break;
           case 5:a2=a2+5;  break;
           case 6:a2=a2+6;  break;
           case 7:a2=a2+7;  break;
           case 8:a2=a2+8;  break;
           case 9:a2=a2+9;  break;
           case 10:a2=a2+10;break;
           default:a2=a2+11;};
           };
}


void TUser::DGL(){
   int i,j;
   double dx,dy,w,fr,q,a,b,c,d,e,ff1,ff2,ff3,ff4;
   for(i=0;i<N;i++){                                    //##Die Reibung zwischen dem Boden und der Kugel##
   if (X2OP(i)==0) a=0.5*M_PI;                          //a zeigt die Richtung von Kugelgeschwindigkeit
   else  a=atan(X2OP(N+i)/X2OP(i));

   fr=3;                                                //fr ist der Vorfaktor von der Reibung
   X2OPP(i) =0.0;
   X2OPP(i+N) = 0.0;
   if(X2OP(i)>0)                                        //Die Reibung in x und y Richtung zu trennen
   X2OPP(i) = -fr*(cos(sqrt(a*a)));                     //if-Bedingung bestimmt, ob die Geschwindigkeit positiv ist
   else
   X2OPP(i) = fr*(cos(sqrt(a*a)));
   if(X2OP(i+N)>0)
    X2OPP(N+i) = -fr*(sin(sqrt(a*a)));
   else
    X2OPP(N+i) = fr*(sin(sqrt(a*a)));
   }

   for(i=0;i<N-1;i++){                                  //##Stoss zwischen Kugeln;
    for(j=i+1;j<N;j++){                                 //w ist der Abstand zwischen Kugeln;
    dx = X2O(i) - X2O(j);
    dy = X2O(N+i)-X2O(N+j);
    w = sqrt(dx*dx+dy*dy);
    if(w<0.49&&w>0){                                    //if-Bedingung bestimmt, ob zwei Kugeln stossen;
    q = cb*0.5*(0.5-w);                                 //q ist der Vorfaktor der Kraft von Stoss;
    X2OPP(i) += q*dx/w;                                 //q=Kugelelastizitaet*Eindringung;
    X2OPP(N+i) += q*dy/w;                               //q in x und y Richtung zu trennen;
    X2OPP(j) += -q*dx/w;
    X2OPP(N+j) += -q*dy/w;}}}

   for(i=0;i<N;i++){                                    //##Stoss zwischen der Kugel und der Wand;
    b= X2O(i) - 1.5;                                    //b,c,d,e sind Abstaende zwischen der Kugel und der Wand;
    c= 18.5  -  X2O(i);
    d= X2O(i+N)- 1.5;
    e= 10.5  -  X2O(i+N);
    if(b<0.24&&b>0){                                    //if-Bedingung bestimmt, ob Kugeln und die Wand stossen;
    ff1 = cw*(0.25-b);                                  //ff1,ff2,ff3,ff4 sind Vorfaktoren der Kraft von Stossen;
    X2OPP(i) += ff1;}                                   //ff1,ff2,ff3,ff4 = Wandelastizitaet*Eindringung;
    if(c<0.24&&c>0){
    ff2 = cw*(0.25-c);
    X2OPP(i) += -ff2;}
    if(d<0.24&&d>0){
    ff3 = cw*(0.25-d);
    X2OPP(i+N) += ff3;}
    if(e<0.24&&e>0){
    ff4 = cw*(0.25-e);
    X2OPP(i+N) += -ff4;}}


   }


void TUser::Blatt(){
   int i,j;
   SetPen(Hellrot,2);
   SetBrush(Hellblau);
   Rectangle(1.0,1.0,18.0,10.0);                 // aussere Wand zu defilieren
   SetPen(Blau); SetBrush(Grau);
   Rectangle(1.5,1.5,17.0,9.0);                  // innere Wand zu defilieren
   SetPen(Schwarz,3);
   SetBrush(Schwarz);
   for(i=0;i<=2;i++)                             // sechs Loecher zu defilieren
   for(j=0;j<=1;j++)
   {
   Circle(1.50+8.5*i,1.50+9.0*j,0.35);
   }
}

void TUser::Reset(){
   double x=5.0,y=6.0,z=9.0;                     // x ist X Bezugswert im Koordinaten von Kugel
                                                 // y ist Y bezugswert im Koordinaten von Kugel
                                                 // z ist der Bezugsabstand zwischen der weisser Kugel und der erster Kugel
   int i;
   a1=0;
   a2=0;
   X2O(0)=x;                                     //die Position der weisser Kugel definieren
   X2O(0+N)=y;

                                                 // die Positionen der erste 4 Kugeln
  X2O(1)=x+z+0.433*0,X2O(1+N)=y+0.25*0;
  X2O(2)=x+z+0.433*1,X2O(2+N)=y+0.25*1;
  X2O(3)=x+z+0.433*2,X2O(3+N)=y+0.25*2;
  X2O(4)=x+z+0.433*3,X2O(4+N)=y+0.25*3;

                                                 // die Positionen der zweite 3 Kugeln
  X2O(5)=x+z+0.433+0.433*0,X2O(5+N)=y-0.25+0.25*0;
  X2O(6)=x+z+0.433+0.433*1,X2O(6+N)=y-0.25+0.25*1;
  X2O(7)=x+z+0.433+0.433*2,X2O(7+N)=y-0.25+0.25*2;

                                                 // die Positionen der dritte 2 Kugeln
   X2O(8)=x+z+0.433*2+0.433*0,X2O(8+N)=y-0.25*2+0.25*0;
   X2O(9)=x+z+0.433*2+0.433*1,X2O(9+N)=y-0.25*2+0.25*1;


                                                 // die Position der letzte 1 Kugel
   X2O(10)=x+z+0.433*3,X2O(10+N)=y-0.25*3;

   for(i=0;i<N;i++){                             //Anfangsgeschwindigkeit zu definieren
   X2OP(i) = 0;
   X2OP(N+i) = 0;}



   InitIntegration();

   Draw();
   }

void TUser::Draw() {
   Clear();
   Blatt();
   SetPen(Weiss);
   SetBrush(Weiss);
   Circle(X2O(0),X2O(0+N),0.25);                 // weisse Kugel zu zeichnen

   int i;
   SetPen(Schwarz); SetBrush(Schwarz);           // ein farbige Kugel zu zeichnen
   Circle(X2O(10),X2O(0+N+10),0.25);

   SetPen(Schwarz); SetBrush(Blau);              // zwei farbige Kugeln zu zeichnen
   Circle(X2O(9),X2O(9+N),0.25);
   SetPen(Schwarz); SetBrush(Hellblau);
   Circle(X2O(8),X2O(8+N),0.25);

   SetPen(Schwarz); SetBrush(Hellviolett);        // drei farbige Kugeln zu zeichnen
   Circle(X2O(7),X2O(7+N),0.25);
   SetPen(Schwarz); SetBrush(Hellgruen);
   Circle(X2O(6),X2O(6+N),0.25);
   SetPen(Schwarz); SetBrush(Hellgelb);
   Circle(X2O(5),X2O(5+N),0.25);

   SetPen(Schwarz); SetBrush(Hellrot);              // vier farbige Kugeln zu zeichnen
   Circle(X2O(4),X2O(4+N),0.25);
   SetPen(Schwarz); SetBrush(Rot);
   Circle(X2O(3),X2O(3+N),0.25);
   SetPen(Schwarz); SetBrush(Gelb);
   Circle(X2O(2),X2O(2+N),0.25);
   SetPen(Schwarz); SetBrush(Violett);
   Circle(X2O(1),X2O(1+N),0.25);

   Klick();
   PlanString s1,s2;                             //die Oberflaeche fuer Punkte zeichenen
   s1="Punkt1";
   s2="Punkt2";
   SetText(Schwarz,30);
   SetBrush(Klar);
   Text(0.2, 0.9, s1);
   Text(0.2, 0.5, a1);
   SetText(Rot,30);
   Text(1.5, 0.9, s2);
   Text(1.5, 0.5, a2);
   }

void TUser::Klick(){                             //##die Darstellung vom Stock;
   double w;
   if(klick){
   dx=X2O(22)-X2O(0);
   dy=X2O(23)-X2O(N);
   w = sqrt(dx*dx+dy*dy);
   if(f1==true)                                  //Schwarzer Stock vom Spieler 1;
   {SetPen(Schwarz,18);
    MoveTo(X2O(22),X2O(23));
    LineTo(X2O(22)+2*dx/w,X2O(23)+2*dy/w);
    SetPen(Weiss,10);
    MoveTo(X2O(22),X2O(23));
    LineTo(X2O(22)+2*dx/w,X2O(23)+2*dy/w); }
   if(f2==true)                                  //Roter Stock vom Spieler 2;
   {SetPen(Rot,18);
    MoveTo(X2O(22),X2O(23));
    LineTo(X2O(22)+2*dx/w,X2O(23)+2*dy/w);
    SetPen(Weiss,10);
    MoveTo(X2O(22),X2O(23));
    LineTo(X2O(22)+2*dx/w,X2O(23)+2*dy/w); }
    }
   }

void TUser::RunTaste0(){                         //##Spieler 1
   f1=true;                                      //den Stock zu aktivieren
   f2=false;
   klick=true;
   X2O(22)=X2O(0)+0.01;
   X2O(23)=X2O(N)+0.01;
   Draw();}

void TUser::RunTaste1(){                         //##Spieler 2
   f2=true;                                      //den Stock zu aktivieren
   f1=false;
   klick=true;
   X2O(22)=X2O(0)+0.01;
   X2O(23)=X2O(N)+0.01;
   Draw();}

void TUser::RunTaste2(){                                                  //##Reset von der weissen Kugel,wenn sie ins Lochs geht;
   X2O(0)=5.0;X2O(N)=6.0;X2OP(0)=0;X2OP(N)=0;X2OPP(0)=0;X2OPP(N)=0;}

void TUser::BildMouseDown(int x, int y){                                  //##Mouseklickevent ;
   double xx ,yy ;                                                        //xx,yy sind die Koordinaten des Stocks in Fensterkoordinatensystem;
   xx= XToInt(X2O(22)); yy= YToInt(X2O(23));

   if((x>=xx-1)&&(x<=xx+1)&&(y>=yy-1)&&(y<=yy+1))                         //der Mouseklickpunkt bleibt im Punkte des Stocks;
   ZeigerAktiv=true;
   if(!ZeigerAktiv) return;
   }

void TUser::BildMouseMove(int x, int y, int leftdown){
   double w;
   xx= XToInt(X2O(22)); yy= YToInt(X2O(23));
   if(!leftdown)return;
   Draw();
   xx = x;
   yy = y;
   xc= IntToX(xx);
   yc= IntToY(yy);
   X2O(22)=xc;                 //die Veraenderung von der Position des Stocks durch Mousebewegung;(xc,yc sind neue Posen vom Stock)
   X2O(23)=yc;
   Klick();
   dx=X2O(22)-X2O(0);          //die Kraft von dem Stock zu definieren:
   dy=X2O(23)-X2O(N);          //je groessere Abstand zwischen dem weissen Kugeln und dem Stock,desto groessere Kraft;
   w = sqrt(dx*dx+dy*dy);      //w ist der Abstand;
   xp=5*w*dx/w;                //Kraft vom Stock in x und y Richtung zu trennen. Hier wird die Kraft durch die Geschwindigkeitsaenderung ersetzt.
   yp=5*w*dy/w;                //xp und yp sind die Geschwindigkeitsaenderung in x und y Richtungen;

   }

void TUser::BildMouseUp(int x, int y){
   los=true;                   //Nach dem "BildMouseUp" wird "los" gleich true sein. D.h. die Kraft vom Stock wird auf weisse Kugel uebertragen;
   klick=false;                //Nach dem "BildMouseUp" wird der Stock verschwinden;
   ZeigerAktiv = false;
   };

//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____
