//
//
/// \file ShieldModelPrimaryGeneratorAction.hh
/// \brief Definition of the ShieldModelPrimaryGeneratorAction class

#ifndef ShieldModelPrimaryGeneratorAction_h
#define ShieldModelPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"
#include "globals.hh"

class G4ParticleGun;
class G4GeneralParticleSource;
class G4Event;
class G4Box;

/// The primary generator action class with particle gun.
///
/// The default kinematic is a 6 MeV gamma, randomly distribued 
/// in front of the phantom across 80% of the (X,Y) phantom size.

class ShieldModelPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    ShieldModelPrimaryGeneratorAction();    
    virtual ~ShieldModelPrimaryGeneratorAction();

    // method from the base class
    virtual void GeneratePrimaries(G4Event*);         
  
    // method to access particle gun
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }
    const G4GeneralParticleSource* GetParticleSource() const { return fParticleSource; }

  private:
    G4ParticleGun*  fParticleGun; // pointer a to G4 gun class
    G4GeneralParticleSource* fParticleSource;
    G4Box* fEnvelopeBox;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
