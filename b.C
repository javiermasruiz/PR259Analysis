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
| Steps to correct calibration of Focal Plane of K600 spectrometer
| 1- Lineshape correction
| 2- Energy Calibration using Rigidity or peak energies by pol2 
| 3- Energy correction of excitation energy levels despite of energy loss in target.
*/
void b()
{
   TStopwatch t;

   TFile *output = new TFile("b.root","recreate");


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



/*dchain->Add("sorted40.root"); //Target #2 Good Fellows
dchain->Add("sorted41.root"); //Target #2 Good Fellows*/

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
  TCanvas *eee = new TCanvas();
gROOT->ProcessLine(".x newcut9B.C");

TCanvas *cc1r1 = new TCanvas();
gROOT->ProcessLine(".x ProtonCakevsExcut.C");
/*
TCanvas *bananaP1 = new TCanvas();
gROOT->ProcessLine(".x bananaP1.C");

TCanvas *bananaP2 = new TCanvas();
gROOT->ProcessLine(".x bananaP2.C");
*/

dchain->SetAlias("newX1pos","X1pos+0.0127483*(tof-3120)-0.000332362*pow(tof-3120,2.)"); // Scattering Angle correction Daniel manual
/*
TCanvas *c44 = new TCanvas();
	TH1F *hnewX1pos = new TH1F("hnewX1pos","X1pos+Scatter Angle Correction 9B;Focal Plane (arb. units);Counts",1200,-10,800);
//	TH1F *X1pos = new TH1F("X1pos","X1pos - NO Scatter Angle Correction",930,-110,820);
    dchain->Draw("newX1pos>>hnewX1pos","newcut9B && !X1flag && !U1flag","col");
	 hnewX1pos->Write();
 */
/*
TCanvas *c1 = new TCanvas();
 TH2F *pad1vstof = new TH2F("pad1vstof","pad1:tof for create TritCut;#DeltaTOF [0.1ns/Ch];#DeltaE_{Scint} [arb. units]",600,2800,3400,2500,0,2500);
dchain->Draw("pad1:tof>>pad1vstof","!X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300","col");
pad1vstof->GetXaxis()->CenterTitle();
pad1vstof->GetYaxis()->CenterTitle();
pad1vstof->Write();
*/
/*
TCanvas *c444 = new TCanvas();
   TH1F *K = new TH1F("K","Kinetic_t + ScatCorr 9B; Kinetic_t (MeV);Counts",1200,40,50);
  dchain->Draw("40.9967+newX1pos*0.0110095-0.00000008437*pow(newX1pos,2.)>>K","newcut9B && !X1flag && !U1flag","col");
  K->Write();
*/
   dchain->SetAlias("Et","40.9967+newX1pos*0.0110095-0.00000008437*pow(newX1pos,2.)");

   dchain->SetAlias("Exx","50.0-Et-1.08662683205-0.035+0.129");

TCanvas *c4444 = new TCanvas();
   TH1F *Ex_tclean = new TH1F("Ex_tclean"," 9B Spectrum+Time_Gate+ProtonCakevsExcut; Ex (MeV);Counts",1200,-2,6);
  dchain->Draw("Exx>>Ex_tclean","newcut9B && abs(SiliconTime-tof)<200 && !X1flag && !U1flag && ProtonCakevsExcut","col");
  Ex_tclean->Write();

TCanvas *c44442vv = new TCanvas();
   TH1F *Ex_sibananaP2 = new TH1F("Ex_sibananaP2","9B Spectrum+Time_Gate; Ex (MeV);Counts",1200,-2,6);
  dchain->Draw("Exx>>Ex_sibananaP2","newcut9B && abs(SiliconTime-tof)<200 && !X1flag && !U1flag","col");
  Ex_sibananaP2->Write();
/*
TCanvas *c44442 = new TCanvas();
   TH1F *Ex_nobananaP2 = new TH1F("Ex_nobananaP2"," no !bananaP2 9B Spectrum; Ex (MeV);Counts",1200,-2,6);
  dchain->Draw("50.0-Et-1.08662683205-0.035+0.129>>Ex_nobananaP2","newcut9B && !bananaP2 && SiliconTime>2800 && SiliconTime<3300 && !X1flag && !U1flag","col");
  Ex_nobananaP2->Write();


TCanvas *c4444bananaP1 = new TCanvas();
   TH1F *Ex_bananaP1 = new TH1F("Ex_bananaP1","bananaP1 9B Spectrum; Ex (MeV);Counts",1200,-2,6);
  dchain->Draw("50.0-Et-1.08662683205-0.035+0.129>>Ex_bananaP1","newcut9B && bananaP1 && SiliconTime>2800 && SiliconTime<3300 && !X1flag && !U1flag","col");
  Ex_bananaP1->Write();


TCanvas *c4444banananoP1 = new TCanvas();
   TH1F *Ex_banananoP1 = new TH1F("Ex_banananoP1","bananaP1 9B Spectrum; Ex (MeV);Counts",1200,-2,6);
  dchain->Draw("50.0-Et-1.08662683205-0.035+0.129>>Ex_banananoP1","newcut9B && !bananaP1 && SiliconTime>2800 && SiliconTime<3300 && !X1flag && !U1flag","col");
  Ex_banananoP1->Write();
*/


/*
TCanvas *cbc1r1 = new TCanvas();
TH2F *TH2c1r1 = new TH2F("TH2c1r1","TH2c1r1;FP [mm];Silicon Energy [arb. units] ",1200,0,800,1200,0,10000);
  dchain->Draw("SiliconEnergy:newX1pos>>TH2c1r1"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300","col"); 
  TH2c1r1->Write();
  */
/*
TCanvas *c77711 = new TCanvas();
TH2F *Caketime = new TH2F("Caketime","SiliconEnergy_:SiliconTime-tof (1);Silicon Energy [arb. units];Tsi-Tk600/ns ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime"," newcut9B && !X1flag && !U1flag && SiliconTime>2800 && SiliconTime<3300","col"); 
  Caketime->Write();
*/
// ----------------------------- Histo for ProtonCakevsExcut ---------------------------------
TCanvas *c77 = new TCanvas();
TH2F *SiliconEnergysvsExx = new TH2F("SiliconEnergysvsExx","SiliconEnergy_:Exx_ 9B;Ex [MeV];Silicon Energy [arb. units] ",1200,-0.5,6,1200,0,10000);
	dchain->Draw("SiliconEnergy:Exx>>SiliconEnergysvsExx","newcut9B && !X1flag && !U1flag && abs(SiliconTime-tof)<200","col");
  SiliconEnergysvsExx->Write();
 // c77->Print("SiliconEnergysvsExx.png");

/*
TCanvas *c7744711 = new TCanvas();
TH2F *Caketime = new TH2F("Caketime","SiliconEnergy_:SiliconTime-tof (1);Silicon Energy [arb. units];Tsi-Tk600/ns ",1200,0,10000,1200,-400,400);
  dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime"," newcut9B && !X1flag && !U1flag && abs(SiliconTime-tof)<200","col"); 
  Caketime->Write();
*/

/*
TCanvas *c77711 = new TCanvas();
TH2F *Caketime = new TH2F("Caketime","SiliconEnergy_:SiliconTime-tof (1);Silicon Energy [arb. units];Tsi-Tk600/ns ",1200,0,10000,1200,-400,400);
	dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime"," newcut9B && !X1flag && !U1flag && abs(SiliconTime-tof)<200 && DetectorHit==1","col"); 
  Caketime->Write();
//  c77711->Print("CAKE_1.png");

TCanvas *c77722 = new TCanvas();
TH2F *Caketime2 = new TH2F("Caketime2","SiliconEnergy_:SiliconTime-tof (2);Silicon Energy [arb. units];Tsi-Tk600/ns ",1200,0,10000,1200,-400,400);
	dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime2"," newcut9B && !X1flag && !U1flag && abs(SiliconTime-tof)<200 && DetectorHit==2","col"); 
  Caketime2->Write();
 // c77722->Print("CAKE_2.png");

TCanvas *c77733 = new TCanvas();
TH2F *Caketime3 = new TH2F("Caketime3","SiliconEnergy_:SiliconTime-tof (3);Silicon Energy [arb. units];Tsi-Tk600/ns ",1200,0,10000,1200,-1000,1000);
	dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime3"," newcut9B && !X1flag && !U1flag && abs(SiliconTime-tof)<200 && DetectorHit==3","col"); 
  Caketime3->Write();
 // c77733->Print("CAKE_3.png");

TCanvas *c77744 = new TCanvas();
TH2F *Caketime4 = new TH2F("Caketime4","SiliconEnergy_:SiliconTime-tof (4);Silicon Energy [arb. units];Tsi-Tk600/ns ",1200,0,10000,1200,-1000,1000);
	dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime4"," newcut9B && !X1flag && !U1flag && abs(SiliconTime-tof)<200 && DetectorHit==4","col"); 
  Caketime4->Write();
 // c77744->Print("CAKE_4.png");

TCanvas *c77755 = new TCanvas();
TH2F *Caketime5 = new TH2F("Caketime5","SiliconEnergy_:SiliconTime-tof (5);Silicon Energy [arb. units];Tsi-Tk600/ns ",1200,0,10000,1200,-400,400);
	dchain->Draw("(SiliconTime-tof):SiliconEnergy>>Caketime5"," newcut9B && !X1flag && !U1flag && abs(SiliconTime-tof)<200 && DetectorHit==5","col"); 
  Caketime5->Write();
  // c77755->Print("CAKE_5.png");
*/
/*
TCanvas *c77557 = new TCanvas();
TH1F *toff = new TH1F("toff","tof;Ex [MeV];Tsi-Tk600/ns ",20000, -20000, 20000);
	dchain->Draw("SiliconTime>>toff","!X1flag && !U1flag","col"); 
  toff->Write();
 //cutb9tritons && !X1flag && !U1flag && abs(SiliconTime-tof)<200
*/
t.Print();
}
