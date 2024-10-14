//
//
/// \file ShieldModelEventAction.hh
/// \brief Definition of the ShieldModelEventAction class

#ifndef ShieldModelEventAction_h
#define ShieldModelEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class ShieldModelRunAction;

/// Event action class
///

class ShieldModelEventAction : public G4UserEventAction
{
  public:
    ShieldModelEventAction(ShieldModelRunAction* runAction);
    virtual ~ShieldModelEventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    void AddEdep(G4double edep) { fEdep += edep; }
    void AddLtvl(G4double ltvl) { fLtvl += ltvl; }

  private:
    ShieldModelRunAction* fRunAction;
    G4double     fEdep;
    G4double     fLtvl;    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
