//
//
/// \file ShieldModelActionInitialization.cc
/// \brief Implementation of the ShieldModelActionInitialization class

#include "ShieldModelActionInitialization.hh"
#include "ShieldModelPrimaryGeneratorAction.hh"
#include "ShieldModelRunAction.hh"
#include "ShieldModelEventAction.hh"
#include "ShieldModelSteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ShieldModelActionInitialization::ShieldModelActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ShieldModelActionInitialization::~ShieldModelActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ShieldModelActionInitialization::BuildForMaster() const
{
  ShieldModelRunAction* runAction = new ShieldModelRunAction;
  SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ShieldModelActionInitialization::Build() const
{
  SetUserAction(new ShieldModelPrimaryGeneratorAction);

  ShieldModelRunAction* runAction = new ShieldModelRunAction;
  SetUserAction(runAction);
  
  ShieldModelEventAction* eventAction = new ShieldModelEventAction(runAction);
  SetUserAction(eventAction);
  
  SetUserAction(new ShieldModelSteppingAction(eventAction));
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
