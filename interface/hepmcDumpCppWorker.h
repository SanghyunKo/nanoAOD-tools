#ifndef PhysicsTools_NanoAODTools_hepmcDumpCppWorker_h
#define PhysicsTools_NanoAODTools_hepmcDumpCppWorker_h

#include <memory>
#include <string>
#include <vector>
#include <TTree.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include "HepMC/IO_GenEvent.h"

class hepmcDumpCppWorker {

public:

  hepmcDumpCppWorker(const std::string fileName, const unsigned int pdfStart, const unsigned int pdfEnd, const std::string pdfSet);
  ~hepmcDumpCppWorker();

  void setGenEventInfo(TTreeReaderValue<unsigned long long> *eventNumber,
                       TTreeReaderValue<float> *genWeight,
                       TTreeReaderValue<float> *Generator_x1, TTreeReaderValue<float> *Generator_x2,
                       TTreeReaderValue<unsigned> *nLHEScaleWeight = nullptr, TTreeReaderArray<float> *LHEScaleWeight = nullptr,
                       TTreeReaderValue<unsigned> *nLHEPdfWeight = nullptr, TTreeReaderArray<float> *LHEPdfWeight = nullptr,
                       TTreeReaderValue<unsigned> *nUnknownWeight = nullptr, TTreeReaderArray<float> *UnknownWeight = nullptr);

  void setGenParticles(TTreeReaderValue<unsigned> *nGenPart,
                       TTreeReaderArray<float> *GenPart_pt, TTreeReaderArray<float> *GenPart_eta, TTreeReaderArray<float> *GenPart_phi, TTreeReaderArray<float> *GenPart_mass,
                       TTreeReaderArray<int> *GenPart_pdgId, TTreeReaderArray<int> *GenPart_status,
                       TTreeReaderArray<int> *GenPart_genPartIdxMother);
  void genEvent();

private:
  TTreeReaderValue<unsigned long long> *b_eventNumber = nullptr;
  TTreeReaderValue<float> *b_genWeight = nullptr;
  TTreeReaderValue<float> *b_Generator_x1 = nullptr;
  TTreeReaderValue<float> *b_Generator_x2 = nullptr;
  TTreeReaderValue<unsigned> *b_nLHEScaleWeight = nullptr; 
  TTreeReaderArray<float> *b_LHEScaleWeight = nullptr;
  TTreeReaderValue<unsigned> *b_nLHEPdfWeight = nullptr;
  TTreeReaderArray<float> *b_LHEPdfWeight = nullptr;

  TTreeReaderValue<unsigned> *b_nUnknownWeight = nullptr;
  TTreeReaderArray<float> *b_UnknownWeight = nullptr;

  TTreeReaderValue<unsigned> *b_nGenPart = nullptr;
  TTreeReaderArray<float> *b_GenPart_pt = nullptr, *b_GenPart_eta = nullptr, *b_GenPart_phi = nullptr, *b_GenPart_mass = nullptr;
  TTreeReaderArray<int> *b_GenPart_pdgId = nullptr, *b_GenPart_status = nullptr;
  TTreeReaderArray<int> *b_GenPart_genPartIdxMother= nullptr;

  const double cmEnergy_ = 13000.;
  std::vector<int> signalParticlePdgIds_;
  HepMC::IO_GenEvent* fout_;

  const unsigned int _pdfStart, _pdfEnd;
  const std::string _pdfSet;
};

#endif
