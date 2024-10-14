//
//
/// \file ShieldModelEventAction.cc
/// \brief Implementation of the ShieldModelEventAction class

#include "ShieldModelEventAction.hh"
#include "ShieldModelRunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"

#include "ShieldModelAnalysis.hh" 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ShieldModelEventAction::ShieldModelEventAction(ShieldModelRunAction* runAction)
: G4UserEventAction(),
  fRunAction(runAction),
  fEdep(0.),
  fLtvl(0.)
{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ShieldModelEventAction::~ShieldModelEventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ShieldModelEventAction::BeginOfEventAction(const G4Event*)
{    
  fEdep = 0.;
  fLtvl = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ShieldModelEventAction::EndOfEventAction(const G4Event* event)
{ 
  // get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();
  
  // fill ntuple
  if (fEdep>0.0){
    analysisManager->FillNtupleDColumn(0, fEdep);
    analysisManager->FillNtupleDColumn(1, fLtvl);
    analysisManager->AddNtupleRow();  
  }
  
  // Print per event (modulo n)
  //
  auto eventID = event->GetEventID();
  auto printModulo = G4RunManager::GetRunManager()->GetPrintProgress();
  if ( ( printModulo > 0 ) && ( eventID % printModulo == 0 ) ) {
  //if ( 1 ) {
    G4cout << "---> End of event: " << eventID << G4endl;     

    G4cout
       << "   Absorber: total energy: " << std::setw(7)
                                        << G4BestUnit(fEdep,"Energy")
       << "       total track length: " << std::setw(7)
                                        << G4BestUnit(fLtvl,"Length")
       << G4endl;
  }

  // accumulate statistics in run action
  fRunAction->AddEdep(fEdep);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
