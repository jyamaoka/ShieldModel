//
//
/// \file ShieldModelSteppingAction.hh
/// \brief Definition of the ShieldModelSteppingAction class

#ifndef ShieldModelSteppingAction_h
#define ShieldModelSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class ShieldModelEventAction;

class G4LogicalVolume;

/// Stepping action class
/// 

class ShieldModelSteppingAction : public G4UserSteppingAction
{
  public:
    ShieldModelSteppingAction(ShieldModelEventAction* eventAction);
    virtual ~ShieldModelSteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);

  private:
    ShieldModelEventAction*  fEventAction;
    G4LogicalVolume* fScoringVolume;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
