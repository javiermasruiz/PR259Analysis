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
void mg()
{
   TStopwatch t;

   TFile *output = new TFile("mg.root","recreate");

// 26Mg data
TString Treename = "DATA";
TChain * dchain = new TChain(Treename);
dchain->Add("sorted26.root");//This run was used for resolution check 
//dchain->Add("sorted31.root");//This run only lasted 8 minutes from 2:05 to 2:13 
dchain->Add("sorted34.root"); 
dchain->Add("sorted46.root"); 
dchain->Add("sorted49.root"); 
dchain->Add("sorted52.root"); 
dchain->Add("sorted55.root"); 
dchain->Add("sorted58.root"); 
dchain->Add("sorted61.root"); 
dchain->Add("sorted64.root"); 
dchain->Add("sorted66.root");
dchain->Add("sorted69.root"); 
dchain->Add("sorted72.root"); 
/*
// 9Be data from Tick(really Thin) targets
TString Treename1 = "DATA";
TChain * dchain1 = new TChain(Treename1);
//dchain1->Add("sorted32.root"); //Target #3 Thick Home Made
//dchain1->Add("sorted33.root"); //Target #3 Thick Home Made
//dchain1->Add("sorted35.root"); //Target #3 Thick Home Made
//dchain1->Add("sorted36.root"); //Target #3 Thick Home Made
//dchain1->Add("sorted37.root"); //Target #3 Thick Home Made
//dchain1->Add("sorted38.root"); //Target #3 Thick Home Made
//dchain1->Add("sorted39.root"); //Target #3 Thick Home Made
dchain1->Add("sorted40.root"); //Target #2 Good Fellows
dchain1->Add("sorted41.root"); //Target #2 Good Fellows
*/
 //-------------------------------------------  

int entries = dchain->GetEntries();

for(int i = 0; i < entries; i++)
   {
      dchain->GetEntry(i);
   }
/*
int entries1 = dchain1->GetEntries();

for(int j = 0; j < entries1; j++)
	{
		dchain1->GetEntry(j);
	}
*/

//------------------ load CUT's ------------------------------
gROOT->ProcessLine(".x cutMg26L.C");
//gROOT->ProcessLine(".x cutb9tritons.C");

dchain->SetAlias("newX1pos","X1pos+0.0127483*(tof-3120)-0.000332362*pow(tof-3120,2.)"); // Scattering Angle correction Daniel manual
//dchain1->SetAlias("newX1posBthick","X1pos+0.0127483*(tof-3120)-0.000332362*pow(tof-3120,2.)"); // Scattering Angle correction

TCanvas *c44 = new TCanvas();
	TH1F *hnewX1pos = new TH1F("hnewX1pos","X1pos+Scatter Angle Correction 26Al;Focal Plane (arb. units);Counts",1200,0,500);
//	TH1F *X1pos = new TH1F("X1pos","X1pos - NO Scatter Angle Correction",930,-110,820);
    dchain->Draw("newX1pos>>hnewX1pos","cutMg26L && !X1flag && !U1flag","col");
	 hnewX1pos->Write();
  
/*
TCanvas *c45 = new TCanvas();
	TH1F *hnewX1posB = new TH1F("hnewX1posB","X1pos+Scatter Angle Correction 9Bthick;Focal Plane (arb. units);Counts",930,-110,820);
//	TH1F *X1posB = new TH1F("X1posB","X1posB - NO Scatter Angle Correction",930,-110,820);
    dchain1->Draw("newX1posBthick>>hnewX1posB","cutb9tritons && !X1flag && !U1flag","col");
	hnewX1posB->Write();
*/

TCanvas *c2 = new TCanvas();
   TH2F *hX1posvstof = new TH2F("hX1posvstof","TOF vs X1pos (cutMg26L && !X1flag && !U1flag);FP (mm);tof (0.1ns/Ch)",1000,0,500,1000,3020,3200);
   dchain->Draw("tof:X1pos>>hX1posvstof","cutMg26L && !X1flag && !U1flag","col");
   hX1posvstof->Write();

TCanvas *c2456 = new TCanvas();
   TH2F *hX1posvstofcorrr = new TH2F("hX1posvstofcorrr","TOF vs newX1pos (cutMg26L && !X1flag && !U1flag);FP (mm);tof (0.1ns/Ch) ",1000,0,500,1000,3020,3200);
   dchain->Draw("tof:newX1pos>>hX1posvstofcorrr","cutMg26L && !X1flag && !U1flag","col");
   hX1posvstofcorrr->Write();
/*
//TCanvas *c2 = new TCanvas();
   TH1F *hX1posCorr = new TH1F("hX1posCorr","X1pos+Scatter Angle Correction",2000,0,700);
    dchain->Draw("X1pos+0.0127483*(tof-3120)-0.000332362*pow(tof-3120,2.)>>hX1posCorr","cutMg26L && !X1flag && !U1flag","col");// Scattering Angle correction
 //  hX1posCorr->Write();

//TCanvas *c3 = new TCanvas();
    TH2F *hnewX1posvstof = new TH2F("hnewX1posvstof","TOF vs X1pos+Scatter Angle Correction",1000,0,500,1000,3020,3200);
   dchain->SetAlias("newX1pos","X1pos+0.0127483*(tof-3120)-0.000332362*pow(tof-3120,2.)"); // Scattering Angle correction
   dchain->Draw("tof:newX1pos>>hnewX1posvstof","cutMg26L && !X1flag && !U1flag","col");
   hnewX1posvstof->Write();
   c3->Print("tof_vs_X1Pos_angle_correction.png");

TCanvas *c4 = new TCanvas();
   TH1F *hnewX1pos = new TH1F("hnewX1pos","X1pos+Scatter Angle Correction",2000,0,700);
   TH1F *X1pos = new TH1F("X1pos","X1pos - NO Scatter Angle Correction",2000,0,700);
    dchain->Draw("newX1pos>>hnewX1pos","cutMg26L && !X1flag && !U1flag","col");
    dchain->Draw("X1pos>>X1pos","cutMg26L && !X1flag && !U1flag","col");
   hnewX1pos->Write();

TCanvas *c5 = new TCanvas();
   hnewX1pos->SetLineColor(2);
   hnewX1pos->Draw();
   X1pos->SetLineColor(1);
   X1pos->Draw("same");
*/

//     Fiting 

//   Pol2 fitting to Lineshape Correction to tof:X1pos ******
/*
   const int n=6;
   Float_t tof[n] = {52.03, 31.91, -5.17, -31.65, -47.54, -62.37};
   Float_t X1[n] = {440.899, 440.992, 441.039, 441.085, 442.300, 443.047};              

   TCanvas *cl11 = new TCanvas("cl11", "Correction Scattering angle using TOF",55,52,700,500);

   TF1 *fl = new TF1("fl","pol2");
   TGraph *gr = new TGraph(n,tof,X1);
   
   gr->SetLineColor(kBlack);
   gr->SetLineWidth(2);
   gr->SetLineStyle(1);
   gr->SetMarkerColor(1);
   gr->SetMarkerStyle(20);

   gr->Fit("fl");    
   gr->Draw("AP");
   gr->Write();

// cl11->Update();
   cl11->cd();
   cl11->Write();

   float p0 = fl->GetParameter(0);
   float p1 = fl->GetParameter(1);
   float p2 = fl->GetParameter(2);
   cout << "************ POL2 *************************   " << endl;
   cout << "p0:   " << p0 << endl;
   cout << "p1:   " << p1 << endl;
   cout << "p2:   " << p2 << endl;
   cout << "************ FIN POL2 *************************   " << endl;
*/

//             Gauss Fit 26Al peaks  *********

   TF1 *fg1_D1 = new TF1("fg1_D1","gaus");
   fg1_D1->SetLineColor(kGreen);
   fg1_D1->SetLineWidth(2);
   TF1 *fg2_D1 = new TF1("fg2_D1","gaus");
   fg2_D1->SetLineColor(kGreen);
   fg2_D1->SetLineWidth(2);
   TF1 *fg3_D1 = new TF1("fg3_D1","gaus");
   fg3_D1->SetLineColor(kGreen);
   fg3_D1->SetLineWidth(2);
   TF1 *fg4_D1 = new TF1("fg4_D1","gaus");
   fg4_D1->SetLineColor(kGreen);
   fg4_D1->SetLineWidth(2);
   hnewX1pos->Fit("fg1_D1","", "", 430, 446);// esta info se extrae del macro vis26mg9b.C del X1pos+lineshape correction 
   hnewX1pos->Fit("fg2_D1","+", "", 355, 368);
   hnewX1pos->Fit("fg3_D1","+", "", 282, 292);
   hnewX1pos->Fit("fg4_D1","+", "", 262, 272);

   float mean1_D1 =  fg1_D1->GetParameter(1);
   float sigma1_D1 = fg1_D1->GetParameter(2);

   float mean2_D1 =  fg2_D1->GetParameter(1);
   float sigma2_D1 = fg2_D1->GetParameter(2);

   float mean3_D1 =  fg3_D1->GetParameter(1);
   float sigma3_D1 = fg3_D1->GetParameter(2);

   float mean4_D1 =  fg4_D1->GetParameter(1);
   float sigma4_D1 = fg4_D1->GetParameter(2);

   cout << "************ Gaus Fit 26Al *************************   " << endl;
   cout << "Medio1_D1: " <<  mean1_D1 << endl;
   cout << "Sigma1_D1: " << sigma1_D1 << endl;

   cout << "Medio2_D1: " <<  mean2_D1 << endl;
   cout << "Sigma2_D1: " << sigma2_D1 << endl;  

   cout << "Medio3_D1: " <<  mean3_D1 << endl;
   cout << "Sigma3_D1: " << sigma3_D1 << endl;

   cout << "Medio4_D1: " <<  mean4_D1 << endl;
   cout << "Sigma4_D1: " << sigma4_D1 << endl;

   cout << "************ FIN Gaus 26Al*************************   " << endl;


   /*
//             Gauss Fit 9B peaks  **********
   TF1 *fg5_D1 = new TF1("fg5_D1","gaus");
   fg5_D1->SetLineColor(kGreen);
   fg5_D1->SetLineWidth(2);
   hnewX1posB->Fit("fg5_D1","", "", 715, 743); // esta info se extrae del macro vis26mg9b.C del X1pos+lineshape correction 

   float mean5_D1 =  fg5_D1->GetParameter(1);
   float sigma5_D1 = fg5_D1->GetParameter(2);

   cout << "************ Gaus Fit 9B *************************   " << endl;
   cout << "Medio5_D1: " <<  mean5_D1 << endl;
   cout << "Sigma5_D1: " << sigma5_D1 << endl;

   cout << "************ FIN Gaus 9B*************************   " << endl;
*/

//   Pol2 fitting to Focal plane, Excitation Energy vs Kinetic Energy of Tritons ********

   const int nn=4;
   //Float_t rig[nn] = { 1697.563, 1681.874, 1666.724, 1662.474};      // Excited States 26Al 26Mg(3He,3H)26Al 
   Float_t kin[nn] = { 45.735, 44.901, 44.144, 43.880};                // Kinetic energy of triton hitting Focal Plane
   Float_t Ex[nn] = { mean1_D1, mean2_D1, mean3_D1, mean4_D1};            

   TCanvas *clEx = new TCanvas("clEx", "Correction Scattering angle using TOF",55,52,700,500);

   TF1 *flEx = new TF1("flEx","pol2");
   TGraph *grEx = new TGraph(nn,Ex,kin);
   
   grEx->SetLineColor(kBlack);
   grEx->SetLineWidth(2);
   grEx->SetLineStyle(1);
   grEx->SetMarkerColor(1);
   grEx->SetMarkerStyle(20);

   grEx->Fit("flEx");    
   grEx->Draw("AP");
   grEx->Write();

// clEx->Update();
   clEx->cd();
   clEx->Write();
/*
   float p0Ex = flEx->GetParameter(0);
   float p1Ex = flEx->GetParameter(1);
   float p2Ex = flEx->GetParameter(2);

   cout << "************ POL2 Ex*************************   " << endl;
   cout << "p0Ex:   " << p0Ex << endl;
   cout << "p1Ex:   " << p1Ex << endl;
   cout << "p2Ex:   " << p2Ex << endl;
   cout << "************ FIN POL2 Ex*************************   " << endl;
*/
/*
// Parameters output *******
fstream out;
   out.open("Fitting_Parameters.txt",ios::out);

   if(out.fail()){
     cout <<" No se pudo abrir el archivo de Salida ";
     exit(1);
   }
   
   out << " Pol2 fitting scattering angle correction, Lineshape Correction "<< endl;
   out << " pol2 p0: " << p0 << endl;
   out << " pol2 p1: " << p1 << endl;
   out << " pol2 p2: " << p2 << endl;
   out << " --------------------------" << endl;
   out << " Pol2 fitting to Focal plane to Excitation Energy "<< endl;
   out << " p0Ex: " << p0Ex << endl;
   out << " p1Ex: " << p1Ex << endl;
   out << " p2Ex: " << p2Ex << endl;

out.close();
*/
   /*
   TCanvas *c6 = new TCanvas();
   TH1F *hnewX1posCalibrated = new TH1F("hnewX1posCalibrated","X1Pos_angle_correction+Energy_Calibration",2000,-500,4918);
//    dchain->Draw("((newX1pos-462.055)/(-0.0939672))>>hnewX1posCalibrated","cutMg26L && !X1flag && !U1flag","col");
   dchain->Draw("(-10.642*newX1pos)+4917.19>>hnewX1posCalibrated","cutMg26L && !X1flag && !U1flag","col");
   hnewX1posCalibrated->GetXaxis()->SetTitle("Excitation Energy of populated states or 26Al[keV]");
   hnewX1posCalibrated->GetYaxis()->SetTitle("Counts");
   hnewX1posCalibrated->Write();
   c6->Print("X1Pos_angle_correction+Energy_Calibration.png");
*/

TCanvas *c444 = new TCanvas();
   TH1F *K = new TH1F("K","Kinetic_t + ScatCorr 26Al; Kinetic_t (MeV);Counts",1200,40,50);
  dchain->Draw("40.9967+newX1pos*0.0110095-0.000000584097*pow(newX1pos,2.)>>K","cutMg26L && !X1flag && !U1flag","col");
  K->Write();
dchain->SetAlias("Et","40.9967+newX1pos*0.0110095-0.000000584097*pow(newX1pos,2.)");

// Ex = Eb - Et - Qval

TCanvas *c4444 = new TCanvas();
   TH1F *Ex_t = new TH1F("Ex_t","Ex + ScatCorr 26Al + Energy loss corr; Ex (MeV);Counts",1200,-1,6);
  dchain->Draw("50.0-Et-4.023024-0.035>>Ex_t","cutMg26L && !X1flag && !U1flag","col");
  Ex_t->Write();
//dchain->SetAlias("Et","40.9967+newX1pos*0.0110095-0.000000584097*pow(newX1pos,2.)");

t.Print();
}
