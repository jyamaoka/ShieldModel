//
//
/// \file ShieldModelSteppingAction.cc
/// \brief Implementation of the ShieldModelSteppingAction class

#include "ShieldModelSteppingAction.hh"
#include "ShieldModelEventAction.hh"
#include "ShieldModelDetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ShieldModelSteppingAction::ShieldModelSteppingAction(ShieldModelEventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fScoringVolume(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ShieldModelSteppingAction::~ShieldModelSteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ShieldModelSteppingAction::UserSteppingAction(const G4Step* step)
{
  if (!fScoringVolume) { 
    const ShieldModelDetectorConstruction* detectorConstruction
      = static_cast<const ShieldModelDetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();   
  }

  // get volume of the current step
  G4LogicalVolume* volume 
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();
      
  // check if we are in scoring volume
  if (volume != fScoringVolume) return;

  // collect energy deposited in this step
  G4double edepStep = step->GetTotalEnergyDeposit();
  fEventAction->AddEdep(edepStep);  

   // collect track traveled in this step
  G4double stepLength  = step->GetStepLength();
  fEventAction->AddLtvl(stepLength);   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

