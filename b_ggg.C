#include "TFile.h"
#include "TChain.h"
#include "TNtuple.h"
#include "TTree.h"
#include "TCutG.h"
#include "TCanvas.h"
#include "TStopwatch.h"
#include "TText.h"
#include <TH2F.h>
#include <TGraph.h>
#include <TF1.h>
#include <TLegend.h>
#include <TMath.h>
#include <TAxis.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <TROOT.h>
#include <TRint.h>

using namespace std;

/*
Either start “root -b” (try “root -?”) or:
gROOT->SetBatch(kTRUE); // before creating the canvas
*/
void b_ggg()
{
   TStopwatch t;

   TFile *output = new TFile("b_ggg.root","recreate");


// 9Be data from Tick(really Thin) targets
TString Treename1 = "DATA";
TChain * dchain = new TChain(Treename1);

dchain->Add("sorted32.root"); //Target #3 Thick Home Made
dchain->Add("sorted33.root"); //Target #3 Thick Home Made
dchain->Add("sorted35.root"); //Target #3 Thick Home Made
dchain->Add("sorted36.root"); //Target #3 Thick Home Made
dchain->Add("sorted37.root"); //Target #3 Thick Home Made
dchain->Add("sorted38.root"); //Target #3 Thick Home Made
dchain->Add("sorted39.root"); //Target #3 Thick Home Made
//dchain->Add("sorted40.root"); //Target #2 Good Fellows
//dchain->Add("sorted41.root"); //Target #2 Good Fellows

 //-------------------------------------------  
/*
int entries = dchain->GetEntries();

for(int i = 0; i < entries; i++)
   {
      dchain->GetEntry(i);
   }
*/
//------------------------------------------------


int entries = dchain->GetEntries();

for(int j = 0; j < entries; j++)
	{
		dchain->GetEntry(j);
	}


//gROOT->ProcessLine(".x cutMg26L.C");

 // Tritons Gate   -----    --------// 
  TCanvas *cuttri = new TCanvas();
gROOT->ProcessLine(".x newcut9B.C");

dchain->SetAlias("newX1pos","X1pos+0.0127483*(tof-3120)-0.000332362*pow(tof-3120,2.)"); // Scattering Angle correction Daniel manual
/*
TCanvas *c44 = new TCanvas();
	TH1F *hnewX1pos = new TH1F("hnewX1pos","X1pos+Scatter Angle Correction 9B;Focal Plane (arb. units);Counts",1200,-10,800);
//	TH1F *X1pos = new TH1F("X1pos","X1pos - NO Scatter Angle Correction",930,-110,820);
    dchain->Draw("newX1pos>>hnewX1pos","newcut9B && !X1flag && !U1flag","col");
	 hnewX1pos->Write();
 */

/*
TCanvas *c444 = new TCanvas();
   TH1F *K = new TH1F("K","Kinetic_t + ScatCorr 9B; Kinetic_t (MeV);Counts",1200,40,50);
  dchain->Draw("40.9967+newX1pos*0.0110095-0.000000584097*pow(newX1pos,2.)>>K","newcut9B && !X1flag && !U1flag","col");
  K->Write();
*/
  dchain->SetAlias("Et","40.9967+newX1pos*0.0110095-0.00000008437*pow(newX1pos,2.)");
/*
TCanvas *c4444 = new TCanvas();
   TH1F *Ex_t = new TH1F("Ex_t","9B Spectrum clean; Ex (MeV);Counts",1200,-2,6);
  dchain->Draw("50.0-Et-1.08662683205-0.035+0.129>>Ex_t","newcut9B && !X1flag && !U1flag","col"); // Eloss= -0.168, 50.0-Et-1.08662683205 
  Ex_t->Write();
  */
dchain->SetAlias("Exx","50.0-Et-1.08662683205-0.035+0.129"); // Eloss= -0.168

/*
TCanvas *c77 = new TCanvas();
TH2F *SiliconEnergysvsExx = new TH2F("SiliconEnergysvsExx","SiliconEnergy_:Exx_ 9B;Ex [MeV];Silicon Energy [arb. units] ",1200,-0.5,6,1200,0,10000);
	dchain->Draw("SiliconEnergy:Exx>>SiliconEnergysvsExx","newcut9B && !X1flag && !U1flag && abs(SiliconTime-tof)<200","col");
  SiliconEnergysvsExx->Write();
*/
/*
 TCanvas *c77333333 = new TCanvas();
TH2F *SiliconEnergysvsFPmm = new TH2F("SiliconEnergysvsFPmm","SiliconEnergy_:FP;FP [mm];Silicon Energy [arb. units] ",1200,-10,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>SiliconEnergysvsFPmm","newcut9B && !X1flag && !U1flag && abs(SiliconTime-tof)<200","col");
  SiliconEnergysvsFPmm->Write(); 
*/

//--------   Upload protons Gates TCutG ---------//
// CAKE 1 Rings -------------
//c1r0 not work
 TCanvas *cc1r1 = new TCanvas();
gROOT->ProcessLine(".x c1r1.C");

 TCanvas *cc1r2 = new TCanvas();
gROOT->ProcessLine(".x c1r2.C");

 TCanvas *cc1r3 = new TCanvas();
gROOT->ProcessLine(".x c1r3.C");

 TCanvas *cc1r4 = new TCanvas();
gROOT->ProcessLine(".x c1r4.C");

 TCanvas *cc1r5 = new TCanvas();
gROOT->ProcessLine(".x c1r5.C");

 TCanvas *cc1r6 = new TCanvas();
gROOT->ProcessLine(".x c1r6.C");

 TCanvas *cc1r7 = new TCanvas();
gROOT->ProcessLine(".x c1r7.C");

 TCanvas *cc1r8 = new TCanvas();
gROOT->ProcessLine(".x c1r8.C");

 TCanvas *cc1r9 = new TCanvas();
gROOT->ProcessLine(".x c1r9.C");

 TCanvas *cc1r10 = new TCanvas();
gROOT->ProcessLine(".x c1r10.C");

 TCanvas *cc1r11 = new TCanvas();
gROOT->ProcessLine(".x c1r11.C");

 TCanvas *cc1r12 = new TCanvas();
gROOT->ProcessLine(".x c1r12.C");

 TCanvas *cc1r13 = new TCanvas();
gROOT->ProcessLine(".x c1r13.C");

 TCanvas *cc1r14 = new TCanvas();
gROOT->ProcessLine(".x c1r14.C");

 TCanvas *cc1r15 = new TCanvas();
gROOT->ProcessLine(".x c1r15.C");

// CAKE 2 Rings ---------------------
TCanvas *cc2r0 = new TCanvas();
gROOT->ProcessLine(".x c2r0.C");

TCanvas *cc2r1 = new TCanvas();
gROOT->ProcessLine(".x c2r1.C");

 TCanvas *cc2r2 = new TCanvas();
gROOT->ProcessLine(".x c2r2.C");

 TCanvas *cc2r3 = new TCanvas();
gROOT->ProcessLine(".x c2r3.C");

 TCanvas *cc2r4 = new TCanvas();
gROOT->ProcessLine(".x c2r4.C");

 TCanvas *cc2r5 = new TCanvas();
gROOT->ProcessLine(".x c2r5.C");

//c1r0 not work

 TCanvas *cc2r7 = new TCanvas();
gROOT->ProcessLine(".x c2r7.C");

 TCanvas *cc2r8 = new TCanvas();
gROOT->ProcessLine(".x c2r8.C");

 TCanvas *cc2r9 = new TCanvas();
gROOT->ProcessLine(".x c2r9.C");

 TCanvas *cc2r10 = new TCanvas();
gROOT->ProcessLine(".x c2r10.C");

 TCanvas *cc2r11 = new TCanvas();
gROOT->ProcessLine(".x c2r11.C");

 TCanvas *cc2r12 = new TCanvas();
gROOT->ProcessLine(".x c2r12.C");

 TCanvas *cc2r13 = new TCanvas();
gROOT->ProcessLine(".x c2r13.C");

 TCanvas *cc2r14 = new TCanvas();
gROOT->ProcessLine(".x c2r14.C");

 TCanvas *cc2r15 = new TCanvas();
gROOT->ProcessLine(".x c2r15.C");

// CAKE 5 Rings -----------------------
TCanvas *cc5r0 = new TCanvas();
gROOT->ProcessLine(".x c5r0.C");

TCanvas *cc5r1 = new TCanvas();
gROOT->ProcessLine(".x c5r1.C");

 TCanvas *cc5r2 = new TCanvas();
gROOT->ProcessLine(".x c5r2.C");

 TCanvas *cc5r3 = new TCanvas();
gROOT->ProcessLine(".x c5r3.C");

 TCanvas *cc5r4 = new TCanvas();
gROOT->ProcessLine(".x c5r4.C");

 TCanvas *cc5r5 = new TCanvas();
gROOT->ProcessLine(".x c5r5.C");

 TCanvas *cc5r6 = new TCanvas();
gROOT->ProcessLine(".x c5r6.C");

 TCanvas *cc5r7 = new TCanvas();
gROOT->ProcessLine(".x c5r7.C");

 TCanvas *cc5r8 = new TCanvas();
gROOT->ProcessLine(".x c5r8.C");

 TCanvas *cc5r9 = new TCanvas();
gROOT->ProcessLine(".x c5r9.C");

 TCanvas *cc5r10 = new TCanvas();
gROOT->ProcessLine(".x c5r10.C");

 TCanvas *cc5r11 = new TCanvas();
gROOT->ProcessLine(".x c5r11.C");

 TCanvas *cc5r12 = new TCanvas();
gROOT->ProcessLine(".x c5r12.C");

 TCanvas *cc5r13 = new TCanvas();
gROOT->ProcessLine(".x c5r13.C");

 TCanvas *cc5r14 = new TCanvas();
gROOT->ProcessLine(".x c5r14.C");

 TCanvas *cc5r15 = new TCanvas();
gROOT->ProcessLine(".x c5r15.C");

/// -- END ---- GATES ------



/*
TCanvas *cakevsmm = new TCanvas();
TH2F *SiliconEnergysvsmmc1r1 = new TH2F("SiliconEnergysvsmmc1r1","SiliconEnergy:newX1pos;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
	dchain->Draw("SiliconEnergy:newX1pos>>SiliconEnergysvsmmc1r1"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && c1r1 && c1r2 && c1r3 && c1r4 && c1r5 && c1r6 && c1r7 && c1r8 && c1r9 && c1r10 && c1r11 && c1r12 && c1r13 && c1r14 && c1r15","col");
  SiliconEnergysvsmmc1r1->Write();
*/

/*
TCanvas *cakevsmm = new TCanvas();
TH2F *SiliconEnergysvsmmc1r1 = new TH2F("SiliconEnergysvsmmc1r1","SiliconEnergy:newX1pos;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>SiliconEnergysvsmmc1r1"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && c1r1 && c1r2 && c1r3 && c1r4 && c1r5 && c1r6 && c1r7 && c1r8 && c1r9 && c1r10 && c1r11 && c1r12 && c1r13 && c1r14 && c1r15","col");
  SiliconEnergysvsmmc1r1->Write();
*/


// -----------  BIDI CAKE 1 -------------///
// c1r0 NO WORK 

TCanvas *cbc1r1 = new TCanvas();
TH2F *TH2c1r1 = new TH2F("TH2c1r1","TH2c1r1;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r1"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==1 && c1r1","col");
  TH2c1r1->Write();

TCanvas *cbc1r2 = new TCanvas();
TH2F *TH2c1r2 = new TH2F("TH2c1r2","TH2c1r2;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r2"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==2 && c1r2","col");
  TH2c1r2->Write();

TCanvas *cbc1r3 = new TCanvas();
TH2F *TH2c1r3 = new TH2F("TH2c1r3","TH2c1r3;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r3"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==3 && c1r3","col");
  TH2c1r3->Write();

TCanvas *cbc1r4 = new TCanvas();
TH2F *TH2c1r4 = new TH2F("TH2c1r4","TH2c1r4;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r4"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==4 && c1r4","col");
  TH2c1r4->Write();

TCanvas *cbc1r5 = new TCanvas();
TH2F *TH2c1r5 = new TH2F("TH2c1r5","TH2c1r5;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r5"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==5 && c1r5","col");
  TH2c1r5->Write();

TCanvas *cbc1r6 = new TCanvas();
TH2F *TH2c1r6 = new TH2F("TH2c1r6","TH2c1r6;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r6"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==6 && c1r6","col");
  TH2c1r6->Write();

TCanvas *cbc1r7 = new TCanvas();
TH2F *TH2c1r7 = new TH2F("TH2c1r7","TH2c1r7;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r7"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==7 && c1r7","col");
  TH2c1r7->Write();

TCanvas *cbc1r8 = new TCanvas();
TH2F *TH2c1r8 = new TH2F("TH2c1r8","TH2c1r8;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r8"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==8 && c1r8","col");
  TH2c1r8->Write();

TCanvas *cbc1r9 = new TCanvas();
TH2F *TH2c1r9 = new TH2F("TH2c1r9","TH2c1r9;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r9"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==9 && c1r9","col");
  TH2c1r9->Write();

TCanvas *cbc1r10 = new TCanvas();
TH2F *TH2c1r10 = new TH2F("TH2c1r10","TH2c1r10;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r10"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==10 && c1r10","col");
  TH2c1r10->Write();

TCanvas *cbc1r11 = new TCanvas();
TH2F *TH2c1r11 = new TH2F("TH2c1r11","TH2c1r11;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r11"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==11 && c1r11","col");
  TH2c1r11->Write();

TCanvas *cbc1r12 = new TCanvas();
TH2F *TH2c1r12 = new TH2F("TH2c1r12","TH2c1r12;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r12"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==12 && c1r12","col");
  TH2c1r12->Write();

TCanvas *cbc1r13 = new TCanvas();
TH2F *TH2c1r13 = new TH2F("TH2c1r13","TH2c1r13;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r13"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==13 && c1r13","col");
  TH2c1r13->Write();

TCanvas *cbc1r14 = new TCanvas();
TH2F *TH2c1r14 = new TH2F("TH2c1r14","TH2c1r14;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r14"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==14 && c1r14","col");
  TH2c1r14->Write();

TCanvas *cbc1r15 = new TCanvas();
TH2F *TH2c1r15 = new TH2F("TH2c1r15","TH2c1r15;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r15"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==1 && StripFront==15 && c1r15","col");
  TH2c1r15->Write();

// -----------  BIDI CAKE 2 -----------------------------------------------------------------------------------------------------------------------------------------------///
TCanvas *cbc2r0 = new TCanvas();
TH2F *TH2c2r0 = new TH2F("TH2c2r0","TH2c2r0;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r0"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==1 && c2r0","col");
  TH2c2r0->Write();

TCanvas *cbc2r1 = new TCanvas();
TH2F *TH2c2r1 = new TH2F("TH2c2r1","TH2c2r1;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r1"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==1 && c2r1","col");
  TH2c2r1->Write();

TCanvas *cbc2r2 = new TCanvas();
TH2F *TH2c2r2 = new TH2F("TH2c2r2","TH2c2r2;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r2"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==2 && c2r2","col");
  TH2c2r2->Write();

TCanvas *cbc2r3 = new TCanvas();
TH2F *TH2c2r3 = new TH2F("TH2c2r3","TH2c2r3;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r3"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==3 && c2r3","col");
  TH2c2r3->Write();

TCanvas *cbc2r4 = new TCanvas();
TH2F *TH2c2r4 = new TH2F("TH2c2r4","TH2c2r4;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r4"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==4 && c2r4","col");
  TH2c2r4->Write();

TCanvas *cbc2r5 = new TCanvas();
TH2F *TH2c2r5 = new TH2F("TH2c2r5","TH2c2r5;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r5"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==5 && c2r5","col");
  TH2c2r5->Write();

// c2r6 NO WORK 

TCanvas *cbc2r7 = new TCanvas();
TH2F *TH2c2r7 = new TH2F("TH2c2r7","TH2c2r7;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r7"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==7 && c2r7","col");
  TH2c2r7->Write();

TCanvas *cbc2r8 = new TCanvas();
TH2F *TH2c2r8 = new TH2F("TH2c2r8","TH2c2r8;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r8"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==8 && c2r8","col");
  TH2c2r8->Write();

TCanvas *cbc2r9 = new TCanvas();
TH2F *TH2c2r9 = new TH2F("TH2c2r9","TH2c2r9;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r9"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==9 && c2r9","col");
  TH2c2r9->Write();

TCanvas *cbc2r10 = new TCanvas();
TH2F *TH2c2r10 = new TH2F("TH2c2r10","TH2c2r10;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r10"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==10 && c2r10","col");
  TH2c2r10->Write();

TCanvas *cbc2r11 = new TCanvas();
TH2F *TH2c2r11 = new TH2F("TH2c2r11","TH2c2r11;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r11"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==11 && c2r11","col");
  TH2c2r11->Write();

TCanvas *cbc2r12 = new TCanvas();
TH2F *TH2c2r12 = new TH2F("TH2c2r12","TH2c2r12;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r12"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==12 && c2r12","col");
  TH2c2r12->Write();

TCanvas *cbc2r13 = new TCanvas();
TH2F *TH2c2r13 = new TH2F("TH2c2r13","TH2c2r13;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r13"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==13 && c2r13","col");
  TH2c2r13->Write();

TCanvas *cbc2r14 = new TCanvas();
TH2F *TH2c2r14 = new TH2F("TH2c2r14","TH2c2r14;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r14"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==14 && c2r14","col");
  TH2c2r14->Write();

TCanvas *cbc2r15 = new TCanvas();
TH2F *TH2c2r15 = new TH2F("TH2c2r15","TH2c2r15;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c2r15"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==15 && c2r15","col");
  TH2c2r15->Write();

// ------ BIDI CAKE 5  -----------------------------------------------------------------------------------------------------------------------------------------------//
TCanvas *cbc5r0 = new TCanvas();
TH2F *TH2c5r0 = new TH2F("TH2c5r0","TH2c5r0;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r0"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==0 && c5r0","col");
  TH2c5r0->Write();

TCanvas *cbc5r1 = new TCanvas();
TH2F *TH2c5r1 = new TH2F("TH2c5r1","TH2c5r1;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r1"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==1 && c5r1","col");
  TH2c5r1->Write();

TCanvas *cbc5r2 = new TCanvas();
TH2F *TH2c5r2 = new TH2F("TH2c5r2","TH2c5r2;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r2"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==2 && c5r2","col");
  TH2c5r2->Write();

TCanvas *cbc5r3 = new TCanvas();
TH2F *TH2c5r3 = new TH2F("TH2c5r3","TH2c5r3;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r3"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==3 && c5r3","col");
  TH2c5r3->Write();

TCanvas *cbc5r4 = new TCanvas();
TH2F *TH2c5r4 = new TH2F("TH2c5r4","TH2c5r4;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r4"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==4 && c5r4","col");
  TH2c5r4->Write();

TCanvas *cbc5r5 = new TCanvas();
TH2F *TH2c5r5 = new TH2F("TH2c5r5","TH2c5r5;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r5"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==5 && c5r5","col");
  TH2c5r5->Write();

TCanvas *cbc5r6 = new TCanvas();
TH2F *TH2c5r6 = new TH2F("TH2c5r6","TH2c5r6;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r6"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==6 && c5r6","col");
  TH2c5r6->Write();

TCanvas *cbc5r7 = new TCanvas();
TH2F *TH2c5r7 = new TH2F("TH2c5r7","TH2c5r7;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r7"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==7 && c5r7","col");
  TH2c5r7->Write();

TCanvas *cbc5r8 = new TCanvas();
TH2F *TH2c5r8 = new TH2F("TH2c5r8","TH2c5r8;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r8"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==8 && c5r8","col");
  TH2c5r8->Write();

TCanvas *cbc5r9 = new TCanvas();
TH2F *TH2c5r9 = new TH2F("TH2c5r9","TH2c5r9;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r9"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==9 && c5r9","col");
  TH2c5r9->Write();

TCanvas *cbc5r10 = new TCanvas();
TH2F *TH2c5r10 = new TH2F("TH2c5r10","TH2c5r10;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r10"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==10 && c5r10","col");
  TH2c5r10->Write();

TCanvas *cbc5r11 = new TCanvas();
TH2F *TH2c5r11 = new TH2F("TH2c5r11","TH2c5r11;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r11"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==11 && c5r11","col");
  TH2c5r11->Write();

TCanvas *cbc5r12 = new TCanvas();
TH2F *TH2c5r12 = new TH2F("TH2c5r12","TH2c5r12;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r12"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==12 && c5r12","col");
  TH2c5r12->Write();

TCanvas *cbc5r13 = new TCanvas();
TH2F *TH2c5r13 = new TH2F("TH2c5r13","TH2c5r13;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r13"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==13 && c5r13","col");
  TH2c5r13->Write();

TCanvas *cbc5r14 = new TCanvas();
TH2F *TH2c5r14 = new TH2F("TH2c5r14","TH2c5r14;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r14"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==14 && c5r14","col");
  TH2c5r14->Write();

TCanvas *cbc5r15 = new TCanvas();
TH2F *TH2c5r15 = new TH2F("TH2c5r15","TH2c5r15;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c5r15"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==5 && StripFront==15 && c5r15","col");
  TH2c5r15->Write();

//-----   END BIDI  -----------


// ---- MERGE Histos ----- ///
TCanvas *cbmerge = new TCanvas();
TList *list = new TList;
// c1r0 no work
  list->Add(TH2c1r1);
  list->Add(TH2c1r2);
  list->Add(TH2c1r3);
  list->Add(TH2c1r4);
  list->Add(TH2c1r5);
  list->Add(TH2c1r6);
  list->Add(TH2c1r7);
  list->Add(TH2c1r8);
  list->Add(TH2c1r9);
  list->Add(TH2c1r10);
  list->Add(TH2c1r11);
  list->Add(TH2c1r12);
  list->Add(TH2c1r13);
  list->Add(TH2c1r14);
  list->Add(TH2c1r15);

  list->Add(TH2c2r0);
  list->Add(TH2c2r1);
  list->Add(TH2c2r2);
  list->Add(TH2c2r3);
  list->Add(TH2c2r4);
  list->Add(TH2c2r5);
// c2r6 no work
  list->Add(TH2c2r7);
  list->Add(TH2c2r8);
  list->Add(TH2c2r9);
  list->Add(TH2c2r10);
  list->Add(TH2c2r11);
  list->Add(TH2c2r12);
  list->Add(TH2c2r13);
  list->Add(TH2c2r14);
  list->Add(TH2c2r15);

  list->Add(TH2c5r0);
  list->Add(TH2c5r1);
  list->Add(TH2c5r2);
  list->Add(TH2c5r3);
  list->Add(TH2c5r4);
  list->Add(TH2c5r5);
  list->Add(TH2c5r6);
  list->Add(TH2c5r7);
  list->Add(TH2c5r8);
  list->Add(TH2c5r9);
  list->Add(TH2c5r10);
  list->Add(TH2c5r11);
  list->Add(TH2c5r12);
  list->Add(TH2c5r13);
  list->Add(TH2c5r14);
  list->Add(TH2c5r15);

  TH2F *TH2Merge = (TH2F*)TH2c1r1->Clone("TH2Merge");
  TH2Merge->Reset();
  TH2Merge->Merge(list);
  TH2Merge->SetLineColor(9);
  TH2Merge->Draw();
  TH2Merge->Write();
  cbmerge->Print("MERGE_sipCutCorr.png");

  //TH2Merge->Print("all"); > filename.txt


/*
////------     GATES   CAKE 1  ------- /////
TCanvas *c77701 = new TCanvas();
TH2F *Caketime = new TH2F("Caketime","Caketime",1200,0,10000,1200,-400,400);
	dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==0","col"); 
  Caketime->Write();
 // c77701->Print("CAKE_1reb01.png");

TCanvas *c77722 = new TCanvas();
TH2F *Caketime2 = new TH2F("Caketime2","Caketime2 ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime2"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==1 ","col");  
  Caketime2->Write();
 // c77722->Print("CAKE_1reb02.png");

TCanvas *c77733 = new TCanvas();
TH2F *Caketime3 = new TH2F("Caketime3","Caketime3 ",1200,0,10000,1200,-400,400);
	dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime3"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==2","col"); 
  Caketime3->Write();
 // c77733->Print("CAKE_1reb03.png");

TCanvas *c77744 = new TCanvas();
TH2F *Caketime4 = new TH2F("Caketime4","Caketime4 ",1200,0,10000,1200,-400,400);
	dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime4"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==3","col"); 
  Caketime4->Write();
 // c77744->Print("CAKE_1reb04.png");

TCanvas *c77755 = new TCanvas();
TH2F *Caketime5 = new TH2F("Caketime5","Caketime5 ",1200,0,10000,1200,-400,400);
	dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime5"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==4","col"); 
  Caketime5->Write();
 //  c77755->Print("CAKE_1reb05.png");

TCanvas *c77766 = new TCanvas();
TH2F *Caketime6 = new TH2F("Caketime6","Caketime6",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime6"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==5","col"); 
  Caketime6->Write();
 //  c77766->Print("CAKE_1reb06.png");

TCanvas *c77777 = new TCanvas();
TH2F *Caketime7 = new TH2F("Caketime7","Caketime7",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime7"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==6","col"); 
  Caketime7->Write();
 //  c77777->Print("CAKE_1reb07.png");

TCanvas *c77788 = new TCanvas();
TH2F *Caketime8 = new TH2F("Caketime8","Caketime8 ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime8"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==7","col"); 
  Caketime8->Write();
 //  c77788->Print("CAKE_1reb08.png");

TCanvas *c77799 = new TCanvas();
TH2F *Caketime9 = new TH2F("Caketime9","Caketime9 ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime9"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==8","col"); 
  Caketime9->Write();
//   c77799->Print("CAKE_1reb09.png");

TCanvas *c77710 = new TCanvas();
TH2F *Caketime10 = new TH2F("Caketime10","Caketime10 ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime10"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==9","col"); 
  Caketime10->Write();
//   c77710->Print("CAKE_1reb10.png");

TCanvas *c77711 = new TCanvas();
TH2F *Caketime11 = new TH2F("Caketime11","Caketime11 ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime11"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==10","col"); 
  Caketime11->Write();
 //  c77711->Print("CAKE_1reb11.png");

TCanvas *c77712 = new TCanvas();
TH2F *Caketime12 = new TH2F("Caketime12","Caketime12 ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime12"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==11","col"); 
  Caketime12->Write();
 //  c77712->Print("CAKE_1reb12.png");

TCanvas *c77713 = new TCanvas();
TH2F *Caketime13 = new TH2F("Caketime13","Caketime13",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime13"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==12","col"); 
  Caketime13->Write();
 //  c77713->Print("CAKE_1reb13.png");

TCanvas *c77714 = new TCanvas();
TH2F *Caketime14 = new TH2F("Caketime14","Caketime14 ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime14"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==13","col"); 
  Caketime14->Write();
 //  c77714->Print("CAKE_1reb14.png");

TCanvas *c77715 = new TCanvas();
TH2F *Caketime15 = new TH2F("Caketime15","Caketime15 ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime15"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==14","col"); 
  Caketime15->Write();
 //  c77715->Print("CAKE_1reb15.png");

TCanvas *c77716 = new TCanvas();
TH2F *Caketime16 = new TH2F("Caketime16","Caketime16",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime16"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300 && DetectorHit==2 && StripFront==15","col"); 
  Caketime16->Write();
 //  c77716->Print("CAKE_1reb16.png");
*/

t.Print();
}
