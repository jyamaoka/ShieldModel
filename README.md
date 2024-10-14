# G4 Shield Model
Model of shielded CsI detector 


## Overview
Simultion of CsI detector shielded by a Al, Cu, or brass shields.  Returns event level energy deposted in the CsI detector.

## Getting Started

### Prerequisites
- [Geant5](https://github.com/Geant4/geant4) 
- [CMake](https://cmake.org/)
- [root](https://root.cern.ch/) (optional)

### 1. Clone the repository

```shell
git clone https://github.com/jyamaoka/G4ShieldModel.git
cd G4ShieldModel
```

### 2. Make build directory

```shell
mkdir shieldmodel_build
cd shieldmodel_build
```

### 3. Run cmake and build executable

```shell
cmake ../
make
```

### 3. Launch the executable

Run in interactive mode with visualization
```shell
./shieldmodel
```

Run in batch mode with Cs137 ion source
```shell
./shieldmodel cs137.mac
```