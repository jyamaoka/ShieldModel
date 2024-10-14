//
//
/// \file ShieldModelActionInitialization.hh
/// \brief Definition of the ShieldModelActionInitialization class

#ifndef ShieldModelActionInitialization_h
#define ShieldModelActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class ShieldModelActionInitialization : public G4VUserActionInitialization
{
  public:
    ShieldModelActionInitialization();
    virtual ~ShieldModelActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
