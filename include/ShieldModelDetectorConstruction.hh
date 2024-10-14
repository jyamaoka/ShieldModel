//
//
/// \file ShieldModelDetectorConstruction.hh
/// \brief Definition of the ShieldModelDetectorConstruction class

#ifndef ShieldModelDetectorConstruction_h
#define ShieldModelDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

/// Detector construction class to define materials and geometry.

class ShieldModelDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    ShieldModelDetectorConstruction();
    virtual ~ShieldModelDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    
    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

  protected:
    G4LogicalVolume*  fScoringVolume;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

