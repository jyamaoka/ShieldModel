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
class G4GenericMessenger;

/// Detector construction class to define materials and geometry.

class ShieldModelDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    ShieldModelDetectorConstruction();
    virtual ~ShieldModelDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    
    void SetNumShields(G4int num);
    void SetShieldDim(G4int id, G4double xdim, G4double ydim, G4double zdim);
    void SetShieldLoc(G4int id, G4double xloc, G4double yloc, G4double zloc);
    void SetDetectorLoc(G4double xloc, G4double yloc, G4double zloc);

    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

  private:
    void DefineCommands();

    G4LogicalVolume*  fScoringVolume;
    G4GenericMessenger* fMessenger;

    G4int fNumShields;
    

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

